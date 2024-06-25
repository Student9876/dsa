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
    https://www.geeksforgeeks.org/problems/word-ladder-ii/1
    https://leetcode.com/problems/word-ladder-ii/description/ (MLE with this code)

    Word Ladder II

    Time complexity for this varies, cannot be said exactly. Because there can be multiple
    possible paths to reach the end word.
*/


class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        
        int level = 0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            // Erase all the words that has been 
            // used on the previous level 
            if(vec.size() > level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
            }
            
            
            // storing the ans
            string word = vec.back();
            if(word == endWord){
                // if the first sequence we reached end 
                if(ans.size() == 0){
                    ans.push_back(vec);
                } else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            
            
            for(int i = 0;i<word.size();i++){
                char original = word[i];
                
                for(char ch = 'a';ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        // mark the word as visited 
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
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