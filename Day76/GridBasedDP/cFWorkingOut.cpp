#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
const int NN =1005;

int boy_start[NN][NN];
int boy_end[NN][NN];
int girl_start[NN][NN];
int girl_end[NN][NN];
int calories[NN][NN];

int maxCalories(int M,int N){
    //max calories burnt by he boy going from
    //1,1 to i,j
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            boy_start[i][j]=calories[i][j] + max(boy_start[i-1][j],boy_start[i][j-1]);
        }
    }

    //for girl M,1 to i,j
    for(int i=M;i>=1;i--){
        for(int j=1;j<=N;j++){
            girl_start[i][j]=calories[i][j] + max(girl_start[i+1][j],girl_start[i][j-1]);
        }
    }

    //max calories burnt by he boy going from
    //M,N to i,j
    for(int i=M;i>=1;i--){
        for(int j=N;j>=1;j--){
            boy_end[i][j]=calories[i][j] + max(boy_end[i+1][j],boy_end[i][j+1]);
        }
    }

    //for girl starting from end 1,N to i,j
    for(int i=1;i<=M;i++){
        for(int j=N;j>=1;j--){
            girl_end[i][j]=calories[i][j] + max(girl_end[i-1][j],girl_end[i][j+1]);
        }
    }
    //iterating all the points assuming them as the meeting points

    int ans=0;
    for(int i=2;i<M;i++)
    {
        for(int j=2;j<N;j++){
            int ans1 = boy_start[i][j-1]+boy_end[i][j+1]+girl_start[i+1][j]+girl_end[i-1][j];
            int ans2 = boy_start[i-1][j]+boy_end[i+1][j]+girl_start[i][j-1]+girl_end[i][j+1];
            ans = max(ans,max(ans1,ans2));
        }
    }
    return ans;
}

int main(){
    memset(boy_start,0,sizeof boy_start);//for all the 4 arrays
    int M,N;
    cin>>M>>N;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++)cin>>calories[i][j];
    }
    cout<<maxCalories(M,N)<<endl;
    return 0;

}