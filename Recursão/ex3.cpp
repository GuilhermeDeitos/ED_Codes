#include <iostream>
#include <vector>
using namespace std;

int sumVet(int vet[], int n){
    if(n<0) return 0;
    else return (vet[n] + sumVet(vet, n-1));
}

int main() {
    int n;
    cout << "Informe tamanho vetor" << endl;
    cin >> n;

    int vet[n];
    for(int i = 0; i < n; i++){
        cin >>vet[i];
    }

    cout << "A soma: " << sumVet(vet, n) << endl;
    

    return 0;
}
