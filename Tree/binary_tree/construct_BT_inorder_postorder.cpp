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



TreeNode * buildTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, omp(int, int) & inMap){
    if(postStart>postEnd or inStart>inEnd) return NULL;
    TreeNode * root = new TreeNode(postorder[postEnd]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = buildTree(postorder, postStart, postStart + numsLeft -1, inorder, inStart, inRoot-1, inMap);
    root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, inMap);
    return root;
}



TreeNode * buildTree(vector<int> &postorder, vector<int> &inorder){
    if(postorder.size() != inorder.size()) return NULL;
    omp(int, int) inMap;
    f(i,0,inorder.size()) inMap[inorder[i]] = i;
    TreeNode * root = buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}



void preOrderTraversal(TreeNode* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


int main(){
    vector<int> inorder = {40,20,50,10,60,30};
    vector<int> postorder = {40,50,20,60,30,10};

    TreeNode* root = buildTree(postorder, inorder);

    preOrderTraversal(root);
    return 0;
}