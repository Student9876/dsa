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

class TreeNode{
    public:
        int val;
        TreeNode * left;
        TreeNode * right;
        TreeNode():val(0),left(nullptr),right(nullptr){}
        TreeNode(int val):val(val),left(nullptr),right(nullptr){}
        TreeNode(int val, TreeNode * left, TreeNode * right):val(val),left(left), right(right){}
} typedef TN;

// Recursion 
// int helper(int m, int n){
//     if(m==0 && n==0){
//         return 1;
//     }
//     if(m < 0 || n < 0){
//         return 0;
//     }
//     int c1 = helper(m-1,n);
//     int c2 = helper(m,n-1);
//     return c1 + c2;
// }

// int uniquePaths(int m, int n) {
//     return helper(m-1,n-1);
// }



// Memoization 
// int helper(int m, int n, vector<vector<int>> &dp){
//     if(m==0 && n==0){
//         return 1;
//     }
//     if(m < 0 || n < 0){
//         return 0;
//     }
//     if(dp[m][n] != -1){
//         return dp[m][n];
//     }
//     return dp[m][n] = helper(m-1,n, dp) + helper(m,n-1, dp);
// }

// int uniquePaths(int m, int n) {
//     vector<vector<int>> dp(m,vector<int>(n,-1));
//     return helper(m-1,n-1, dp);
// }

// Tabulation 
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(i==0 and j==0){
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;

            if(i-1 >= 0){
                up = dp[i-1][j];
            }
            if(j-1 >= 0){
                left = dp[i][j-1];
            }
            dp[i][j] = up + left;
            
        }
    }
    return dp[m-1][n-1];
}

// Space optimized 



int main(){
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        cout<<uniquePaths(n,m);nl;
    }
    return 0;
}