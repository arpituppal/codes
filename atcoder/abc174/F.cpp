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
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
#define finish(x) {cout<<x<<'\n'; return;}
  
const int MAX = 500005; 
  
struct Query 
{ 
    int l, r, idx; 
}; 
  
bool cmp(Query x, Query y) 
{ 
    return x.r < y.r; 
} 
  
void update(int idx, int val, int bit[], int n) 
{ 
    for (; idx <= n; idx += idx&-idx) 
        bit[idx] += val; 
} 
  
int query(int idx, int bit[], int n) 
{ 
    int sum = 0; 
    for (; idx>0; idx-=idx&-idx) 
        sum += bit[idx]; 
    return sum; 
} 
  
void solve(int arr[], int n, Query queries[], int q) 
{ 
    int bit[MAX]; 
    memset(bit, 0, sizeof(bit)); 
  
    int lvisit[MAX]; 
    MSV(lvisit, -1); 
  
    int ans[q]; 
    int query_counter = 0; 
    for (int i=0; i<n; i++) 
    { 
        if (lvisit[arr[i]] !=-1) 
            update (lvisit[arr[i]] + 1, -1, bit, n); 
  
        lvisit[arr[i]] = i; 
        update(i + 1, 1, bit, n); 
  
        while (query_counter < q && queries[query_counter].r == i) 
        { 
            ans[queries[query_counter].idx] = 
                     query(queries[query_counter].r + 1, bit, n)- 
                     query(queries[query_counter].l, bit, n); 
            query_counter++; 
        } 
    } 
  
    for (int i=0; i<q; i++) 
        cout << ans[i] << '\n'; 
} 
  
int main() 
{ 
    int n, q;
    scanf("%d %d", &n, &q);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    
    Query queries[q];
    for(int i=0;i<q;i++) {
        int ql, qr;
        scanf("%d %d", &ql, &qr);
        queries[i].l = ql-1;
        queries[i].r = qr-1;
        queries[i].idx = i; 
    }
    
    sort(queries, queries+q, cmp); 
    solve(a, n, queries, q); 
    return 0; 
}