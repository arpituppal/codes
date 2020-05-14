#include <iostream>
#include<bits/stdc++.h>
#define PB push_back
#define LL long long int

using namespace std;

map<string, LL> mp;
vector<LL> vec;

int main() {

	LL q, k, i;
	LL ans = 0, e;
	
	scanf("%lld %lld", &q, &k);
	
	while(q--) {
		
		string s;
		cin>>s;
		cin>>e;
	
		mp[s] = mp[s] + e;
	}
	
	for(std::map<string, LL>::iterator it = mp.begin(); it != mp.end(); it++) {
		vec.PB(it->second);
	}
	
	sort(vec.begin(), vec.end(), greater<LL>());
	
	for(i = 0; i < vec.size() && k > 0; i++, k--) {
		ans += vec[i];
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
