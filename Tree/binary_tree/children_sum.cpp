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



void changeTree(TreeNode* root){
    if(root == NULL) return;
    int child=0;
    if(root->left) child+=root->left->val;
    if(root->right) child+=root->right->val;
    if(child >= root->val) root->val = child;
    else {
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);
    
    int tot=0;
    if(root->left) tot+=root->left->val;
    if(root->right) tot+=root->right->val;
    if(root->left  or root->right) root->val = tot;

}


void preOrder(TreeNode* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(30);

    changeTree(root);

    preOrder(root);

    

    return 0;
}