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


int a[1000010], b[1000010];

int main() {

	int t;
	scanf("%d", &t);

	while(t--) {

		int i, n, flag = 0;
		scanf("%d", &n);

		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		for(i = 0 ; i < n; i++) {
			scanf("%d", &b[i]);
		}

		for(i = n-1; i >=2; i--) {

			if(b[i] == a[i]) continue;

			if((b[i] - a[i]) % 3 == 0) {
				int numops = (b[i] - a[i])/3;

				a[i] = a[i] + 3*numops;
				a[i-1] += 2*numops;
				a[i-2] += 1*numops;

			} else {
				flag = 1;
				break;
			}
		}

		for(i = 0 ; i < n;i++) {
			if(a[i] != b[i]) {
				flag = 1;
				break;
			}
		}


		if(flag == 0) {
			printf("TAK\n");
		} else {
			printf("NIE\n");
		}
	}

	return 0;
}