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
};


// TC = O(n)
// SC = O(n)


// Function to return the top view of a binary tree
vector<int> topView(TreeNode * root){
    omp(int, int) nodes;
    vector<int> res;
    if(root == NULL) return res;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second;
        if(nodes.find(x) == nodes.end()) nodes[x] = node->val;
        if(node->left) q.push({node->left, x-1});
        if(node->right) q.push({node->right, x+1});
    }
    fa(p, nodes) res.push_back(p.second);
    return res;
}

// Function to return the top view of a binary tree
vector<int> bottomView(TreeNode* root){
    omp(int, int) nodes;
    vector<int> res;
    if(root == NULL) return res;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second;
        nodes[x] = node->val;
        if(node->left) q.push({node->left, x-1});
        if(node->right) q.push({node->right, x+1});

    }
    fa(p, nodes) res.push_back(p.second);
    return res;
}





int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);


    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> ans = topView(root);
    cout<<"Top View of the tree is: ";nl;
    fa(i, ans) cout<<i<<" ";

    nl;
    ans = bottomView(root);
    cout<<"Bottom View of the tree is: ";nl;
    fa(i, ans) cout<<i<<" ";


    return 0;
}