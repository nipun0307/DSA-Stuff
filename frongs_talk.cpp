#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

bool compare (const pair<int,int>&p1, const pair<int,int>&p2){
    return (p1.first<p2.first);
}

int find_parent(vector<int>& parent, int a){
    if (parent[a]==a) return a;
    else return parent[a]= find_parent(parent, parent[a]);
}

void do_union (vector<int> &parent, int a, int b, vector<int> &size){
    if(parent[a]==parent[b]) return;

    // when two frogs can talk, they are united in a set. the set name is the
    // smaller frog number. the function is passed the frog number

    int parent_a=find_parent(parent,a);
    int parent_b=find_parent(parent,b);

    if(size[parent_a]>size[parent_b]){
        parent[b]=parent_a;
    }
    else if (size[parent_a]<size[parent_b]){
        parent[a]=parent_b;
    }
    else {
        if(a<b){
            parent[b]=parent_a;
            size[parent_a]++;
        }
        else{
            parent[a]=parent_b;
            size[parent_b]++;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen ("in.txt","r", stdin);
        freopen ("out.txt","w",stdout);
    #endif

    int n,k,p;
    cin>>n>>k>>p;

    vector<pair<int,int>> frog(n);
    vector<int> parent(n+1);
    vector<int> size(n+1);

    for(int i=0; i<n ; i++){
        cin>>frog[i].first;
        frog[i].second=i+1;
        parent[i+1]=i+1;
        size[i+1]=1;
    }
    
    sort(frog.begin(), frog.end(), compare);

    // for(auto i: frog){
    //     cout<<i.first<<"   "<<i.second<<endl;
    // }
    // cout<<endl;

    // for(int i=1; i<=n; i++){
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl<<endl;

    for (int i=0; i<n-1; i++){
        // two frogs can talk if their distance is less than or equal to k
        if (frog[i+1].first-frog[i].first<=k) do_union(parent, frog[i+1].second, frog[i].second, size);
    }
    int f1, f2;

    // for(int i=1; i<=n; i++){
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl<<endl;

    for(int i=0; i<p; i++){
        cin>>f1>>f2;
        if(find_parent(parent, f1)==find_parent(parent, f2)) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}