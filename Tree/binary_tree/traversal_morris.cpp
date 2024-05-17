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

// Time O(n)
// Space O(1)

vector<int> getInorderMorrisTraversal(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left == NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while(prev->right and prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                // This means that the node not having a thread 
                prev->right = curr;
                curr = curr->left;

            } else {
                // This means that the node having a thread and came back to this state
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

vector<int> getPreorderMorrisTraversal(TreeNode* root){
    vector<int> preorder;
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left == NULL){
            preorder.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while(prev->right and prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                // This means that the node not having a thread 
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;

            } else {
                // This means that the node having a thread and came back to this state
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}



int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> inorder = getInorderMorrisTraversal(root);
    vector<int> preorder = getPreorderMorrisTraversal(root);

    cout<<"Inorder using morris traversal is: "<<endl;
    fa(i,inorder) cout<<i<<" ";

    cout<<endl;

    cout<<"Preorder using morris traversal is: "<<endl;
    fa(i,preorder) cout<<i<<" ";


    return 0;
}