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

	int n, r = 0;
	scanf("%d", &n);
	// while(n > 0) {
	// 	r = (r*10) + (n%10);
	// 	n /= 10;
	// } 

	int dig = n%10;
	if(dig == 0 || dig == 1|| dig == 6|| dig == 8) {
		printf("pon\n");
	}  else if(dig == 2 || dig == 4|| dig == 5|| dig == 7|| dig == 9) {
		printf("hon\n");
	} else {
		printf("bon\n");
	}

	return 0;
}