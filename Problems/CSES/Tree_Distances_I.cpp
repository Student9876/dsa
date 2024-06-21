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
    https://cses.fi/problemset/task/1132/
    Tree Distances I

    Intuition
    The intuition for this problem is to find the longest path from any arbitrary node to any other node.
    and from the last node it visits from the arbitrary node, again run the bfs to find the longest path.
    then again run the bfs from the last node visited in the second bfs to find the longest path.

    Recorded the distances in a map and printed the distances.
*/


const int sz = 200005;
vector<int> adj[sz];

pair<int, int> bfs(int node, omp(int, int) &mp){

    queue<pair<int, int>> q;
    vector<int> vis(sz, 0);
    q.push({node, 0});
    vis[node] = 1;

    pair<int, int> p; 
    while(!q.empty()){
        p = q.front();
        q.pop();
        vis[p.first] = 1;
        fa(i, adj[p.first]){
            if(vis[i] == 0){
                q.push({i, p.second+1});
                if(mp.find(i) != mp.end()){
                    if(mp[i] < p.second+1) mp[i] = p.second + 1;
                } else {
                    mp[i] = p.second + 1;
                }
            }
        }
    }
    return p;

}


int main(){
    int n;cin>>n;
    if(n == 1){
        cout<<0;
        return 0;
    }
    f(i, 0, n-1){
        int x, y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    omp(int, int) mp;
    pair<int, int> end1 = bfs(1, mp);
    pair<int, int> end2 = bfs(end1.first, mp);
    pair<int, int> end3 = bfs(end2.first, mp);
    fa(i, mp){
        cout<<i.second<<" ";
    }
    nl;
    return 0;
}