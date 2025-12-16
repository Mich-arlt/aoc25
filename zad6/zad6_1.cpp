#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad6_data");
    string sub_string;

    vector<long long> input_vector;
    vector<long long> input_vector_sub;

    vector<string> input_vector2;


    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            stringstream ss(line);
            while (getline(ss, sub_string, ' ')) {
                if (!sub_string.empty() && sub_string.find_first_not_of("0123456789") == std::string::npos) {
                    input_vector.push_back(stoll(sub_string));
                }
                else if (!sub_string.empty() && sub_string.find_first_not_of("*+") == std::string::npos) {
                    input_vector2.push_back(sub_string);
                }

            }
        }
        int eq_size = input_vector.size() / input_vector2.size();
        input.close();
        for (int j = 0; j < input_vector2.size(); j++) {
            for (int i = j; i < input_vector.size(); i+=input_vector2.size()) {
                input_vector_sub.push_back(input_vector[i]);
            }
        }
        long long result = 0;

        int q_len = 0;
        for (int i = 0; i < input_vector2.size(); i++) {
            long long sum_add = 0;
            long long sum_x = 1;
            cout << input_vector2[i] << endl;
            for (int q = q_len; q < q_len + eq_size; q++) {
                cout << input_vector_sub[q] << endl;
                if (input_vector2[i] == "*") {
                    sum_x*=input_vector_sub.at(q);

                }
                else {
                    sum_add+=input_vector_sub.at(q);
                }

            }
            result += sum_add;
            if (sum_x != 1) {
                result+=sum_x;
            }
            q_len+=eq_size;

        }
        cout << result << endl;
    }

    return 0;
}