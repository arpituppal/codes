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

char s[110];
int main() {

	scanf("%s", s);
	char lastfound = ' ';
	int l, i, num = 0, lcount = 0;
	l = strlen(s);

	for(i = 0 ; i < l ;i++) {

		if(lastfound == ' ' and s[i] == 'h') {
			num++;
			lastfound = 'h';

		} else if(lastfound == 'h' && s[i] == 'e') {
			num++;
			lastfound = 'e';
		} else if(lastfound == 'e' && s[i] == 'l') {
			num++;
			lastfound = 'l';
			lcount = 1;

		} else if (lastfound == 'l' && s[i] == 'l' && lcount == 1) {
			num++;
			lastfound = 'l';
			lcount = 2;
		} else if(lastfound == 'l' && s[i] == 'o' && lcount == 2) {
			num++;
			lastfound = 'o';
		}

		if(num == 5) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");

	return 0;
}
