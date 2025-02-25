sum = 0.0
n = int(input("Enter the value of n : "))
for i in range(1, n+1):
    if(i%2):
        sum += 4/(2*(i-1)+1)
    else: sum -= 4/(2*(i-1)+1)

print(f"Summation : {sum:.3f}")