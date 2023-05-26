class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[n+1][W+1]; // O(n x W)
       for(int i=0;i<n+1;i++){
           for(int j=0;j<W+1;j++){
               if(i == 0 || j == 0)
                    dp[i][j] = 0; // initialization check for empty store and full bag
           }
       }
        // O(n x W)   
       for(int i=1;i<n+1;i++){
           for(int j=1;j<W+1;j++){
               if(wt[i-1] <= j){
                   dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]); // Taking that one or not taking
               }
               else{
                   dp[i][j] = dp[i-1][j]; // bag is full so, we can't take anything
               }
           }
       }
       return dp[n][W]; // return the last element which is our answer
    }
};