// TextProcessor.h
#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <vector>
#include <string>
#include <unordered_set>
#include <map>

class TextProcessor {
    std::vector<std::string> words;
    std::vector<std::string> wordsF;  // Armazenará o texto processado
    std::unordered_set<std::string> keywords;

public:
    TextProcessor(std::string text);

    void processText(const std::string& text);
    std::string removePontuacao(std::string str);
    void processTextFinal();
    std::string regularizar(std::string s);
    void removeNonKeywords();

    std::vector<std::string>& getWords();
    std::vector<std::string>& getProcessedWords();

private:
    std::map<char, char> tabelaAcentos;
    std::string removeAcentosEspeciais(const std::string& palavra);
    std::string tratarString(std::string palavra);
};

#endif // TEXTPROCESSOR_H


