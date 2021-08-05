#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){

        int n; cin>>n;

        vector <int> water_lvl(n);
        for(int i=0; i<n; i++) cin>>water_lvl[i];

        /*
        ans declared as follows:
        a certain level at the end is maintained in all the buckets, if we are looking
        for minimum, this level will be maintained by atleast one bucket present in the sequence 
        originally. If not, (that is if the level is less than that), that is not optimum since
        we need not remove from the bucket that was in a sense minimum at the time of computation 
        (as we could have maintained the other buckets at the same level)

        Therefore, we iterate through all the buckets in descending order and if we are ith bucket,
        we see how much water we need to throw to maintain all buckets at the same level.

        */

        sort(water_lvl.begin(), water_lvl.end(), greater<int>()); // descending order

        int total_water=accumulate(water_lvl.begin(), water_lvl.end(), 0);

        // Now when we are at the ith bucket, and let us assume that this is the final level
        // throw the water from all buckets from (i+1) to end
        // then how much water we need to throw?
        // total-water maintained while taking bucket i as final
        // total - ( water[i] + water [i] .... {i+1} times)

        // we will take the minimum of all cases

        int water_thrown=total_water; // considering all water is thrown

        for(int i=0; i<n; i++){
            water_thrown=min(water_thrown , total_water-(water_lvl[i]*(i+1)));
        }

        cout<<"Water thrown is: "<<water_thrown<<endl;

    }

    return 0;
}