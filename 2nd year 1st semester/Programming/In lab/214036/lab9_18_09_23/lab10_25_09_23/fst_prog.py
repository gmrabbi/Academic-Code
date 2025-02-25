# try:
# print("Hello! )

# x = int(input("What's X?"))
# print(f"x is {x}")


# flag = True
# while flag:
#     try:
#         x = int(input("x >> "))
#         print(f"x is {x}")
#         flag = False
#     except ValueError:
#         print("x is not an integer.")

while True:
    try:
        x = int(input("x >> "))
        print(f"x is {x}")
        break
    except ValueError:
        print("x is not an integer.")
        

# for i in range(2):
#     print(i)
# else:
#     print(7)