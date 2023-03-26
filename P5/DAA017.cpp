#include <iostream>
#define MAX 1002
using namespace std;

long long ways(int n, long long piramide[MAX][MAX]) {
    for(int i = n-1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            if(piramide[i][j] == 1 ) piramide[i][j] = piramide[i+1][j] + piramide[i+1][j+1];
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         cout << piramide[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return piramide[1][1];


}

int main() {
    int N;
    cin >> N;  // Nº camadas + Pedras no primeiro nivel
    long long piramide[MAX][MAX];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            piramide[i][j] = 1;
        }
    }

    int D;
    cin >> D;  // Pedras damaged
    for (int i = 0; i < D; i++) {
        int n, p;
        cin >> n >> p;  // em que nivel e que posiçao
        piramide[N-n+1][p] = 0; // porque conta a partir do 0
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         cout << piramide[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ways(N,piramide) << endl;


    return 0;
}