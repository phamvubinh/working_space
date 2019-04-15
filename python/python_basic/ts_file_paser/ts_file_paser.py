#!/usr/bin/python
import sys
import os
import time

def TFP_Open_File(fileName):
	fd = open(fileName, "rb+")
	return fd

def TFP_Get_Syncbyte_Postion(fd):

	fd.seek(0, 0)

	while True:
		#Reading data from file
		position = fd.tell()
		syncByte = fd.read(1)

		#Check Null byte for EOF
		if(syncByte == None):
			print "End of file!"
			break

		#Compare to sync byte
		syncByteHex = ord(syncByte)
		if(syncByteHex == 0x47):
			print "syncByte is: 0x%x" %(syncByteHex)
			break

	return position

def TFP_Get_Packet_Pid(packet):
	return (((ord(packet[1]) & 0x1f) << 8) + ord(packet[2]))

def TFP_Get_Packet_Afc(packet):
	return ((ord(packet[3]) & 0x30)>>4);

def TFP_Get_Packet_Buff(fd, findPid):
	syncBytePos = TFP_Get_Syncbyte_Postion(fd)
	# print "syncBytePos: ", syncBytePos

	fd.seek(syncBytePos, 0)

	while True:
		buffPAT = fd.read(188)
		pid = 0xff
		pid = TFP_Get_Packet_Pid(buffPAT)
		if(pid == findPid):
			print "Found packet with PID: ", pid
			return buffPAT
		if(buffPAT == None):
			print "End of file"
			return None

def TFP_Get_Pat_Info(packetPAT):
	patDict = {}
	afc     = TFP_Get_Packet_Afc(packetPAT)
	afcLen  = ord(packetPAT[4])

	if(afc == 3):
		channelNum = ((((ord(packetPAT[7+afcLen])&0x0f)<<8) + ord(packetPAT[8+afcLen])) - 9)/4
	elif(afc == 1):
		channelNum = ((((ord(packetPAT[6])&0x0f)<<8) + ord(packetPAT[7])) - 9)/4
	else:
		channelNum = 0
		print "channelNum in function3: ", channelNum
	patDict["ChannelNum"] = channelNum

	for i in range(channelNum):
		programNum = ((ord(packetPAT[14 + afcLen + i*4])&0xff)<<8) + ord(packetPAT[15 + afcLen + i*4])
		pmtPID     = ((ord(packetPAT[16 + afcLen + i*4])&0x1f)<<8) + ord(packetPAT[17 + afcLen + i*4])

		patDict["ProgramNum_Channel_"+str(i)] = programNum
		patDict["PMT_PID_Channel_"+str(i)]    = pmtPID

	return patDict

def TFP_Get_Pmt_Info(packetPAT):
	pmtDict = {}
	afc     = TFP_Get_Packet_Afc(packetPAT)
	afcLen  = ord(packetPAT[4])

	checkEsLen  = 0
	esCount     = 0

	infoLen =((ord(packetPAT[16+ afcLen])&0x0f)<<8) + ord(packetPAT[17 + afcLen])
	esLen   =((ord(packetPAT[7 + afcLen])&0x0f)<<8) + ord(packetPAT[8  + afcLen]) - 13 - infoLen
	while(checkEsLen < esLen):
		esPid       = ((ord(packetPAT[18 + infoLen + afcLen + 1 + checkEsLen])&0x1f)<<8) + ord(packetPAT[18 + infoLen + afcLen + 2 + checkEsLen])
		streamType  =   ord(packetPAT[18 + infoLen + afcLen + checkEsLen])
		checkEsLen += ((ord(packetPAT[18 + infoLen + afcLen + 3 + checkEsLen])&0x0f)<<8) + ord(packetPAT[18 + infoLen + afcLen + 4 + checkEsLen]) + 5

		pmtDict["EsPid"+str(esCount)] 	   = esPid
		pmtDict["StreamType"+str(esCount)] = streamType

		esCount += 1;

	return pmtDict

def TFP_Help():
	print "Usage:"
	print "./ts_file_paser file_name"

def TFP_Main():

	#Open ts file
	fTSFileFd = TFP_Open_File(sys.argv[1])
	print "Name of this file: ", fTSFileFd.name

	#Get PAT packet
	packetPAT = TFP_Get_Packet_Buff(fTSFileFd, 0x00)
	for i in range(0,187):
		print "packetPAT[%d]: %x" %(i, ord(packetPAT[i]))

	#Get PAT info
	print "################# PAT #####################"
	patInfo = TFP_Get_Pat_Info(packetPAT)
	for field in patInfo:
		print field + ": %d" %(patInfo[field])

	print("\n\n\n")

	print "################# PMT #####################"
	for i in range(patInfo["ChannelNum"]):
		#Get PAT packet
		packetPMT = TFP_Get_Packet_Buff(fTSFileFd, patInfo["PMT_PID_Channel_"+ str(i)])

		#Get PMT info
		pmtInfo   = TFP_Get_Pmt_Info(packetPMT)
		for field in pmtInfo:
			print field + ": %d" %(pmtInfo[field])

	fTSFileFd.close()

if(len(sys.argv) >= 2 ):
	if(sys.argv[1] == "help"):
		TFP_Help()
	else:
		TFP_Main()
else:
	TFP_Help()

