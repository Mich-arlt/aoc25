#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad7_data");
    ifstream input2("C:/Users/mradz/aoc2025/data/zad7_data");

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
        string tab[h][lin_len];
        int j =0;
        while (getline(input2, line)) {
            for (int i = 0; i < lin_len; i++) {
                tab[j][i]= line[i] ;
            }
            j++;
        }
        input.close();
        long long sum = 0;
        for (int q = 0; q < h-1; q++) {
            for (int z = 0; z < lin_len; z++) {
                // cout << tab[q][z] << "\t";
                if (tab[q][z] == "S") {
                    tab[q+1][z] = "1";
                }
                else if (tab[q][z] != "." and tab[q][z] != "^") {
                    if (tab[q+1][z] == ".") {
                        tab[q+1][z] = tab[q][z];
                    }
                    else if (tab[q+1][z] == "^") {
                        if (tab[q+1][z+1] == ".") {tab[q+1][z+1] = to_string(stoll(tab[q][z]));}
                        else if (tab[q+1][z+1] != "." and tab[q+1][z+1] != "^") {tab[q+1][z+1] = to_string(stoll(tab[q+1][z+1])+stoll(tab[q][z]));}
                        if (tab[q+1][z-1] == ".") {tab[q+1][z-1] = to_string(stoll(tab[q][z]));;}
                        else if (tab[q+1][z-1] != "." and tab[q+1][z-1] != "^") {tab[q+1][z-1] = to_string(stoll(tab[q+1][z-1])+stoll(tab[q][z]));}

                    }
                    else {
                        tab[q+1][z] = to_string(stoll(tab[q+1][z])+ stoll(tab[q][z]));
                    }
                }

            }
        }

        // for (int q = 0; q < h; q++) {
        //     for (int z = 0; z < lin_len; z++) {
        //         cout << tab[q][z] << "\t";
        //     }
        // }
            for (int z = 0; z < lin_len; z++) {
                if (tab[h-1][z] != ".") {
                    sum += stoll(tab[h-1][z]);
                }
            }

        cout <<sum<< endl;
    }
    return 0;
}