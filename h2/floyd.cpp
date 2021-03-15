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
#include<sstream>
#include<sstream>
#define mem(a,b) memset(a,b,sizeof(a))
#define debug() puts("what the fuck!")
#define dedebug() puts("what the fuck!!!")
#define ll long long
#define ull unsigned long long
#define speed {ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); };
using namespace std;
const double PI = acos(-1.0);
const int maxn = 2e5 + 10;
const int N = 2e2 + 10;
const ll INF = 1e18;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double esp_0 = 1e-6;
const double gold = (1 + sqrt(5)) / 2;
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}
int n, m;
int g[N][N];
void init() {
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			if (i == j)g[i][j] == 0;
			else g[i][j] = inf;
		}
	}
}
void floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}
signed main(){
	init();
	cin >> n >> m;//n个点，m条边
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
	}
	floyd();
	return 0;
}