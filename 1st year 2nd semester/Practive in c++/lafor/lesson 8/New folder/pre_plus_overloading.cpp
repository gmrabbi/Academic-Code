#include <bits/stdc++.h>
using namespace std;

class Counter
{
private:
    int num;
public:
    Counter(int n = 0):num(n) { }

    void set_Data()
    {
        cout<<"Enter the value : "; cin>>num;
    }
    void Display()
    {
        cout<<"Number : "<<num<<endl;
    }
    Counter operator ++ () ;   //pre overloading; ++c1
    Counter operator ++(int) ; //post overloadin; c1++
    void operator += (Counter) ;    // += overloding , c1 += c2;
    bool operator == (Counter) ;   //return boolean value == operator
    bool operator <= (Counter) ;   //return boolean value <= operator
};
//pre overloading; ++c1
Counter Counter::operator++()
{
    return Counter(++num);
}
//post overloadin; c1++
Counter Counter::operator++(int)
{
    return Counter(num++);
}
// += overloding , c1 += c2;
void Counter::operator+=(Counter c1)
{
    num += c1.num;
    //return Counter(c1.num);
}
//return boolean value == operator
bool Counter::operator==(Counter c1)
{
    return (c1.num == num)?true : false;
}
//return boolean value <= operator
bool Counter::operator <= (Counter c1)
{
    return (c1.num <= num)? true: false;
}

int main()
{
    Counter c1, c2, c3;
    cout<<"c1"; c1.Display();
    cout<<"c2"; c2.Display();
    c1++;    // post operator overloding
    c2 = c1;
    ++c2;     // pre operator overloding
    cout<<"c1++ "; c1.Display();
    cout<<"++c2 "; c2.Display();
    c2 += c1;   //+= operator overloding
    c3 += c2;
    cout<<"c2 += c1\nc3 += c2 "; c3.Display();

    if(c1==c2)  //== operator overloading
        cout<<"c1 equal to c2"<<endl;
    else
        cout<<"c1 not equal to c2"<<endl;

    if(c1<= c2)  //<= operator overloading
        cout<<"c1 is gather then or equal to c2"<<endl;
    else
        cout<<"c1 is less then c2"<<endl;
    return 0;

}
