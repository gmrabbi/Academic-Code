def circle_area(r):
    area = 3.1416*r*r
    cir = 2*3.1416*r
    return  area, cir


radius = float(input("Enter radius : "))

# print(f"{circle_area(radius):.3f}")

area = circle_area(radius)
print(type(area))
# print(f"Result = {round(circle_area(radius) , 3)}")
print(area[0], area[1]) #, cir)

# a , c = circle_area(radius)
# print(a, c)
