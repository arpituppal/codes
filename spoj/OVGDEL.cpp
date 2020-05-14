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


int arr[100000];


int main() {

	int t, x;
	scanf("%d", &t);

	for(x = 1; x <= t; x++) {

		int hashi[1000001] = {0};
		int n, i, maxi = 0, ans = 0;
		LL ele;
		scanf("%d", &n);

		for(i = 0 ; i < n; i++) {
			scanf("%d", &arr[i]);
			hashi[arr[i]]++;
			maxi = MAX(maxi, arr[i]);
		}

		for(i = 0 ; i < n; i++) {
			ele = 1;
			if(arr[i] == 1) {

				if(hashi[1] > 1) {
					ans++;
				}

			} else {

				while(ele <=maxi) {

					if((ele == arr[i] && hashi[ele] > 1) || (ele != arr[i] && hashi[ele] > 0)) { //arr[i] is good
						ans++;
						break;
					}

					ele = ele * arr[i];
				}
			}
		}

		printf("Case %d: %d\n", x, ans);
	}

	return 0;
}