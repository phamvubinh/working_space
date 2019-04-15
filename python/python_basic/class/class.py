#!/usr/bin/python
import sys
class Employee:
	'Common base class for all employees'
	empCount = 0

	def __init__(self, name , salary):
		self.name = name
		self.salary = salary
		Employee.empCount += 1
	def displayCount(self):
		print "Total Employee %d" % Employee.empCount

	def displayEmployee(self):
		print "Name : ", self.name, ", Salary ", self.salary

emp1 = Employee("Binh", 1000)
emp2 = Employee("Long", 200)

print Employee.empCount

emp1.displayEmployee()
emp2.displayEmployee()

#Add and change attibute info in employee
emp1.age = 8
emp2.salary = emp1.salary/2 + emp1.age

emp2.displayEmployee()

#Get class attribute info
print "Employee.__doc__: ", Employee.__doc__
print "Employee.__name__: ", Employee.__name__
print "Employee.__module__: ", Employee.__module__
print "Employee.__bases__: ", Employee.__bases__
print "Employee.__dict__: ", Employee.__dict__