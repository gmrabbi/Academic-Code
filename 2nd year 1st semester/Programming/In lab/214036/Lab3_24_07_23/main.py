
# # from Packages import logic
# # print(logic.OR_op(False, False))
# import random
# #
#
# # a = 10
# # b = 0b10
# # c = 0o3
# # d = 0x12
# # print(a , b, c , d)
# # print("\n")
# # rnd_lst = list()
# # for i in range(3):
# #     e = random.randint(1, 20)
# #     rnd_lst.append(e)
# #
# # print(rnd_lst)
#
# ls = [1, "name", 2.3, 4+5j, [1,5,"ad"]]
# # print(ls[-1][-1])
# sb_lst = ls[0:1+1]
# # print(sb_lst)
# #
# # for item in ls:
# #     # print(item, end=" ")
# # # print(2.1 in ls)
# # # print("2.1" in ls)
#
# # for i in range(1, 100, 2):
# #     print(i)
#
# # odd_num = [i for i in range(1, 101) if i%2]
# # print(odd_num)
#
# ls.insert(0, "daf")
# # print(ls)
#
# # ls.extend(sb_lst)
# ls += sb_lst
# print(ls)
# print(sb_lst)
# print(ls.remove(1))
# print(ls)
# ls[0] = "kljdjf"
# print(ls)

ls = [11, 10 , 15, 32, 33, 56, 101, 150]
odd_list = [i for i in ls if i%2]
even_list = [i for i in ls if i%2==0]
print(odd_list)
print(even_list)

# odd = lambda i:  i for i in ls if i%2
# result = list(filter(lambda x: [x for x in ls if x%2] ))

result =  lambda x: [ y for y in x  if y % 2 == 0]
print(result(ls))

t = lambda x : [y for y in x if y%2]
# print(t(ls))

b = list(filter(lambda x: [x for x in ls if x% 2], ls))
#  when use the filter must use list
# print(b(ls))

color_list = ["black", "blue", "green", "red"]

print(t(ls))
print("::::::::::::::::::::::::::")
color = input("> ")
for color in color_list:
    if color in color_list:
        print(color, end=" ")
    else:
        print(color, end="-")
print()
