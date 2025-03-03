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
            makePartialSumMatrix();
        }
};

/*
Determinam matricea sumelor partiale, lucram direct pe matricea initiala
complexitate timp: THETA(n * m)
complexitate spatiu: THETA(1)
*/
void SolutionClass::makePartialSumMatrix() {
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            int topLeftValue = 0,
            downLeftValue = 0,
            topRightValue = 0,
            downRightValue = matrix[i][j];
            
            if(i != 0 && j != 0)
                topLeftValue = matrix[i - 1][j - 1];
            if(j != 0)
                downLeftValue = matrix[i][j - 1];
            if(i != 0)
                topRightValue = matrix[i - 1][j];

            matrix[i][j] += topRightValue + downLeftValue - topLeftValue;
        }
    }
}

/*
Determinarea vectorului cu sumele din fiecare patrat delimiatat de coordonate
Return type: vectorul care contine sumele corespunzatoare perechilor
vector_coordonate : vectorul care contine perechile de indici
complexitate timp: Theta(n) , n - numarul de perechi de coordonate
complexitate spatiu: Theta(n)
*/
vector<int> SolutionClass::getResult(vector<pair<pair<int, int>, pair<int,int>>> vector_coordonate) {
    vector<int> sums;
    for(auto elem : vector_coordonate) {
        auto firstCoordinates = elem.first;
        auto secondCoordinates = elem.second;
        
        int X_firstCoordinate = firstCoordinates.first,
            Y_firstCoordinate = firstCoordinates.second,
            X_secondCoordinate = secondCoordinates.first,
            Y_secondCoordinate = secondCoordinates.second;

        int topLeftValue = 0,
            downLeftValue = 0,
            topRightValue = 0,
            downRightValue = matrix[X_secondCoordinate][Y_secondCoordinate];
        
        if(X_firstCoordinate != 0 && Y_firstCoordinate != 0)
            topLeftValue = matrix[X_firstCoordinate - 1][Y_firstCoordinate - 1];
        if(Y_firstCoordinate != 0)
            downLeftValue = matrix[X_secondCoordinate][Y_firstCoordinate - 1];
        if(X_firstCoordinate != 0)
            topRightValue = matrix[X_firstCoordinate - 1][Y_secondCoordinate];
        
        sums.push_back(downRightValue - downLeftValue - topRightValue + topLeftValue);
    }
    return sums;
}

/*
Aceasta metoda este ideala pentru cazul in care avem un numar de perechi mare.
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

    return 0;
}