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
    map<char, string> getAlphabetMap();
    int compareInsensitiveStrings(const string& word1, const string& word2);
public:
    string getResult(const string& textGiven);

};

/*
Return: Un map care pentru fiecare litera din dictionar are un corespondent initial string vid
Complexitate timp: O(1)
Complexitate spatiu: O(1)
*/
map<char, string> SolutionClass::getAlphabetMap() {
    map<char, string> alphabetMap;
    for (char c = 'a'; c <= 'z'; ++c) {
        alphabetMap[c] = "";
    }
    return alphabetMap;
}

/*
Return: Un vector care contine cuvintele din text care au fost separate prin spatiu
Complexitate timp: O(n)
Complexitate spatiu: O(n)
*/
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

/*
Return: 
    -1 , daca word1 este mai mic dpdv lexicografic fata de word2
     0 , daca sunt egale
     1 , daca word1 este mai mare dpdv lexicografic fata de word2
Complexitate timp: O(L) , L - lungimea unui cuvant, insa L nu poate depasi n deci complexitatea finala este O(n)
Complexitatea spatiu: O(1)
*/
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

/*
Return: cuvantul cel mai mare dpdv lexicografic
Complexitate timp: O(n) + O(n) + O(1) = O(n)
Complexitate spatiu: O(n)
*/
string SolutionClass::getResult(const string& textGiven) {
    sir = textGiven;
    vector<string> stringSplit{ splitString() };
    map<char, string> alphabetMap{ getAlphabetMap() };

    for (const string& word : stringSplit) {
        int firstChar{ tolower(word[0]) };
        if(compareInsensitiveStrings(word, alphabetMap[firstChar]) == 1)
            alphabetMap[firstChar] = word;
    }

    for (auto itr = alphabetMap.rbegin(); itr != alphabetMap.rend(); ++itr) {
        if (!itr->second.empty())
            return itr->second;
    }
    return "";
}
int main() {
    SolutionClass sol = SolutionClass();
    assert(sol.getResult("Ana are mere si pere") == "si");
    assert(sol.getResult("") == "");
    assert(sol.getResult("Gabon este o tara localizata pe ecuator") == "tara");
    assert(sol.getResult("Sucevita este o localitate din judetul Suceava") == "Sucevita");
    return 0;
}