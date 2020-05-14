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
#define N 10000000

int prime[10000000];
vector<int> primenum;

void sieve() {

	int i,j;
	prime[0] = prime[1] = 1;
	prime[2] = 0;

	for(i = 2; i *i < N; i++) {

		if(prime[i] == 0) {

			primenum.PB(i);
			for(j = i*i; j < N; j += i) {
				prime[j] = 1;
			}
		}
	}

	for( ; i < N; i++) {
		if(prime[i] == 0) {
			primenum.PB(i);
		}
	}
}

int main() {
	
	int t;
	scanf("%d", &t);
	sieve();

	while(t--) {

		long long n, a = 0, b = 0, c = 0, rem = 1, copyn;
		int flag = 0, i;

		scanf("%lld", &n);
		copyn = n;
		int sz = primenum.size();

		for(i = 0 ;i < sz; i++) {

			LL prod = 1;

			int cnt = 0;

			if(n < primenum[i]) {
				break;
			}

	
			while(n % primenum[i] == 0 && n > 0) {
				cnt++;
				prod*=primenum[i];
				n /= primenum[i];

			}

			if(cnt == 0) {
				continue;
			}

			if(a == 0) {

				a = primenum[i];
				cnt--;

				if(cnt >=2) {
					b = primenum[i] * primenum[i];
					cnt -= 2;
				} else if(cnt != 0){
					rem = primenum[i];
					cnt--;
				}

				while(cnt >0) {
					rem*=primenum[i];
					cnt--;
				}

			} else if(b == 0) {

				b = rem * primenum[i];
				rem = 1;
				cnt--;
				
			} 
		
			if(a != 0 && b!=0 && c== 0) {
				c = copyn/(a*b);


				if(c == a || c == b || c == 1) {
					flag = 0;
				} else {
				flag = 1;
			}
				break;
			}
		}

		if(flag == 0) {
			printf("NO\n");
		} else {
			printf("YES\n");
			printf("%lld %lld %lld\n", a, b, c);
		}
	} 

	return 0;
}