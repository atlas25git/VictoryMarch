class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        int a = 0,b = 1,c = 1;
        n-=2;
        while(n-->0)
        {
            int s = a + b + c;
            a=b;
            b=c;
            c=s;
        }
        return c;
    }
};