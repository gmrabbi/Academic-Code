#include <iostream>
using namespace std;

class Shape
{
protected :
    int height ;
    int weight ;
public:
    Shape(int w = 0 , int h = 0 ): weight(w), height(h) { }
    virtual int Area()
    {
        cout<<"Present Area : "<<endl;
        return 0;
    }

};

class Rectangle : public Shape
{
public :
    Rectangle(int w=0 ,int h=0) : Shape(w , h) { }
    int Area()
    {
        cout<<"Rectangle Area : "<<endl;;
        return (weight  * height) ;
    }
};

class Triangle : public Shape
{
public:
    Triangle(int w=0 , int h=0) : Shape(w , h) { }
    int Area()
    {
        cout<<"Triangle Area : "<<endl;
        return (weight*height)/2;
    }
};

int main()
{
    Shape *s;
//    s.Area();

    Rectangle rec(10 , 5);
    Triangle tri(10 , 7);

    s = &rec;
    cout << s ->Area()<<endl;;
    //cout << rec.Area();

    s = &tri;
    cout << s ->Area();

    return 0;
}
