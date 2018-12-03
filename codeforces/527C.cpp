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

map<string, char> premap;
map<string, char> suffmap;

vector<string> vec[100];
vector<string> inpstrings;


int validate(string s, int n) {

	int i;

	for(i = 1; i <=n - 1; i++) {

		string s1 = vec[i][0];
		string s2 = vec[i][1];

		//find if s1 is prefix
		if(s.substr(0,i).compare(s1) == 0) {

			premap[s1] = 'P';
			//now check if s2 is suffix
			if(s.substr(n-i).compare(s2) != 0) {
				return 0;
			}
			suffmap[s2] = 'S';

		} else if(s.substr(n-i).compare(s1) == 0) {
			//find if s1 is suffix
			suffmap[s1] = 'S';
			//find if s2 is prefix
			if(s.substr(0,i).compare(s2) != 0) {
				return 0;
			}

			premap[s2] = 'P';

		} else {
			return 0;
		}
	}

	return 1;
}

void printtoutput() {

	int i;
	for(i = 0 ; i < inpstrings.size(); i++) {

		if(premap.find(inpstrings[i]) != premap.end()) {
			printf("P");
			premap.erase(premap.find(inpstrings[i]));
		} else {
			printf("S");
			suffmap.erase(suffmap.find(inpstrings[i]));
		}

		//printf("%c", ansmap.find(inpstrings[i])->second);
	}

	printf("\n");
}

int main() {


	set<string> possstrings;


	set<string>::iterator it;

	string s;

	int n, i, l, flag = 0;
	scanf("%d", &n);

	for(i = 0 ; i < (2*n-2) ;i++) {
		cin>>s;
		l = s.length();
		vec[l].PB(s);
		inpstrings.PB(s);
	}

	premap[vec[n-1][0]] = 'P';
	suffmap[vec[1][0]] = 'S';
	suffmap[vec[n-1][1]] = 'S';
	premap[vec[1][1]] = 'P';

	if(n > 2 && validate(vec[n-1][0] + vec[1][0], n) == 1) {
		printtoutput();
		return 0;
	}

	premap.clear();
	suffmap.clear();

	premap[vec[n-1][0]] = 'P';
	suffmap[vec[1][1]] = 'S';
	suffmap[vec[n-1][1]] = 'S';
	premap[vec[1][0]] = 'P';

	if(validate(vec[n-1][0] + vec[1][1], n) == 1) {
		printtoutput();
		return 0;
	}

	premap.clear();
	suffmap.clear();

	premap[vec[n-1][1]] = 'P';
	suffmap[vec[1][0]] = 'S';
	suffmap[vec[n-1][0]] = 'S';
	premap[vec[1][1]] = 'P';
	
	if(validate(vec[n-1][1] + vec[1][0], n) == 1) {
		printtoutput();
		return 0 ;
	}

	premap.clear();
	suffmap.clear();

	premap[vec[n-1][1]] = 'P';
	suffmap[vec[1][1]] = 'S';
	suffmap[vec[n-1][0]] = 'S';
	premap[vec[1][0]] = 'P';
	
	if(n > 2 && validate(vec[n-1][1] + vec[1][1], n) == 1) {
		printtoutput();
		return 0;
	}

	premap.clear();
	suffmap.clear();

	premap[vec[n-1][1]] = 'P';
	suffmap[vec[1][1]] = 'S';
	suffmap[vec[n-1][0]] = 'S';
	premap[vec[1][0]] = 'P';

	if(n > 2 && validate(vec[1][0] + vec[n-1][0], n) == 1) {
		printtoutput();
		return 0;
	}

	premap.clear();
	suffmap.clear();

	suffmap[vec[n-1][1]] = 'S';
	suffmap[vec[1][1]] = 'S';
	premap[vec[n-1][0]] = 'P';
	premap[vec[1][0]] = 'P';

	if(validate(vec[1][0] + vec[n-1][1], n) == 1) {
		printtoutput();
		return 0;
	}

	premap.clear();
	suffmap.clear();

	premap[vec[n-1][1]] = 'P';
	premap[vec[1][1]] = 'P';
	suffmap[vec[n-1][0]] = 'S';
	suffmap[vec[1][0]] = 'S';

	if(validate(vec[1][1] + vec[n-1][0], n) == 1) {
		printtoutput();
		return 0;
	}

	premap.clear();
	suffmap.clear();

	suffmap[vec[n-1][1]] = 'S';
	premap[vec[1][1]] = 'P';
	premap[vec[n-1][0]] = 'P';
	suffmap[vec[1][0]] = 'S';

	if(n > 2 && validate(vec[1][1] + vec[n-1][1], n) == 1) {
		printtoutput();
		return 0;
	}

	return 0;

}