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
    https://leetcode.com/problems/distinct-subsequences/description/
*/

// Memoization 
int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(j == -1) return 1;
    if(i == -1) return 0;
    if(dp[i][j] !=-1 ) return dp[i][j];
    if(s[i] == t[j]){
        return dp[i][j] = helper(i-1, j-1, s, t, dp) + helper(i-1, j, s, t, dp);
    }
    return dp[i][j] = helper(i-1, j, s, t, dp);
}
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n-1, m-1, s, t, dp);
}

// Tabulation 
int numDistinct(string s, string t) {
    int MOD = 1e9 + 7;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1 , 0));
    for(int i = 0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    } 
    return dp[n][m];
}

// Space Optimised
int numDistinct(string s, string t) {
    int MOD = 1e9 + 7;
    int n = s.length();
    int m = t.length();
    vector<int> prev(m + 1 , 0);
    for(int i = 1;i<=n;i++){
        vector<int> cur(m + 1, 0);
        prev[0] = 1;
        for(int j = 1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                cur[j] = (prev[j-1] + prev[j])%MOD;
            } else {
                cur[j] = prev[j];
            }
        }
        prev = cur;
    } 
    return prev[m];
}


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}