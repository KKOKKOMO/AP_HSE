#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1001
#define MAXH 1001
#define MOD 1000000007

int n;
int leftChild[MAXN], rightChild[MAXN];
int isChild[MAXN];
long long dp[MAXN][2][MAXH]; // dp[node][color][black_height]
int maxH[MAXN]; // максимальная чёрная высота поддерева

int max_a(int a, int b) {
    return a > b ? a : b;
}

// Объединяем два поддерева
void combine(int node, int l, int r) {
    int i, j;
    long long temp[2][MAXH] = {{0}};
    int hlim = max_a(maxH[l], maxH[r]) + 1;

    for (i = 1; i <= hlim; i++) {
        // dp[node][1][i] — node красный
        // дети — только чёрные, чёрная высота у них — i - 1
        if (i - 1 <= maxH[l] && i - 1 <= maxH[r]) {
            dp[node][1][i] = dp[l][0][i - 1] * dp[r][0][i - 1] % MOD;
        }

        // dp[node][0][i] — node чёрный
        // дети — любые, но с чёрной высотой i - 1
        long long sum = 0;
        if (i - 1 <= maxH[l] && i - 1 <= maxH[r]) {
            for (int lc = 0; lc <= 1; lc++) {
                for (int rc = 0; rc <= 1; rc++) {
                    sum += dp[l][lc][i - 1] * dp[r][rc][i - 1] % MOD;
                    if (sum >= MOD) sum -= MOD;
                }
            }
            dp[node][0][i] = sum;
        }
    }

    maxH[node] = hlim;
}

void dfs(int node) {
    int l = leftChild[node];
    int r = rightChild[node];

    if (!l && !r) {
        dp[node][0][1] = 1; // чёрный лист
        maxH[node] = 1;
        return;
    }

    if (l) dfs(l);
    if (r) dfs(r);

    if (!l) {
        // только правый
        for (int i = 1; i <= maxH[r] + 1; i++) {
            if (i - 1 <= maxH[r]) {
                dp[node][1][i] = dp[r][0][i - 1];
                dp[node][0][i] = (dp[r][0][i - 1] + dp[r][1][i - 1]) % MOD;
            }
        }
        maxH[node] = maxH[r] + 1;
    } else if (!r) {
        // только левый
        for (int i = 1; i <= maxH[l] + 1; i++) {
            if (i - 1 <= maxH[l]) {
                dp[node][1][i] = dp[l][0][i - 1];
                dp[node][0][i] = (dp[l][0][i - 1] + dp[l][1][i - 1]) % MOD;
            }
        }
        maxH[node] = maxH[l] + 1;
    } else {
        combine(node, l, r);
    }
}

int main() {
    scanf("%d", &n);
    int i, a, b;
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &leftChild[i], &rightChild[i]);
        if (leftChild[i]) isChild[leftChild[i]] = 1;
        if (rightChild[i]) isChild[rightChild[i]] = 1;
    }

    int root = 1;
    while (isChild[root]) root++;

    dfs(root);

    long long ans = 0;
    for (i = 1; i <= maxH[root]; i++) {
        ans = (ans + dp[root][0][i]) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
