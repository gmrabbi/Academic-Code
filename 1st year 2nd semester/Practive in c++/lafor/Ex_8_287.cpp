/*#include <bits/stdc++.h>

using namespace std;

class Counter
{
private:
    static int cnt ;
public:
    Counter()
        { cout<<"This is object number "<<cnt++<<endl;}

};

int Counter::cnt=0;
   // cnt++;

int main()
{
    Counter c1, c2;

    return 0;
}
*/
#include <iostream>
using namespace std;

class SerialNumberedObject {
private:
    static int count; // class-level variable to keep track of how many objects have been created
    int serial_number; // data member that holds the serial number for each object

public:
    SerialNumberedObject() {
        count++; // increment count for each new object
        serial_number = count; // assign serial number based on count
    }

    string get_serial_number() {
        return "I am object number " + to_string(serial_number);
    }
};

int SerialNumberedObject::count = 0; // initialize class-level variable to 0

int main() {
    SerialNumberedObject obj1, obj2, obj3;
    cout << obj1.get_serial_number() << endl; // should print "I am object number 1"
    cout << obj2.get_serial_number() << endl; // should print "I am object number 2"
    cout << obj3.get_serial_number() << endl; // should print "I am object number 3"
    return 0;
}
