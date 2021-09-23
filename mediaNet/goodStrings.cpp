   bool validate(int num, char value, int& newNum) {
    if(value == '1') {
        newNum = 0;
        return (num != 1);
    }
    if(value == '2'){
        if(num == 1)
        {
            newNum = 2;
            return true;
        }
        else if(num == 0)
        {
            newNum = 1;
            return true;
        }
      else{
        return false;
      }   
    }
}
   
string A,B; 
int n = A.size();
int dp[n][3][3];//initialised to 0


int solve(int s, int j, int k){
            
    char a = A[s];
    char b = B[s];
    
    int nextj,nextk;
    
    if(validate(j,a,nextj) && validate(k,b,nextk)){
               dp[s][nextj][nextk] += dp[s-1][j][k];
    }
    
          if(validate(j,b,nextj) && validate(k,a,nextk)){
          dp[s][nextj][nextk] += dp[s-1][j][k];
      }
    
}

int main(){
    //inputs
  
  for(int i=0;i<n;i++){
    for(int j=0;j<=2;j++){
      for(int k=0;k<=2;k++){
        solve(i,j,k);
      }
    }
  }
    
    cout<<dp[n-2][0][0]*2;
}