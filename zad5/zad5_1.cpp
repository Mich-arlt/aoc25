#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad5_data");
    vector<long long> input_vector;
    vector<long long> input_vector2;
    string sub_string;

    bool state = true;
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            stringstream ss(line);
            if (line == " " || line == "") {
                state = false;
            }
            if (state == true) {
                while (getline(ss, sub_string, '-')) {
                    input_vector.push_back(stoll(sub_string));
                }
            }
            else {
                while (getline(ss, sub_string)) {
                    input_vector2.push_back(stoll(sub_string));

                }
            }
        }
        input.close();
    }
    int sum = 0;
    for (int i = 0; i < input_vector2.size(); i++) {
        for (int j = 0; j < input_vector.size(); j+=2) {
            if (input_vector[j]<=input_vector2[i] and input_vector2[i]<=input_vector[j+1]) {
                sum++;
                break;
            }
        }
    }
    cout << sum << endl;



    return 0;
}