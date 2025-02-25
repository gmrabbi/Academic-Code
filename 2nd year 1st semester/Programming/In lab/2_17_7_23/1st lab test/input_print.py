# class c :
#     def __init__(self, x) -> None:
#         self.x = x

#     def get_x(self):
#         return self.x
#     def set_x(self, val):
#         self.x = val

# obj = c(23)
# print(obj.get_x())

# obj.set_x(3)
# print(obj.get_x())


# students = {
#     "Hermoine": "Gryffindor",
#     "Harry": "Gryffindor",
#     "Ron": "Gryffindor",
#     "Draco": "Slytherin",
# }
# for student in students:
#  print(student, students[student], sep=",")

# def is_even(n):
#     return False if(n%2) else True

# print(is_even(5))
# ===========================================================================
# file = open("name.csv", "w")
# stu_num = int(input("How many student: "))
# file.write("Name, Age, Dept\n")

# for name in range(stu_num):
#     name = input("Name: ")
#     age = int(input("Age: "))
#     dept = input("Dept: ")
#     file.write(f"{name}, {age}, {dept}\n")

# file.close()

# ls = list()
# file = open("name.csv", "r")
# head = file.readlines()
# # print(head[0])

dic = dict()

# for line in head[1:]:
#     word = line.strip().split(",")

#     dic[word[0]] = word[1:]

# st_data = sorted(dic, key=lambda x : int(x[0]))
# print(dic)


# with open("name.csv") as file:
#     for line in file.readlines()[1:]:
#         name, age , dept = line.rstrip().split(",")
#         # print(name ,age, dept)
#         dic[name] = [age, dept]
# # print(dic)

# sv = sorted(dic.items(), key=lambda item: item[1], reverse=False)
# print(sv)

# students = list()
# tudents = []
# with open("name.csv") as file:
#     for line in file:
#         name, *house = line.rstrip().split(",")
#         student = {}
#         student["name"] = name
#         student["house"] = house
#         students.append(student)
# # print(students)
# for student in students:
#     print(f"{student['name']} is in {student['house']}")

# tudents = []
# with open("name.csv") as file:
#     for line in file:
#         name, *house = line.rstrip().split(",")
#         students.append({"name": name, "house": house})


# def get_name(student):
#  return student["name"]


# for student in sorted(students, key=get_name):
#  print(f"{student['name']} is in {student['house']}")


# def student():
#     name = input("Name : ")
#     age = input("Age : ")
#     return (name, age)

# obj =  student()
# print(type(obj))


# class Student:
#     def __init__(self, name, house):
#         self.name = name
#         self.house = house
# def main():
#     student = get_student()
#     print(f"{student.name} from {student.house}")
# def get_student():
#     name = input("Name: ")
#     house = input("House: ")
#     student = Student(name, house)
#     print(type(student))
#     return student

# if __name__ == "__main__":
#     main()


# class Student:
#     def __init__(self, name, age) -> None:
#         self.name = name
#         self.age = age

# def get_data():
#     name = input("Name : ")
#     age = input("Age")
#     stu = Student(name, age)
#     return stu

# def main():
#     obj = get_data()
#     print(f"Name : {obj.name} and Age: {obj.age}")

# main()
# if __name__ == "main":
#     main()

class Student:
    def __init__(self, name, mark, age):
        self.name = name
        self.age = age
        self.mark = mark
    def __add__(self, other):
        age = self.age +other.age
        mark = self.mark + other.mark
        return(age, mark)
    def __eq__(self, other) -> bool:
        return True if(self.mark ==other.mark) else False


def main():
    student = get_student()
    print(f"{student.name} from {student.house}")


def get_student():
    name = input("Name: ")
    house = input("House: ")
    return Student(name, house)

obj1 = Student("a", 23, 23)
obj2 = Student("b", 23, 3)

age, mark = obj1 + obj2
print(obj1.__eq__(obj2))
print(age , mark)
# if __name__ == "__main__":
#     main()
