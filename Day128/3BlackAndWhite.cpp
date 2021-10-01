long long numOfWays(int N, int M)
{   
    int m = 1e9+7;
    //here our approach is to do a complete board search
    //and for particular i,j we got to calculate all the spots reachablef from
    //this via knight's move.
    //And then we substract these from the total ones. 
    //that is for knight 1, n*m knight2 once 1 has been placed then n*m*(n*m - 1)
    
    //direction co-ordinates;
    int x[] = {1,1,2,2,-2,-2,-1,-1};
    int y[] = {2,-2,1,-1,1,-1,2,-2};
    int count=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            for(int k=0;k<8;k++)
                {
                    int xc = i + x[k];
                    int yc = j + y[k];
                    
                    if(xc<N && yc<M && xc>=0 && yc>=0)
                        count++;        
                }
                
        long long total = N*M;
        total = (total*(total-1))%m;
        return (total + m -count)%m;
}