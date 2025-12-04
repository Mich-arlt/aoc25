#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad4_data");
    ifstream input2("C:/Users/mradz/aoc2025/data/zad4_data");
    vector<string> input_vector;

    int lin_len;
    int sum = 0;
    if (input.is_open()) {
        string line;
       if (getline(input, line)) {
           lin_len = line.length();
        }
        input.close();
        }

    if (input2.is_open()) {
        string line;
        char tab[lin_len][lin_len];
        char tab2[lin_len][lin_len];
        int j =0;
        while (getline(input2, line)) {
            for (int i = 0; i < lin_len; i++) {
            tab[j][i]= line[i] ;
            }
            j++;
        }
        input.close();
        int old_sum;
        while (old_sum != sum) {
            old_sum = sum;
            for (int q = 0; q < lin_len; q++) {
                for (int z = 0; z < lin_len; z++) {
                    if (tab[q][z] == '@') {
                        int at_sum=0;
                        if ((z==0 and q ==0) or (z==lin_len-1 and q ==lin_len-1) or (z==0 and q ==lin_len-1) or (z==lin_len-1 and q == 0)) {
                            at_sum= at_sum+5;
                        }
                        if (((z==0 or z == lin_len-1) and q != 0 and q !=lin_len-1) or ((q==0 or q == lin_len-1) and z != 0 and z !=lin_len-1)) {
                            at_sum= at_sum+3;
                        }
                        if (z+1 < lin_len and tab[q][z+1] == '.') {
                            at_sum++;
                        }
                        if (q+1 < lin_len and tab[q+1][z] == '.') {
                            at_sum++;
                        }
                        if (z-1 >= 0 and tab[q][z-1] == '.') {
                            at_sum++;
                        }
                        if (q-1 >= 0 and tab[q-1][z] == '.') {
                            at_sum++;
                        }
                        if (q-1 >= 0 and z-1 >= 0 and tab[q-1][z-1] == '.') {
                            at_sum++;
                        }
                        if (q+1 < lin_len and z+1 < lin_len and tab[q+1][z+1] == '.') {
                            at_sum++;
                        }
                        if (q+1 < lin_len and z-1 >= 0 and tab[q+1][z-1] == '.') {
                            at_sum++;
                        }
                        if (q-1 >= 0 and z+1 < lin_len and tab[q-1][z+1] == '.') {
                            at_sum++;
                        }
                        if (at_sum >= 5) {
                            tab2[q][z] = '.' ;
                            sum++;
                        }
                        else {
                            tab2[q][z] = tab[q][z];
                        }
                    }
                    else {
                        tab2[q][z] = tab[q][z];
                    }
                }
            }

            for (int i = 0; i < lin_len; ++i) {
                for (int j = 0; j < lin_len; ++j) {
                    tab[i][j] = tab2[i][j];
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}