#include <bits/stdc++.h>
#define _ ios_base:sync_with_stdio(0);cin.tie(0);
using namespace std;
/*** typedef ***/
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;
/** function **/
#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define print(x) pf("%d ", x)
#define println(x) pf("%d\n", x)
#define sf scanf
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define MAX 1000000
#define MM 300000

int ans[MM + 1]= {0}, last[MAX];
bool vis[MAX] = {false}, isp[MAX]= {false};
const int dir[][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int p[MAX], c, cnt = 0;

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int findnext(int n) {
    for(int i = 3; ; i++) {
        if(!vis[i] && gcd(i, n) != 1)
            return i;
    }
}

int solve(int n) {
    int position = INF;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }
            while(i * last[i] < MAX && vis[i * last[i]]) {
                last[i]++;
            }
            if(i * last[i] < position)
                position = i * last[i];
            else {
                if(last[i] == 1)
                    return position;
            }
        }
    }
    if(n > 1) {
        int i = n;
        while(i * last[i] < MAX && vis[i * last[i]]) {
            last[i]++;
        }
        if(i * last[i] < position)
            position = i * last[i];
    }
    return position;
}

int main(void) {
#ifndef ONLINE_JUDGE
    READ("input.txt");
#endif
    int n;
    for(int i = 2; i < MAX; i++) {
        last[i] = 1;
    }
    ans[1] = 1;
    ans[2] = 2;
    last[0]++;
    int pre = 2;

    vis[1] = true;
    vis[2] = true;

    for(int cnt = 2, i = 3; cnt < MM; i++) {
        pre = solve(pre);
        if(pre <= MM) {
            cnt++;
            ans[pre] = i;
        }
        vis[pre] = true;
    }

    while(scanf("%d", &n) != EOF && n > 0) {
        printf("The number %d appears in location %d.\n", n, ans[n]);
    }
    return 0;
}