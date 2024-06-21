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

// https://cses.fi/problemset/task/1674/


/* 
    Intuition 
    - We can solve this problem using DFS
    - We can calculate the number of subordinates of each employee
    - A dfs algorithm which always initializes the number of subordinates of a node as 1
    - then for each child of the node, we add the number of subordinates of the child to the number of subordinates of the node
    - Finally, we print the number of subordinates of each employee
    - As we are calculating the total number of clild nodes including the parent node itself, so the ans will be subtree[node]-1
*/

const int MAX = 200001;

vector<int> children[MAX];
int subtree[MAX];

void dfs(int node){
    subtree[node] = 1;
    for(auto child:children[node]){
        dfs(child);
        subtree[node] += subtree[child];
    }
}


int main(){
    
    int n;
    cin>>n;
    f(i,2,n+1){
        int x;
        cin>>x;
        children[x].push_back(i);
    }



    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<subtree[i]-1<<" ";
    }   
    nl;

    return 0;
}