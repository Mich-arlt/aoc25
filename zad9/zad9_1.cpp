#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>


struct Point {
    long x, y;
};


using namespace std;
int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad9_data");
    vector<Point> input_vector;

    long x,y;
    char comma;
    while (input >> x >> comma >> y ) {
        input_vector.push_back({x, y});
    }
    input.close();
    Point first = input_vector[0];
    input_vector.erase(input_vector.begin());
    long long max_size = 0;
    while (input_vector.size() > 0) {
        for (int i = 0; i < input_vector.size(); i++) {
            long long dy = abs(first.y - input_vector[i].y) + 1;
            long long dx = abs(first.x - input_vector[i].x) + 1;
            long long size = dx * dy;
            if (max_size == 0) {
                max_size = size;
            }
            else if (size > max_size) {
                max_size = size;
            }
        }
        first = input_vector[0];
        input_vector.erase(input_vector.begin());
    }
    cout << max_size;
    return 0;
}