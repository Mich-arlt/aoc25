#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad2_data");
    vector<string> input_vector;
    string sub_string;
    string sub_string1;
    if (input.is_open()) {
        string line;
        if (getline(input, line)) {
            stringstream ss(line);
            while (getline(ss, sub_string, ',')) {
                stringstream ss1(sub_string);
                while (getline(ss1, sub_string1, '-')) {
                    input_vector.push_back(sub_string1);
                }
            }
        }
        input.close();
    }
    long long sum = 0;
    for (int i = 0; i < input_vector.size(); i+=2) {
        cout << input_vector[i]<<"-"<< input_vector[i+1] << endl;
        for (long long j = stoll(input_vector[i]);j <= stoll(input_vector[i+1]);j++ ) {
            // cout << j << endl;
            string s = to_string(j);
            int half_len = s.length() / 2;
            string part1 = s.substr(0, half_len);
            string part2 = s.substr(half_len, s.length() - half_len);
            if (part1 == part2) {
                sum+=j;
            }
        }
    }
    cout << sum << endl;


    return 0;
}