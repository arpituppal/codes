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

int arr[1000001];

int main() {

	int n, s, k, i, rem = 0, currsum = 0, flag = 0;
	cin>>n>>s;

	if(n == 1 && s != 1) {
		printf("YES\n");
		printf("%d\n", s);
		printf("%d\n", s-1);
		return 0;
	}

	if(n == 1 && s == 1) {
		printf("NO\n");
		return 0;
	}

	for(i = 0 ; i < n; i++) {
		arr[i] = 1;
	}

	k = s/2;
	rem = s-n;
	i = MIN((k-1), (n-1));

	// printf("i = %d rem %d\n", i, rem);
	while(i < n) {

		if(rem < k) {
			printf("NO\n");
			return 0;
		}


		arr[i] += k;
		rem -= k;

		if(s%2 == 1 && arr[i] == (s-k)) {

			if(rem == 0) {
				printf("NO\n");
				return 0;
			}

			arr[i] ++;
			rem--;
		}

		i += k;


	}

	if(rem != 0) {
		arr[n-1] += rem;
	}

	printf("YES\n");
	for(i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n%d\n",k);

	return 0;
}