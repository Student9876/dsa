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



bool isSymmetric2(TreeNode* left, TreeNode* right){
    if(left == NULL || right == NULL) return left == right;

    if(left->val!=right->val) return false;
    return isSymmetric2(left->left, right->right) && isSymmetric2(left->right, right->left);
}
bool isSymmetric(TreeNode* root){
    return root==NULL || isSymmetric2(root->left, root->right);
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    cout<<"Binary tree is Symmetric "<<isSymmetric(root);
    return 0;
}