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
struct Node {
    int id;
    int startTime;
    int endTime;
    bool operator<(Node tmp) {
        if (endTime != tmp.endTime)return endTime < tmp.endTime;
        else return startTime < tmp.startTime;
    }
}timeInfo[maxn];

vector<int>save;
Node saveInfo[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        timeInfo[i].id = i;
        cin >> timeInfo[i].startTime >> timeInfo[i].endTime;
        saveInfo[i] = timeInfo[i];
    }
    sort(timeInfo, timeInfo + n);
    save.push_back(timeInfo[0].id);
    int preEndTime = timeInfo[0].endTime;
    for (int i = 1; i < n; i++) {
        int id = timeInfo[i].id;
        if (timeInfo[i].startTime >= preEndTime) {
            save.push_back(id);
            preEndTime = timeInfo[i].endTime;
        }
    }
    printf("%d\n", save.size());
    for (int i = 0; i < save.size(); i++)
        printf("%d ", save[i] + 1);
    return 0;
}