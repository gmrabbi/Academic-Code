
#include <bits/stdc++.h>
using namespace std;

class part
{
private :
    int modelNumber;
    int partNumber;
    float cost;
public:
    void setData(int mn, int pn , float c)
    {
        modelNumber = mn;
        partNumber = pn;
        cost = c;
    }
    void showData()
    {
        cout<<"Model Number : "<< modelNumber<<endl;
        cout<<"Part Number : "<< partNumber<<endl;
        cout<<"Cost $ "<< cost<<endl;
    }
};

int main()
{
    part obj;
    obj.setData(34, 23 , 45.75f);
    obj.showData();
    return 0;
}


////////////////////////////////////////////////////////////////
/*
// objpart.cpp
// widget part as an object
#include <iostream>
using namespace std;

class part //define class
{
private:
int modelnumber; //ID number of widget
int partnumber; //ID number of widget part
float cost; //cost of part
public:
void setpart(int mn, int pn, float c) //set data
{

modelnumber = mn;
partnumber = pn;
cost = c;
}
void showpart() //display data
{
cout << "Model  "<< modelnumber;
cout << ", part " << partnumber;
cout << ", costs $" << cost << endl;
}
};
////////////////////////////////////////////////////////////////
int main()
{
part part1; //define object
// of class part
part1.setpart(6244, 373, 217.55F); //call member function
part1.showpart(); //call member function
return 0;
}
*/
