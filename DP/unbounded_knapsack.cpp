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

*/

// Memoization 
// int helper(int i, int W, int val[], int wt[], vector<vector<int>> &dp){
//     if(i == 0){
//         if(wt[0] <= W) return val[0] + helper(0, W - wt[0], val, wt, dp);
//         else return 0;
//     }
//     if(dp[i][W] != -1) return dp[i][W];
//     int notTake = helper(i-1, W, val, wt, dp);
//     int take = 0;
//     if(W >= wt[i])
//         take = val[i] + helper(i, W - wt[i], val, wt, dp);
//     return dp[i][W] = max(notTake, take);
// }
// int knapSack(int N, int W, int val[], int wt[]){
//     vector<vector<int>> dp(N, vector<int> (W+1, -1));
//     return helper(N-1, W, val, wt, dp);
// }

// Tabulation 
// int knapSack(int N, int W, int val[], int wt[]){
//     vector<vector<int>> dp(N, vector<int> (W+1, 0));
//     for(int j = 0;j <=W;j++){
//         dp[0][j] = (j/wt[0])* val[0];
//     }
//     for(int i = 1;i<N;i++){
//         for(int j = 0;j<=W;j++){
//             int notTake = dp[i-1][j];
//             int take = 0;
//             if(j >= wt[i])
//                 take = val[i] + dp[i][j - wt[i]];
//             dp[i][j] = max(notTake, take);
//         }
//     }
//     return dp[N-1][W];
// }

// Space optimised 
int knapSack(int N, int W, int val[], int wt[]){
    vector<int> cur(W+1, 0), prev(W+1, 0);
    for(int j = 0;j <=W;j++){
        prev[j] = (j/wt[0])* val[0];
    }
    for(int i = 1;i<N;i++){
        for(int j = 0;j<=W;j++){
            int notTake = prev[j];
            int take = 0;
            if(j >= wt[i])
                take = val[i] + cur[j - wt[i]];
            cur[j] = max(notTake, take);
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