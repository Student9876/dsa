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
    https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
    Shortest distance in Binary Maze

    Using Dijkstras Algorithm but with a Queue

*/


class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        q.push({{source.first, source.second}, 0});
        dist[source.first][source.second] = 0;
        int delRow[] = {1, -1, 0, 0};
        int delCol[] = {0, 0, 1, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            if(row == destination.first and col == destination.second) return steps;
            
            for(int i = 0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m 
                and grid[nrow][ncol] == 1 and (steps + 1 < dist[nrow][ncol])){
                    dist[nrow][ncol] = steps + 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
            
        }
        return -1;
        
    }
};

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
    return 0;
}


/*
5 4
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
0 1
2 2

Output: 3
*/