#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>

#define send freopen("in.txt", "r", stdin);
#define help freopen("out.txt","w", stdout);

using namespace std;
int n_=0;
 
void dfs(int node, vector<vector<int>>&adjList, vector<bool> &visited, stack <int> &stk){
    if (visited[node]==false){
        //cout<<node<<endl;
        visited[node]=true;
        n_++;
        for (int mem : adjList[node]){
            if (visited[mem]==false) stk.push(mem);
        }
        while( stk.empty()==false ){
            int front = stk.top(); stk.pop();
            dfs(front, adjList, visited, stk);
        }

        return;
    }
    //if (visited[node]==true && stk.empty())
}

int main(){
    send help

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adjList(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int components=0;

    vector <bool> visited (n, false);

    for(int i=0; i<n; i++){
        if (visited[i]==false){
            n_=0;
            cout<<i<<" ";
            stack<int> stk;
            components++;
            dfs(i, adjList, visited, stk);
            cout<<n_<<endl;
        }
    }

    cout<<endl<<components;

    return 0;
}