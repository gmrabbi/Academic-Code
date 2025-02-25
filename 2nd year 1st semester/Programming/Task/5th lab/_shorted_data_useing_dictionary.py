stu_data = dict() 
file = open("Student.csv", "w")
file.write("Name,Roll,Mark\n")
num = int(input("How many Student : "))
for i in range(num):
    name = input("Name : ")
    roll = int(input("Roll : "))
    mark = int(input("Mark : "))
    file.write(f"{name},{roll},{mark}\n")
    stu_data[name]= [roll, mark]
file.close()

with open('Student.csv', 'r') as file:
    lines = file.readlines()

header = lines[0]
data = list()
for line in lines[1:]:
    data.append(line.strip().split(","))

sorted_data = sorted(data, key=lambda x: int(x[2]))

with open('sorted_data.csv', 'w') as file:
    file.write(header)
    for row in sorted_data:
        file.write(f" {row[0]}, {row[1]}, {row[2]} \n")

print(stu_data)
print("Data has been sorted successfully.")
















# file = open("Student.csv", "r")

# for line in file.readlines()[1:]:
#     stu_data[line.split(",")[0]] = int(line.split(",")[-1][:-1])

# for key, value in stu_data.items():
#     stu_data[key] = value
#     stu_lst.append([key, value])

# st_lst = list(stu_data.values())
# st_lst.sort()


# stu_dic = {}
# num = int(input("Enter the number of students: "))

# with open("Student.csv", "w") as file:
#     file.write("Name,Roll\n")

#     for i in range(num):
#         name = input("Enter student name: ")
#         roll = int(input("Enter student roll: "))
#         file.write(f"{name},{roll}\n")
#         stu_dic[name] = roll

# print("Student data written to file.")

# with open('Student.csv', 'r') as file:
#     lines = file.readlines()

# header = lines[0]
# data = []
# for i in lines[1:]:
#     data.append(i.strip(","))

# sorted_data = sorted(data, key=lambda x: int(x[1]))

# with open('sorted_data.csv', 'w') as file:
#     file.write(header)
#     for row in sorted_data:
#         file.write(f"{row[0]},{row[1]}\n")

# print("Data sorted and written to sorted_data.csv.")
# print("Student data:", stu_dic)


# student_records = {}
# num_of_students = int(input("Enter the total number of students: "))

# with open("StudentData.csv", "w") as data_file:
#     data_file.write("StudentName,Score\n")

#     for i in range(num_of_students):
#         student_name = input("Enter the name of the student: ")
#         student_score = int(input("Enter the score of the student: "))
#         data_file.write(f"{student_name},{student_score}\n")
#         student_records[student_name] = student_score

# print("Student data has been saved to the file.")

# with open('StudentData.csv', 'r') as data_file:
#     lines = data_file.readlines()

# header = lines[0]
# data = [line.strip().split(',') for line in lines[1:]]

# sorted_data = sorted(data, key=lambda x: int(x[1]))

# with open('sorted_student_data.csv', 'w') as sorted_file:
#     sorted_file.write(header)
#     for row in sorted_data:
#         sorted_file.write(f"{row[0]},{row[1]}\n")

# print("Data has been sorted and saved to sorted_student_data.csv.")

# print("Student records:", student_records)
