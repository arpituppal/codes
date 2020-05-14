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

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {

		char s[10000] = {};
		int i, n, k, q, r = 0, l = 0, j, idx = 0;
		
		scanf("%d %d", &n, &k);
		q = n/k;
		r = n%k;

		for(i = 0 ; i < k; i++) {
			for(j = 1; j <= q; j++) {
				l++;
				s[idx++] = (char)(i+97);
			}
		}

		//printf("l = %d n = %d\n",l,n );
		if(l < n) {

			for(j = 1; j <= (n-l); j++) {
				s[idx++] = (char)(97+k-1);
			}
		}

		printf("%s\n", s);
	}

	return 0;
}