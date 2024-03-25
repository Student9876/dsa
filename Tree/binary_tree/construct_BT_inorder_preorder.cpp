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


// TC = O(N)
// SC = O(N)

TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder,int inStart, int inEnd, omp(int, int) inMap){
    if(preStart> preEnd or inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    omp(int, int) inMap;
    f(i,0,inorder.size()){
        inMap[inorder[i]] = i;
    }
    TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}



void preOrderTraversal(TreeNode* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}



int main(){

    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};

    TreeNode* root = buildTree(preorder, inorder);

    preOrderTraversal(root);

    return 0;
}