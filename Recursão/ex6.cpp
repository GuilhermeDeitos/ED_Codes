
#include <iostream>
#include <string>

using namespace std;

int sumDigits(string num){
    if(num.length() == 0) return 0;
    else return (stoi(num.substr(num.length()-1)) + sumDigits(num.substr(0, num.length()-1)));
}

int main() {
    string num;

    cout << "Insira o numero: " << endl;
    cin >> num;

    cout << "Soma dos digitos: " << sumDigits(num) << endl;


    return 0;
}
