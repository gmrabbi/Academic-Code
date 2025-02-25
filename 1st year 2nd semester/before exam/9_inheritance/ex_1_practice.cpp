#include <iostream>
using namespace std;

class publiction
{
protected:
    string title;
    float price;
public:
    void getdata()
    {
        cout<<"Title : "; cin>>title;
        cout<<"Price : "; cin>>price;
    }
    void putdata()
    {
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
    }
};

class book: public publiction
{
protected:
    int cnt;
public:
    void getdata()
    {
        publiction::getdata();
        cout<<"Page : "; cin>>cnt;
    }
    void putdata()
    {
        publiction::putdata();
        cout<<"Total Page : "<<cnt<<endl;
    }
};

class tape:public publiction
{
protected:
    float Time;
public:
    void getdata()
    {
        publiction::getdata();
        cout<<"Time : "; cin>>Time;
    }
    void putdata()
    {
        publiction::putdata();
        cout<<"Total Time : "<<Time<<endl;
    }
};



int main()
{
    tape t;
    book b;
    b.getdata();
    b.putdata();

    cout<<endl;
    t.getdata();
    t.putdata();

    return 0;
}






