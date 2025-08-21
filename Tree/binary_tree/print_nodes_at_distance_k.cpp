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


/*
    https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
    TC: O(N)
    SC: O(N)
*/




// Normal BFS (levelOrderTraverrsal) with tracking parent nodes for every node 
void markParents(TreeNode* root, ump(TreeNode*, TreeNode*) &parent_track){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode * current = q.front();
        q.pop();
        if(current->left){
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    ump(TreeNode*, TreeNode*) parent_track;
    markParents(root, parent_track);

    ump(TreeNode*, bool) visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while(!q.empty()){
        int size = q.size();
        if(curr_level++ == k) break;
        f(i,0,size){
            TreeNode* current = q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> res;
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        res.push_back(current->val);
    }
    return res;
}


int main(){
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);


    vector<int> res = distanceK(root, root->left, 2);

    fa(i,res) cout<<i<<" ";


    return 0;
}