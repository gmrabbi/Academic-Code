#include <bits/stdc++.h>

using namespace std;

vector<int> w;
vector<int> x;
int solution = 0;
int m=0;

void SumofSub(int s, int k, int r)
{
    x[k] = 1;
    if(s+w[k] == m)
    {
        solution++;

        /*
        for(int z=0; z<=k; z++)
        {
            if(x[z])
                cout<<w[z]<<" ";
        }
        cout<<endl;
        */
    }
    else if(s+w[k]+w[k+1] <= m)
    {
        SumofSub(s+w[k], k+1, r-w[k]);
    }
    if((s+r-w[k] >=m) && (s+w[k+1] <= m))
    {
        x[k] = 0;
        SumofSub(s,k+1, r-w[k]);
    }

}

int main()
{

    ifstream infile("number.txt");
    int num;
    int t=0;
    while(infile>>num)
    {
        //cout<<num<<endl;
        w.push_back(num);
        t++;
    }
    /*
    w.resize(5);
    w.push_back(5);
    w.push_back(7);
    w.push_back(15);
    w.push_back(12);
    w.push_back(13);
    */

    for(int z = 0; z<=2; z++)
        m+= w[z];
        //cout<<w[z]<<" ";
    // cout<<m<<endl;
    x.resize(w.size());

    int r=0;
    for(int z = 0; z<w.size(); z++)
        r+= w[z];
    // cout<<r<<endl;
    auto Start = chrono::high_resolution_clock::now();
    SumofSub(0,0,r);
    auto End = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> duration = End - Start;

    cout<<"Total Number : "<<t<<endl;
    cout<<"Total Time taken: "<<duration.count()<<" MilliSecond"<<endl;

    cout<<"Total solution: "<<solution<<endl;


    return 0;
}


