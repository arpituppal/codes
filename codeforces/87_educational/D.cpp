#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long LL;
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

int arr[1000001], que[1000001], n, q;

bool binsearch(int ele) {
	int small = 0, i;

	for(i = 1 ; i <= n; i++) {
		if(arr[i] <= ele) {
			small++;
		}
	}


	for(i = 0 ; i < q; i++) {

		if(que[i] >=0) {
			if(que[i] <= ele) {
				small++;
			} 
		} else {
			if(abs(que[i]) <=small) {
				small--;


			}
		}
	}

	return small > 0;
}

int main() {

	int i;
	scanf("%d %d", &n,&q);

	for(i = 1 ; i <=n;i++) {
		scanf("%d", &arr[i]);
	}

	for(i = 0 ; i < q; i++) {
		scanf("%d", &que[i]);
	}

	int l = 0, r = 1000000, mid, ans = 0;

	while(l<=r) {
		mid = (l+r)/2;

		if(binsearch(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	printf("%d\n", ans);
	return 0;
}