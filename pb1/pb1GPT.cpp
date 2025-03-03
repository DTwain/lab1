#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;


/*
Complexitatea timp: O(n) , n este numarul total de litere din cuvant
Complexitatea spatiu: O(n), se utilizeaza spatiu suplimentar pentru stocarea textului si al cuvintelor suplimentare
*/
class Solution {
public:
    // Functia getResult primește un șir de caractere și returnează
    // ultimul cuvânt din punct de vedere alfabetic, comparând cuvintele
    // în mod case-insensitive.
    string getResult(const string &text) {
        istringstream iss(text);
        string word, best = "";
        while (iss >> word) {
            // Convertim cuvântul curent în litere mici pentru comparație
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
            // Convertim și cuvântul "best" curent
            string lowerBest = best;
            transform(lowerBest.begin(), lowerBest.end(), lowerBest.begin(), ::tolower);
            // Dacă cuvântul curent este mai mare alfabetic (ignorând majusculele),
            // actualizăm rezultatul.
            if (lowerWord > lowerBest) {
                best = word;
            }
        }
        return best;
    }
};

int main() {
    Solution sol = Solution();
    assert(sol.getResult("Ana are mere si pere") == "si");
    assert(sol.getResult("") == "");
    assert(sol.getResult("Gabon este o tara localizata pe ecuator") == "tara");
    assert(sol.getResult("Sucevita este una din localitatile din judetul Suceava") == "una");
    assert(sol.getResult("Sucevita este o localitate din judetul Suceava") == "Sucevita");
    return 0;
}
