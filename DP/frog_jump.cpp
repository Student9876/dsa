#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,m,n) for(ll i=m;i<n;i++)
#define fi(i,m,n) for(ll i=m;i>=n;i--)
#define fa(i,j) for(auto i:j)
#define nl cout<<endl;
#define ump(a,b) unordered_map<a,b>
#define omp(a,b) map<a,b>
const int MOD = 1e9+7;
ll power(ll x, ll y){ll res = 1;while(y>0){if(y&1) res = (res*x);y = y>>1;x = (x*x);}return res;}

class TreeNode{
    public:
        int val;
        TreeNode * left;
        TreeNode * right;
        TreeNode():val(0),left(nullptr),right(nullptr){}
        TreeNode(int val):val(val),left(nullptr),right(nullptr){}
        TreeNode(int val, TreeNode * left, TreeNode * right):val(val),left(left), right(right){}
} typedef TN;


/*
    https://www.naukri.com/code360/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&count=25&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM

*/



// Recursion  
int frogJump(int n, vector<int> &heights)
{
    if(n==1) return 0;
    int c1 = frogJump(n-1, heights) + abs(heights[n-1] - heights[n-2]);
    int c2 = INT_MAX;
    if(n-1 > 1)
        c2 = frogJump(n-2, heights) + abs(heights[n-1] - heights[n-3]);
    return min(c1, c2);
}

// Memoization 
int helper(int n, vector<int> &heights, vector<int> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int c2 = INT_MAX;
    int c1 = helper(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    if(n > 1){
       c2 = helper(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
    }
    
   return dp[n] = min(c1, c2);
}
int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, -1);
    dp[n-1] = helper(n-1, heights, dp);
    return dp[n-1];
}

// Tabulation 
int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);
    for(int i = 2;i<n;i++){
        int c1 = abs(heights[i] - heights[i-1]) + dp[i-1];
        int c2 = abs(heights[i] - heights[i-2]) + dp[i-2];
        dp[i] = min(c1, c2);
    }
    return dp[n-1];
}

// Space optimised 
int frogJump(int n, vector<int> &heights){
    int x1 = 0;
    int x2 = abs(heights[0] - heights[1]);
    int x3;
    for(int i = 2;i<n;i++){
        int c1 = abs(heights[i] - heights[i-1]) + x2;
        int c2 = abs(heights[i] - heights[i-2]) + x1;
        x1 = x2;
        x2 = min(c1, c2);
    }
    return x2;
}


int main(){

    return 0;
}