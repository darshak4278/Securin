#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> Die_A = {1, 2, 3, 4, 5, 6};
vector<int> Die_B = {1, 2, 3, 4, 5, 6};

unordered_map<int, int> original_sums;

vector<vector<int>> diceA;
vector<vector<int>> diceB;

void find_diceA_possibility(int number, vector<int> temp) {
    if (temp.size() == 6) {
        if (find(diceA.begin(), diceA.end(), temp) == diceA.end()) {
            diceA.push_back(temp);
        }
        return;
    }

    for (int i = number; i <= 6; ++i) {
        temp.push_back(i);
        find_diceA_possibility(i, temp);
        temp.pop_back();
    }
}

void find_diceB_possibility(int number, vector<int> temp) {
    if (temp.size() == 6) {
        if (find(diceB.begin(), diceB.end(), temp) == diceB.end()) {
            diceB.push_back(temp);
        }
        return;
    }

    for (int i = number; i <= 8; ++i) { 
        temp.push_back(i);
        find_diceB_possibility(i, temp);
        temp.pop_back();
    }
}

void undoom_dice() {
    cout << "Undooming Dice A and Dice B...\n";

    for (int i = 1; i <= 6; ++i) {
        find_diceA_possibility(i, {i});
    }

    for (int j = 1; j <= 8; ++j) { 
        find_diceB_possibility(j, {j});
    }

    for (const auto& i : diceA) {
        for (const auto& j : diceB) {
            unordered_map<int, int> tdic;

            for (size_t k = 0; k < i.size(); ++k) {
                for (size_t l = 0; l < j.size(); ++l) {
                    int sum = i[k] + j[l];
                    ++tdic[sum];
                }
            }

            int c = 0;
            for (const auto& pair : tdic) {
                if (pair.second != original_sums[pair.first]) {
                    break;
                } else {
                    ++c;
                }
            }

            if (c == 11) {
                cout << "Transformed Dice A -> ";
                for (const auto& val : i) {
                    cout << val << " ";
                }
                cout << "\n";

                cout << "Transformed Dice B -> ";
                for (const auto& val : j) {
                    cout << val << " ";
                }
                cout << "\n";

                cout << "\nProbability of Dice After Transforming:\n";
                for (const auto& pair : tdic) {
                    double probability = static_cast<double>(pair.second) / (Die_A.size() * Die_B.size());
                    cout << "P(Sum = " << pair.first << ")  Occurrence = " << pair.second << "  Probability = " << probability << "\n";
                }
                return;  // No need to continue searching
            }
        }
    }
}

int main() {
    cout << "Original Dice A: ";
    for (const auto& value : Die_A) {
        cout << value << " ";
    }
    cout << "\n";

    cout << "Original Dice B: ";
    for (const auto& value : Die_B) {
        cout << value << " ";
    }
    cout << "\n";

    int total_combinations = Die_A.size() * Die_B.size();

    for (size_t i = 0; i < Die_A.size(); ++i) {
        for (size_t j = 0; j < Die_B.size(); ++j) {
            int temp = Die_A[i] + Die_B[j];
            ++original_sums[temp];
        }
    }

    cout << "\nOriginal Probabilities: \n";
    for (const auto& pair : original_sums) {
        double probability = static_cast<double>(pair.second) / total_combinations;
        cout << "P(Sum = " << pair.first << ")  Occurrence = " << pair.second << "  Probability = " << probability << "\n";
    }

    undoom_dice();

    return 0;
}