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

queue<pair<pair<LL, LL>, LL> > q;

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {

		LL a, b;
		scanf("%lld %lld", &a, &b);

		q.push(MP(MP(a,b),0));

		while(!q.empty()) {

			LL f = q.front().first.first;
			LL s = q.front().first.second;
			LL l = q.front().second;
			q.pop();

			if(f == s) {
				printf("%d\n",l);
				break;
			}

			q.push(MP(MP(f+l+1,s), l+1));
			q.push(MP(MP(f, s+l+1), l+1));
		}

		while(!q.empty()) {
			q.pop();
		}
	}
}