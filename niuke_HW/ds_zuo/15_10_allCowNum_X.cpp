#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
struct matrix {
    LL nengsheng;
    LL gangchusheng;
    LL chusheng2;
    LL chusheng3;
};

/*超时*/
LL allCowNum(LL year) {
    matrix preyear{ 1,1,0,0 };
    matrix nextyear{ 0,0,0,0 };
    if (year == 1) {
        cout << 0 << endl;
        return 0;
    }
    else if (year == 2) {
        cout << 2 << endl;
        return 0;
    }
    for (LL i = 2; i < year; i++) {
        nextyear.nengsheng = preyear.nengsheng + preyear.chusheng3;
        nextyear.gangchusheng = nextyear.nengsheng;
        nextyear.chusheng2 = preyear.gangchusheng;
        nextyear.chusheng3 = preyear.chusheng2;
        preyear = nextyear;
    }
    return nextyear.nengsheng + nextyear.gangchusheng + nextyear.chusheng2 + nextyear.chusheng3;
}
/*超内存*/
LL c1(LL n) {
    if (n < 1)return 0;
    if (n == 1 || n == 2 || n == 3)return n;
    return c1(n - 1) + c1(n - 3);
}

vector<vector<int>> matrixPower(vector<vector<int>> base, int n) {
    vector<vector<int>> arr = { {1,1,0},{0,0,1},{1,0,0} };
    vector<vector<int>> temp = arr;
    vector<vector<int>> res = arr;
    while (--n) {
        res[0][0] = arr[0][0] * temp[0][0] + arr[0][1] * temp[1][0] + arr[0][2] * temp[2][0];
        res[0][1] = arr[0][0] * temp[0][1] + arr[0][1] * temp[1][1] + arr[0][2] * temp[2][1];
        res[0][2] = arr[0][0] * temp[0][2] + arr[0][1] * temp[1][2] + arr[0][2] * temp[2][2];

        res[1][0] = arr[1][0] * temp[0][0] + arr[1][1] * temp[1][0] + arr[1][2] * temp[2][0];
        res[1][1] = arr[1][0] * temp[0][1] + arr[1][1] * temp[1][1] + arr[1][2] * temp[2][1];
        res[1][2] = arr[1][0] * temp[0][2] + arr[1][1] * temp[1][2] + arr[1][2] * temp[2][2];

        res[2][0] = arr[2][0] * temp[0][0] + arr[2][1] * temp[1][0] + arr[2][2] * temp[2][0];
        res[2][1] = arr[2][0] * temp[0][1] + arr[2][1] * temp[1][1] + arr[2][2] * temp[2][1];
        res[2][2] = arr[2][0] * temp[0][2] + arr[2][1] * temp[1][2] + arr[2][2] * temp[2][2];
        temp = res;
    }
    return res;
}
/*超时*/
int c3(int n) {
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2 || n == 3) {
        return n;
    }
    vector<vector<int>> base = { 
                        {1,1,0},
                        {0,0,1},
                        {1,0,0} };
    vector<vector<int>> res = matrixPower(base, n - 3);
    return 3 * res[0][0] + 2 * res[1][0] + res[2][0];
}




int main() {
    LL year;
    cin >> year;
    cout << c1(year) % 1000000007 << endl;
    cout << allCowNum(year)%1000000007 << endl;

    return 0;
}



/*
https://www.cnblogs.com/daminzhou/p/8376107.html
*/