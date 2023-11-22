
#include <iostream>

using namespace std;

int Multip_Rec(int n1, int n2){
    if(n2 == 0) return 0;
    else return (n1 + Multip_Rec(n1, n2-1));
}
// 2 * 3 = 2 + 2 + 2
int main() {
    int n1, mult;
    cout << "Informe o numero e o multiplicador" << endl;
    cin >> n1 >> mult;

    cout << "Resultado: " << Multip_Rec(n1, mult) << endl;

    return 0;
}
