/*QUESTION1:Given an integer array A, how efficiently can you find the duplicates in
A. Also, print the multiplicity for each integer in A.*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void findDuplicates(vector<int> A) {
    unordered_map<int, int> count;
    for (int x : A) {
        count[x]++;
    }
    for (auto p : count) {
        if (p.second > 0) {
            cout << p.first << " appears " << p.second << " times" << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    findDuplicates(A);
    return 0;
}

