def is_even(n):
    # if(n%2):
    #     return False
    # return True
    return False if n%2 else True


num = int(input("Enter a Number : "))
if(is_even(num)):
    print(f"{num} is even number.")
else:
    print(f"{num} is odd number.")


