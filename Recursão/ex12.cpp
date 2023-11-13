#include <iostream>
using namespace std;

int fatorial(int n){
    if (n == 0 || n == 1) return 1;
    else return (n * fatorial(n - 1));
}

unsigned long long int fatorialQuad(int n){
    return fatorial(2 * n) / fatorial(n);
}

int main() {
    int n;
    cout << "Informe o numero para fatorar: " << endl;
    cin >> n;

    cout << fatorialQuad(n) << endl;
    return 0;
}
