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
#define MP make_pair
#define PB push_back
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define MOD 1000000007
#define MAX 100005


int main() {

	int n;
	LL i, arr[2*MAX], lt[2*MAX], rt[2*MAX], ans = -1;

	cin>>n;
	for(i = 0 ; i < n; i++) {
		cin>>arr[i];
	}

	for(i = 0 ; i < n; i++) {
		lt[i] = i-2 >= 0 ? arr[i] + lt[i-2] : arr[i];
	}

	for(i = n-1; i >= 0; i--) {
		rt[i] = (i+2) < n ? arr[i] + rt[i+2] : arr[i];
	}

	for(i = 0; i < n; i++) {

		LL sum1 = arr[i], sum2 = arr[i];

		if(i-2 >=0) sum1 += lt[i-2];
		if(i+1 < n) sum1 += rt[i+2];

		if(i-1 >=0) sum2 += lt[i-1];
		if(i+2 < n) sum2 += rt[i+2];

		ans = max(ans, max(sum1, sum2));
	}

	cout<<ans<<endl;
	return 0;

}