#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Returns the words that appear exactly once in the given text.
// Complexitate timp: O(n)
// Complexitate spatiu O(n)
vector<string> getUniqueWords(const string& text) {
    unordered_map<string, int> wordCount;
    vector<string> order;
    istringstream iss(text);
    string word;
    
    // Tokenize the text and count each word.
    while (iss >> word) {
        if (wordCount[word] == 0) {
            order.push_back(word);
        }
        wordCount[word]++;
    }
    
    // Collect words that appear exactly once.
    vector<string> result;
    for (const string& w : order) {
        if (wordCount[w] == 1) {
            result.push_back(w);
        }
    }
    return result;
}

int main() {
    string text = "ana are ana are mere rosii ana";
    vector<string> uniqueWords = getUniqueWords(text);
    
    // Expected unique words: "mere" and "rosii"
    vector<string> expected = { "mere", "rosii" };
    
    // Test the returned result.
    if (uniqueWords == expected) {
        cout << "Test passed." << endl;
    } else {
        cout << "Test failed." << endl;
        cout << "Expected: ";
        for (const auto &w : expected) {
            cout << w << " ";
        }
        cout << "\nGot: ";
        for (const auto &w : uniqueWords) {
            cout << w << " ";
        }
        cout << endl;
    }
    
    return 0;
}
