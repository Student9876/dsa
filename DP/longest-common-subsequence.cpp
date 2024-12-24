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
    https://leetcode.com/problems/longest-common-subsequence/description/
*/

// Memoization 
int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i < 0 || j < 0)
        return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return dp[i][j] = 1 + helper(i-1,j-1,s1,s2, dp);
    return dp[i][j] = max(helper(i-1, j, s1, s2, dp), helper(i, j-1, s1, s2, dp));
}
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n-1, m-1, text1, text2, dp);
}

// Tabulation
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=m;j++){
            if(i <= 0 || j <= 0)
                continue;
            if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

// Space Optimized
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<int> prev(m+1, 0);
    for(int i = 1; i<=n;i++){
        vector<int> cur(m+1, 0);
        for(int j = 1; j<=m;j++){
            if(i <= 0 || j <= 0)
                continue;
            if(text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];
            else cur[j] = max(prev[j], cur[j-1]);
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