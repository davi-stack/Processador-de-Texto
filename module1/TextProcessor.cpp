// TextProcessor.cpp
#include "TextProcessor.h"
#include <sstream>
#include <locale>

TextProcessor::TextProcessor(std::string text) {
    tabelaAcentos = {
        {'á', 'A'}, {'à', 'A'}, {'â', 'A'}, {'ã', 'A'},
        {'é', 'E'}, {'è', 'E'}, {'ê', 'E'}, {'í', 'I'},
        {'ó', 'O'}, {'ò', 'O'}, {'ô', 'O'}, {'õ', 'O'},
        {'ú', 'U'}, {'ù', 'U'}, {'û', 'U'}, {'ç', 'C'}
    };

    // Initialize the keywords
    keywords = {
        "EM", "NAO", "AO",
        "UM", "UNS", "UMA", "UMAS", "O", "OS", "A", "AS", "E", "OU", "QUE", "DE", "DA", "DO", "DOS", "NO", "NA", "NAS", "NOS",
        "POR", "PARA", "COM", "SE", "MAS", "NAO", "MAIS", "MENOS", "MUITO", "POUCO", "AINDA", "JA", "ENTAO", "AQUI", "AI", "ONDE",
        "QUANDO", "PORQUE", "COMO", "QUAL", "QUAIS", "SER", "ESTAR", "TER", "HAVER", "PODER", "DEVER", "SOU", "ES", "E", "SOMOS",
        "SOIS", "SAO", "ERA", "ERAS", "ERAMOS", "EREIS", "ERAM", "FUI", "FOI", "FOSTE", "FOMOS", "FUISTES", "FORAM", "SEREI",
        "SERAS", "SEREMOS", "SEREIS", "SERAO", "SERIA", "SERIAS", "SERIAMOS", "SERIAIS", "SERIAM", "SOU", "ES", "E", "SOMOS",
        "SOIS", "SAO", "ERA", "ERAS", "ERAMOS", "EREIS", "ERAM", "FUI", "FOI", "FOSTE", "FOMOS", "FUISTES", "FORAM", "SEREI",
        "SERAS", "SEREMOS", "SEREIS", "SERAO", "SERIA", "SERIAS", "SERIAMOS", "SERIAIS", "SERIAM", "LA"
    };

    processText(text);
    processTextFinal();
    removeNonKeywords();
}

void TextProcessor::processText(const std::string& text) {
    std::stringstream ss(text);
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }
}

std::string TextProcessor::removePontuacao(std::string str) {
    std::string nova_string;

    for (int i = 0; i < str.length(); i++) {
        if (!ispunct(str[i])) {
            nova_string += str[i];
        }
    }

    return nova_string;
}

void TextProcessor::processTextFinal() {
    for (std::string s : words) {
        wordsF.push_back(removePontuacao(tratarString(s)));
    }
}

std::string TextProcessor::regularizar(std::string s) {
    for (int i = 0; i < s.size(); i++) {
        if (tabelaAcentos.find(s[i]) != tabelaAcentos.end()) {
            s[i] = tabelaAcentos[s[i]];
        }
    }

    return s;
}

void TextProcessor::removeNonKeywords() {
    std::vector<std::string> filteredWords;
    for (const std::string& word : wordsF) {
        if (keywords.find(word) == keywords.end()) {
            filteredWords.push_back(word);
        }
    }
    wordsF = filteredWords;
}

std::vector<std::string>& TextProcessor::getWords() {
    return words;
}

std::vector<std::string>& TextProcessor::getProcessedWords() {
    return wordsF;
}

std::string TextProcessor::removeAcentosEspeciais(const std::string& palavra) {
    std::string resultado;

    for (char c : palavra) {
        char lowercase = std::tolower(c, std::locale());
        auto it = tabelaAcentos.find(lowercase);
        if (it != tabelaAcentos.end()) {
            resultado += it->second;
        } else if (std::isalnum(c)) {
            resultado += std::toupper(c, std::locale());
        }
    }

    return resultado;
}

std::string TextProcessor::tratarString(std::string palavra) {
    palavra = removeAcentosEspeciais(palavra);
    for (int x = 0; x < palavra.size(); x++) {
        palavra[x] = toupper(palavra[x]);
        x++;
    }
    return palavra;
}
