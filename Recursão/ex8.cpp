
#include <iostream>

using namespace std;

int tribonacci(int n) {
    if(n == 0 || n == 1) return 0;
    else if (n == 2) return 1;
    else if (n > 2) return (tribonacci(n - 1) + tribonacci(n-2) + tribonacci(n-3)); 
    else runtime_error("Numero inválido");
}

int padovan(int n){
    if(n == 0 || n == 1 || n == 2) return 1;
    else if (n > 2) return (padovan(n - 2) + padovan(n - 3)); 
    else runtime_error("Numero inválido");
}

int main() {
    int n;
    cout << "Informe n para calcularmos tribonacci e padovan" << endl;
    cin >> n;

    cout << "Tribonacci: " << tribonacci(n+1) << endl << "Padovan: " << padovan(n-1) << endl;
    return 0;
}
