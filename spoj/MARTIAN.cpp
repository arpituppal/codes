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

int yey[505][505], blo[505][505];
LL dp[505][505];
LL sumy[505][505], sumb[505][505];


int main() {
	
	int n, m, i, j;
	
	while(1) {
		
		scanf("%d %d", &n, &m);
		LL ans = 0;
		
		if(n == 0 && m == 0)
			break;
			
		for(i = 1; i <= n; i++) {
			for(j = 1; j <=  m; j++)
				scanf("%d", &yey[i][j]);
		}
		
		for(i = 1; i <=n; i++) {
			for(j = 1; j <=m; j++)
				scanf("%d", &blo[i][j]);
		}
	
		for(i = 0 ; i<=m; i++){
			dp[0][i] = 0;
			sumy[0][i] = 0;
			sumb[0][i] = 0;
		}
		
			
		for(i = 0 ; i<=n; i++){
			dp[i][0] = 0;
			sumy[i][i] = 0;
			sumb[i][0] = 0;
		}
		
		for(i = 1; i<=n;i++){
			for(j= 1; j<=m; j++){
				
				sumb[i][j] = sumb[i-1][j] + blo[i][j];
				sumy[i][j] = sumy[i][j-1] + yey[i][j];
				dp[i][j] = max(dp[i-1][j] + sumy[i][j], dp[i][j-1] + sumb[i][j]);
			}
		}
		
		printf("%lld\n", dp[n][m]);
	}

	return 0;
}
