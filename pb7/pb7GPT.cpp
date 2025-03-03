#include <iostream>
#include <vector>
#include <algorithm>  // pentru std::nth_element și std::greater

/*
complexitate timp: O(n * log(n))
complexitatea spatiu: O(1)
*/
int main() {
    // Exemplu: sir = [7,4,6,3,9,1], k = 2
    // Al 2-lea cel mai mare element ar trebui să fie 7.
    
    std::vector<int> sir = {7, 4, 6, 3, 9, 1};
    int k = 2;  // k < n, unde n = sir.size()
    
    // Folosim un comparator std::greater<int>() pentru a găsi al k-lea element "cel mai mare".
    // (Implicit, nth_element găsește poziția dacă am sorta crescător, 
    //  dar noi vrem invers, deci folosim std::greater<int>.)
    std::nth_element(
        sir.begin(),               // începutul
        sir.begin() + (k - 1),     // poziția (k-1) în zero-based indexing
        sir.end(),                 
        std::greater<int>()        // comparator pentru ordonare descrescătoare
    );
    
    // După această operație, sir[k-1] este al k-lea cel mai mare element.
    std::cout << "Al " << k << "-lea cel mai mare element este: " << sir[k - 1] << '\n';

    return 0;
}
