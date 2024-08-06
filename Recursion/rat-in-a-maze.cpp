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
    https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

    TC -> O(2^N * 4)
    SC -> O(2*N) auxiliary stack space
*/


class Solution {
    private:
        void solve(int row, int col, int n, string &path, vector<vector<int>> &mat, 
        vector<vector<int>> &vis, vector<string> & ans){
            if(row == n-1 and col == n-1){
                ans.push_back(path);
                return;
            }
            vis[row][col] = 1;
            // L R U D 
            int delRow[] = {0, 0, 1, -1};
            int delCol[] = {1, -1, 0, 0};
            char dir[] = {'R', 'L', 'D', 'U'};
            for(int i = 0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow >=0 and nrow < n and ncol >= 0 and ncol < n){
                    if(mat[nrow][ncol] == 1 and vis[nrow][ncol] == 0){
                        path.push_back(dir[i]);
                        solve(nrow, ncol, n, path, mat, vis, ans);
                        path.pop_back();
                        vis[nrow][ncol] = 0;
                    }
                }
            }
        }
    public:
        vector<string> findPath(vector<vector<int>> &mat) {
            vector<string> ans;
            int n = mat.size();
            vector<vector<int>> vis(n, vector<int>(n, 0));
            string path = "";
            if(mat[0][0] == 0) return ans;
            solve(0, 0, n, path, mat, vis, ans);
            return ans;
        }
};



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}