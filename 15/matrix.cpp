#include <iostream>
#include <string>
using namespace std;

void matrixChainOrder(int* p, int n) {
  int m[n][n];
  for (int i = 0; i < n; i++) m[i][i] = 0;

  for (int l = 1; l < n; l++) {
    for (int i = 0; i + l < n; i++) {
      int j = i + l;
      m[i][j] = INT32_MAX;
      for (int k = i; k < j; k++) {
        int x = m[i][k] + m[k + 1][j] + p[i]*p[j + 1]*p[k + 1];
        if (x < m[i][j]) m[i][j] = x;
      }
    }
  }
  cout << m[0][n - 1];

}

int main(int argc, char *argv[])
{
  int p[] = {30, 35, 15, 5, 10, 20, 25};
  matrixChainOrder(p, 6);
  return 0;
}