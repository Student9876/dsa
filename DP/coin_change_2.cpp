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
    https://leetcode.com/problems/coin-change-ii/description/
*/

// Memoization 
// int helper(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
//     if(i == 0){
//         if(amount%coins[0]) return 0;
//         else return 1;
//     }
//     if(dp[i][amount] != -1) return dp[i][amount];
//     int notTake = helper(i-1, amount, coins, dp);
//     int take = 0;
//     if(amount >= coins[i])
//         take = helper(i, amount - coins[i], coins, dp);
//     return dp[i][amount] = notTake + take;
// }
// int change(int amount, vector<int>& coins) {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//     int ans = helper(n-1, amount, coins, dp);
//     return ans;
// }

// Tabulation 
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0)); 
    for(int j = 0;j<=amount;j++){
        if(j%coins[0] == 0) dp[0][j] = 1;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=amount;j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(j >= coins[i])
                take = dp[i][j - coins[i]];
            dp[i][j] = (notTake + take);
        }
    }
    return dp[n-1][amount];
}


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}