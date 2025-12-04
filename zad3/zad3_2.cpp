#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad3_data");
    vector<string> input_vector;
    string sub_string;
    long long sum = 0;
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            input_vector.push_back(line);
        }
        input.close();
    }

    for (const string& input_line : input_vector) {
        string result = "";
        int first_num_place = 0;
        for (int j=12; j>0; j--) {
            int max_num = 0;
            int place = first_num_place;
            for (int i = place; i <= input_line.length()-j; i++) {
                int num = input_line[i] - '0';
                if (max_num < num) {
                    max_num = num;
                    first_num_place = i+1;
                }
            }
            result+=to_string(max_num);

        }
        sum += stoll(result);

    }

    cout << sum << endl;


    return 0;
}