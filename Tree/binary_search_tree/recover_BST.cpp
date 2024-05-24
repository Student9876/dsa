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



class Solution {
    private:
        TreeNode* first;
        TreeNode* prev;
        TreeNode* middle;
        TreeNode* last;
    private:
        void inorder(TreeNode* root){
            if(root == NULL) return;
        
            inorder(root->left);
            if(prev != NULL and (root->val < prev->val)){
                // If this is first violation, mark these two nodes as 
                // 'first' and 'middle'
                if(first == NULL){
                    first = prev;
                    middle = root;
                } else {
                    // If this is second violation, mark this nodes as last
                    last = root;
                }
            }
            prev = root;
            inorder(root->right);
        }
    public:
        void recoverTree(TreeNode* root){
            first = middle = last = NULL;
            prev = new TreeNode(INT_MIN);
            inorder(root);
            if(first and last) swap(first->val, last->val);
            else if(first and middle) swap(first->val, middle->val);
        }

};

void inorderTraversal(TN* root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}


int main(){

    TN* root = new TN(3);

    root->left = new TN(1);

    root->right = new TN(4);
    root->right->left = new TN(2);


    inorderTraversal(root);
    Solution s1;
    s1.recoverTree(root);
    nl;
    inorderTraversal(root);
    
    return 0;
}