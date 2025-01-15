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
    https://leetcode.com/problems/wildcard-matching/description/
*/

// Memoization
bool isAllStars(string &S1, int i) {
    for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
            return false;
    }
    return true;
}
bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp){
    if (j < 1 && i < 1)
        return true;
    if (j < 1 && i >= 1)
        return false;
    if (i < 1 && j >= 1)
        return isAllStars(p, j-1);
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == p[j-1] || p[j-1] == '?') 
        return dp[i][j] = helper(i-1, j-1, s, p, dp);
    if(p[j-1] == '*') 
        return dp[i][j] = (helper(i-1, j, s, p, dp) | helper(i, j-1, s, p, dp));
    return false;
}
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    return helper(n, m, s, p, dp);
}

// Tabulation
bool isAllStars(string &S1, int i) {
    for (int j = 1; j <= i; j++) {
        if (S1[j-1] != '*')
            return false;
    }
    return true;
}
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
    dp[0][0] = true;
    for(int j = 1;j<m+1;j++){
        dp[0][j] = isAllStars(p, j);
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?') 
                dp[i][j] = dp[i-1][j-1];
            if(p[j-1] == '*') 
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
        }
    }
    return dp[n][m];
}

// Space Optimised 
bool isAllStars(string &S1, int i) {
    for (int j = 1; j <= i; j++) {
        if (S1[j-1] != '*')
            return false;
    }
    return true;
}

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<bool> prev(m+1, false);
    prev[0] = true;
    for(int j = 1;j<m+1;j++){
        prev[j] = isAllStars(p, j);
    }
    for(int i = 1;i<n+1;i++){
        vector<bool> cur(m+1, false);
        for(int j = 1;j<m+1;j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?') 
                cur[j] = prev[j-1];
            if(p[j-1] == '*') 
                cur[j] = prev[j] | cur[j-1];
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