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
#define N 100005


vector<int> fac(int n) {

	vector<int> vec;
	vec.PB(1);

	for(int i = 2; i*i <= n; i++) {
		if(n % i == 0) {
			 vec.PB(i);

			 if(n/i != i) {
			 	vec.PB(n/i);
			 }
		}
	}

	sort(vec.begin(), vec.end());
	return vec;
}



int main() {

	int t;
	cin>>t;
	while(t--) {

		int n, arr[N], mx = -1, i, j, ans[N] = {0};

		cin>>n;

		for(i = 1 ; i <=n ; i++) {
			cin>>arr[i];
		}

		ans[1] = 1;

		for(i = 2; i <=n ;i++) {
			
			mx = 1;

			vector<int> vec = fac(i);

			for(j = 0 ; j < vec.size(); j++) {
				if(arr[i] > arr[vec[j]]) {
					mx = max(mx, ans[vec[j]] + 1);
				}
			}

			ans[i] = mx;
		}

		mx = 1;
		for(i = 1; i<=n; i++) {
			mx = max(mx, ans[i]);
		}

		cout<<mx<<endl;
	}

	return 0 ;
}