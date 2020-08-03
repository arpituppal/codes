#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MSV(A,a) memset(A, a, sizeof(A))
#define MP make_pair
#define PB push_back
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
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

int main() {

    int n, i, m, mxans = -1, ans = 0, sz, ngvirus = 0, ncvirus = 0;
    string virus, vaccine;

    cin>>n;
    cin>>m;
    cin>>virus;

    for(i = 0; i < m; i++) {
        if(virus[i] == 'C') ncvirus++;
        if(virus[i] == 'G') ngvirus++;
    }

    for(int x = 1; x <= n; x++) {

        cin>>sz;
        cin>>vaccine;
        int ngvaccine = 0, ncvaccine = 0;

        for(i = 0 ; i < sz; i++) {
            if(vaccine[i] == 'G') ngvaccine++;
            if(vaccine[i] == 'C') ncvaccine++;
        }

        if(ngvaccine*ncvirus + ncvaccine*ngvirus > mxans) {
            mxans = ngvaccine*ncvirus + ncvaccine*ngvirus;
            ans = x;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
