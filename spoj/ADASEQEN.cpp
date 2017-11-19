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

#define N 2005

using namespace std;

LL lcs[N][N];
char s[N], s1[N];
int cost[26];

int main() {
	
	int n, m, i, j;
	
	scanf("%d %d", &n, &m);
	
	for(i = 0; i < 26; i++) {
		scanf("%d", &cost[i]);
	}
	
	scanf("%s", s);
	scanf("%s", s1);
	
	for( i = 0 ; i <= n; i++) {
		
		for(j = 0; j <= m; j++) {
			
			if(i == 0 || j == 0) {
				lcs[i][j] = 0;
				
			} else if(s[i-1] == s1[j-1]) {
				lcs[i][j] = lcs[i-1][j-1] + cost[s[i-1] -'a'];
				
			} else{
				lcs[i][j] = MAX(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
	
	printf("%lld\n", lcs[n][m]);
	return 0;
}
