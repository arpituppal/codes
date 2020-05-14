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
#define MOD 1000000007

char s1[110], s2[110], res[110];
int hashi[26];

int main() {

	scanf("%s", s1);
	scanf("%s", s2);
	scanf("%s", res);

	int l1, l2, l3, i, flag = 0;
	l1 = strlen(s1);
	l2 = strlen(s2);
	l3 = strlen(res);

	for(i = 0 ; i < l1; i++) {
		hashi[s1[i] - 65]++;
	}


	for(i = 0 ; i < l2; i++) {
		hashi[s2[i] - 65]++;
	}


	for(i = 0 ; i < l3; i++) {
		hashi[res[i] - 65]--;
	}

	for(i = 0 ; i < 26; i++) {
		if(hashi[i] != 0) {
			flag = 1;
			break;
		}
	}

	if(flag == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}


	return 0;
}