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



TN* lowest_commmon_ancestor_BST(TN* root, TN* p, TN* q){
    if(root == NULL) return NULL;
    int curr = root->val;
    if(curr < p->val and curr < q->val){
        return lowest_commmon_ancestor_BST(root->right, p, q);
    }
    if(curr > p->val and curr > q->val){
        return lowest_commmon_ancestor_BST(root->left, p, q);
    }
    return root;
}




int main(){
    TN* root = new TN(10);

    root->left = new TN(4);
    root->left->left = new TN(3);
    root->left->left->left = new TN(1);
    root->left->left->left->right = new TN(2);
    root->left->right = new TN(8);
    root->left->right->left = new TN(6);
    root->left->right->left->left = new TN(5);
    root->left->right->left->right = new TN(7);
    root->left->right->right = new TN(9);

    root->right = new TN(13);
    root->right->left = new TN(11);
    root->right->right = new TN(15);


    TN* node = lowest_commmon_ancestor_BST(root,root->left->left->left->right,root->left->right->left->right);
    cout<< node->val;



    return 0;
}