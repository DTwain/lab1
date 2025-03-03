/*
4. Să se determine cuvintele unui text care apar exact o singură dată în acel text. 
De ex. cuvintele care apar o singură dată în ”ana are ana are mere rosii ana" sunt: 'mere' și 'rosii'.
*/
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
Return: vector care contine cuvintele care nu se repeta
textGiven - textul pe care l-am primit
Complexitate timp: O(n ^ 2)
Complexitate spatiu: O(n)
*/
vector<string> SolutionClass::getResult(const string& textGiven) {
    sir = textGiven;
    vector<string> stringSplit{ splitString() };
    vector<string> wordsThatApearOnce;

    for(int i = 0; i < stringSplit.size(); ++i) {
        bool duplicate = false;
        for(int j = 0; j < stringSplit.size(); ++j) 
            if(stringSplit[i] == stringSplit[j] && i != j) {
                duplicate = true;
                break;
            }
        if(!duplicate)
            wordsThatApearOnce.push_back(stringSplit[i]);
    }
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