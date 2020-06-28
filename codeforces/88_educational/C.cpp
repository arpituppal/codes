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

		LL h, c, t, ans;
		cin>>h>>c>>t;

		if(t == h) {
			cout<<1<<endl;
			continue;
		}

		if(t<= (h+c)/2) {
			cout<<2<<endl;
			continue;
		}

		//ideal -- k+1 hot cups and k cold cups becomes equal to t
		//ans = no. of cold cups; ans+1 = no. of hot cups
		ans = floor((t-h)/(h + c - 2*t));

		//check if adding 1 more pair of hot and cold makes ans closer to t
		LL lhs = abs((2*ans + 3) * (ans * (h + c) + h - t* (2 * ans + 1)));
		LL rhs = abs((2*ans + 1) * ((ans + 2) * h + (ans + 1) * c - 2 * ans * t - 3*t));

		if(lhs > rhs) {
			ans++;
		}

		cout<<2*ans+1<<endl;
	} 

	return 0;
}