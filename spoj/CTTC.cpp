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

int arr[1000];

int main() {

	int t, x;
	scanf("%d", &t);
	for(x = 1 ; x <= t; x++) {

		stack<int> stk;
		int successor[100], ans[1000] = {0}, i, n;
		scanf("%d", &n);

		for(i = 0 ; i < 2*n; i++) {
			scanf("%d", &arr[i]);
		}

		stk.push(arr[0]);

		for(i = 1 ; i < 2*n; i++) {

			if(arr[i] != stk.top()) {
				stk.push(arr[i]);

			} else {
				stk.pop();

				if(i != (2*n - 1)) {
					ans[stk.top()]++;
				}
			}
		}

		printf("Case %d:\n", x);
		for(i = 1 ; i <= n; i++) {
			printf("%d -> %d\n",i, ans[i]);
		}

	}

	return 0;

}