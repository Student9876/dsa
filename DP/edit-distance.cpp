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
    https://leetcode.com/problems/edit-distance/description/
*/

// Memoization
int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i < 1) return j;
    if(j < 1) return i;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i-1] == s2[j-1])
        return dp[i][j] = helper(i-1, j-1, s1, s2, dp);
    return dp[i][j] = 1 + min(helper(i, j-1, s1, s2, dp), 
        min(helper(i-1, j, s1, s2, dp), helper(i-1, j-1, s1, s2, dp)));
}
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return helper(n, m, word1, word2, dp);
}

// Tabulation
int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<m+1;j++){
            if(i < 1) {
                dp[i][j] = j;
                continue;
            }
            if(j < 1) {
                dp[i][j] = i;
                continue;
            }
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}

// Space Optimised
int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1, 0);
    for(int i = 0;i<n+1;i++){
        vector<int> cur(m+1, 0);
        for(int j = 0;j<m+1;j++){
            if(i < 1) {
                cur[j] = j;
                continue;
            }
            if(j < 1) {
                cur[j] = i;
                continue;
            }
            if(s1[i-1] == s2[j-1])
                cur[j] = prev[j-1];
            else 
                cur[j] = 1 + min(cur[j-1], min(prev[j], prev[j-1]));
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