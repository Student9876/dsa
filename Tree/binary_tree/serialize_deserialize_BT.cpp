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


string serialize(TreeNode * root){
    if(!root) return "";
    string s="";
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode * node = q.front();
        q.pop();
        if(node == NULL) s.append("#,");
        else s.append(to_string(node->val) + ",");

        if(node!=NULL){
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode * deSerialize(string &data){
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode * root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode * node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#"){
            node->left = NULL;
        } else {
            node->left = new TreeNode(stoi(str));
            q.push(node->left);
        }
        
        getline(s, str, ',');
        if(str == "#"){
            node->right = NULL;
        } else {
            node->right = new TreeNode(stoi(str));
            q.push(node->right);
        } 
    }
    return root;
}



void preorderTraversal(TreeNode * root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);


    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    preorderTraversal(root);
    cout<<endl;

    string s = serialize(root);
    cout<<s;

    cout<<endl;
    TreeNode * node = deSerialize(s);
    preorderTraversal(node);

    return 0;
}