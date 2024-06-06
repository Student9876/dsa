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



// https://leetcode.com/problems/number-of-enclaves/description/
// https://www.geeksforgeeks.org/problems/number-of-enclaves/1

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int>(m,0));
        queue<pair<int, int>> q;
        for(int j=0;j<m;j++){
            if(grid[0][j] == 1){
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(grid[n-1][j] == 1){
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(grid[i][m-1] == 1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
            
        int delRow[] = {1, -1, 0, 0};
        int delCol[] = {0, 0, 1, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
        
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow >=0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 1 
                and vis[nrow][ncol] == 0){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 and vis[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}