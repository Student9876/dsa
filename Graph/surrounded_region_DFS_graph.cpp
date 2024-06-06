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


// https://leetcode.com/problems/surrounded-regions/description/
// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1


class Solution {
private:
    void dfs(int row, int col, int n, int m, vector<vector<char>>& mat,
             vector<vector<int>>& vis, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and
                mat[nrow][ncol] == 'O') {
                if (!vis[nrow][ncol])
                    dfs(nrow, ncol, n, m, mat, vis, delRow, delCol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delRow[] = {1, -1, 0, 0};
        int delCol[] = {0, 0, 1, -1};
        // traverse first last row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] and mat[0][j] == 'O') {
                dfs(0, j, n, m, mat, vis, delRow, delCol);
            }

            if (!vis[n - 1][j] and mat[n - 1][j] == 'O') {
                dfs(n - 1, j, n, m, mat, vis, delRow, delCol);
            }
        }
        // traverse first last col
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] and mat[i][0] == 'O') {
                dfs(i, 0, n, m, mat, vis, delRow, delCol);
            }

            if (!vis[i][m - 1] and mat[i][m - 1] == 'O') {
                dfs(i, m - 1, n, m, mat, vis, delRow, delCol);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O' and vis[i][j])
                    mat[i][j] = 'O';
                else
                    mat[i][j] = 'X';
            }
        }
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}