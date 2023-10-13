/* QUESTION 2:Given an integer n, find (i) prime factors of n (ii) prime
factorization of n (iii) all factors (iv) sum of all factors*/
#include <iostream>
#include <vector>
using namespace std;

// Function to find prime factors of n
vector<int> primeFactors(int n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

// Function to find all factors of n
vector<int> allFactors(int n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    // Prime factors
    vector<int> primeFactorsList = primeFactors(n);
    cout << "Prime factors of " << n << ": ";
    for (int factor : primeFactorsList) {
        cout << factor << " ";
    }
    cout << endl;

    // Prime factorization
    cout << "Prime factorization of " << n << ": ";
    for (int factor : primeFactorsList) {
        cout << factor << " ";
    }
    cout << endl;

    // All factors
    vector<int> allFactorsList = allFactors(n);
    cout << "All factors of " << n << ": ";
    for (int factor : allFactorsList) {
        cout << factor << " ";
    }
    cout << endl;

    // Sum of all factors
    int sum = 0;
    for (int factor : allFactorsList) {
        sum += factor;
    }
    cout << "Sum of all factors of " << n << ": " << sum << endl;

    return 0;
}
//Factors

