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
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i = 0; i<n;i++){
	        for(int j = 0;j<n;j++){
	            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	            if(i == j) matrix[i][j] = 0;
	        }
	    }
	    
	    for(int k = 0;k<n;k++){
	        for(int i = 0;i<n;i++){
	            for(int j = 0;j<n;j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }


        // for(int i = 0;i<n;i++){
        //     if(matrix[i][i] < 0){
        //         negetive_cycle = true;
        //             break;
        //     }
        // }

	    for(int i = 0; i<n;i++){
	        for(int j = 0;j<n;j++){
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	        }
	    }
	}
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}