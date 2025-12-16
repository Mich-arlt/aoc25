#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad6_data");
    ifstream input2("C:/Users/mradz/aoc2025/data/zad6_data");

    vector<string> input_vector;
    vector<char> signs;

    int lin_len=0;
    int h = 0;
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            if (lin_len<line.length() or lin_len ==0) {
                lin_len = line.length();
            }

            h++;
        }
        input.close();
    }
    cout << h << endl;
    cout << lin_len << endl;

    if (input2.is_open()) {
        string line;
        char tab[h][lin_len];
        int j =0;
        while (getline(input2, line)) {
            for (int i = 0; i < lin_len; i++) {
                tab[j][i]= line[i] ;
            }
            j++;
        }
        input.close();
        for (int i = 0; i < lin_len; i++) {
            if (tab[h-1][i] != ' ') {
                signs.push_back(tab[h-1][i]);
            }

        }


    }
    return 0;
}