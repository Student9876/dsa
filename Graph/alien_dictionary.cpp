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



/*
    https://www.geeksforgeeks.org/problems/alien-dictionary/1
    Alien Dictionary
    Using tpological sort algorithm to determine the order of the alphabets. 
    Create a graph of the alphabets and then apply the topo sort algorithm.
*/


class Solution{
    private:
        vector<int> topoSort(int V, vector<int> adj[]){
            vector<int> res;
            vector<int> indeg(V);
            queue<int> q;
            
            for(int i=0;i<V;i++){
                for(auto it:adj[i]){
                    indeg[it]++;
                }
            }
            
            for(int i=0;i<V;i++){
                if(indeg[i] == 0) q.push(i);
            }
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                res.push_back(node);
                
                for(auto it:adj[node]){
                    indeg[it]--;
                    if(indeg[it] == 0) q.push(it);
                }
            }
            return res;
        }
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        for(int i = 0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int j=0;
            while(j<min(s1.length(), s2.length())){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
                j++;
            }
        }
        
        
        vector<int> res = topoSort(K, adj);
        
        string ans="";
        for(auto it:res){
            ans = ans + char(it + 'a');
        }
        return ans;
        
    }
};



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}