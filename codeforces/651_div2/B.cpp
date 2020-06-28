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
#define MAX 1000000


int main() {

	int t = 1;
	cin>>t;
	while(t--) {

		int n, arr[2010], i, j;
		vector<int> odd, even;

		cin>>n;
		for(i = 0 ; i < 2*n; i++) {
			cin>>arr[i];

			if(arr[i] % 2 == 0) even.PB(i+1);
			else odd.PB(i+1);
		}

		int oddj = 0, evenj = 0, oddn = odd.size(), evenn = even.size();
		for(i = 1; i < n ;i++) {

			if(oddn - oddj >= 2) {
				cout<<odd[oddj]<< " " << odd[oddj + 1]<<endl;
				oddj += 2;
			} else {
				cout<<even[evenj] << " " << even[evenj + 1] << endl;
				evenj += 2;
			}
		}
	}

	return 0;
}