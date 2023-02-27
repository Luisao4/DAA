//Dadas vários pares de matrículas em qualquer um dos quatro formatos possíveis, a tua tarefa é calcular e imprimir a distância entre cada par.
#include <iostream>
#include <string>
#include <cctype> // see if its a int or char
using namespace std;

int gen(string str){
  int cases = 5290000;

  if(isalpha(str[0])){
    if(isalpha(str[7]))
      return cases * 3;

    else
      return 0;
  }

  else{
    if(isalpha(str[3]))
      return cases * 2;

    else
      return cases;
  }
}

int number(string a){
  int num = gen(a);
  int base = 1;

  for(int i=7; i>=0; i--){
    if(isdigit(a[i])){
      num += (a[i] - '0') * base;
      base *= 10;
      //cout << a[i] << " " << num << endl;
    }
  }

  for(int i=7; i>=0; i--){
    if(isalpha(a[i])){
      int value = a[i] - 'A';

      if(a[i] > 'K') value--;
      if(a[i] > 'W') value--;
      if(a[i] > 'Y') value--;
      num += value * base;
      base *= 23;
    //cout << a[i] << " " << value << endl;
    }
  }
  return num;
}

string cleanse(string str){ // no need
    for(int i=0 ; i< 8; i++){
        if(str[i]=='-') str.erase(i , 1); // erase na posiçao i 1 caracter em busca do ' - '
    }
    //cout << str << endl;
    return str;
}

int main(){
    int n;
    cin >> n;
    string p,u;
    for(int i=0; i<n; i++){
        cin >> p >> u;
        // p = cleanse(p);
        // u = cleanse(u);
        //cout << p << endl << u << endl;
        cout << abs(number(p) - number(u)) << endl; 
    }
    return 0;
}
