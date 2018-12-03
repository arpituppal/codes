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

stack<int> stk, minstk;

string ip()
{
    string i="";
    int temp=getchar_unlocked();
    while(temp<'A'||temp>'Z')
        temp=getchar_unlocked();
    while(temp>='A'&&temp<='Z')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}

int main() {

	int n, i, m;
	//string s;
	char s[10];

	scanf("%d", &n);
	while(n--) {
		//s = ip();
		scanf("%s",s);
		if(s[0] == 'P') {

			if(s[1] == 'U') {
				scanf("%d", &m);
				stk.push(m);

				if(minstk.empty() || m < minstk.top()) {
					minstk.push(m);
				} else {
					minstk.push(minstk.top());
				}
					

			} else {
				if(stk.empty()) {
					printf("EMPTY\n");
				} else {
					stk.pop();
					minstk.pop();
				}
			}

		} else if(s[0] == 'M') {

			if(minstk.empty()) {
				printf("EMPTY\n");
			} else {
				printf("%d\n",minstk.top());
			}
		}
	}

	return 0;
}