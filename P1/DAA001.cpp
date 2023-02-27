//Dada uma sequência de N números inteiros, a tua tarefa é calcular a frequência do número 42, ou seja, quantas vezes ocorre o número 42 na sequência que te é dada.

#include <iostream>
using namespace std;
int BIGINT = 1000;

int lookforit(int arr[], int size){
    int c=0;
    for (int i = 0; i < size; i++){
    if(arr[i]==42)
        c++;
    }
    return c;
}


int main(){
    int n;
    cin >> n;
    int arr[BIGINT];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    cout << lookforit(arr,n) << endl;
}