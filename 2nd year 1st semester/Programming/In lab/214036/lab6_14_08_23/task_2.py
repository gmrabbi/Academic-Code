class Point:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __gt__(self, other):
        return self.age > other.age

    def Display(self, obj):
        if(self.age>obj.age):
            print(f"{self.name} is older than {obj.name}")
        else:
            print(f"{self.name} is younger than {obj.name}")


p1 = Point("Alica", 40)
p2 = Point("Bob", 30)

p1.Display(p2)


