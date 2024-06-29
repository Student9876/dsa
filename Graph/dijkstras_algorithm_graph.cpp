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
    https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
    Dijkstra's Algorithm finding shortest paths from a given source using priority queue
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Defining a Min heap in C++
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = edgeWeight + dis;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};



/*
    https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
    Dijkstra's Algorithm finding shortest paths from a given source using set
    using set, we can remove already update nodes from the set which have greater distance
    In this way we can save some time in iterations in some cases
*/

class Solution2
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        // set approach 
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        
        
        st.insert({0, S});
        dist[S] = 0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto i:adj[node]){
                int adjNode = i[0];
                int edgeWeight = i[1];
                
                if(dis + edgeWeight < dist[adjNode]){
                    // erase if already updated once 
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}