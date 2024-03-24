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



void markParents(TreeNode* root, ump(TreeNode*, TreeNode*) & parent_track){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode * node = q.front();
        q.pop();
        if(node->left){
            parent_track[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parent_track[node->right] = node;
            q.push(node->right);
        }
    }
}

int timeTakenToBurnBT(TreeNode* root, TreeNode* target){
    ump(TreeNode*, TreeNode*) parent_track;
    markParents(root, parent_track);
    ump(TreeNode*, bool) visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int time=0;
    while(!q.empty()){
        int size = q.size();
        int flag=0;
        f(i,0,size){
            TreeNode* current = q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
                flag=1;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
                flag=1;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
                flag=1;
            }
        }
        if(flag) time++;
    }
    return time;
}



int main(){
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(7);



    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    TreeNode* burnNode = root->left;

    cout<<"Time taken to burn the tree from node "<<burnNode->val<<" is "<<timeTakenToBurnBT(root,burnNode);

    return 0;
}