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

char s[2010];
int numkbefore[2010];
int numkafter[2010];

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		
		vector<int> epos;
		scanf("%s", s);	
		int i, j, l;
		long long int ans = 0;
		l = strlen(s);
		
		if(s[0] == 'K') {
			numkbefore[0] = 1;
		} else {
			numkbefore[0] = 0;
		}
	
		for( i = 1; i < l; i++) {
	
			if(s[i] == 'E') {
				epos.PB(i);
				numkbefore[i] = numkbefore[i-1];
			} else if(s[i] == 'K') {
				numkbefore[i] = numkbefore[i-1] + 1;
			} else {
				numkbefore[i] = numkbefore[i-1];
			}
		}
	
		if(s[l-1] == 'K') {
			numkafter[l-1] = 1;
		} else {
			numkafter[l-1] = 0;
		}
	
		for( i = l -2; i >= 0; i--) {
			 if(s[i] == 'K') {
				numkafter[i] = numkafter[i+1] + 1;
			} else {
				numkafter[i] = numkafter[i+1];
			}
		}
	
		for(i = 0; i < epos.size(); i++) {
			ans += numkbefore[epos[i]] * numkafter[epos[i]];
		}
	
		printf("%lld\n", ans);
	}
	return 0;
}