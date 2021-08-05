#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);
    #endif

    int t; cin>>t; 
    while(t--){

        long long n; cin>>n;
        long long inp[n];
        for(long long i=0; i<n; i++) cin>>inp[i];
        
        long long max_till_i=0;
        long long min_till_i=0;
        // max till i stores the maximum subarray sum computed till the ith element
        // min stores the minimum element till the ith element
        // still max and min are both parts of the array, we initialise them as:
        max_till_i=min_till_i=inp[0];

        long long ans=max((long long)0, inp[0]); // stores the answer in every iteration
        // Now using Kadane's algorithm:

        // taking the answer till the ith element

        for(long long i=1; i<n; i++){
            if (max_till_i<0){ // the max is negative
                max_till_i = inp[i]; // try this element (as total sum <0, delete the sum and just take this element)
                min_till_i = max_till_i;
            }
            else {  // if the max sum is positive,
                max_till_i+=inp[i];
                min_till_i=min(min_till_i,inp[i]); // take the most negative element
            }

            ans= max(ans, max_till_i);
            ans=max(ans, max_till_i-min_till_i); // the required deletion from subarray
                                                // (should we delete or not)
            
        }

        if (ans==0){    // for this, every element has to be negative, as ans=max(ans,...) and initially ans =0;

            ans=*max_element(inp, inp+n);

        }
        cout<<ans<<endl;




    }


    return 0;
}