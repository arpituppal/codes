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

int main() {

	int n, arr[100001], ans = 0, evehash[100001] = {0}, oddhash[100001]= {0}, i;
	int evemax = -1, evemaxnum, evesecmax = -1, evesecmaxnum, oddmax = -1, oddmaxnum, oddsecmax = -1, oddsecmaxnum;

	cin>>n;
	
	for(i = 0 ; i < n ; i++) {
		cin>>arr[i];

		if(i % 2) {
			oddhash[arr[i]]++;
		} else {
			evehash[arr[i]]++;
		}
	}

	for(i = 0 ; i < 100001; i++) {

		if(evehash[i] >= evemax) {

			evesecmax = evemax;
			evesecmaxnum = evemaxnum;
			evemax = evehash[i];
			evemaxnum = i;
		} else if (evehash[i] > evesecmax) {
			evesecmax = evehash[i];
			evesecmaxnum = i;
		}

		if(oddhash[i] >= oddmax) {

			oddsecmax = oddmax;
			oddsecmaxnum = oddmaxnum;
			oddmax = oddhash[i];
			oddmaxnum = i;
		} else if (oddhash[i] > oddsecmax) {
			oddsecmax = oddhash[i];
			oddsecmaxnum = i;
		}
	}

	if(evemaxnum != oddmaxnum) {
		ans = n - evehash[evemaxnum] - oddhash[oddmaxnum];
	} else {
		ans = min(n - evehash[evemaxnum] - oddhash[oddsecmaxnum], n - evehash[evesecmaxnum] - oddhash[oddmaxnum]);
	}

	cout<<ans<<endl;

	return 0;
}