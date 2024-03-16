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



bool isLeaf(TreeNode* root){
    return root->left==NULL && root->right==NULL;
}

void addLeftBoundary(TreeNode* root, vector<int> &res){
    TreeNode* cur = root;
    while(cur!=NULL){
        if(!isLeaf(cur)) res.push_back(cur->val);
        if(cur->left!=NULL) cur = cur->left;
        else cur = cur->right;
    }
}

void addRightBoundary(TreeNode* root, vector<int> &res){
    TreeNode* cur = root;
    vector<int> temp;
    while(cur!=NULL){
        if(!isLeaf(cur)) temp.push_back(cur->val);
        if(cur->right!=NULL) cur = cur->right;
        else cur = cur->left;
    }
    for(int i=temp.size()-1;i>=0;i--) res.push_back(temp[i]);
}

void addLeaves(TreeNode* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left!=NULL) addLeaves(root->left,res);
    if(root->right!=NULL) addLeaves(root->right,res);
}


// Anticlockwise order of printing boundary elements of a binary tree
// technique is to print left boundary, leaves and right boundary
vector<int> printBoundary(TreeNode* root){
    vector<int> res;
    if(root==NULL) return res;
    if(!isLeaf(root)) res.push_back(root->val);
    addLeftBoundary(root->left,res);
    addLeaves(root,res);
    addRightBoundary(root->right,res);
    return res;
}


int main(){
    TreeNode * root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    vector<int> res = printBoundary(root);
    fa(i,res) cout<<i<<" ";

    return 0;
}