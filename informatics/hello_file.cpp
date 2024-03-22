#include <iostream>
#include "vector"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = 0; j < numbers.size()-i; ++j) {
            if (numbers[j] < numbers[j+1]) {
                swap(numbers[j], numbers[j+1]);
            }
        }
    }
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << "\n";
}