class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       //memoization
       int t[n+1][W+1];
       memset(t,-1,sizeof(t));
       
       if(n==0||W==0) return 0;
       if(t[n][W]!=-1) return t[n][W];
       
       if(wt[n-1]<=W){
           return t[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),
                                knapSack(W,wt,val,n-1));;
       }
       
       else if(wt[n-1]>W){
           return t[n][W]=knapSack(W,wt,val,n-1);
       }
       
    }
};