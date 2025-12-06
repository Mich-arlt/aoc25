#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad5_data");
    vector<long long> input_vector;
    vector<long long> vector2;
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

        }
        input.close();
    }
    while (input_vector.size() !=2) {
        long long start = input_vector.front();
        input_vector.erase(input_vector.begin());
        long long end = input_vector.front();
        input_vector.erase(input_vector.begin());
        bool state1 = false;
        for (int i = 0; i < input_vector.size(); i+=2) {
            if (start < input_vector[i] and end >= input_vector[i] and end < input_vector[i+1]) {
                input_vector[i] = start;
                state1 = true;
                break;
            }
            if (start <= input_vector[i+1] and end > input_vector[i+1] and start > input_vector[i]) {
                input_vector[i+1] = end;
                state1 = true;
                break;
            }
            if (start < input_vector[i] and end > input_vector[i+1]) {
                input_vector[i] = start;
                input_vector[i+1] = end;
                state1 = true;
                break;
            }
            if (start >= input_vector[i] and end <= input_vector[i+1]) {
                state1 = true;
                break;
            }
            if (start < input_vector[i] and end == input_vector[i+1]) {
                input_vector[i] = start;
                state1 = true;
                break;
            }
            if (start == input_vector[i] and end > input_vector[i+1]) {
                input_vector[i+1] = end;
                state1 = true;
                break;
            }
        }
        if (state1 == false) {
            vector2.push_back(start);
            vector2.push_back(end);
        }
    }
    vector2.push_back(input_vector[0]);
    vector2.push_back(input_vector[1]);

    long long sum = 0;
    for (int z = 0; z < vector2.size(); z+=2) {
        sum += vector2[z+1] - vector2[z] +1;
    }
    cout << sum << endl;

    return 0;
}