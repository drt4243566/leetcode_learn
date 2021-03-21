#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
typedef unsigned long long LL;
const int mod = 1000000007;
int process(int n, int k, int pre, int index) {
	if (index == n) {
		int cnt = 0;
		for (int i = 1; i <= k; i++) {
			if (pre <= i || pre % i != 0) {
				cnt++;
			}
		}
		return cnt;
	}
	int num = 0;
	for (int i = 1; i <= k; i++) {
		if (pre == -1) {
			num += process(n, k, i, index + 1);
		}
		else if (pre <= i || pre % i != 0) {
			num += process(n, k, i, index + 1);
		} 
	}
	return num;
}
void lessArray(int n, int k) {
	if (n <= 0 || k <= 0) {
		cout << 0 << endl;
		return;
	}
	cout << process(n, k, -1, 1) % mod << endl;

}
void waysDp(int n, int k) {
	vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, 0));
	for (int i = 1; i <= k; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		LL rowsum = 0;
		for (int j = 1; j <= k; j++) {
			LL cnt = 0;
			for (int t = 1; t <= k; t++) {
				if (t <= j || t % j != 0) {
					cnt += dp[i - 1][t];
					cnt %= mod;
				}
			}
			dp[i][j] = cnt;
			rowsum += cnt;
		}
		dp[i][0] = rowsum % mod;
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << dp[i][j] << "\t\t";
		}
		cout << endl;
	}
	*/
	cout << dp[n][0] << endl;
}
void waysDp2(int n, int k) {
	vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, 0));
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		LL sum = 0;
		for (int j = 1; j <= k; j++) {
			sum += dp[i - 1][j];
			sum %= mod;
		}
		for (int j = 1; j <= k; j++) {
			LL sum2 = 0;
			for (int z = j + j; z <= k; z += j) {
				sum2 += dp[i - 1][z];
				sum2 %= mod;
			}
			dp[i][j] = (sum - sum2 + mod) % mod;
		}
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << dp[i][j] << "\t\t";
		}
		cout << endl;
	}
	*/
	LL res = 0;
	for (int j = 0; j <= k; j++) {
		res += dp[n][j];
		res %= mod;
	}
	cout << res << endl;
}
void waysDp3(int n, int k) {/*节省空间*/
	vector<int> dp1(k+1), dp2(k+1);
	dp1[1] = 1;
	int temp = n;
	while (temp--) {
		LL sum = 0;
		for (int j = 1; j <= k; j++) {
			sum += dp1[j];
			sum %= mod;
		}
		for (int j = 1; j <= k; j++) {
			LL sum2 = 0;
			for (int z = j + j; z <= k; z += j) {
				sum2 += dp1[z];
				sum2 %= mod;
			}
			dp2[j] = (sum - sum2 + mod) % mod;
		}
		dp1 = dp2;
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cout << dp[i][j] << "\t\t";
		}
		cout << endl;
	}
	*/
	LL res = 0;
	for (int j = 0; j <= k; j++) {
		res += dp1[j];
		res %= mod;
	}
	cout << res << endl;
}
int main() {
	int n, k;
	clock_t start, finish;
	double duration;
	while (cin >> n >> k) {
		//lessArray(n, k);
		//start = clock();
		//waysDp(n, k);
		//duration = (double)(clock() - start) / CLOCKS_PER_SEC;
		//cout << duration << endl;
		start = clock();
		waysDp2(n, k);
		duration = (double)(clock() - start) / CLOCKS_PER_SEC;
		cout << duration << endl;
		start = clock();
		waysDp3(n, k);
		duration = (double)(clock() - start) / CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	
	return 0;
}