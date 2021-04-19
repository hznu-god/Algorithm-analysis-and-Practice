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
vector<int>s;
int n, k;
void selectKth(vector<int>s, int n, int k) {
	vector<int>temp(s);
	vector<int>m;
	vector<int>s1, s2;
	for (int i = 0; i < n; i += 5) {
		int len = min(n - i, 5);
		sort(temp.begin() + i, temp.begin() + i + len);
		m.push_back(temp[i + (len - 1) / 2]);//中位数m*数组
	}
	sort(m.begin(), m.end());
	int mid = m[(m.size() - 1) / 2];
	for (int i = 0; i < n; ++i) {
		if (n - i < 5) {
			for (int j = i; j < n; ++j) {
				if (temp[j] > mid)s2.push_back(temp[j]);
				else if (temp[j] < mid)s1.push_back(temp[j]);
			}
			break;
		}
		if (temp[i + 2] < mid) {
			for (int j = i; j <= i + 2; ++j)s1.push_back(temp[j]);
			for (int j = i + 3; j < i + 5; ++j) {
				if (temp[j] > mid)
					s2.push_back(temp[j]);
				else 
					s1.push_back(temp[j]);
			}
		}
		else if (temp[i + 2] > mid) {
			for (int j = i; j <= i + 2; j++) {
				if (temp[j] > mid)
					s2.push_back(temp[j]);
				else s1.push_back(temp[j]);
			}
			for (int j = i + 3; j < i + 5; j++)
				s2.push_back(temp[j]);
		}
		else {
			for (int j = i; j < i + 2; j++)
				s1.push_back(temp[j]);

			for (int j = i + 3; j < i + 5; j++)
				s2.push_back(temp[j]);
		}
	}
	if (k == s1.size() + 1) {
		cout << mid << endl;
		return;
	}
	else if (k <= s.size())
		selectKth(s1, s1.size(), k);
	else
		selectKth(s2, s2.size(), k - s1.size() - 1);
}
signed main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.push_back(x);
	}
	selectKth(s, n, k);
	return 0;
}
