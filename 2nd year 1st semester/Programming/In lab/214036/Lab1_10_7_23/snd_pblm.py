def circle_area(a):
    return 3.1416*a*a;


radius = int(input("Enter radius : "))
area = circle_area(radius)

print(area)
print(round(area, 3))
print(f"{area:.3f}")
