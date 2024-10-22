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
    https://leetcode.com/problems/coin-change/description/
*/

// Memoization 
// int helper(int i, int amount, vector<int>& coins, vector<vector<int>> &dp){
//     if(amount == 0) return 0;
//     if(i == 0){
//         if(amount == coins[i])  return 1;
//         else {
//             if(amount%coins[i] != 0) return 1e9;
//             else return amount/coins[i];
//         }
//     }
//     if(dp[i][amount] != -1) return dp[i][amount];
//     int notTake = helper(i-1, amount, coins, dp);
//     int take = 1e9;
//     if(amount >= coins[i])
//         take = 1 + helper(i, amount - coins[i], coins, dp);
//     return dp[i][amount] = min(take, notTake);
// }
// int coinChange(vector<int>& coins, int amount) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount+1, -1));
//     int ans = helper(n-1, amount, coins, dp);
//     if(ans == 1e9) return -1;
//     return ans;
// }

// Tabulation 
// int coinChange(vector<int>& coins, int amount) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount+1, 0));
//     for(int j = 0;j <= amount;j++){
//         if(j == coins[0]) dp[0][j] = 1;
//         else {
//             if(j%coins[0] != 0) dp[0][j] = 1e9;
//             else dp[0][j] = j/coins[0];
//         }
//     }
//     for(int i = 1;i<n;i++){
//         for(int j = 1;j<=amount;j++){
//             int notTake = dp[i-1][j];
//             int take = 1e9;
//             if(j >= coins[i])
//                 take = 1 + dp[i][j - coins[i]];
//             dp[i][j] = min(take, notTake);
//         }
//     }
//     if(dp[n-1][amount] == 1e9) return -1;
//     return dp[n-1][amount];
// }

// Space optimized tabulation
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
    for(int j = 0;j <= amount;j++){
        if(j == coins[0]) prev[j] = 1;
        else {
            if(j%coins[0] != 0) prev[j] = 1e9;
            else prev[j] = j/coins[0];
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=amount;j++){
            int notTake = prev[j];
            int take = 1e9;
            if(j >= coins[i])
                take = 1 + cur[j - coins[i]];
            cur[j] = min(take, notTake);
        }
        prev = cur;
    }
    if(prev[amount] == 1e9) return -1;
    return prev[amount];
}


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}