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
	int n, t, x;
	cin>>t;
	while(t--) {
		cin>>n>>x;
		int a[n];
		int even = 0, odd = 0;
		for(int i=0;i<n;i++) {
			cin>>a[i];
			if(a[i]&1) odd++;
			else even++;
		}
		
		if(odd == 0) {cout<<"No"<<endl; continue;}
		
		if(odd%2 == 0) odd--;
		if(x % 2 == 0) {
			x -= min(x-1, odd);
		} else {
			x-=(odd);
		}
		bool ans = (even>=x);
		
		if(ans) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
    return 0;
}