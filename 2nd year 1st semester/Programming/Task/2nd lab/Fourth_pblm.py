def is_even(num):
    if(num % 2):
        return False
    else:
        return True


num = int(input("Enter a number : "))
if(is_even(num)):
    print(f"{num} is even number.")
else:
    print(f"{num} is odd number.")
