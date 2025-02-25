#include <bits/stdc++.h>
using namespace std;

void aFunc(int& a, const int& b); //declaration
int main()
{
int alpha = 7;
int beta = 11;
aFunc(alpha, beta);
return 0;
}
//--------------------------------------------------------------
void aFunc(int& a, const int& b) //definition
{
a = 107; //OK
b = 111; //error: can’t modify constant argument
}
