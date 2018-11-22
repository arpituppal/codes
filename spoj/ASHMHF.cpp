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

	int t, x;

	scanf("%d", &t);

	for(x = 1; x <= t; x++) {

		int n, i;

		vector<pair<LL, int> > left(100005);
		vector<pair<LL, int> > right(100005);
		vector<pair<LL, int> > vec;
		
		LL num, mini = -1, minidx = -1;

		scanf("%d", &n);

		for(i = 0; i < n; i++) {

			scanf("%lld", &num);
			vec.PB(MP(num,i));
		}

		sort(vec.begin(), vec.end());

		left[0] = MP(0, vec[0].second);
		right[n-1] = MP(0, vec[n-1].second);

		for(i = 1; i < n; i++) {
			left[i] = MP((left[i-1].first + (i * (vec[i].first - vec[i-1].first))), vec[i].second);
		}

		for(i = n - 2; i >= 0; i--) {
			right[i] = MP((right[i+1].first + (n-i-1)*(vec[i+1].first - vec[i].first)), vec[i].second);
		}

		mini = left[0].first + right[0].first;
		minidx = left[0].second;

		for(i = 0 ; i < n; i++) {

			LL sum = left[i].first + right[i].first;
			//cout<< "sum "<< sum << " mini " << mini << " " 

			if(sum < mini) {

				mini = sum;
				minidx = left[i].second;
			} else if(sum == mini && left[i].second < minidx) {
				minidx = left[i].second;
			} 
		}

		printf("Case %d: %lld\n", x, (minidx + 1));

	}

	return 0;
}

