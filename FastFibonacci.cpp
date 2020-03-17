 /*
 If you use the standard way of finding fibonacci [i.e, O(n) method] : it will result in TLE : if the value of n is very large.
 For this, you can check out the following method which calculates the nth fibonacci number in log(n) time.
 If you are wondering how we could find the fibonacci matrix, refer to this video : 
 https://www.youtube.com/watch?v=iVNoIwY0UV8
 */
 
 
 void multiply(vector<vector<int>>&a,vector<vector<int>>&b)
    {
        vector<vector<int>>temp(2,vector<int>(2));
        temp[0][0]= a[0][0]*b[0][0] + a[0][1]*b[1][0];
        temp[0][1]= a[0][0]*b[0][1] + a[0][1]*b[1][1];        
        temp[1][0]= a[1][0]*b[0][0] + a[1][1]*b[1][0];
        temp[1][1]= a[1][0]*b[0][1] + a[1][1]*b[1][1];
        a=temp;
    }
    
    int fib(int N) {
        if(N==0)return 0;
        if(N<3)return 1;
        vector<vector<int>>ans(2,vector<int>(2)); 
        ans[0][0]=1;ans[0][1]=1;ans[1][0]=1;ans[1][1]=0;
        N-=2;
        vector<vector<int>>temp(ans);
        while(N>0)
        {
            if(N&1) multiply(ans,temp);
            N=N>>1;
            multiply(temp,temp);
        }
        return ans[0][0];
    }
    
    int main(){
      int N;
      cin>>N;
      cout<<fib(N)<<endl;
    }
