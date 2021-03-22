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
const int maxn = 1e6 + 10;
const int N = 2e2 + 10;
const ll INF = 1e18;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double esp_0 = 1e-6;
const double gold = (1 + sqrt(5)) / 2;
template<typename T>
inline void rd(T&x) {
	int temp = 1;
	char c = getchar();
	x = 0;
	while (c > '9' || c < '0') {if (c == '-')temp = -1;	c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0';c = getchar();}
	x *= temp;
}
ll gcd(ll x, ll y) {return y ? gcd(y, x % y) : x;}
int vis[maxn];
int n;
signed main() {
	cin >> n;
	mem(vis, 0);
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		vis[x] = i;
	}
	int q;
	while (cin >> q) {
		if (vis[q])cout << vis[q] << endl;
		else cout << 0 << endl;
	}
	return 0;
}