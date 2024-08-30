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
    https://www.naukri.com/code360/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
    https://leetcode.com/problems/minimum-path-sum/description/

*/


// Recursion 
// int helper(int i, int j, vector<vector<int>> &grid, int sum){
//     if(i==0 and j==0){
//         return sum + grid[i][j];
//     }
//     if(i < 0 || j < 0){
//         return INT_MAX;
//     }
//     int c1 = helper(i-1,j,grid, sum + grid[i][j]);
//     int c2 = helper(i,j-1,grid, sum + grid[i][j]);
//     return min(c1,c2);
// }

// int minSumPath(vector<vector<int>> &grid) {
//     int m = grid.size();
//     int n = grid[0].size();
//     return helper(m-1,n-1,grid, 0);
// }

// Memoization 
// int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
//      if (i == 0 && j == 0) {
//         return grid[i][j];
//     }
//     if (i < 0 || j < 0) {
//         return INT_MAX;
//     }
//     if (dp[i][j] != -1) {
//         return dp[i][j];
//     }
//     int c1 = helper(i - 1, j, grid, dp);
//     int c2 = helper(i, j - 1, grid, dp);
//     dp[i][j] = grid[i][j] + min(c1, c2);
//     return dp[i][j];
// }

// int minSumPath(vector<vector<int>> &grid) {
//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     return helper(m-1,n-1,grid, dp);
// }

// Tabulation 
// int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
//      if (i == 0 && j == 0) {
//         return grid[i][j];
//     }
//     if (i < 0 || j < 0) {
//         return INT_MAX;
//     }
//     if (dp[i][j] != -1) {
//         return dp[i][j];
//     }
//     int c1 = helper(i - 1, j, grid, dp);
//     int c2 = helper(i, j - 1, grid, dp);
//     dp[i][j] = grid[i][j] + min(c1, c2);
//     return dp[i][j];
// }

int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
   
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(i == 0 and j == 0)
                dp[i][j] = grid[i][j];
            else {
                int up = grid[i][j];
                if(i>0)
                    up += dp[i-1][j];
                else 
                    up += 1e9;


                int left = grid[i][j];
                if(j>0)
                    left += dp[i][j-1];
                else 
                    left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[m-1][n-1];
}


int main(){
    int T;cin>>T;
    while(T--){
        int m,n;cin>>m>>n;
        vector<vector<int>> grid(m, vector<int>(n));
        f(i,0,m){
            f(j,0,n){
                cin>>grid[i][j];
            }
        }
        cout<<minSumPath(grid);nl;
    }
    return 0;
}