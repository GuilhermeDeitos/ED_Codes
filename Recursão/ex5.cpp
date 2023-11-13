#include <iostream>

using namespace std;

int Comb(int n, int k){
    if(n == k) return 1;
    else if (k == 1) return n;
    else if (k > 1 && k < n) return Comb(n-1, k-1) + Comb(n-1, k);
}

int main() {
    int n, k;
    cout << "N e K:" << endl;
    cin >> n >> k;

    cout << "Comb: " << Comb(n, k) << endl;
    return 0;
}
