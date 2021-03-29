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
const int N = 1e3 + 10;
const ll INF = 1e18;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps_0 = 1e-9;
const double gold = (1 + sqrt(5)) / 2;
template<typename T>
inline void rd(T& x) {
	int f = 1;x = 0;char c = getchar();
	while (c<'0' || c>'9') { f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	x *= f;
}
template<typename T>
inline T gcd(T a, T b) {
	return b ? gcd(b, a % b) : a;
}
int ans[maxn];
int a[maxn];
int n;
void merge(int* a, int l, int r, int mid) {
	int i = l;
	int j = mid + 1;
	int index = l;
	while (i <= mid && j <= r) {
		if (a[i] < a[j])ans[index++] = a[i++];
		else ans[index++] = a[j++];
	}
	while (i <= mid)ans[index++] = a[i++];
	while (j <= r)ans[index++] = a[j++];
	for (int k = l; k <= r; ++k) {
		a[k] = ans[k];
	}
}
void mergeSort(int* a, int l, int r) {
	if (l >= r)return;
	int mid = (l + r) >> 1;
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	merge(a, l, r, mid);
}
void print(int* a) {
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", a[i], " \n"[i == n]);
	}
}
signed main() {
	while (cin>>n) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		print(a);
		mergeSort(a, 1, n);
		//print(a);
		printf("mergeSort:");
		print(ans);
	}
	return 0;
}