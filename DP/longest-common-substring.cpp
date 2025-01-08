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
    https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
*/

// Tabulation 
int longestCommonSubstr(string& s1, string& s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

// Space optimised 
int longestCommonSubstr(string& s1, string& s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1, 0), cur(m+1,0);
    int ans = 0;
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(s1[i-1] == s2[j-1]){
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            } else {
                cur[j] = 0;
            }
        }
        prev = cur;
    }
    return ans;
}

int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}