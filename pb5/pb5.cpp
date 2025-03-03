/*
5. Pentru un șir cu n elemente care conține valori din mulțimea {1, 2, ..., n - 1} astfel încât o singură valoare se repetă de două ori, 
să se identifice acea valoare care se repetă. De ex. în șirul [1,2,3,4,2] valoarea 2 apare de două ori.
*/
#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using std::vector;
using std::map;

class SolutionClass {
    public:
        SolutionClass() {}
        int getResult(const vector<int>& vec);
};

/*
Return: Numarul care este duplicat in sirul dat
vec : sirul de numere 
Complexitate timp: O(n), se insumeaza liniar cele n valori.
Complexitate spatiu: O(1), nu se folosesc tablouri aditionale 
*/
int SolutionClass::getResult(const vector<int>& vec) {
    int sum_from_1_to_n = ((vec.size() - 1) * vec.size() / 2);
    int sum_of_elements = 0;
    for(int elem : vec)
        sum_of_elements += elem;
    
    return sum_of_elements - sum_from_1_to_n;
}
int main() {    
    SolutionClass sol;
    assert(sol.getResult({1,2,3,2,4}) == 2);

    assert(sol.getResult({1,4,2,1,3}) == 1);
    return 0;
}