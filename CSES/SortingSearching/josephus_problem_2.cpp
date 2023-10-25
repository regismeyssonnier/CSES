#include<bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<'>'<< #v <<':';for(auto ii:v)cout<<ii<<' ';cout<<endl;
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


void run_case(){
	//taking input
	int n,k;
	cin>>n>>k;
	
	//using policy based data structure for ordered set
	ordered_set<int> oset;
	
	//inserting values in the set
	for(int i=1;i<=n;i++)oset.insert(i);
	
	//setting initial position
	int pos=k%n;
	
	//printing values until set is not empty
	while(!oset.empty()){
		
		//finding value at pos'th position
		int val = *oset.find_by_order(pos);
		
		//deleting this value
		oset.erase(val);
		
		//printing the value
		cout<<val<<' ';
		
		//finding next position
		if(!oset.empty()){
			pos=(pos+k)%oset.size();
		}
	}
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
while(tc--)run_case();
return 0;
}

/*
set[3],
set.find_by_order(4)

1 2 3 5 6

find_by_order(x) : return iterator to the number x in log n time
order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.

k =2, n = 7
pos = 2
1 2 4 5 6 7
pos = (2+2)%6 = 4
1 2 4 5 7
pos = (4+2)%5 = 1
1 4 5 7
pos = (1+2)%4 =3
1 4 5
pos = (3+2)%3 = 2
1 4
pos = (2+2)%2 = 0
4
pos = (0+2)%1 = 0

O(n2)
3 6 2 7 5 1 4
*/
