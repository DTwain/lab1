/*
7. Să se determine al k-lea cel mai mare element al unui șir de numere cu n elemente (k < n). 
De ex. al 2-lea cel mai mare element din șirul [7,4,6,3,9,1] este 7.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cassert>

using std::priority_queue;
using std::vector;
using std::cin;
using std::cout;


class SolutionClass {
    public:
        SolutionClass() {}
        int getResult(const vector<int>& vec, int k);
};
/*
[7,4,6,3,9,1] 
[7,4,6,3,9,1,8] 
Return type: int
vec : vectorul de numere
k : va determina care cel mai mare numar vrem sa-l determinam
Complexitatea timp: O(n * log(k))
Complexitatea spatiu: O(n)
*/
int SolutionClass::getResult(const vector<int>& vec, int k) {
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for(int element : vec) {
        minHeap.push(element);
        if(minHeap.size() > k)
            minHeap.pop();
    }
    return minHeap.top();
}
int main() {
    SolutionClass sol;
    vector<int> vec = {7,4,6,3,9,1};
    assert(sol.getResult(vec, 2) == 7);

    assert(sol.getResult(vec, 3) == 6);

}