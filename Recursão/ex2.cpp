#include <iostream>
using namespace std;

int potencia(int n, int x){
    if (n == 0) return 1;
    else if (x == 0) return 0;
    else if (n == 1) return x;
    else return (x * potencia(n-1, x));
}


int main() {
    int n, x;
    cout << "Digite o numero e expoente" << endl;
    cin >> x >> n;
    cout << "Resultado: " << potencia(n, x) << endl;
    return 0;
}

