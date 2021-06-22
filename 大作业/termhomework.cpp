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
#include<unordered_map>
#define mem(a,b) memset(a,b,sizeof(a))
#define debug() puts("what the fuck!")
#define debug(a) cout<<#a<<"="<<a<<endl;
#define speed {ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); };
#define ll long long
#define mod 998244353
using namespace std;
const double PI = acos(-1.0);
const int maxn = 1e2 + 10;
const int N = 1e2 + 10;
const int INF = 0x3f3f3f3f;
const double esp_0 = 1e-6;
int n;				//n个任务
int t[maxn];			//加工时间ti
int tot;			//总时间t
int dp[maxn];			//dp矩阵
int judge[maxn][maxn];	//记录某个dp状态选择了哪项任务
int first_id[maxn];			//标记第一台机器选择的任务ID

void print() {
	int step = n;
	int now = tot / 2;
	vector<int>v;
	v.clear();
	while (now && step) {
		if (!judge[step][now]) {
			step--;
			continue;
		}
		v.push_back(judge[step][now]);
		first_id[judge[step][now]] = 1;
		now -= t[step];
		step--;
	}

	cout << "第一台机器选择的加工时间: ";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size();++i) {
		cout << "t" << v[i] << " ";
	}
	cout << ", 花费总时间 = " << dp[tot / 2] << endl;
	cout << "第二台机器选择的加工时间: ";
	for (int i = 1; i <= n; i++) {
		if (first_id[i]) continue;
		cout << "t" << i << " ";
	}
	cout << ", 花费总时间 = " << (tot - dp[tot / 2]) << endl;

	cout << "最终的总加工时间 = " << max(dp[tot / 2], tot - dp[tot / 2]) << endl;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		tot += t[i];
	}
	//滚动数组压缩
	for (int i = 1; i <= n; i++) {
		for (int j = tot / 2; j >= t[i]; j--) {	//枚举背包容量,最大背包空间为总时间t的一半
			if (dp[j - t[i]] + t[i] > dp[j]) {//转移方程，选取最优，并记录id
				dp[j] = dp[j - t[i]] + t[i];
				judge[i][j] = i;
			}
		}
	}
	print();
	return 0;
}

