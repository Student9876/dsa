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


/*
    https://www.naukri.com/code360/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
    https://leetcode.com/problems/unique-paths-ii/description/
*/


// Recursion 
// int helper(int n, int m, vector<vector<int>> &mat){
//     if(n==0 && m==0){
//         return 1;
//     }
//     if(n < 0 || m < 0){
//         return 0;
//     }
//     int up = 0;
//     int left = 0;
//     if(n-1 >=0 and mat[n-1][m] == 0) left = helper(n-1,m,mat);
//     if(m-1 >=0 and mat[n][m-1] == 0) up = helper(n,m-1,mat);
//     return up + left;
// }


// int mazeObstacles(int n, int m, vector< vector<int> > &mat) {
//     return helper(n-1,m-1,mat);
// }

// Memoization 
// int helper(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp){
//     if(n >= 0 and m >= 0 and mat[n][m] == -1){
//         return 0;
//     }
//     if(n==0 && m==0){
//         return 1;
//     }
//     if(n < 0 || m < 0){
//         return 0;
//     }
//     if(dp[n][m] != -1){
//         return dp[n][m];
//     }
//     int up = helper(n-1,m,mat, dp);
//     int left = helper(n,m-1,mat, dp);
//     return dp[n][m] = (up + left)%MOD;
// }


// int mazeObstacles(int n, int m, vector< vector<int> > &mat) {
//     vector<vector<int>> dp(n,vector<int>(m, -1));
//     return helper(n-1,m-1,mat, dp);
// }


// Tabulation 
int mazeObstacles(int n, int m, vector< vector<int> > &mat) {
    vector<vector<int>> dp(n,vector<int>(m, 0));
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i == 0 and j == 0){
                if(mat[i][j] != -1){
                    dp[i][j] = 1;
                    continue;
                }

            } 
            int down = 0;
            int right = 0;
            if(i-1 >= 0 and mat[i-1][j] != -1){
                down = dp[i-1][j];
            }
            if(j-1 >= 0 and mat[i][j-1] != -1){
                right = dp[i][j-1];
            }
            dp[i][j] = (down + right)%MOD;
        }
    }
    return dp[n-1][m-1];
}


int main(){
    int T;cin>>T;
    while(T--){
        int n, m; cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m,0));
        f(i,0,n){
            f(j,0,m){
                cin>>grid[i][j];
            }
        }
        cout<<mazeObstacles(n,m,grid);nl;

    }
    return 0;
}