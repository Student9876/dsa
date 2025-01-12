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
    https://leetcode.com/problems/shortest-common-supersequence/description/

    Solution is made using the LCS DP table and then we backtrack to get the shortest common supersequence
*/


// Tabulation 
string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            ans += str1[i-1];
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]){
            ans += str1[i-1];
            i--;
        } else {
            ans += str2[j-1];
            j--;
        }
    }
    while(i > 0){
        ans += str1[i-1];
        i--;
    }
    while(j > 0){
        ans += str2[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}