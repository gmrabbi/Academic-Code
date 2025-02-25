#include <iostream>

using namespace std;

class human
{
protected:
    int age;
public:
    human():age(0) { }
    human(int a):age(a) { }
    void Display()
    {  cout<<"you are "<<age<<" years old."<<endl;  }
    friend void secret(human)
    {  cout<<"Welcome ."<<endl;    }
};

class student: public human
{
private:
    int Roll;
public:
    student(int a):Roll(a) { }
    void show()
    { cout<<"Roll Number : "<<Roll<<endl;  }
};
int main()
{
    student st(10);
    st.Display();
    st.show();

    human hm(20);
    secret(hm);

//    st.secret(st);


    return 0;
}
