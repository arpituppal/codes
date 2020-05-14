#include <iostream>
#include<bits/stdc++.h>
#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define LL long long int

using namespace std;


int main() {

	int t;
	scanf("%d", &t);
	while(t--) {
		
		LL n, i, val, mx = -1;
		LL m, ans = 0;
		
		int hash[100010] = {0};
		
		scanf("%lld", &n);
		
		for(i = 0; i < n ; i++) {
			scanf("%lld", &val);
			hash[val]++;
			mx = MAX(mx, val);
			
		}
		
		scanf("%lld", &m);
		
		for(i = mx; i >0 && m >0 ; i--) {
			
			LL spend = MIN(m, 1LL*hash[i]);
			
			ans += (spend * i);
			m -= spend;
			hash[i] -= spend;
			hash[i-1] += spend;
		}
		
		printf("%lld\n", ans);
	}

	return 0;
}
