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
    https://www.naukri.com/code360/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
    https://leetcode.com/problems/triangle/description/

*/

// Recursion 
// int helper(int i, int j, vector<vector<int>> &triangle, int n){
//     if(i == n-1)
//         return triangle[i][j];
//     int down = triangle[i][j] + helper(i+1, j, triangle, n);
//     int diag = triangle[i][j] + helper(i+1, j+1, triangle, n);
//     return min(down, diag);
// }

// int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	return helper(0, 0, triangle, n);
// }

// Memoization
// int helper(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp){
//     if(i == n-1)
//         return dp[i][j] = triangle[i][j];

//     if(dp[i][j] != -1)
//         return dp[i][j];
//     int down = triangle[i][j] + helper(i+1, j, triangle, n, dp);
//     int diag = triangle[i][j] + helper(i+1, j+1, triangle, n, dp);
//     return dp[i][j] = min(down, diag);
// }

// int minimumPathSum(vector<vector<int>>& triangle, int n){
//     vector<vector<int>> dp(n, vector<int>(n, -1));
// 	return helper(0, 0, triangle, n, dp);
// }

// Tabulation 
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, 0));
	for(int j = 0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i = n-2;i>=0;i--){
        for(int j = i;j>=0;j--){
            int d = triangle[i][j] + dp[i+1][j];
            int dia = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(d, dia);
        }
    }

    return dp[0][0];
}



int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<vector<int>> triangle(n, vector<int>(n));
        f(i,0,n){
            f(j,0,i+1){
                cin>>triangle[i][j];
            }
        }
        cout<<minimumPathSum(triangle, n);nl;
    }
    return 0;
}