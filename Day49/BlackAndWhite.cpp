//Function to find out the number of ways we can place a black and a white 
//Knight on this chessboard such that they cannot attack each other.
long long solve(int n, int m) 
{
    //specifying the directions to check in i.e 8 directions.
    static int x_off[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    static int y_off[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    static const long long MOD = (long long)1e9 + 7;

    //using variable to maintain number of positions which are not feasible.
    long long ret = 0;
    int x, y;

    //iterating for complete matrix.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) 
        {
            for (int k = 0; k < 8; ++k)
            {
                x = i + x_off[k];
                y = j + y_off[k];
                //checking if the attack position is within bounds.
                if (x >= 0 && x < n && y >= 0 && y < m)
                    //if in bounds then it is not feasible so we increment.
                    ++ret; 
            }
        }
    }
    long long total = n * m;
    
    //total possible combinations of 2 knights.
    total =(total * (total - 1)) % MOD; 
    
    // returning total feasible combinations.
    return (total + MOD - ret) % MOD; 
}