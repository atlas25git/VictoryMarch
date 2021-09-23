#include<bits/stdc++.h>
using namespace std;

class A{

    public:
    A()
    {
        cout<<"construct A"<<endl;
    }

    ~A()
    {
        cout<<"Destructor of A"<<endl;
    }
    virtual void show()
    {
        cout<<"in A"<<endl;
    }

};

class B: public A{

    public:


    B():A{} 
    {
        cout<<"construct B"<<endl;
    }

    ~B()
    {
        cout<<"Destructor of B"<<endl;
    }

    void show()
    {
        cout<<"in B"<<endl;
    }

};

int main()
{
    A* a = new B();
    a->show();
    delete a;
    return 0;
}