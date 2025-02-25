#include <bits/stdc++.h>
#define Max 10

using namespace std;

class Family
{
private:
    int Size;
    char names[Max];
    int ages[Max];
public:
    Family()
    {
        cout<<"Enter member size : "; cin>>Size;
        for(int i=0; i<Size; i++)
        {
            cout<<"Enter Name : "; cin>>names[i];
            cout<<"Enter Age : "; cin>>ages[i];
        }
    }
    float avg()
    {
        float sum =0.0;
        for(int i=0; i<Size; i++)
        {  sum += ages[i]; }
        return sum/Size;
    }
    void display()
    {
        cout<<"The average age of the family : "<<avg()<<endl;
        cout<<"Name   ->  Age"<<endl;
        for(int i=0; i<Size ; i++)
        {
            cout<<names[i]<<" -> "<<ages[i]<<endl;
        }
    }
    float eldest(Family f1 , Family f2)
    {
        int max1 = f1.ages[0], max2 = f2.ages[0];
        for(int i=0; i<Size ; i++)
        {
            if(max1 < f1.ages[i])
            {
                max1 = f1.ages[i];
            }
            if(max2 < f2.ages[i])
            {
                max2 = f2.ages[i];
            }
        }
        return (max1>max2?max1:max2);
    }

    float youngest(Family f1 , Family f2)
    {
        int min1 = f1.ages[0], min2 = f2.ages[0];
        for(int i=0; i<Size ; i++)
        {
            if(min1 > f1.ages[i])
            {
                min1 = f1.ages[i];
            }
            if(min2 > f2.ages[i])
            {
                min2 = f2.ages[i];
            }
        }
        return (min1<min2?min1:min2);
    }
};

int main()
{
    Family f1 , f2;
    f1.display();
    f2.display();
    cout<<"Eldest age : "<<f1.eldest(f1 , f2)<<endl;
    cout<<"Youngest age : "<<f1.youngest(f1 , f2)<<endl;
    return 0;
}
