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
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define MOD 1000000007
#define MAX 10000001

int arr[500005];
int primes[MAX], factor[MAX];

void sieve() {

	int i, j;

	for(i = 2; i * i < MAX; i++) {
		if(primes[i] == 0) {
			for(j = i * i; j < MAX; j+=i) {
				
				primes[j] = 1;

				if(!factor[j]) factor[j] = i;
			}
		}
	}
}

int main() {

	int n,i, numprimes = 0;
	
	vector<int> firstnum;
	vector<int> secondnum;
	sieve();

	scanf("%d", &n);

	for(i = 0 ; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for(i = 0 ; i < n; i++) {

		if(!primes[arr[i]]) {
			firstnum.PB(-1);
			secondnum.PB(-1);
			continue;
		}

		int fac = 1, num = arr[i];

		while(num % factor[arr[i]] == 0) {
			num /= factor[arr[i]];
			fac *= factor[arr[i]];
		}

		if(num > 1) {
			firstnum.PB(num);
			secondnum.PB(fac);
		} else {
			firstnum.PB(-1);
			secondnum.PB(-1);
		}
	}

	for(i = 0; i < n; i++) {
		printf("%d ", firstnum[i]);
	}

	printf("\n");

	for(i = 0; i < n ; i++) {
		printf("%d ", secondnum[i]);
	}

	printf("\n");

	//printf("done \n" );
	return 0;
}