#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int find_parent (vector <int>&parent, int a){
    if (parent[a]==a) return a;
    else return parent[a]=find_parent(parent, parent[a]);
}

void do_union (vector <int>&parent, vector<int>&size, int a, int b){
    int par_a=find_parent(parent,a), par_b=find_parent(parent, b);
    if (par_a==par_b) return;

    if (size[par_a]>size[par_b]){
        parent[par_b]=par_a;
    }
    else if (size[par_b]>size[par_a]) parent[par_a]=par_b;
    else {
        if (par_a<par_b){
            parent[par_b]=par_a;
            size[par_a]++;
        }
        else{
            parent[par_a]=par_b;
            size[par_b]++;
        }
    }

}

int num_comps (vector<vector<int>> &adjm){

    int n=adjm.size();
    vector<int> parent(n), size(n);
    for(int i=0; i<n; i++) {parent[i]=i; size[i]=1;}

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if (adjm[i][j]==1){
                do_union(parent, size, i, j);
            }
        }
    }

    for(auto mem : parent) cout<<mem<<" ";
    cout<<endl;

    map <int, bool> A;

    int count=0;
    for(int i=0; i<n; i++){
        parent[i]=find_parent(parent, parent[i]);
        if (A[parent[i]]==0){
            A[parent[i]]=1;
            count++;
        }
    }

    return count;

}

int main(){
    int n;
    cin>>n;
    
    vector <vector<int>> adjm (n, vector<int>(n,0));

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++) cin>>adjm[i][j];
    // }

    int u, v;
    cout<<"Enter number of edges: "; int k;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>u>>v;
        adjm[u][v]=adjm[v][u]=1;
    }

    int ans= num_comps(adjm);
    cout<<ans;


    return 0;
}