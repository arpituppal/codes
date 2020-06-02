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

int main() {

	int t;
	cin>>t;
	while(t--) {

		int n,i, arr[1010], hashi[1010]={0}, end[1010]={0}, flag = 0, maxi = -1;
		vector<int> vec;

		cin>>n;
		
		for(i = 0; i < n ;i++) {
			cin>>arr[i];
			hashi[arr[i]]++;
			maxi = max(maxi, arr[i]);
		}

		for(i = 1; i <= maxi; i++) {
			if(hashi[i] > 0) {
				vec.PB(hashi[i]);
			}
		}


		sort(vec.begin(), vec.end());

		for(i = 1; i < n; i++) {

			if(arr[i] != arr[i-1]) {
				end[arr[i-1]] = 1;
				if(end[arr[i]]) {
					flag = 1;
					break;
				}
			}
		}

		if(flag == 0) {
			for(i = 1; i < vec.size(); i++) {

				if(vec[i] == vec[i-1]) {
					flag = 1;
					break;
				}

			}
		}

		if(flag) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}

	}

	return 0;
}