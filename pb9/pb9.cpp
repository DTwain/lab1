/*
Considerându-se o matrice cu n x m elemente întregi și o listă cu perechi formate din coordonatele a 2 căsuțe din matrice
 ((p,q) și (r,s)), să se calculeze suma elementelor din sub-matricile identificate de fieare pereche.
De ex, pt matricea
[[0, 2, 5, 4, 1],
[4, 8, 2, 3, 7],
[6, 3, 4, 6, 2],
[7, 3, 1, 8, 3],
[1, 5, 7, 9, 4]]
și lista de perechi ((1, 1) și (3, 3)), ((2, 2) și (4, 4)), suma elementelor din prima sub-matrice este 38,
 iar suma elementelor din a 2-a sub-matrice este 44.
*/
#include <iostream>
#include <vector> 
#include <cassert>

using std::vector;
using std::cout;
using std::cin;
using std::copy;
using std::pair;

class SolutionClass {
    private: 
        vector<vector<int>> matrix;
        void makePartialSumMatrix();
    public:
        SolutionClass() {}
        vector<int> getResult(vector<pair<pair<int, int>, pair<int,int>>> lista_coordonate);
        void setMatrix(vector<vector<int>> matrixGiven) {
            matrix = matrixGiven;
        }
};

/*
Determinarea vectorului cu sumele din fiecare patrat delimiatat de coordonate
Aceasta metoda poate fi vicioasa daca perechile sunt in numar foarte mare si desemneaza submatrici de dimensiuni mari
Return type: vectorul care contine sumele corespunzatoare perechilor
vector_coordonate : vectorul care contine perechile de indici
complexitate timp: O(n * m * p)
complexitate spatiu: Theta(p)
*/
vector<int> SolutionClass::getResult(vector<pair<pair<int, int>, pair<int,int>>> vector_coordonate) {
    vector<int> sums;
    for(auto elem : vector_coordonate) {
        size_t sum = 0;
        auto firstCoordinates = elem.first;
        auto secondCoordinates = elem.second;
        
        int X_firstCoordinate = firstCoordinates.first,
            Y_firstCoordinate = firstCoordinates.second,
            X_secondCoordinate = secondCoordinates.first,
            Y_secondCoordinate = secondCoordinates.second;

        for(int i = X_firstCoordinate; i <= X_secondCoordinate; ++i)
            for(int j = Y_firstCoordinate; j <= Y_secondCoordinate; ++j)
                sum += matrix[i][j];
        sums.push_back(sum);
    }
    return sums;
}

/*
Complexitate timp: Theta(n * m * p) 
n - numarul de linii
m - numarul de coloane
p - numarul de perechi
Complexitatea spatiu: Theta(max(n * m, p))
*/
int main() {
    SolutionClass sol;
    sol.setMatrix({ {0, 2, 5, 4, 1},
        {4, 8, 2, 3, 7},
        {6, 3, 4, 6, 2},
        {7, 3, 1, 8, 3},
        {1, 5, 7, 9, 4}});
    vector<int> sums { sol.getResult({ { {1, 1}, {3, 3} }, { {2, 2}, {4, 4} } }) };
    
    assert(sums.size() == 2);
    assert(sums[0] == 38);
    assert(sums[1] == 44); 

    sol.setMatrix({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });
    
    sums = sol.getResult({
        {{0, 0}, {0, 0}},
        {{0, 0}, {1, 1}}
    });
    

    assert(sums.size() == 2);
    assert(sums[0] == 1);
    assert(sums[1] == 12);

    return 0;
}