#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
    string criptografado;
    getline(cin, criptografado);
    string vetor[criptografado.size()];
    string alfabeto_numerico[26] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
    string alfabeto[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    for (int i = 0; i < criptografado.size(); i+=2){
        std::string s;
        s = criptografado[i];
        s += criptografado[i+1];
        vetor[i] = s;
        for (int j = 0; j < 26; j++){
            if (vetor[i] == alfabeto_numerico[j]){
                vetor[i] = alfabeto[j];
            }
        }
        cout << vetor[i];
    }
    return 0;
}