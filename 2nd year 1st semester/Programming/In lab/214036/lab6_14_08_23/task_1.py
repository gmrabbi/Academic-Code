
'''
https://learn.microsoft.com/en-us/training/modules/python-object-oriented-programming/1-introduction
# Find objects, data, and behavior
https://www.geeksforgeeks.org/python-oops-concepts/
class defination and other ....

protected data member will be one underscore
def _speak(self):
	statement

Assignment..
1) stage | actor/object | Behavior | Data
	Find objects, data, and behavior
2) 2 problem solution

3) Resubmit 14/08/23 code
 		Name , Subject, Score   (student.csv)
 		Read
 		List
 		Sorted(list , key)


'''

class Dog:

	# class attribute
	attr1 = "mammal"

	# Instance attribute
	def __init__(sel, name):
		sel.name = name

# Driver code
# Object instantiation
Rodger = Dog("Rodger")
Tommy = Dog("Tommy")

# Accessing class attributes
print("Rodger is a {}".format(Rodger.__class__.attr1))
print("Tommy is also a {}".format(Tommy.__class__.attr1))

# Accessing instance attributes
print("My name is {}".format(Rodger.name))
print("My name is {}".format(Tommy.name))


print(4>8)
