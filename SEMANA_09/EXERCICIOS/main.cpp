#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main(){
    // string input;
    // getline(cin, input);
    string input = "pablinho";
    string vetor[input.size()];
    string alfabeto_numerico[26] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
    string alfabeto[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    for (int i = 0; i < input.size(); i++){
        vetor[i] = tolower(input[i]);
        for (int j = 0; j < 26; j++){
            if (vetor[i] == alfabeto[j]){
                vetor[i] = alfabeto_numerico[j];
            }
        }
    }
    for(int i = 0; i < input.size(); i++){
        cout << vetor[i];
    }
    return 0;
}