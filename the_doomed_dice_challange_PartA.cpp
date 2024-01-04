#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    
    int total = 6 * 6;
    cout << "\nTotal Combinations Possible with 2 Dice: " << total << endl;


    vector<vector<pair<int, int>>> distribution;
    vector<vector<int>> dicesum;

    for (int i = 1; i <= 6; ++i) {
        vector<pair<int, int>> row;
        vector<int> sumRow;

        for (int j = 1; j <= 6; ++j) {
            row.push_back(make_pair(i, j));
            sumRow.push_back(i + j);
        }

        distribution.push_back(row);
        dicesum.push_back(sumRow);
    }

    
    cout << "\nDistribution Matrix for 2 Dice:" << endl;
    for (const auto& row : distribution) {
        for (const auto& pair : row) {
            cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        cout << endl;
    }

    
    cout << "\nSum of Distribution Matrix for 2 Dice:" << endl;
    for (const auto& row : dicesum) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    
    cout << "\nProbability Distribution for all possible Sums: " << endl;
    for (int i = 2; i <= 12; ++i) {
        int combinations = 0;

        for (const auto& row : dicesum) {
            for (int val : row) {
                if (val == i) {
                    ++combinations;
                }
            }
        }

        double probability = static_cast<double>(combinations) / total;
        cout << "P(Sum = " << i << "): " << probability << " => "
             << fixed << setprecision(2) << probability * 100 << endl;
    }

    return 0;
}