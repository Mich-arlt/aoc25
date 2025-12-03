#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad2_data");
    vector<string> input_vector;
    vector<string> vector1;
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
            string s = to_string(j);
            for(int k = 1; k < s.length(); k++){
                string first_fragment;
                int len_to_cut = k;
                for (int g = 0; g < s.length(); g += k) {
                    if (s.length() - g < k) {
                        len_to_cut = s.length() - g;
                    }
                    vector1.push_back(s.substr(g, len_to_cut)) ;
                }
                if ( adjacent_find( vector1.begin(), vector1.end(), not_equal_to<>() ) == vector1.end() )
                {
                    sum += j;
                    break;
                }
                vector1.clear();
            }

        }
    }
    cout << sum << endl;


    return 0;
}