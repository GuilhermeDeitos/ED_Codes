#include <iostream>

using namespace std;

int padovan(int n){
    if(n == 0 || n == 1 || n == 2) return 1;
    else if (n > 2) return (padovan(n - 2) + padovan(n - 3)); 
    else runtime_error("Numero inválido");
}

int main() {
    int n;
    cout << "Informe n para calcularmos padovan" << endl;
    cin >> n;

    cout << "Padovan: " << padovan(n) << endl;
    return 0;
}
