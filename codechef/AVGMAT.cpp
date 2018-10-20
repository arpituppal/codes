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

int arr[310][310];

int main() {

	int t;
	
	scanf("%d", &t);

	while(t--) {

		int n, m, i, j;
		int dist[610] = {0};
		char s[310];

		scanf("%d %d", &n, &m);

		for(i = 0; i < n; i++) {
			
			scanf("%s" ,s);
			int len = strlen(s);

			for(j = 0; j < len ;j++) {
				arr[i][j] = s[j]-'0';
			} 
		}


		for(i = 0; i < n; i++) {
			
			for(j = 0 ; j < m; j++) {


				
			}

		}



	}
	return 0;


}