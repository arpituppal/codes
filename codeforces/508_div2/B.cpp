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

int main() {

	int n, sz1, sz2;

	cin>>n;

	if(n == 1 || n == 2) {
		printf("No\n");
		return 0;
	}

	sz1 = n/2;
	if(n%2) sz1++;
	sz2 = n - sz1;

	printf("Yes\n");
	printf("%d ", sz1);

	for(int i = 1; i <= n; i+=2) {
		printf("%d ", i);
	}

	printf("\n%d ", sz2);

	for(int i = 2; i <= n; i+=2) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}