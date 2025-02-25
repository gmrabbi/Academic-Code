#include <iostream>
using namespace std;

class Bita;

class Alph
{
private :
    int data ;
public :
    Alph(int d=0) : data(d) { }
    friend int FunOperation(Alph, Bita);
};

class Bita
{
private:
    int data;
public:
    Bita(int d=0):data(d) { }
    friend int FunOperation(Alph , Bita);
};

int FunOperation(Alph a , Bita b)
{
    return (a.data + b.data);
}

int main()
{
    Alph aa=5;
    Bita bb(10);

    cout<<FunOperation(aa, bb)<<endl;
}
