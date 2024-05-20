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




bool isValidBST(TN* root, int mn, int mx){
    if(root == NULL) return true;
    return (root->val > mn and root->val < mx) and isValidBST(root->left, mn, root->val) and isValidBST(root->right, root->val, mx);
}


int main(){
    TN* root = new TN(13);

    root->left = new TN(10);
    root->left->left = new TN(7);
    root->left->right = new TN(12);
    root->left->left->right = new TN(9);
    root->left->left->right->left = new TN(8);

    root->right = new TN(15);
    root->right->left = new TN(14);
    root->right->right = new TN(17);
    root->right->right->left = new TN(16);

    cout<<"Is the binary search tree valid? "<<isValidBST(root, INT_MIN, INT_MAX);

    return 0;
}