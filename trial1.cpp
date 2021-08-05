#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


int main() {
	vector<string> vec = {"Arya", "Samiksha", "Nipun", "Aditya", "Ruchit", "Sresth", "Rohit", "Kankshi", "Tanvi", "Riya"};
	
	map <string, bool> mp;
	int ran= rand()%(vec.size());
	string top;
	int i=0;
	cout<<"\nPrinting Cyclic Permutation\n";
	while(i<vec.size()){
		if (i==0) top=vec[ran];
		if (mp[vec[ran]]==false){
		mp[vec[ran]]=true;
		cout<<vec[ran]<<" -> ";
		i++;
		}
		ran=rand()%vec.size();
	}
	cout<<top<<endl;

	return 0;
	
}
