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

	LL n, arr[1000000], sum = 0, i, mini = INFL;
	bool positive = false, negative = false;

	scanf("%lld", &n);

	for(i = 0 ; i < n; i++) {
		scanf("%lld", &arr[i]);
		sum += abs(arr[i]);
		mini = min(mini, abs(arr[i]));
		positive = positive || (arr[i] >=0);
		negative = negative || (arr[i] < 0);
	}

	if(n == 1) {
		cout<<arr[0]<<endl;
		return 0;
	}

	if(positive && negative) {
		cout<<sum<<endl;
	} else {
		cout<<(sum-2*mini)<<endl;
	} 

	return 0;
}