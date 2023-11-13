#include <iostream>

using namespace std;

int somatorio(int n){
    if (n == 1) return 1;
    else return (n + somatorio(n-1));
}


int main(){
    int n;
    cout << "Digite um numero: ";
    cin >> n;
    cout << "O somatorio de 1 ate " << n << " eh: " << somatorio(n) << endl;
    return 0;
}