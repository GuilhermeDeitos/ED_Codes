#include <iostream>

using namespace std;

string fibonacci(int n){
    if(n == 0) return "b";
    else if (n == 1) return "a";
    else if (n > 1) return fibonacci(n-1) + fibonacci(n-2);
    else return "Error: Invalid number";
}

int main() {
    int n;

    cout << "Insira um numero..." << endl;
    cin >> n;
    
    cout << "Sequencia fibonacci: " << fibonacci(n) << endl;
    return 0;
}
