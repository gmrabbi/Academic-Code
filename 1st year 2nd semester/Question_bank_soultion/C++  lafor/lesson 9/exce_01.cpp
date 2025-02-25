#include <bits/stdc++.h>
using namespace std;

class publication
{
protected:
    string title;
    float price;
public:
    publication(string s="", float p=0.0):title(s), price(p) { }
    void getdata()
    {
        cout<<"Title : ";cin>>title;
        cout<<"Price : ";cin>>price;
    }
    void putdata()
    {
        cout<<"Enter Title : "<<title<<endl;;
        cout<<"Enter Price : "<<price<<endl;
    }
};

class book:public publication
{
protected:
    int page;
public:
    book(string s="", float p=0.0, int pg=0):publication(s, p)
    {
        page = pg;
    }
    void getdata()
    {
        publication::getdata();
        cout<<"Total page : "; cin>>page;
    }
    void putdata()
    {
        publication::putdata();
        cout<<"Page : "<<page<<endl;
    }
};

class tape: public publication
{
private:
    float time;
public:
    tape(string s="", float p=0.0, float t=0.0):publication(s, p)
    {
        time =t;
    }
    void getdata()
    {
        publication::getdata();
        cout<<"Total time : ";cin>>time;
    }
    void putdata()
    {
        publication::putdata();
        cout<<"Time : "<<time<<endl;
    }
};

int main()
{
    publication pub;
    book bk;
    tape tp;

    pub.getdata();
    bk.getdata();
    tp.getdata();

    cout<<"==========="<<endl;
    pub.putdata();
    cout<<"==========="<<endl;
    bk.putdata();
    cout<<"==========="<<endl;
    tp.putdata();

    return 0;
}
