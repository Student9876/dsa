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




// Function for finding height of a tree 
// TC = O(n)
// SC = O(n)
int maxDepth(TreeNode * root){
    if(root == NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh,rh);
}



// Function for checking a tree is balanced or not 
// TC = O(n)
// SC = O(n)
int isBalanced(TreeNode * root){
    if(root == NULL) return 0;

    int lh = isBalanced(root->left);
    if(lh == -1) return -1;
    int rh = isBalanced(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1 + max(lh,rh);
}


// Function for diameter of a tree (longest path between 2 nodes)
// TC = O(n)
// SC = O(n)
int diameterOfBinaryTree(TreeNode * root, int &diameter){
    if(root == NULL) return 0;

    int lh = diameterOfBinaryTree(root->left, diameter);
    int rh = diameterOfBinaryTree(root->right, diameter);
    diameter = max(diameter, lh + rh);

    return 1+max(lh,rh);
}




int main(){
    
    TreeNode * root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // root->left->left->left = new TreeNode(8);
    // root->left->left->left->left = new TreeNode(9);


    cout<<"Height of the tree is: "<<maxDepth(root);

    nl;

    int balanced = isBalanced(root);
    if(balanced == -1) cout<<"Tree is not balanced";
    else cout<<"Tree is balanced";
    
    nl;

    int diameter=0;
    diameterOfBinaryTree(root, diameter);
    cout<<"Diameter of binary tree is: "<<diameter;


    return 0;
}