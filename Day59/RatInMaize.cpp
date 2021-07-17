// //all possible paths from source to destination
#include<bits/stdc++.h>
using namespace std;

int cnt =0;
bool safe(int a,int b, int n, char maze[10][10])
{
    if (a >=0 && a <= n && b >= 0 && b <= n && maze[a][b] != 'X')
        return true;
    return false;

}

bool ratInMaze(char maze[10][10],int (soln)[10][10], int i,int j, int m, int n){
    
   

    if(i==m && j==n){
        soln[m][n]=1;
        return true;
    }

    if(safe(i,j,m,maze))
    {
    //assuming soln exists through the curr maize
    //if(soln[i][j])return false;
    soln[i][j]=1;
    if(ratInMaze(maze,soln,i,j+1,m,n))return true;
    if(ratInMaze(maze,soln,i+1,j,m,n))return true;
    soln[i][j] = 0;
    return false;
    }
    return false;
}


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","1",stdout);

    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0x00",
    };
    int soln[10][10] = {0};

    bool exist = ratInMaze(maze,soln,0,0,3,3);
    if(exist)
    {
        for(int i=0;i<4;i++)
            {for(int j=0;j<4;j++)
                {cout<<soln[i][j]<<" ";}
            cout<<"\n";
            }
    }
    if(!exist)cout<<"Path doesn't exist";
}

