// main.cpp
#include "TextProcessor.h"
#include <iostream>

int main() {
    string inputText;
    cout << "Digite um texto (termine com {*}):" << endl;

    string line;
    while (getline(cin, line) && line != "{*}") {
        inputText += line;
    }

    TextProcessor txs(inputText);

    // Imprimir o texto lido
    cout << "\nTexto armazenado:" << endl;
    vector<string>& words = txs.getProcessedWords();
    for (const string& word : words) {
        cout << "["<<word << "]" << endl;
    }
    cout << endl;

    return 0;
}
