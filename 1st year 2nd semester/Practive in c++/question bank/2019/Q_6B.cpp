/*
In C++, a copy constructor is a special constructor that is used to create a new object as a copy of an existing object of the same class. The copy constructor takes a reference to an object of the same class and creates a new object that is a copy of the original object.

The purpose of the copy constructor is to create a new object that is a copy of an existing object. This is useful when you want to create a new object that has the same values as an existing object, without having to manually copy all of the values.

The copy constructor differs from a normal constructor in that it takes an argument that is a reference to an object of the same class, whereas a normal constructor does not take any arguments or takes arguments of a different type.
*/
#include <iostream>
using namespace std;

class MyClass {
  int x;
public:
  MyClass(int val) : x(val) {}
  MyClass(const MyClass& obj) : x(obj.x) {}
  int getVal() { return x; }
};

int main() {
  MyClass obj1(10);
  MyClass obj2 = obj1; // Copy constructor called
  cout << obj1.getVal() << endl;
  cout << obj2.getVal() << endl;
  return 0;
}
