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

vector<string> arr;


int main() {

	LL n;

	arr.PB("Asad");
	arr.PB("Foyj");
	arr.PB("Juwel");
	arr.PB("Mijan");
	arr.PB("Tanmay");
	
	while(scanf("%lld", &n) != EOF) {
		int i, num = 5, p = 0;

		while(num < n) {
			n -= num;
			num *= 2;
			p++;
		}

		LL power2 = pow(2, p);
		int idx = 0;

		while(power2 < n) {

			n = n - power2;
			idx++;
		}

		cout<<arr[idx]<<endl;
	}

	return 0;
}