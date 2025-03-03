#include <iostream>
using namespace std;
/*
    Complexitatea spatiu: O(1)
    Complexitatea timp: O(n)
*/
int main() {
    int n;
    cin >> n;
    int suma = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        suma += x;
    }
    
    // Suma numerelor de la 1 la n - 1
    int sumaAsteptata = (n - 1) * n / 2;
    
    // Diferența dintre suma reală și cea așteptată este valoarea repetată
    cout << suma - sumaAsteptata;
    
    return 0;
}
