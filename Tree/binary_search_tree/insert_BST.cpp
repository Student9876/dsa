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



TN* insert_in_BST(TN* root, int val){
    if(root == NULL) return new TN(val);
    TN* cur = root;
    while(true){
        if(cur->val <= val) {
            if(cur->right != NULL) cur = cur->right;
            else {
                cur->right = new TN(val);
                break;
            } 
        } else {
            if(cur->left != NULL) cur = cur->left;
            else {
                cur->left = new TN(val);
                break;
            }
        }
    }

    return root;
}


void inorderTraversal(TN* root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

int main(){
    TN* root = new TN(10);

    root->left = new TN(5);
    root->left->left = new TN(3);
    root->left->right = new TN(6);
    root->left->left->left = new TN(2);
    root->left->left->right = new TN(4);


    root->right = new TN(13);
    root->right->left = new TN(11);
    root->right->right = new TN(14);


    inorderTraversal(root);
    nl;
    root = insert_in_BST(root, 12);
    inorderTraversal(root);

    return 0;
}