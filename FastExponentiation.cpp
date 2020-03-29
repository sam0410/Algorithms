/*
The time complexity of usual exponentiation is O(n), whereas the complexity of the following function is 0(logn).
*/

long long fastExponentiation(long long x, int n)
{
    bool flag=0; if(x<0 && (n&1))flag=1;
    x= abs(x);
    long long ans=1;
    while(n>0)
    {
        if(n&1)
            ans*=x;
        x*=x;
        n= n>>1;
    }
    if(flag) ans*=-1;
    return ans;
}
