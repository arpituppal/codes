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

char s[1100], ans[1100];
int hashi[26];

int main() {

	int k, l, i, j = 0, mini = INF;
	scanf("%d", &k);
	scanf("%s", s);

	l = strlen(s);
	for(i = 0 ; i < l; i++) {
		hashi[s[i]-'a']++;
	}

	for(i = 0; i< 26; i++) {

		if(hashi[i] % k != 0) {
			printf("-1\n");
			return 0;
		}

		if(hashi[i] != 0) {
			mini = min(mini,hashi[i]);
			//ans[j++] = (char)(i+97);
		}
	}

	for(i = 0; i < 26; i++) {
		int q = hashi[i]/k;

		if(q != 0) {

			for(int z = 1; z <=q; z++) {
				ans[j++] = (char)(i+97);
			}
		}

	}

	for(i = 1; i <= k; i++) {
		printf("%s", ans);
	}
	
	printf("\n");

	return 0;
}