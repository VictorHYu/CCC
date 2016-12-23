#include <iostream>
#include <algorithm>
#define INF 2147483647

using namespace std;

int main (void) {
    int d, n;
    cin >> d >> n;
    int c[n];
    int dp[d+1];

    for (int i = 1; i <= d; i++)
        dp[i] = INF;
    dp[0] = 0;

    for (int i = 0; i < n; i++)
        cin >> c[i];

    for (int i = 0; i <= d; i++) {
        for (int j = 0; j < n; j++) {
            if (i + c[j] <= d && dp[i] != INF)
                dp[i+c[j]] = min(dp[i+c[j]],dp[i]+1);
        }
    }

    if (dp[d] != INF)
        cout << "Roberta wins in " << dp[d] << " strokes." << endl;
    else
        cout << "Roberta acknowledges defeat." << endl;
    return 0;
}
