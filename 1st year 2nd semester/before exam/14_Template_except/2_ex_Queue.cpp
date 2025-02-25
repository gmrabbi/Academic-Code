#include <iostream>
#include <string>
#define Max 5

using namespace std;

template <class t>

class Queue
{
private:
    t arr[Max];
    int head;
    int tail;
public:
    Queue():head(-1),tail(-1) { }
    void put(t val)
    {
        arr[++tail] = val;
        if(tail >= Max-1)
            tail = -1;
        if(tail < -1)
        { cout<<"Full"<<endl; exit(1); }
    }
    t get()
    {
        return arr[++head];
        if(head >= Max -1)
            head = -1;
        if(head < -1)
        { cout<<"Empty"<<endl; exit(1); }
    }
};

int main()
{
    Queue<int> q;
    q.put(2);
    q.put(1);
    q.put(3);
    q.put(4);

    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;
    cout<<q.get()<<endl;

    return 0;
}
