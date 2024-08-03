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
    https://leetcode.com/problems/n-queens/description/

*/


// Approach 1
// With extra O(3N) complexity 
// TC -> nearly O(N! * N) 
// SC -> O(N^2) 
class Solution {
private:
    bool isSafeToPlace(vector<string> &board, int row, int col, int n){
        int x = row, y = col;

        while(row >= 0 and col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = x; col = y;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        col = y;
        while(row < n and col >=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
private:
    void solve(vector<string> &board, int col, int n, vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(isSafeToPlace(board, row, col, n)){
                board[row][col] = 'Q';
                solve(board, col + 1, n, ans);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0;i<n;i++){
            board[i] = s;
        }
        solve(board, 0, n, ans);
        return ans;
    }
};




// Approach 2 (Optimised)
// This one takes extra space but get rid of the extra O(3N) time complexity in each recursion call 
// TC -> O(N! * N )
// SC -> O(N) 
class Solution1 {
private:
    bool isSafeToPlace(vector<string> &board, int row, int col, int n){
        int x = row, y = col;

        while(row >= 0 and col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = x; col = y;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        col = y;
        while(row < n and col >=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
private:
    void solve(vector<string> &board, int col, int n, vector<vector<string>> &ans, 
    vector<int> &leftRow, vector<int> &lowerDiag, vector<int> &upperDiag){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(leftRow[row] == 0 and lowerDiag[row + col] == 0 and
            upperDiag[n-1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n-1 + col - row] = 1;
                solve(board, col + 1, n, ans, leftRow, lowerDiag, upperDiag);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n-1 + col - row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        vector<int> leftRow(n,0), lowerDiag(2*n-1, 0), upperDiag(2*n-1, 0);
        for(int i = 0;i<n;i++){
            board[i] = s;
        }
        solve(board, 0, n, ans, leftRow, lowerDiag, upperDiag);
        return ans;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
        
    }
    return 0;
}