def fact(n):
    result = 1
    for i in range(2, n+1):
        result *= i
    return result

x = int(input("Enter the value of x : "))
n = int(input("Enter the value of n : "))
sum = 0
for i in range(n):
    sum += ((x**i)/fact(i))
print(sum)