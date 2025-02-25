#include <bits/stdc++.h>

using namespace std;

vector<int> x;
int soln = 0;
bool Place(int k, int i)
{
    for(int j=0; j<=k-1; j++)
    {
        if((x[j] == i) || (abs(x[j]-i) == abs(j-k)))
        {
            return false;
        }
    }
    return true;
}

void NQueens(int k, int n)
{
    for(int i=0; i<=n; i++)
    {
        if(Place(k, i))
        {
            x[k]=i;
            if(k==n)
            {
                /*
                for(int z=0; z<=n; z++)
                {
                    cout<<x[z]+1<<" ";
                }
                cout<<endl;
                */
                soln++;
            }
            else
            {
                NQueens(k+1, n);
            }
        }
    }
}

int main()
{
    int n;

    for(n = 4; n<=20; n= n+2)
    {
        cout<<n<<endl;
        x.resize(n);

        auto Start = chrono::high_resolution_clock::now();
        NQueens(0, n-1);
        auto End = chrono::high_resolution_clock::now();

        chrono::duration<double, std::milli> duration = End - Start;
        cout<<"Total Time taken: "<<duration.count()<<" MilliSecond"<<endl;

        cout<<"Total solution: "<<soln<<endl<<endl;
    }

    return 0;
}
