#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

struct matrix {
    int64 v[5][5];
    int64 row, col; // number of row and column
};
int64 mod;

// multiplies two matrices and returns the result
matrix multiply(matrix &a, matrix &b) {
    assert(a.col == b.row);
    matrix ret;
    ret.row = a.row;
    ret.col = b.col;
    for (int64 i = 0; i < ret.row; i++) {
        for (int64 j = 0; j < ret.col; j++) {
            int64 sum = 0;
            for (int64 k = 0; k < a.col;  k++) {
                sum += a.v[i][k] * b.v[k][j];
                sum %= mod;
            }
            ret.v[i][j] = sum;
        }
    }
    return ret;
}

// returns mat^p
/*
matrix power(matrix mat, int64 p) {
    assert(p >= 1);
    if (p == 1) return mat;
    if (p & 1) return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}
*/

// optimized power calculation
string binary(int64 p) {
  string ret = "";
  while (p > 0) {
    ret += (p % 2 == 0) ? "0" : "1";
    p /= 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

matrix power(matrix mat, int64 p) {
  string bin = binary(p);
  matrix ret = mat;
  for (int64 i = 1; i < bin.size(); i++) {
    ret = multiply(ret, ret);
    if (bin[i] == '1') {
      ret = multiply(ret, mat);
    }
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int tcase;
    int a, b, n, m;
    a = 0, b = 1;
    matrix mat;
    while ( cin >> n >> m ) {
        mat.row = mat.col = 2;
        mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
        mat.v[1][1] = 0;
        mod = 1 << m;
        if (n < 3) {
            if (n == 0) cout << a << endl;
            if (n == 1) cout << b << endl;
        } else {
            mat = power(mat, n - 1);
            int64 ans = b * mat.v[0][0] + a * mat.v[0][1];
            ans %= mod;
            cout << ans << endl;
        }
    }
    return 0;
}
