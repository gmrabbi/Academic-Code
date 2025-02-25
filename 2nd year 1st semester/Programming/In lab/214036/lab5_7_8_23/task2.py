"""Dictionary
- Key value pair
- Key must be unique
- Datatypes of key have to be immutable (string, number, type,...)
- Datatypes of values may be any
example {key1:value1, key2:value2}
"""

# my_dict = {}
# my_dict = {1:"A",2:"B", 3:"C" , 4:"D"}
# for key, value in my_dict.items():
    # print(item)
    # print(key, value)
# print(my_dict[2])

# dict_1 = {"Alice":10, "Bob":20, "jon":3}
# print(list(dict_1.keys()))
# print(list(dict_1.values()))

# my_dict = dict()
# str1 = "bangladesh is our motherland"
# for ch in str1:
#     if(ch in my_dict.keys()):
#         my_dict[ch] += 1;
#     else:
#         my_dict[ch] = 1
# print(my_dict)
# new_dict = dict()
# student_dict = {"Sakib":(5.2, 65), "Rahim":(5.7, 75), "Alica":(5.1, 60), "Bob":(5.6, 70)}
# for key, value in student_dict.items():
#     if(value[0]>=5.6 and value[-1]>=70):
#         new_dict[key]=value
#
# # height>=5.6 and weight>=70
# print(new_dict)


new_dict = dict()
# student_dict = {"Sakib":(5.2, 65), "Rahim":(5.7, 75), "Alica":(5.1, 60), "Bob":(5.6, 70)}
# for item in student_dict.items():
#     print(item[1][-1], type(item))

# height>=5.6 and weight>=70
# print(new_dict)

student_dict = {"Sakib":65, "Rahim":75, "Alica":60, "Bob":70}
with open("student.csv", "w") as file:
    for item in student_dict.items():
        file.write(f"{item[0]} {item[-1]}\n")
ls = list()
with open("student.csv", "r") as file:
    for item in student_dict.items():
        ls.append(item[1])
ls.sort()
print(ls)
n = 0;
with open("new_studetn.csv", "w") as file:
    for item, value in student_dict.items():
        if()



