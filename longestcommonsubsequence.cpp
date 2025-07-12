#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
int MOD=1e9+7;
int helperR(string &x,string &y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(x[n-1]==y[m-1]){
        return 1+helperR(x,y,n-1,m-1);
    }
    else{
        return max(helperR(x,y,n-1,m),helperR(x,y,n,m-1));
    }
}
int helper(string &x,string &y,int n,int m,vector<vector<int>> &dp){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(x[n-1]==y[m-1]){
        return dp[n][m]=1+helper(x,y,n-1,m-1,dp);
    }
    else{
        return dp[n][m]=max(helper(x,y,n-1,m,dp),helper(x,y,n,m-1,dp));
    }
}
string printLCS(string &x,string &y){
    int n=x.length(),m=y.length();
    vector<vector<string>> dp(n+1,vector<string>(m+1,""));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+x[i-1];
            }
            else{
                if(dp[i-1][j].length()>dp[i][j-1].length()){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    return dp[n][m];
}
/*
Longest Common Subsequence
Longest Common Substring
Print LCS
Shortest Common Supersequence
Print SCS
Min number of insertion and deletion from string a --> string b
Longest Repeating Subsequence
Length of Longest Subsequnce of a which is substring in b
Subsequence Pattern Matching
Count how many times a appears as subsequnce in b
Longest Palindromic Subsequence
Longest Palindromic Substring
Count of Palindromic Substring
Min number of deletion in a string to make it palindromic
Min number of insertion in a string to make it palindromic
*/
int main(){
    fastio();
    string x="abcdgh",y="abedfhr";
    int n=x.length(),m=y.length();
    // cout<<helperR(x,y,n,m)<<endl;
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // cout<<helper(x,y,n,m,dp)<<endl;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    string ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    cout<<printLCS(x,y)<<endl;
    return 0;
}