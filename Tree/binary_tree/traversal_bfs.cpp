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

vector<vector<int>> levelOrderTraversal(TreeNode * root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        f(i,0,size){
            TreeNode *node = q.front();
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
// Time Complexity O(N)
// Space Complexity O(N)

// Zig zag level order traversal 

vector<vector<int>> zigzagLevelOrderTraversal(TreeNode* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode *> q;
    q.push(root);
    int st=0;
    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        f(i,0,size){
            TreeNode * node = q.front();
            q.pop();
            if(node->left !=NULL) q.push(node->left);
            if(node->right !=NULL) q.push(node->right);
            level.push_back(node->val);
        }
        if(st){
            reverse(level.begin(), level.end());
            st=0;
        } else {
            st=1;
        }
        ans.push_back(level);
    }
}


int main(){
    TreeNode * root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    vector<vector<int>> ans = levelOrderTraversal(root);
    cout<<"Level Order Traversal";nl;
    for(auto it:ans){
        for(auto item:it) cout<<item<<" ";
    }
    nl;
    ans = zigzagLevelOrderTraversal(root);
    cout<<"Zig Zag Level Order Traversal";nl;
    for(auto it:ans){
        for(auto item:it) cout<<item<<" ";
    }


    return 0;
}