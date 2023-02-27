// Dados vários pares de inteiros Ni e Ki, a tua tarefa é descobrir, para cada par, qual o menor número maior que Ni tal que a soma dos seus dígitos seja exactamente Ki.
#include <iostream>
using namespace std;

int decompor(int n)
{

    int ft = 0;
    // cout<< "chegou" << endl;
    while (n > 0)
    {
        ft += n % 10;
        n = n / 10;
    }
    // cout << ft << endl;
    return ft;
}

void nextnum(int n, int k)
{
    int num = n + 1;
    // decompor(n);
    while (decompor(num) != k)
        num++;
    cout << num << endl;
    // if(num == 95726193);
    // cout<< "funciona"<<endl;
}

int main()
{
    // cout << "Works" << endl;
    int t;
    cin >> t;
    int N, K;
    for (int i = 0; i < t; i++){
        cin >> N >> K;
        nextnum(N, K);
    }
    return 0;
}