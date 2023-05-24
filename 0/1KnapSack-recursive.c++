class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       //recursive approach
       if(n==0||W==0) return 0;             //base condition == smallest valid input
       
       if(wt[n-1]<=W){                      //if the item can be stored
           return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),  //if the item is stored
                      knapSack(W,wt,val,n-1));                  //if the item is not stored
       }
       else if(wt[n-1]>W){                  // if the item can't be stored
           return knapSack(W,wt,val,n-1);
       }
    }
};