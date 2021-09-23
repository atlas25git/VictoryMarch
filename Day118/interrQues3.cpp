#include<bits/stdc++.h>

using namespace std;

// class door{
    
//     private:
//     int noOfDoors;

//     public: 
//     door(){
//         noOfDoors = 4;
//     }

//     door(int x)
//     {
//         this->noOfDoors = x;
//     }

//     void getDoor(int x)
//     {
//         noOfDoors = x;
//         cout<<noOfDoors<<endl;
//     }
    
// };

// class cars{

//     int propA;
//     int propB;

//     door* A = new door(4);

//     public: 
//     cars()
//     {
//         propA = 1;
//         propB = 1;
//     }
//     virtual ~cars()
//     {
//         delete A;
//         cout<<"cleared A"<<endl;
//     }
//     void doorSet(int x)
//     {
//         A->getDoor(x);
//     }
    

// };


// class swift : public cars{

  

//     public:
    
//     swift(int swiftDoors ):cars{}
//     {
//         doorSet(swiftDoors);
//     }

//     ~cars()
//     {
//         cout<<"destructur of Swift"<<endl;
//     }

// };

void mirror(int** arr)
{
    for(int i=0;i<4;i++)
        {
            int k=0,j=4;
            while(k<=j)
            {
                swap(arr[i][k++],arr[i][j--]);
            }
        }
}



int main()
{
    // swift* x = new swift(4);

    // delete x;

    auto arr = new int*[4];

    for(int i=0;i<4;i++)
    {
        arr[i] = new int[5];
    }

    int c=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {       
            arr[i][j] = ++c;
        }        
    }

        

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"RotatedArray"<<endl;

    mirror(arr);

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<4;i++)
    {
        delete []arr[i];
    }

    delete []arr;
}