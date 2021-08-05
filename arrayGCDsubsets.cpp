#include <iostream>
#include <vector> 
#include <utility>
#include <algorithm>

using namespace std;

int res = 0;

int gcd (int a, int b){
    if(b%a==0) return a;
    return gcd(min(a,b-a),max(a,b-a));

}

void get_count(int next, int curr_gcd, vector<int> &v, int count){
    cout<<"next: "<<next<<" gcd: "<<curr_gcd<<" count: "<<count<<endl;
    cout<<"res: "<<res<<endl;
    if(curr_gcd>1) res+= curr_gcd*count;
    cout<<"res now: "<<res<<endl;
    for(int i=next; i<v.size(); i++){
        int d = gcd(min(curr_gcd,v[i]),max(curr_gcd,v[i]));
        if(d>1) get_count(i+1,d,v,count+1);
    }
}

int main(){

    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int tem; cin>>tem;
        v.push_back(tem);
    }
    res = 0;
    for(int i=0; i<n ;i++) get_count(i+1, v[i], v, 1);
    cout<<res<<endl;
    return 0;
}