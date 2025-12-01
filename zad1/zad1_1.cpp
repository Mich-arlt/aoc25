#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad1_data");
    vector<string> input_vector;
    string sub_string;

    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            input_vector.push_back(line);
        }
        input.close();
    }
    int sum = 0;
    int i = 50;
    for (const string& input_line : input_vector) {
        const char d = input_line[0];
        if (const int len = input_line.length(); len<3) {
            sub_string = input_line.substr(1);
        }
        else {
            sub_string = input_line.substr(len - 2,2);
        }
        const int move = stoi(sub_string);
        if (d == 'L') {
            i -= move;
            if (i < 0) {
                i = 100 + i;
            }
        }
        else {
            i += move;
            if (i > 100) {
                i = i-100;
            }
        }
        if (i == 0 or i == 100) {
            sum++;
            i=0;
        }
    }
    cout << sum << endl;


    return 0;
}