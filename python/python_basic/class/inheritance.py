#!/usr/bin/python
class Parent:
	"""docstring for Parent"""
	parentAttr = 100
	def __init__(self):
		print "Calling parent constructor"

	def parentMethod(self):
		print "Calling parent method"

	def setAttr(self, attr):
		Parent.parentAttr = attr

	def getAttr(self):
		print "Parent attribute :", Parent.parentAttr

	def myMethod(self):
		print "Parent own method"

class Child(Parent):
	def __init__(self):
		print "Calling child construtor"

	def childMethod(self):
		print "Calling child method"

	#Overriding method
	def myMethod(self):
		print "Children method instead of parent method"


class House(Parent, Child):
	"Doc string for family"
	familyAttr = 18
	def __init(self):
		print "Calling house constructor"

	def houseMethod():
		print "House method"

class House2(Child, Parent):
	"Doc string for family"
	familyAttr = 18
	def __init(self):
		print "Calling house constructor"

	def houseMethod():
		print "House method"


p = Parent()
c = Child()

#Checking priority if 2 super class has same method
h = House()
h2 = House2()

c.childMethod()
c.parentMethod()
c.setAttr(12)
c.getAttr()

print "\n\n\n"
ret = issubclass(Child, Parent)
print "Child is subclass of super class Parent: ", ret

ret = isinstance(c, Parent)
print "c is an instance of Parent: ", ret

ret = isinstance(c, Child)
print "c is an instance of Child: ", ret

ret = isinstance(p, Parent)
print "p is an instance of Parent: ", ret

ret = isinstance(p, Child)
print "p is an instance of Child: ", ret

print "\n\n\n"
print "Checking overriding method"
p.myMethod()
c.myMethod()
print "\n\n\n"
print "Checking priority if 2 super class has same method"
h.myMethod()
h2.myMethod()


