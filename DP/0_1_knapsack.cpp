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

int countSetBits(int u){unsigned int uCount;uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);return ((uCount + (uCount >> 3)) & 030707070707) % 63;}

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
    https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/


// Memoization 
// int helper(int i, int W, vector<int> &weight, vector<int> &value,
//     vector<vector<int>> &dp){
//     if(i == 0) {
//     	if(weight[i] <= W) return value[i];
//     	else return 0;
//     }
//     if(dp[i][W] != -1) return dp[i][W];
//     int notTake = helper(i-1, W, weight, value, dp);
//     int take = 0;
//     if(weight[i] <= W)
//     	take = value[i] + helper(i-1, W-weight[i], weight, value, dp);
//     return dp[i][W] = max(take, notTake);
// }
// int knapSack(int W, vector<int>& wt, vector<int>& val) {
//     int n = wt.size();
//     vector<vector<int>> dp(n, vector<int>(W + 1, -1));
// 	return helper(n-1, W, wt, val, dp);
// }

// Tabulation 
// int knapSack(int W, vector<int>& wt, vector<int>& val) {
//     int n = wt.size();
//     vector<vector<int>> dp(n, vector<int>(W + 1, 0));
//     for(int j = 0;j<=W;j++){
//         if(wt[0] <= j) dp[0][j] = val[0];
//     }
//     for(int i = 1;i<n;i++){
//         for(int j = 1;j<=W;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(wt[i] <= j)
//             	take = val[i] + dp[i-1][j-wt[i]];
//             dp[i][j] = max(take, notTake);
//         }
//     }
//     return dp[n-1][W];
// }

// Space optimized tabulation 
int knapSack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<int> prev(W + 1, 0), cur(W + 1, 0);
    for(int j = 0;j<=W;j++){
        if(wt[0] <= j) prev[j] = val[0];
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=W;j++){
            int notTake = prev[j];
            int take = 0;
            if(wt[i] <= j)
            	take = val[i] + prev[j-wt[i]];
            cur[j] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[W];
}

int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}