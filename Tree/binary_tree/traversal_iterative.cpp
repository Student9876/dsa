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



class TreeNode{
    public:
        int val;
        TreeNode * left;
        TreeNode * right;
        TreeNode():val(0),left(nullptr),right(nullptr){}
        TreeNode(int val):val(val),left(nullptr),right(nullptr){}
        TreeNode(int val, TreeNode * left, TreeNode * right):val(val),left(left), right(right){}
};


// Preorder 
vector<int> iterativePreorderTraversal(TreeNode * root){
    vector<int> preorder;
    if(root == NULL) return preorder;
    stack<TreeNode *> st;
    st.push(root);

    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->val);

        if(root->right!=NULL) st.push(root->right);
        if(root->left!=NULL) st.push(root->left);
    }
    return preorder;
}

// Inorder
vector<int> iterativeInorderTraversal(TreeNode * root){
    vector<int> inorder;
    stack<TreeNode *> st;
    TreeNode * node = root;
    while (true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        } else {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
}

// Postorder 
vector<int> iterativePostorderTraversal1(TreeNode *root){
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<TreeNode *> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        TreeNode * node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left!=NULL) st1.push(node->left);
        if(node->right!=NULL) st1.push(node->right);
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
}

vector<int> iterativePostorderTraversal2(TreeNode *root){
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<TreeNode *> st;
    TreeNode * curr = root;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode * temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->val);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                }
            } else {
                curr = temp;
            }
        }
    }
    return postorder;
}


// All in one traversal 


int main(){
    

    TreeNode * root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


          

    vector<int> preorder = iterativePreorderTraversal(root);
    cout<<"Iterative preorder traversal:";nl;
    
    fa(i,preorder) cout<<i<<" ";

    nl;
    vector<int> inorder = iterativeInorderTraversal(root);
    cout<<"Iterative inorder traversal:";nl;
    
    fa(i,inorder) cout<<i<<" ";

    nl;
    vector<int> postorder1 = iterativePostorderTraversal1(root);
    cout<<"Iterative postorder traversal 2 stack method:";nl;
    
    fa(i,postorder1) cout<<i<<" ";

    nl;
    vector<int> postorder2 = iterativePostorderTraversal2(root);
    cout<<"Iterative postorder traversal 1 stack method:";nl;
    
    fa(i,postorder2) cout<<i<<" ";


    return 0;
}