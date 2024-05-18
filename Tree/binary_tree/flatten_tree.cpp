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


// TC -> O(N)
// SC -> O(N)
void flatten(TreeNode* root, TreeNode* *prev){
    if(root == NULL) return;
    flatten(root->right, prev);
    flatten(root->left, prev);
    root->right = *prev;
    root->left = NULL;
    *prev = root;
}
void flattenBinaryTreeRecur(TreeNode* root){
    TreeNode* prev = NULL;
    flatten(root, &prev);
}


// TC -> O(N)
// SC -> O(N)
void flattenBinaryTreeIterative(TreeNode* root){
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* cur = st.top();
        st.pop();
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
        if(!st.empty())
            cur->right = st.top();
        cur->left = NULL;
    }
}

// TC -> O(N)
// SC -> O(1)
void  flattenBinaryTreeRecur_2(TreeNode* root){
    TreeNode* cur = root;
    while(cur != NULL){
        if(cur->left != NULL){
            TreeNode* prev = cur->left;
            while(prev->right)
                prev = prev->right;
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}


void preOrderTraversal(TreeNode* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inorderTraversal(TreeNode* root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    
    
    
    
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);


    inorderTraversal(root);
    cout<<endl;
    // flattenBinaryTreeRecur(root);
    // flattenBinaryTreeIterative(root);
    flattenBinaryTreeRecur_2(root);
    inorderTraversal(root);
    // preOrderTraversal(root);

    return 0;
}