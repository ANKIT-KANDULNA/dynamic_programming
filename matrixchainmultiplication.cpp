#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
const int MOD=1e9+7;
const long long INF=1e18+7;
/*
ANKIT KANDULNA
*/
int helperR(vector<int> &arr,int i,int j){
    if(i>=j){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=helperR(arr,i,k)+helperR(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        ans=min(ans,temp);
    }
    return ans;
}
int helper(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=helper(arr,i,k,dp)+helper(arr,k+1,j,dp)+(arr[i-1]*arr[k]*arr[j]);
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}
/*
MCM
Printing MCM
Palindrome Partitioning
Evaluate Expression to true/Boolean Parenthesiszation
Min/Max value of an expression
Scramble String
Egg Dropping Problem
*/
int main(){
    fastio();
    vector<int> arr={40,20,30,10,30};
    int n=arr.size();
    //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //cout<<helperR(arr,1,n-1)<<endl;
    //cout<<helper(arr,1,n-1,dp)<<endl;
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int temp=INT_MAX;
            for(int k=i;k<j;k++){
                int temp1=dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
                temp=min(temp,temp1);
            }
            dp[i][j]=temp;
        }
    }
    cout<<dp[1][n-1]<<endl;
    return 0;
}