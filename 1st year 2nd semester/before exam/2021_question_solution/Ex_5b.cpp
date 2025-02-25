#include <iostream>
#define Max 2

using namespace std;

class Family
{
private:
    float Size[Max];
    string name[Max];
    float age[Max];
public:
    Family()
    {
        cout<<"Enter Data \n"<<endl;
        for(int i=0; i<Max ; i++)
        {
            cout<<"Name : "; cin>>name[i];
            cout<<"Age : "; cin>>age[i];
            cout<<"Size : "; cin>>Size[i];
            cout<<endl;
        }
    }

    void display()
    {
        cout<<"============================="<<endl;
        for(int i=0; i<Max ; i++)
        {
            cout<<"Name : "<<name[i]<<endl;
            cout<<"Age : "<<age[i]<<endl;
            cout<<"Size : "<<Size[i]<<endl;
            cout<<endl;
        }
        cout<<"============================="<<endl;
    }
    void avg()
    {
        float a;
        for(int i=0; i<Max; i++)
        { a += age[i]; }
        cout<<"Average "<<a/Max<<endl;
    }
    void eldest(Family, Family);
    void youngest(Family , Family);
};
void Family::eldest(Family f1 , Family f2)
{
    cout<<"The oldest : "<<endl;
    float mx_f1=0.0, mx_f2=0.0 ;
    for(int i=0; i<Max; i++)
    {
        if(f1.age[i] > mx_f1)
            mx_f1 = f1.age[i];
        if(f2.age[i] > mx_f2)
            mx_f2 = f2.age[i];
    }
    //cout<<mx_f1<<"----------"<<mx_f2<<endl;
    if(mx_f1 > mx_f2)
    {

        cout<<"f1 "<<endl;
        for(int i=0; i<Max; i++)
        {
            if(mx_f1 == f1.age[i])
            {
                cout<<"Name : "<<f1.name[i]<<endl;
                cout<<"Age : "<<f1.age[i]<<endl;
                cout<<"Size : "<<f1.Size[i]<<endl;
            }
        }
    }

    if(mx_f2 > mx_f1)
    {
        cout<<"f2 "<<endl;
        for(int i=0; i<Max; i++)
        {
            if(mx_f2 == f2.age[i])
            {
                cout<<"Name : "<<f2.name[i]<<endl;
                cout<<"Age : "<<f2.age[i]<<endl;
                cout<<"Size : "<<f2.Size[i]<<endl;
            }
        }
    }
}


int main()
{
    Family fm;
    //fm.display();
    //fm.avg();

    Family fm1;
    fm.eldest(fm , fm1);

    return 0;
}
