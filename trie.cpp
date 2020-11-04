#include<bits/stdc++.h>
using namespace std;
struct node{
    int next[26];
    bool leaf=false;
    node(){
        memset(next,-1,sizeof(next));
    }
};
vector<node> trie(1);
void insert(string s){
    int cur=0;
    for(int i=0;i<s.size();i++){
        int edge=s[i]-'a';
        if(trie[cur].next[edge]==-1){
            trie.push_back(node());
            trie[cur].next[edge]=trie.size()-1;
        }
        cur=trie[cur].next[edge];
    }
    trie[cur].leaf=true;
}
bool dfs(int cur,int i,string s){
        if(i==s.size())return true;
        if(trie[cur].leaf)
            return i==s.size();
        int edge=s[i]-'a';
        if(trie[cur].next[edge]!=-1){
            return dfs(trie[cur].next[edge],i+1,s);
        }
        return false;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    string s;
    cin>>s;
    cout<<dfs(0,0,s);
    
    
}
