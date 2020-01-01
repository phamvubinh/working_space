#ifndef __SHARE_MEM_INFO_H__
#define __SHARE_MEM_INFO_H__

#include <stdint.h>

#define SHARE_MEM_NAME 	"pvbinh_sharing"
#define SHARE_MEM_SIZE 	4096

#define SHM_VIRTUAL_START_ADDR 		0
#define SHM_PHYSICAL_OFFSET_ADDR 	0

typedef struct 
{
	char name[128];
	uint8_t age;
}SHARE_MEM_DATA_ST;

#endif