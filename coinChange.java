

// User function Template for Java

class Solution {
    public long count(int S[], int m, int n) 
    {
        
        
       long dp[][]=new long[m+1][n+1];
       
       for(long []x:dp)
       {
           Arrays.fill(x,-1L);
       }
      return  helper(dp,S,m,n);
      
      
        
    }
    
    public long helper(long dp[][],int coin[],int m,int sum)
    {
        if(m==0)
        return 0L;
        if(sum==0)
        return dp[m][sum]=1L;
        if(dp[m][sum]!=-1L)
        return dp[m][sum];
        
        if(coin[m-1]<=sum)
        {
          return  dp[m][sum]=(long)helper(dp,coin,m,sum-coin[m-1])+(long)helper(dp,coin,m-1,sum);
        }
       else
       dp[m][sum]=helper(dp,coin,m-1,sum);
       
       return dp[m][sum];
    }
}
