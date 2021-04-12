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
//#define int long long
#define ll long long
#define ull unsigned long long
#define speed {ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); };
using namespace std;
const double PI = acos(-1.0);
const int maxn = 2e5 + 10;
const int N = 5e2 + 10;
const ll INF = 1e18;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps_0 = 1e-9;
const double gold = (1 + sqrt(5)) / 2;
template<typename T>
inline void rd(T& x) {
	int f = 1;
	x = 0;
	char c = getchar();
	while (c<'0' || c>'9') {
		f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}
template<typename T>
inline T gcd(T a, T b) {
	return b ? gcd(b, a % b) : a;
}
int n;
int s[maxn];
struct point {
	double x, y;
	point() {};
	point(double x, double y) :x(x), y(y) {};
	bool operator<(const point& a)const {
		if (x == a.x)return y < a.y;
		return x < a.x;
	}
}p[maxn];
bool cmp(int a, int b) {
	return p[a].y < p[b].y;
}
double dis(point& a, point& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double sum(point& a, point& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
void forceClosePoint() {
	int pos1 = 0, pos2 = 0;
	double minn = inf;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (sum(p[i], p[j]) < minn) {
				minn = dis(p[i], p[j]);
				pos1 = i;
				pos2 = j;
			}
		}
	}
	printf("Close point:P%d P%d\n", pos1, pos2);
	printf("Distance by force: %.6lf\n", minn);
}
double divideClosePoint(int l, int r) {
	if (l == r)return inf;
	if (l + 1 == r)return dis(p[l], p[r]);
	int mid = (l + r) >> 1;
	double ans = min(divideClosePoint(l, mid), divideClosePoint(mid + 1, r));
	int cnt = 0;
	for (int i = l; i <= r; i++){
		if (p[mid].x - ans <= p[i].x && p[i].x <= p[mid].x + ans)
			s[cnt++] = i;
	}
	sort(s, s + cnt, cmp);
	for (int i = 0; i < cnt; i++){
		int k = min(cnt, i + n / 2);
		for (int j = i + 1; j < k; j++)
		{
			if (p[s[j]].y - p[s[i]].y > ans) break;
			ans = min(dis(p[s[i]], p[s[j]]), ans);
		}
	}
	return ans;
}
signed main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		p[i] = point(x, y);
	}
	sort(p + 1, p + 1 + n);
	forceClosePoint();
	double ans = divideClosePoint(1, n);
	printf("Distance by divide :%.6lf\n", ans);
	return 0;
}
