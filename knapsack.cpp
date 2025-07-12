#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;

// recursion
int helperR(vector<int> &wt,vector<int> &val,int W,int i){
    //base condition: --> think of the smallest valid input
    // W=0 kg , size of array(n)=0
    int n=wt.size();
    if(i>=n || W==0){ // i can also take n as index; i=n and i-- and check n==0
        return 0;
    }
    int include=0;
    if(wt[i]<=W){
        include=val[i]+helperR(wt,val,W-wt[i],i+1);
    }
    int exclude=helperR(wt,val,W,i+1);
    return max(include,exclude);
}

// recursive+memoization
int memo(vector<int> &wt,vector<int> &val,int W,int i,vector<vector<int>> &dp){
    int n=wt.size();
    if(i>=n || W==0){
        return 0;
    }
    if(dp[i][W]!=-1){
        return dp[i][W];
    }
    int include=0;
    if(wt[i]<=W){
        include=val[i]+memo(wt,val,W-wt[i],i+1,dp);
    }
    int exclude=memo(wt,val,W,i+1,dp);
    return max(include,exclude);
}

// DP solution since in memoization it will lead to stack overflow
int knapsack(vector<int> &wt,vector<int> &val,int W){
    // return helperR(wt,val,W,0);
    // vector<vector<int>> dp(wt.size()+1,vector<int>(W+1,-1));
    // return memo(wt,val,W,0,dp);
    int n=wt.size();
    vector<vector<int>> dp(n+1,vector<int>(W+1));
    //base condtion from recurisive function 
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=W;i++){
        dp[0][i]=0;
    }
    // each cell in dp describes the subproblem for dp[i][j] of jth Weight
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
/*
Subset sum
Equal Sum partition
Count of Subsets with given sum
Subset sum with min difference
Count Subsets with given difference
Target Sum
*/

int main(){
    vector<int> wt={1,3,4,5};
    vector<int> val={1,4,5,7};
    int W=10;
    /*
    maximum profit nikalna h
    choices to include the weight or not 

    */
    vector<vector<int>> dp(wt.size()+1,vector<int>(W+1,-1));
    helperR(wt,val,W,0);
    memo(wt,val,W,0,dp);
    knapsack(wt,val,W);
    vector<int> arr={3,34,4,12,5,2};
    int sum=9;
    isSubsetSum(arr,sum);
    vector<int> nums={1,5,11,5};
    cout<<canPartition(nums)<<endl;
    return 0;
}