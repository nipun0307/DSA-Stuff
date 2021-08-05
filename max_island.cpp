#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

# define send freopen("in.txt", "r", stdin)
# define help freopen("out.txt", "w", stdout)


vector<vector<int>> edges;

void dfs(int node, vector<bool>&visited, int &num){
    if (!visited[node]){

    visited[node]=true;
    num++;
    vector<int> adj=edges[node];
    for(int mem: adj){
        dfs(mem, visited, num);
    }
    return;
    }
    //else return -1;

}

int main(){
    send; help;
    int n; cin>>n;
    // enter the dimension of the matrix
    edges.clear();
    edges.resize(n*n);

    int matrix[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (matrix[i][j]){
                
                if (matrix[i-1][j] && i>=1) edges[(i-1)*n+j].push_back(i*n+j) , edges[i*n+j].push_back((i-1)*n+j) ;
                if (matrix[i][j-1] && j>=1) edges[i*n+j-1].push_back(i*n+j) , edges[i*n+j].push_back(i*n+j-1) ;
            }
        }
    }
    
    for(int i=0; i<n*n; i++){
        cout<<i<<" -> ";
        for(auto mem: edges[i]) cout<<mem<<" "; cout<<endl;
    }

    vector<bool> visited(n*n, false);
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (visited[i*n+j]==false && matrix[i][j]) {
                int tem=0;
                dfs(i*n+j, visited,tem);
                ans=max(ans, tem);
            }
        }
    }
    cout<<ans;
    return 0;
}