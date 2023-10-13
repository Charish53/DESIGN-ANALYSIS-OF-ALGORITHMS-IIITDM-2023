/* QUESTION 3:Given an integer array, find minimum and second minimum in
least time (number of comparisons to return min and second min
must be the least)*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    vector<int> compared;
};

Node getMin(vector<int> A) {
    int n = A.size();
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i].value = A[i];
    }
    while (nodes.size() > 1) {
        vector<Node> newNodes;
        for (int i = 0; i < nodes.size(); i += 2) {
            if (i + 1 == nodes.size()) {
                newNodes.push_back(nodes[i]);
            } else if (nodes[i].value < nodes[i + 1].value) {
                nodes[i].compared.push_back(nodes[i + 1].value);
                newNodes.push_back(nodes[i]);
            } else {
                nodes[i + 1].compared.push_back(nodes[i].value);
                newNodes.push_back(nodes[i + 1]);
            }
        }
        nodes = newNodes;
    }
    return nodes[0];
}

pair<int, int> findMinSecondMin(vector<int> A) {
    Node minNode = getMin(A);
    int minVal = minNode.value;
    int secondMinVal = *min_element(minNode.compared.begin(), minNode.compared.end());
    return make_pair(minVal, secondMinVal);
}

int main() {
    vector<int> A = {-4, 3, -2, -7, 9, 1, 14, -10};
    pair<int, int> result = findMinSecondMin(A);
    cout << "Minimum: " << result.first << endl;
    cout << "Second Minimum: " << result.second << endl;
    return 0;
}

