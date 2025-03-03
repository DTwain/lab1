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
public:
    vector<string> getResult(const string& textGiven);
};


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
Return: Un vector care contine cuvintele din text care au fost separate prin spatiu
textGiven - textul dat la input 
Complexitate timp: O(n)
Complexitate spatiu: O(n)
*/
vector<string> SolutionClass::getResult(const string& textGiven) {
    sir = textGiven;
    vector<string> stringSplit{ splitString() };
    map<string, int> wordsMap;
    vector<string> wordsThatApearOnce;

    for (const string& word : stringSplit) {
        if(wordsMap.find(word) == wordsMap.end()) 
            wordsMap[word] = 1;
        else
            wordsMap[word] += 1;
    }

    for(auto iter = wordsMap.begin(); iter != wordsMap.end(); ++iter)
        if(iter -> second == 1)
            wordsThatApearOnce.push_back(iter -> first);
    
    return wordsThatApearOnce;
}
int main() {
    SolutionClass sol = SolutionClass();
    vector<string> vec = sol.getResult("ana are ana are mere pere si mere");
    for(auto elem : vec) {
        std::cout << elem << " ";
    }

    assert(vec.size() == 2);
    assert(vec[0]== "pere");
    assert(vec[1] == "si");

    std::cout<<"\n";
    vec = sol.getResult("ana are ana are mere rosii ana");
    for(auto elem : vec) {
        std::cout << elem << " ";
    }

    assert(vec.size() == 2);
    assert(vec[0] == "mere");
    assert(vec[1] == "rosii");

    return 0;
}