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


double pi = std::acos(-1);

int main() {

	int a,b,h,m;
	cin>>a>>b>>h>>m;

	double hangle = 0.5 * (h * 60 + m);  
    double mangle = 6 * m;  
    double angle = ABS((hangle - mangle));  

	angle = min(360 - angle, angle);  

	double cosine = cos(angle*pi/180);
	
 	double l = a*a + b*b - 2*a*b*cosine;
 	double ans = sqrt(l);
 	printf("%0.11lf\n", ans);

 	return 0;

}