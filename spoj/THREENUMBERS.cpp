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
#define LIM 20

LL binsearch(LL low, LL high, LL val, LL a, LL b) {
	LL ans;
	LL mid;
	while(low<=high) {
		mid = (low + high) >> 1;
	
		LL adiv = mid/a;
		LL bdiv = mid/b;
	
		LL hcf = __gcd(a, b);
		LL lcm = (a * b) /hcf;
		LL abdiv = mid/lcm;
	
		LL numdiv = adiv + bdiv - abdiv;
	
		//printf("mid %lld adiv %lld bdiv %lld lcm %lld num %lld val %lld\n", mid, adiv, bdiv, lcm, numdiv, val);
	
		if(numdiv >= val) {
			ans = mid;
			high = mid -1;
		}
		 else {
			low = mid + 1;
		}
	}
	return ans;
}

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {
		
		LL a, b, n;
		scanf("%lld %lld %lld" , &a, &b, &n);
		
		printf("%lld\n", binsearch(0, (a*b)*n, n , a, b));
	}
	
	return 0;
}
