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


// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

// TC -> n x m x log(n x m) + (n x m x 4)
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, 
    vector<pair<int, int>> &vec, int row0, int col0){
        vis[row][col] = 1;
        vec.push_back({row-row0, col - col0});
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {1, -1, 0, 0};
        int delCol[] = {0, 0, 1, -1};
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >=0 and nrow < n and ncol >= 0 and ncol < m 
            and !vis[nrow][ncol] and grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, vis, vec, row0, col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n, vector<int> (m,0));
        set<vector<pair<int, int>>> st;
        
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j] == 1){
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}