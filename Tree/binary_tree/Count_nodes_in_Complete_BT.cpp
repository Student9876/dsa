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




int findHeightLeft(TreeNode* node){
    int h=0;
    while(node){
        h++;
        node = node->left;
    }
    return h;
}
int findHeightRight(TreeNode* node){
    int h=0;
    while(node){
        h++;
        node = node->right;
    }
    return h;
}

// TC O((logN)^2)
// SC O(logN)

int countNodes(TreeNode* root){
    if(root == NULL) return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if(lh == rh) return (1<<lh)-1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}



int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);

    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);

    cout<<"Number of nodes in the complete binary tree are "<<countNodes(root);

    return 0;
}