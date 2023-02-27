/*Dada uma sequência de N bakugans, descrita pelas energias Ei de cada um deles, bem como uma série de F fotos, 
cada uma indicando que contém os bakugans entre as posições Ai e Bi, 
a tua tarefa é calcular, para cada foto, a soma das energias dos bakugans com posições no intervalo [Ai, Bi]. */
#include <iostream>
using namespace std;

/* soluçao nao muito boa 
int tirapick(int bakugan[], int A, int B, int size){
    int sum=0;
    for(int i=0; i<size; i++){
       if(i>= A-1 && i<=B-1) sum+= bakugan[i];
    }
    cout << sum <<endl;

    return 0;
}
*/

int main(){
    int n;
    cin >> n;
    int bak[n];
    int sumac[n]; // soluçao soma acumulada somar i com i-1
    for(int i=0; i<n;i++){
        cin >> bak[i];
        //cout << bak[i] << endl;
        if(i==0) sumac[i] = bak[i];
        if(i>=1) sumac[i]= sumac[i-1]+bak[i]; //prefix sum algorithm
        //cout << sumac[i] << endl;
    }
    int f;
    cin >> f;
    int a,b;
    for(int i=0; i<f;i++){
        cin >> a >> b;
        //tirapick(bak, a, b, n);
         if(a==1 && b == n) cout << sumac[n-1] << endl;
         else{
            b -=1;
            a -=2;
            cout << sumac[b] - sumac[a] << endl;
            //cout<< a << " " << b << endl;
         }
    }
    return 0;
}