#include <bits/stdc++.h>
#define LL long long int
#define MAX(a, b) (a) > (b) ? (a) : (b)

using namespace std;

LL arr[25], m, ans = 0, mx = -1;
int n;

int findAns(int i, LL ans) {
	//printf("i = %d\n", i);

	if(mx == m) {
	
		return mx;
	}
	
	if(i == n-1) {
		if(arr[i] + ans <=m) {
			mx = MAX(mx, arr[i] + ans);
		} else {
			mx = MAX(mx, ans);
		}
	}
	
	
	if(arr[i] + ans <= m) {
		//printf("%d %d \n", arr[i], ans);
		LL a= 0, b= 0;
		if(i + 1 <n) { 
			a = findAns(i+1, arr[i] + ans);
			b = findAns(i+1 , ans);
		}
		mx = MAX(mx, MAX(a,b));
	} else{
		LL a= 0;
		if(i+1 <n) a = findAns(i+1, ans);
		mx = MAX(mx, a);
	}
	
	return mx;
}

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {
		ans= 0;
		mx = -1;
		int i;
	
		scanf("%d %lld", &n, &m);
		
		for(i = 0 ; i < n ; i++) {
			scanf("%d", &arr[i]);
		}
		
		findAns(0, 0);
		printf("%lld\n", mx);
	}

	return 0;
}
