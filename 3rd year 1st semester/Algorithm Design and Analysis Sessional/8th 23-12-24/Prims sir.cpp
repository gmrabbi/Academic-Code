#include <bits/stdc++.h>
#define inf 10000
using namespace std;

const int n=6+1;
const int ROWS = 9+1;
const int COLS = 3+1;

int E[ROWS][COLS]={
    {0, 0,0,0},
    {0, 1,1,2},
    {0, 2,1,3},
    {0, 3,2,3},

    {0, 4,3,4},
    {0, 7,4,5},
    {0, 5,3,5},
    {0, 6,3,6},

    {0, 8,5,6}
};
int Cost[n][n]={
    {0, 0,0,0, 0,0,0},

    {0, 0,1,2, 0,0,0},
    {0, 1,0,3, 0,0,0},
    {0, 2,3,0, 4,5,6},

    {0, 0,0,4, 0,7,0},
    {0, 0,0,5, 7,0,8},
    {0, 0,0,6, 0,8,0},
};
int t[n][3];
int near[n];

int Prims()
{
    int minCost=100;
    int index=0;
    int k=0;
    int l=0;

    for(int i=1;i<n;i++)
    {
       if(E[i][1]<minCost)
       {
         index=i;
         minCost=E[i][1];
       }
    }

    k=E[index][2];
    l=E[index][3];

    minCost=Cost[k][l];

    t[1][1]=k; t[1][2]=l;

    for(int i=1;i<n;i++)
    {
       if(Cost[i][l]<Cost[i][k])
         near[i]=l;
       else
         near[i]=k;
    }
    near[k]=0;near[l]=0;

    int j=0;

    for(int i=2;i<n-1;i++)
    {
        int mm=100;
       for(int m=1;m<n;m++)
       {
           if(near[m]!=0)
           {

               if(Cost[m][near[m]]<mm)
               {
                  mm=Cost[m][near[m]];
                  j=m;
               }
           }
       }
        t[i][1]=j;
        t[i][2]=near[j];
        minCost=minCost+Cost[j][near[j]];
        near[j]=0;

        for(int k=1;k<n;k++)
        {

            if((near[k]!=0) && (Cost[k][near[k]]>Cost[k][j]))
                near[k]=j;
        }

    }
    return minCost;
}

int main()
{
    auto Start = chrono::high_resolution_clock::now();
    cout<<"Total Cost: "<<Prims()<<endl;
    auto End = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = End - Start;

    cout<<"Total Duration: "<<duration.count()<<" ms"<<endl;
    return 0;
}

/*
edge
    {0,0,0,0},
    {0,5,1,2},
    {0,7,2,3},
    {0,2,3,4},
    {0,4,4,5},
    {0,3,1,5},
    {0,1,3,5},
    {0,2,2,4}
*/


/*
Cost
{0,0,0,0,0,0},
{0,1000,5,1000,1000,3},
{0,5,1000,7,2,1000},
{0,1000,7,1000,2,1},
{0,1000,2,2,1000,4},
{0,3,1000,1,4,1000}
*/



