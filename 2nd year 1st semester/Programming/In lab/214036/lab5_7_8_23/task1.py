nm_ls = list()

# flag = True
# cnt = 0
# while flag:
#     num = int(input("> "))
#     if (num % 2 == 0):
#         nm_ls.append(num)
#         cnt += 1
#     if (cnt >= 10):
#         flag = False
# print(nm_ls)

# for i in range(10):
#     num = int(input("> "))
#     if(num%2==0):
#         nm_ls.append(num)
#
# print(nm_ls)
# new_ls = list()
# for i in nm_ls:
#     new_ls.append(i+1)
# print(new_ls)

# file = open("student.txt", "a")
# file.write("hello dear, ")
# file.write("Golam Mostafa rabby")
# file.close()
#
# file1= open("student.txt", "a")
# # file.write("hello dear, ")
# file1.write("Golam Mostafa rabby\n")
# file1.close()


# with open("student.txt", "a") as file:
#     # file.write("gm rabby\n")
#     for i in range(10):
#         name = input("enter your name : ")
#         file.write(f"{name} \n")

name_lst = list()
with open("student.txt", "r") as file:
    lines = file.readlines()

# for line in lines:
#     name_lst.append(line)
# sorted(lines)
lines.sort()
print(lines)


