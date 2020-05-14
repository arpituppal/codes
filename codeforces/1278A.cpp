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

char p[110], h[110];

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {

		int i, j, lp, lh, flag = 0;
	
		scanf("%s", p);
		scanf("%s", h);


		lp = strlen(p);
		lh = strlen(h);

		sort(p, p + lp);

		if(lh < lp) {
			printf("NO\n");
			continue;
		}

		for(i = 0; i < lh - lp + 1; i++) {

			char tmp[110];
			int idx = 0;
			flag = 0;

			//printf("temp %s\n", tmp);

			for(j = i; j < i+lp; j++) {
			//	printf("inside loop %c\n", h[j]);
				tmp[idx++] = h[j];
			}

			sort(tmp, tmp+lp);

			//printf(" i = %d  p= %s tmp = %s\n",i, p, tmp);

			for(int k = 0 ; k < lp; k++) {

				//printf("Comparing tmp and p %c %c \n", tmp[k], p[k]);
				if(tmp[k] != p[k]) {

	//				printf("Inside wrong match at k %d tmp %c p %c \n", k, tmp[k], p[k]);
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				printf("YES\n");
				break;
			}
		}
		

		if(flag == 1) {	
			printf("NO\n");
		}
	
	}

	return 0;
}