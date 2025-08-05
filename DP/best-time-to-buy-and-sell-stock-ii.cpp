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
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

// Memoization 
int helper(int i, int prevBought, vector<int> &prices, vector<vector<int>> &dp){
    if(i < 0) return 0;
    int idx = (prevBought == -1)? 0: prevBought + 1;
    if(dp[i][idx] != -1) return dp[i][idx];
    if(prevBought != -1){
        int currProfit = prevBought - prices[i];
        return dp[i][idx] = max(currProfit + helper(i-1, -1, prices, dp), 
            helper(i-1, prevBought, prices, dp));
    } else {
        return dp[i][idx] = max(helper(i-1, prices[i], prices, dp), helper(i-1, -1, prices, dp));
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int mx = *max_element(prices.begin(), prices.end());
    vector<vector<int>> dp(n, vector<int>(mx + 2, -1));
    return helper(n-1, -1, prices, dp);
}

// Tabulation

int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}