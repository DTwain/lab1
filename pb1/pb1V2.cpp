#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <sstream>
#include <assert.h>

using std::string;
using std::vector;
using std::map;
using std::stringstream;
using std::getline;

class SolutionClass {
private:
    string sir;
    vector<string> splitString();
    int compareInsensitiveStrings(const string& word1, const string& word2);
public:
    string getResult(const string& textGiven);

};


vector<string> SolutionClass::splitString() {
    vector<string> stringSplit;
    stringstream ss{ sir };
    string word;
    char delimiter{ ' ' };
    while (getline(ss, word, delimiter)) {
        stringSplit.push_back(word);
    }
    return stringSplit;
}

int SolutionClass::compareInsensitiveStrings(const string& word1, const string& word2) {
    size_t minLength = std::min(word1.length(), word2.length());
    for (size_t i = 0; i < minLength; ++i) {
        char c1 = tolower(word1[i]);
        char c2 = tolower(word2[i]);
        if (c1 < c2)
            return -1;
        if (c1 > c2)
            return 1;
    }
    if (word1.length() < word2.length())
        return -1;
    if (word1.length() > word2.length())
        return 1;
    return 0;
}

string SolutionClass::getResult(const string& textGiven) {
    sir = textGiven;
    vector<string> stringSplit{ splitString() };
    string foundWord = "";
    for (const string& word : stringSplit) {
        if(compareInsensitiveStrings(word, foundWord) == 1)
            foundWord = word;
    }
    return foundWord;
}
int main() {
    SolutionClass sol = SolutionClass();
    assert(sol.getResult("Ana are mere si pere") == "si");
    assert(sol.getResult("") == "");
    assert(sol.getResult("Gabon este o tara localizata pe ecuator") == "tara");
    assert(sol.getResult("Sucevita este una din localitatile din judetul Suceava") == "una");
    assert(sol.getResult("Sucevita este o localitate din judetul Suceava") == "Sucevita");
    return 0;
}