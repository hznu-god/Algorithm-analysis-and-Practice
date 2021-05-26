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
int res = 0;
vector<int>save;

int main() {
    int n;
    cin >> n;
    // 利用小顶堆维护一个栈顶都是当前最小值的数据结构
    priority_queue<int, vector<int>, greater<int> >q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    while (q.size() > 1) {
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        save.push_back(x);
        save.push_back(y);
        res += x + y;
        q.push(x + y);
    }
    printf("WPL = %d\n", res);
    for (int i = 0; i < save.size(); i++)
        printf("%d ", save[i]);
    printf("\n");
    return 0;
}