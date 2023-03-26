#include <iostream>
#define MAX 10005
using namespace std;

int coins[MAX];
int use[MAX];

void many(int m[], int d, int p, int N) {
    coins[0] = 0;
    use[0] = -1;
    for (int i = 1; i <= d; i++) {
        coins[i] = MAX;
        for (int j = 1; j <= N; j++) {
            if (m[j] <= i && 1 + coins[i - m[j]] < coins[i]) {
                coins[i] = 1 + coins[i - m[j]];
                use[i] = m[j];
            }
        }
    }
    cout << d << ": "
         << "[" << coins[d] << "]";
    while (d > 0) {
        cout << " " << use[d];
        d -= use[d];
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;  // quantas moedas
    int m[N];  // tipo de moedas
    for (int i = 1; i <= N; i++) cin >> m[i];
    int p;
    cin >> p;  // quantas perguntas
    for (int i = 0; i < p; i++) {
        int d;
        cin >> d;  // K
        many(m, d, p, N);
    }
    return 0;
}