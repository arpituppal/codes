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
#define MAX 200005

int main() {

	LL n, x, arr[2*MAX], sum = 0, mx = -1, i, j ,rem;
	cin>>n>>x;

	for(i = 0 ; i < n; i++) {
		cin>>arr[i];
		arr[i+n] = arr[i];
	}

	i = 2*n-1, j = 2*n-1, rem = x, sum = 0;

	while(i >= 0 && j>=0) {

		if(arr[j] >= rem) {
			sum += ((arr[j] * (arr[j] +1)/2) - ((arr[j]-rem) * (arr[j]-rem+1)/2));
	
			mx = max(mx, sum);

			if(arr[j] == rem || i == j) {
				

				if(i == j && arr[j] != rem) {
					sum -= (arr[i] * (arr[i]+1))/2 - ((arr[j]-rem) * (arr[j]-rem+1)/2);
				} else {
					sum -= (arr[i] * (arr[i]+1))/2;
				}

				rem = rem - arr[j] + arr[i];
				j--;
				i--;
			} else {
				sum -= (arr[i] * (arr[i]+1))/2;
				sum -= ((arr[j] * (arr[j] +1)/2) - ((arr[j]-rem) * (arr[j]-rem+1)/2));
				rem += arr[i];
				i--;
			}

			continue;
		}

		sum +=  (arr[j] * (arr[j]+1))/2;
		rem -= arr[j];
		j--;
	}


	cout<<mx<<endl;
	return 0;
}	