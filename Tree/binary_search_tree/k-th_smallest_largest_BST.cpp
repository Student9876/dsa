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


// Using Inorder Traversal 
// TC -> O(N)
// SC -> O(N)
void find_Kth_Smallest_Element_InorderTraversal(TN* root, int k, int &ct){
    if(root == NULL) return;
    find_Kth_Smallest_Element_InorderTraversal(root->left, k, ct);
    ct++;
    if(ct == k){
        cout<<root->val;
        return;
    }
    find_Kth_Smallest_Element_InorderTraversal(root->right, k, ct);
}


// Using Morris Traversal 
// TC -> O(N)
// SC -> O(1)
void find_Kth_Smallest_Element_MorrisTraversal(TN* root, int k, int &ct){
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left == NULL){
            ct++;
            curr = curr->right;
            if(ct == k){
                cout<<curr->val;
                return;
            }
        } else {
            TreeNode* prev = curr->left;
            while(prev->right and prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                ct++;
                curr = curr->left;
                if(ct == k){
                    cout<<curr->val;
                    return;
                }

            } else {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}

int main(){
    // TN* root = new TN(5);

    // root->left = new TN(3);
    // root->left->left = new TN(2);
    // root->left->left->left = new TN(1);
    // root->left->right = new TN(4);

    // root->right = new TN(8);
    // root->right->left = new TN(7);
    // root->right->left->left = new TN(6);
    // root->right->right = new TN(9);

    TN* root = new TN(10);

    root->left = new TN(5);
    root->left->left = new TN(3);
    root->left->right = new TN(6);
    root->left->left->left = new TN(2);
    root->left->left->right = new TN(4);


    root->right = new TN(13);
    root->right->left = new TN(11);
    root->right->right = new TN(14);
    
    int ct=0;
    find_Kth_Smallest_Element_InorderTraversal(root,6,ct);
    nl;
    // find_Kth_Smallest_Element_MorrisTraversal(root,6,ct);

    return 0;
}