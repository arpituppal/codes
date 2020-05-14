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
#define LIM 100005

stack<int> stk;

int main() {
		
	int t;
	scanf("%d", &t);
	while(t--) {
		
		int n, i, val, top, ans = 0;
		scanf("%d", &n);
		int deg[LIM] = {0};
		
		scanf("%d", &val);
		stk.push(val);
		
		for(i = 1; i < 2*n; i++) {
			
			scanf("%d", &val);
			
			if(val == stk.top()) {
				stk.pop();
			} else {
				deg[stk.top()]++;
				deg[val]++;
				stk.push(val);
			}
		}
		
		for(i = 1; i <= n; i++) {
			ans = MAX(ans, deg[i]);
		}
		
		while(!stk.empty()) {
			stk.pop();
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}