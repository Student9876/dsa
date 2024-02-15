#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,m,n) for(ll i=m;i<n;i++)
#define fi(i,m,n) for(ll i=m;i>=n;i--)
#define nl cout<<endl;
#define ump(a,b) unordered_map<a,b>
#define omp(a,b) map<a,b>
const int MOD = 1e9+7;



class TreeNode{
    public:
        int val;
        TreeNode * left;
        TreeNode * right;
        TreeNode():val(0),left(nullptr),right(nullptr){}
        TreeNode(int val):val(val),left(nullptr),right(nullptr){}
        TreeNode(int val, TreeNode * left, TreeNode * right):val(val),left(left), right(right){}
};





void preorderTraverse(TreeNode * root){
    if(root == nullptr) return ;
    cout<<root->val<<" ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}


void inorderTraverse(TreeNode * root){
    if(root == nullptr) return ;
    inorderTraverse(root->left);
    cout<<root->val<<" ";
    inorderTraverse(root->right);
}

void postorderTraverse(TreeNode * root){
    if(root == nullptr) return ;
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    cout<<root->val<<" ";
}



int main(){
    TreeNode * root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    // Indorder Traversal 
    cout<<"Preorder Traversal :";
    preorderTraverse(root);
    nl;
    cout<<"Inorder Traversal :";
    inorderTraverse(root);
    nl;
    cout<<"Postorder Traversal :";
    postorderTraverse(root);


    return 0;
}