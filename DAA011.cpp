#include <iostream>
using namespace std;

bool test(int d[], int mid, int k, int n) {
    int sum = 0;
    int part = 1;
    for (int i = 0; i < n; i++) {
        sum += d[i];

        if (sum > mid) {  // se passar da comparaçao pretendida , recua um ciclo, aumenta "um dia" e volta sum=0
            part++;
            sum = 0;
            i--;
        }
        if (part > k) return false;  // se a contagem dos dias passar os dias pretendidos !e_possivel(mid)
    }
    return true;
}

int binarysearch(int low, int high, int d[], int k, int size) {  // quase sempre o mesmo
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (test(d, mid, k, size) == true) high = mid;
        else low = mid + 1;
    }
    if (test(d, low, k, size) == false) return -1; // sse o problema for insoluvel porque tecnicamente o teste do mid anterior é o novo low
    return low;
}

int main() {
    int n;
    cin >> n;
    int d[n];
    int high = 0;

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        high += d[i];
    }

    int p, k;  // k = dias , p = perguntas
    cin >> p;

    for (int i = 0; i < p; i++) {
        cin >> k;
        cout << binarysearch(0, high, d, k, n) << endl;
    }

    return 0;
}