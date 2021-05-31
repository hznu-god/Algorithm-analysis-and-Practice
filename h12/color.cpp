#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<map>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<cctype>
#include<string>
#include<stdexcept>
#include<fstream>
#define mem(a,b) memset(a,b,sizeof(a))
#define debug() puts("what the fuck!")
#define debug(a) cout<<#a<<"="<<a<<endl;
#define speed {ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); };
#define ll long long
#define mod 998244353
using namespace std;
const double PI = acos(-1.0);
const int maxn = 1e3 + 10;
const int N = 1e2 + 10;
const int INF = 0x3f3f3f3f;
const double esp_0 = 1e-6;
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}
ll lcm(ll x, ll y) {
	return x * y / gcd(x, y);
}
ll extends_gcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll gcdd = extends_gcd(b, a % b, x, y);
	ll temp = x;
	x = y;
	y = temp - (a / b) * y;
	return gcdd;
}
int m, n, k;
int G[N][N];
int color[N];
int res;
void dfs(int x) {
    if (x == n + 1) {
        res++;
        return;
    }
    else {
        for (int i = 1; i <= k; i++) {
            bool flag = false;
            for (int y = 1; y <= x; y++) {
                if (G[x][y] == 1 && color[y] == i) {
                    flag = true;
                    break;
                }
            }
            if (flag == true)
                continue;
            color[x] = i;
            dfs(x + 1);
            color[x] = 0;
        }
    }
}
char mp[N][N];
int main() {
    scanf("%d%d%d", &n, &m, &k);  // n个点m条边k种颜色
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x][y] = 1;
        G[y][x] = 1;
    }
    dfs(1);
    if (res == 0)
        puts("NO");
    else
        printf("%d", res);
    return 0;
}