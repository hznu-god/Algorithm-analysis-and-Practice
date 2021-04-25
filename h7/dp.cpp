#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e2 + 10;
int dp[maxn][maxn] = { 0 };
int f[maxn][maxn] = { 0 };
int vis[maxn][maxn] = { 0 };
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> f[j][i];

	for (int k = 1; k <= n; k++)
		for (int x = 1; x <= m; x++)
			for (int i = 0; i <= x; i++)
				if (dp[k - 1][x - i] + f[k][i] >= dp[k][x]) {
					dp[k][x] = dp[k - 1][x - i] + f[k][i];
					vis[k][x] = i;
				}
	cout << "最大收益为：" << dp[n][m] << endl;
	cout << "分配方案为：\n";
	int sum = m;
	for (int i = n; i >= 1; i--) {
		cout << "分配给第" << i << "个项目" << vis[i][sum] << "万\n";
		sum -= vis[i][sum];
	}
}
//5 4
//0 0 0 0
//11 0 2 20
//12 5 10 21
//13 10 30 22
//14 15 32 23
//15 20 40 24