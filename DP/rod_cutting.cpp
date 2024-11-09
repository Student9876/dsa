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
// int helper(int i, int len, int price[], vector<vector<int>> &dp){
//     if(i == 0){
//         if(len >= 1) return price[0] + helper(i, len - (1), price, dp);
//         else return 0;
//     }
//     if(dp[i][len] != -1) return dp[i][len];
//     int notTake = helper(i-1, len, price, dp);
//     int take = 0;
//     if(len >= i + 1){
//         take = price[i] + helper(i, len - (i + 1), price, dp);
//     }
//     return dp[i][len] = max(notTake, take);
// }
// int cutRod(int price[], int n) {
//     vector<vector<int>> dp(n, vector<int> (n+1, -1));
//     return helper(n-1, n, price, dp);
// }

// Tabulation 
int cutRod(int price[], int n){
    vector<vector<int>> dp(n, vector<int> (n+1, 0));
    for(int j = 1;j<=n;j++){
        dp[0][j] = price[0] + dp[0][j-1];
    }
    for(int i = 1; i<n;i++){
        for(int j = 0;j <= n;j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(j >= i + 1){
                take = price[i] + dp[i][j - (i + 1)];
            }
            dp[i][j] = max(notTake, take);
        }
    }
    return dp[n-1][n];
}
// Space optimised 
int cutRod(int price[], int n){
    vector<int> prev(n+1, 0), cur(n+1, 0);
    for(int j = 1;j<=n;j++){
        prev[j] = price[0] + prev[j-1];
    }
    for(int i = 1; i<n;i++){
        for(int j = 0;j <= n;j++){
            int notTake = prev[j];
            int take = 0;
            if(j >= i + 1){
                take = price[i] + cur[j - (i + 1)];
            }
            cur[j] = max(notTake, take);
        }
        prev = cur;
    }
    return prev[n];
}



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}