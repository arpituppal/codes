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

int arr[N];
vector<int> primes;

int main() {

	int t;
	cin>>t;

	while(t--) {

		LL n, k, ans = 0;
		int flag = 0;
		cin>>n>>k;

		if(k == 1) {
			cout<<n<<endl;
			continue;
		}

		if(n <= k) {
			printf("1\n");
		} else {	

			if(n % k == 0) {
				printf("%lld\n", (n/k));

			} else {



				int mini = n;
				for(int i = 2 ; i*i<=n ;i++) {
					if(n % i == 0 && i<=k ) {
						mini = MIN(mini, (n/i));
					}

					int q = n/i;
					if (n % i == 0 && q <=k) {
						mini = MIN(mini,n/q);
					}
				}

				cout<<mini<<endl;
			}
		}
	}

	return 0;
}