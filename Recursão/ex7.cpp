
#include <iostream>

using namespace std;

int mdc(int x, int y){
    if(y == 0) return x;
    else return mdc(y, x%y);
}

int main() {
    int x, y;
    cout << "Informe x e y para calcular o mdc: " << endl;
    cin >> x >> y;
    
    cout << "MDC: " << mdc(x,y) << endl;
    return 0;
}
