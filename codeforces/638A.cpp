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


int main() {


	long long int arr[31];
	int i, n, t;
	

	arr[0] = 2;


	for(i = 1 ; i < 30; i++) {
		arr[i] = arr[i-1] * 2;
	}

	scanf("%d", &t);
	while(t--) {
		long long int diff = 0;
		long long int pile1 = 0, pile2=0;
		scanf("%d", &n);

		for(i = n-1; i>0; i -=2) {

			if(pile1 == pile2 || pile1 < pile2) {
				//("YES i =%d arr[ = %lld ", i , arr[i]);
			pile1 += arr[i];
			pile2 += arr[i-1];
			//printf("%lld %lld\n",pile2, pile1);
		} else if(pile2 < pile1) {
			//printf("YES\n");
			pile1 += arr[i-1];
			pile2 += arr[i];
		}
	}	

	printf("%lld\n", ABS((pile2 - pile1)));
}

	return 0;
}