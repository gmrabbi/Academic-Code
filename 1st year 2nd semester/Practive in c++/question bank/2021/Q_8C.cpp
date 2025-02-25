#include <bits/stdc++.h>
using namespace std;

class Mammals
{
public:
    void Display()
    {
        cout<<"I am mammal"<<endl;
    }
};

class MarineAnimals
{
public:
    void Display()
    {
        cout<<"I am a marine animal"<<endl;
    }
};

class BlueWhale: public Mammals, public MarineAnimals
{
public:
    void Display()
    {
        cout<<"I belong to both the categories: Mammals as well as Marine Animals"<<endl;
    }
};


int main()
{
    Mammals Mam;
    MarineAnimals MAn;
    BlueWhale Bw;

    Mam.Display();
    MAn.Display();
    Bw.Display();

    Bw.Mammals::Display();
    Bw.MarineAnimals::Display();


    return 0;
}
