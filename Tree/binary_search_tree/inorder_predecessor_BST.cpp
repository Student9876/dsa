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



// TC -> O(N);
// SC -> O(1);
void helper(TN* root, int key, TN** successor){
    if(root == NULL) return;
    if(root->val < key) {
        (*successor) = root;
        helper(root->right, key, successor);
    } else {
        helper(root->left, key, successor);
    }
}


// Recursion
TN* findInorderPredecessor(TN* root, int key){
    TN* successor = NULL;
    helper(root,key,&successor);
    return successor;
}


// Iterative
TN* findInorderPredecessor_(TN* root, int key){
    TN* successor = NULL;
    while(root != NULL){
        if(key <= root->val){
            root = root->left;
        } else {
            successor = root;
            root = root->right;
        }
    }
    return successor;
}



int main(){
    TN* root = new TN(5);

    root->left = new TN(2);
    root->left->left = new TN(1);
    root->left->right = new TN(4);
    root->left->right->left = new TN(3);

    root->right = new TN(7);
    root->right->left = new TN(6);
    root->right->right = new TN(9);
    root->right->right->left = new TN(8);
    root->right->right->right = new TN(10);
    

    // TN* node = findInorderPredecessor(root, 3);
    TN* node = findInorderPredecessor_(root, 1);
    cout<<node<<" "<<node->val;

    return 0;
}