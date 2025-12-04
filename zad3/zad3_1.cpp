#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad3_data");
    vector<string> input_vector;
    string sub_string;
    int sum = 0;
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            input_vector.push_back(line);
        }
        input.close();
    }

    for (const string& input_line : input_vector) {
        // cout << input_line << endl;
        int max_num = 0;
        int max_num_sec = 0;
        int first_num_place;
        for (int i = 0; i < input_line.length(); i++) {
           // cout << input_line[i] << endl;
            int num = input_line[i] - '0';
            if (max_num < num and i!=input_line.length()-1) {
                max_num = num;
                first_num_place = i;
            }
        }
        // cout << max_num << endl;
        for (int j = first_num_place+1; j < input_line.length(); j++) {
            // cout << input_line[j] << endl;
            int num = input_line[j] - '0';
            if (max_num_sec < num and j!=input_line.length()) {
                max_num_sec = num;
            }
        }
        // cout << max_num_sec << endl;
        string output;
        output = to_string(max_num) + to_string(max_num_sec);
        sum += stoi(output);
    }

    cout << sum << endl;


    return 0;
}