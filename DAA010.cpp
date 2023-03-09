#include <algorithm>
#include <iostream>
using namespace std;

void bs(int low, int high, int sums[], int valor) {
    // cout << "primeiro " << valor << endl;
    while (low < high) {
        //  cout<< closest<<endl;
        int midle = low + (high - low) / 2;
        if (valor <= sums[midle])
            high = midle;
        else
            low = midle + 1;
    }

    int distHigh = abs(sums[low] - valor);
    int distLow = abs(valor - sums[low - 1]);

    if (distHigh < distLow)
        cout << sums[low] << endl;
    else if (distHigh > distLow)
        cout << sums[low + 2] << endl;  // erro pode estar aqui
    else
        cout << sums[low - 1] << " " << sums[low] << endl;
}

int main() {
    int n;  // sequencia de numeros
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];
    // for (int i = 0; i < n; i++) cout << nums[i]<< endl;
    int p;  // total de perguntas
    cin >> p;

    int c = 0;
    int sum[n];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            sum[c] = nums[i + 1] + nums[j + 1];  // um bocado sus
            c++;
        }
    }
    // for(int i = 0; i < n; i++) cout << sum[i]<< endl;
    sort(sum, sum + n);  // ordenar sum
    // for(int i = 0; i < n; i++) cout << sum[i]<< endl;

    for (int i = 0; i < p; i++) {
        int a = 0;
        cin >> a;
        bs(0, n -1, sum, a);
    }
    return 0;
}
