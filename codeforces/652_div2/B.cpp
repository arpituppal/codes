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

	int t;
	cin>>t;
	while(t--) {

		int n, i, lt1[MAX], rt0[MAX], j = 0;
		char s[MAX];

		cin>>n;
		scanf("%s", s);

		rt0[n-1] = 0;
		for(i = n-2; i>=0; i--) {

			if(s[i+1] == '0') rt0[i] = 1;
			else rt0[i] = rt0[i+1];
		}

		lt1[0] = 0;
		for(i = 1 ; i < n ; i++) {
			if(s[i-1] == '1') lt1[i] = 1;
			else lt1[i] = lt1[i-1];
		}

		for(i = 0 ; i < n ; i++) {

			if(s[i] == '1') {
				if(!rt0[i]) cout<<s[i];
			} else {
				if(!lt1[i] || !rt0[i]) cout<<s[i];
			}
		}

		cout<<endl;
	}

	return 0;
}