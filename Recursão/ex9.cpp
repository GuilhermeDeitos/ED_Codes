#include <iostream>

using namespace std;

int multiplicacaoRussa(int a, int b){
    if(a == 1) return b;
    else if(a % 2 != 0) return (b + multiplicacaoRussa(a/2,b*2));
    else return multiplicacaoRussa(a/2,b*2);
}

int main() {
    int a,b;

    cout << "Informe A e B:" << endl;
    cin >> a >> b;

    cout << "Multiplicacao:" << multiplicacaoRussa(a,b) << endl;
    return 0;
}
