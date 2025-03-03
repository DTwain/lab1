#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    // Folosim o matrice 1-indexată pentru a simplifica calculul
    vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }
    
    // Construim matricea de prefixe
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] = mat[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    
    // Citim numărul de perechi de coordonate (submatrici)
    int q;
    cin >> q;
    while(q--) {
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        
        // Dacă coordonatele nu sunt ordonate (p <= r și q <= s), le rearanjăm
        if(p > r) swap(p, r);
        if(q > s) swap(q, s);
        
        // Calculăm suma submatricei folosind formula matricei de prefixe
        int sum = prefix[r][s] - prefix[p - 1][s] - prefix[r][q - 1] + prefix[p - 1][q - 1];
        cout << sum << "\n";
    }
    
    return 0;
}
/*
Calculul matricei de sume partiale O(n * m)
Calculul sumei pentru fiecare interogare O(1)
Spatiu: O(n * m)

Complexitatea timp totala: O(n * m + p)
Complexitataea spatiu: O(n * m)

*/
