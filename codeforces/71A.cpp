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

	int n, i;
	char s[110];
	char s1[110];
	
	string str;
	string outstr;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		
		cin>>str;
		
		int l = str.length();
		//scanf("%s", s);
		//int l = strlen(s);
		//printf("%d\n", l);
		
		if(l <= 10) {
			outstr = str;
			//strcpy(s1,s);
		} else {
		
			cout << l-2 <<endl;
			outstr = str.at(0);
			//outstr = str.at(0) + (l-2) + str.at(l-1);
			//s1[0] = s[0];
			//s1[1] = l-2 - 48;
			//s1[2] = s[l-1];
			//s1 = s[0] + (l-2 +48) + s[l-1];
		}
		
		cout<<outstr;
		
		//printf("%s\n", outst);
	}
	
	return 0;
	
}
