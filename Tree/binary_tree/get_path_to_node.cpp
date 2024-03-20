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



bool getPath(TreeNode* root, vector<int>& res, int a){
    if(!root) return false;
    res.push_back(root->val);

    if(root->val == a) return true;

    if(getPath(root->left, res, a) or getPath(root->right, res, a)) return true;
    res.pop_back();
    return false;
}


vector<int> solve(TreeNode* root, int a){
    vector<int> res;
    if(root == NULL) return res;
    getPath(root, res, a);
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


    vector<int> res = solve(root, 8);
    fa(i,res) cout<<i<<" ";


    
    return 0;
}