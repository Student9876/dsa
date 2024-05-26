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


void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid){
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row, col});

    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse in the neighbours and mark them its a land 
        f(delrow,-1,2){
            f(delcol,-1,2){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m 
                and grid[nrow][ncol] == '1' and !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

    }
}

int numIslands(vector<vector<char>> & grid){
    int n = grid.size();
    int m = grid[0].size();
    int ct = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    f(row,0,n){
        f(col,0,m){
            if(!vis[row][col] and grid[row][col] == '1'){
                ct++;
                bfs(row, col, vis, grid);
            }
        }
    }
}


int main(){
    vector<vector<char>> grid = {
        {},
        {},
    };
    return 0;
}