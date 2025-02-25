#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    float inch;
public:
    Distance():feet(0),inch(0.0) { }
    Distance(int f, float i):feet(f),inch(i) { }
    void getdata()
    {
        cout<<"Feet : "; cin>>feet;
        cout<<"Inch : "; cin>>inch;
    }
    void Display()
    { cout<<feet<<"\' - "<<inch<<"\""<<endl;   }
};

int main()
{
    Distance dd[10];
    int cnt=0;
    char c;
    cout<<"Enter Distance : \n";
    do
    {
         dd[cnt].getdata();
         cnt++;
         cout<<"Do you  enter another Distance (y/n) :";cin>>c;
    }while(c != 'n');

    for(int i=0; i<cnt; i++)
        dd[i].Display();


    return 0;
}
