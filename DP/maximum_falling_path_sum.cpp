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
    https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
    https://leetcode.com/problems/minimum-falling-path-sum/description/
*/


// Recursion 
// int helper(vector<vector<int>> &mat, int i, int j){
//     if(i < 0 || j < 0 || j >= mat[0].size()){
//         return INT_MIN;
//     }
//     if(i == 0){
//         return mat[i][j];
//     }
//     int x = helper(mat, i-1, j);
//     int y = helper(mat, i-1, j-1);
//     int z = helper(mat, i-1, j+1);
//     return mat[i][j] + max(x, max(y, z));
// }

// int getMaxPathSum(vector<vector<int>> &matrix){
//     int n = matrix.size();
//     int m = matrix[0].size();
//     int res = INT_MIN;
//     for(int j = 0;j<m;j++){
//         res = max(res, helper(matrix, n-1, j));
//     }
//     return res;
// }


// Memoization 
// int helper(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp){
//     if(i < 0 || j < 0 || j >= mat[0].size()){
//         return INT_MIN;
//     }
//     if(i == 0){
//         return mat[i][j];
//     }
//     if(dp[i][j] != -1)
//         return dp[i][j];
//     int x = helper(mat, i-1, j, dp);
//     int y = helper(mat, i-1, j-1, dp);
//     int z = helper(mat, i-1, j+1, dp);
//     return dp[i][j] = mat[i][j] + max(x, max(y, z));
// }

// int getMaxPathSum(vector<vector<int>> &matrix){
//     int n = matrix.size();
//     int m = matrix[0].size();
//     int res = INT_MIN;
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     for(int j = 0;j<m;j++){
//         res = max(res, helper(matrix, n-1, j, dp));
//     }
//     return res;
// }


// Tabulation 
int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int res = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int j = 0;j<m;j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<m;j++){
            int x = dp[i-1][j];
            int y = (j-1 >= 0)? dp[i-1][j-1]:INT_MIN;
            int z = (j+1 < m)? dp[i-1][j+1]:INT_MIN;
            dp[i][j] = matrix[i][j] + max(x, max(y, z));
        }
    }
    for(int j = 0;j<m;j++){
        res = max(res, dp[n-1][j]);
    }
    return res;
}



int main(){
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        vector<vector<int>> matrix(n, vector<int>(m));
        f(i,0,n){
            f(j,0,m){
                cin>>matrix[i][j];
            }
        }
        cout<<getMaxPathSum(matrix);nl;
    }
    return 0;
}