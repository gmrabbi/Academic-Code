# data1 = {"cat", "Dog"}
# print(type(data1))  # set

# print(data1[0]) # "cat"
# data1[2] = "fish"
# [1,2,3,4]
# data3 = {"cat":"cute", "Dog":"Funny", "Fish":"wet"}
# # data4 = (1,2,3,4)
# data4 = list((1, 2, 3, 4))
# data4[0]=10
# print("cat" in data1)

"""
data = ["cat","Dog"]
# data[2] = "fish"
data[0]=10
print(data)
"""

text = ["php","psw", "python", "java", "aaa"]
result = list(filter(lambda x: x == "".join(reversed(x)), text))
print(result)
