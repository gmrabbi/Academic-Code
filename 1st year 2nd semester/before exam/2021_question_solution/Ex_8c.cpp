#include <iostream>

using namespace std;

class Mammals
{
public:
    void Display()
    { cout<<"I am mammal"<<endl; }
};

class MarineAnimals
{
public:
    void Display()
    {  cout<<"I am a marine animal"<<endl;  }
};

class BlueWhale: public Mammals, public MarineAnimals
{
public:
    void Display()
    {  cout<<"I belong to both the categories: Mammals as well as Marine Animals."<<endl; }
};

int main()
{
    Mammals mm;
    MarineAnimals ma;
    BlueWhale bw;

    mm.Display();
    ma.Display();
    bw.Display();

    bw.Mammals::Display();
    bw.MarineAnimals::Display();

    return 0;
}
