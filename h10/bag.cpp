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
int n, volume, dp[maxn];
int cost[maxn], val[maxn];


int zoPack() {
    for (int i = 0; i < n; i++) {
        for (int j = volume; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
        }
    }
    return dp[volume];
}

int main() {
    printf("Please enter the quantity and space of the item\n");
    cin >> n >> volume;

    printf("Please enter every things's cost:\n");
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    printf("Please enter every things's value:\n");
    for (int i = 0; i < n; i++)
        cin >> val[i];

    printf("The max value is : ");
    printf("%d\n", zoPack());
    return 0;
}