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
    https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
*/


// Memoization 
// int helper(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
//     if(i == grid.size() -1){
//         if(j1 == j2) return grid[i][j1];
//         else return grid[i][j1] + grid[i][j2];
//     }
//     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
//     int mx = 0;
//     for(int c1 = -1;c1<=1;c1++){
//         for(int c2 = -1;c2<=1;c2++){
//             if(j1+c1>=0 and j1+c1<grid[0].size() and j2+c2>=0 and j2+c2<grid[0].size()){
//                 if(j1+c1 != j2+c2){
//                     mx = max(mx, grid[i][j1] + grid[i][j2] + helper(i+1,j1+c1,j2+c2,grid, dp));
//                 } else {
//                     mx = max(mx, grid[i][j1] + helper(i+1,j1+c1,j2+c2,grid, dp));
//                 }
//             }
//         }
//     }
//     return dp[i][j1][j2] = mx;
// }

// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
//     vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
//     return helper(0,0,c-1,grid, dp);
// }

// Tabulation 

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    
    for(int j1 = 0;j1<m;j1++){
        for(int j2 = 0;j2<m;j2++){
            dp[n-1][j1][j2] = (j1 == j2) ? grid[n-1][j1] : grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i = n-2;i>=0;i--){
        for(int j1 = 0;j1<m;j1++){
            for(int j2 = 0;j2<m;j2++){
                int mx = -1e8;
                for(int c1 = -1;c1<=1;c1++){
                    for(int c2 = -1;c2<=1;c2++){
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if(j1+c1>=0 and j1+c1<grid[0].size() and j2+c2>=0 and j2+c2<grid[0].size()){
                            value += dp[i + 1][j1 + c1][j2 + c2];
                        } else {
                            value += -1e8;
                        }

                        mx = max(mx, value);
                    }
                }
                dp[i][j1][j2] = mx;
            }
        }
    }
    return dp[0][0][m-1];

}




int main(){
    int T;cin>>T;
    while(T--){
        int r,c;cin>>r>>c;
        vector<vector<int>> grid(r,vector<int>(c));
        f(i,0,r){
            f(j,0,c){
                cin>>grid[i][j];
            }
        }
        cout<<maximumChocolates(r,c,grid);nl;
    }
    return 0;
}