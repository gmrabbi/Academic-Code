#include <iostream>

using namespace std;

class triangle
{
private:
    int width;
    int height;
public:
    triangle():width(0), height(0) { }
    triangle(int w, int h):width(w), height(h) { }
    void inserter()
    {
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<i+1; j++)
                cout<<"*";
            cout<<endl;
        }

    }
};

int main()
{
    triangle tr(5,5);
    tr.inserter();

    return 0;
}
