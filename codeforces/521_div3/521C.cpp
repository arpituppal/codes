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

vector<pair<LL, int> > vec;  //ele - idx
vector<int> ansidx;

LL cumsum[1000000];

int main() {

	int n, i, ans = 0;
	LL ele;

	scanf("%d", &n);
	for(i = 0; i < n ; i++) {
		scanf("%lld", &ele);
		vec.PB(MP(ele,i));
	}

	sort(vec.begin(), vec.end());

	cumsum[0] = vec[0].first;

	for(i = 1 ; i < n; i++) {
		cumsum[i] = vec[i].first + cumsum[i-1];
	}
	
	//remove last ele
	int remove = vec[n-1].first;
	int removeidx = vec[n-1].second;

	int toform = vec[n-2].first;

	if((cumsum[n-2] - toform) == toform)  {

		ans++;
		ansidx.PB(removeidx+1);
	}


	for(i = n-2; i >=0; i--) {

		remove = vec[i].first;
		removeidx = vec[i].second;

		toform = vec[n-1].first;

		if((cumsum[n-2] - remove) == toform) {
			ans++;
			ansidx.PB(removeidx+1);
		}
	}

	printf("%d\n", ans);

	for(i = 0; i < ansidx.size(); i++) {

		printf("%d ", ansidx[i]);
	}

	printf("\n");

	return 0;
}