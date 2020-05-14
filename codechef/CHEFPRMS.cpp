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

int prime[210], semiprime[210];

int main() {

	int t, i ,j;
	scanf("%d", &t);
	
	prime[1] = 1;

	for(i = 2; i*i<=201; i++) {

		if(prime[i] == 0) {

			for(j = i*i; j<=201; j+= i) {
				prime[j] = 1;
			}
		}
	}

	for(i = 2; i<=201; i++) {

		if(prime[i] == 0) {

			for(j = 2; j < i; j++) {
				
				if(prime[j] == 0 && i*j<=200) {
					semiprime[i*j]++;
				}
			}
		}
	}

	while(t--) {

		int n, flag = 0;

		scanf("%d", &n);

		for(i = 1; i<=n/2; i++) {

			//printf("i = %d n-i = %d semiprime[i] = %d semiprime[n-i] = %d\n", i, (n-i), semiprime[i], semiprime[n-i]);
			if(semiprime[i] == 1 && semiprime[n-i] == 1) {
				flag = 1;
				break;
			}
		}

		if(flag == 1) {
			printf("YES\n");
		}else {
			printf("NO\n");
		}

	}

	return 0;

}