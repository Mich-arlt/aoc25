#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    long x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

bool onSegment(Point p, Point r, Point q) {
    return q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
           q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y) &&
           std::abs((r.y - p.y) * (q.x - r.x) - (r.x - p.x) * (q.y - r.y)) < 1e-9;
}

bool isInside(const std::vector<Point>& polygon, Point p) {
    if (std::find(polygon.begin(), polygon.end(), p) != polygon.end()) {
        return true;
    }
    bool result = false;
    int j = polygon.size() - 1;

    for (int i = 0; i < polygon.size(); i++) {
        if (onSegment(polygon[i], polygon[j], p)) {
            return true;
        }
        if ((polygon[i].y > p.y) != (polygon[j].y > p.y)) {
            if (p.x < (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x) {
                result = !result;
            }
        }
        j = i;
    }

    return result;
}


std::vector<Point> getRectanglePerimeter(const std::vector<Point>& input) {
    std::vector<Point> perimeter;

    if (input.size() != 2) return perimeter;

    int min_x = std::min(input[0].x, input[1].x);
    int max_x = std::max(input[0].x, input[1].x);
    int min_y = std::min(input[0].y, input[1].y);
    int max_y = std::max(input[0].y, input[1].y);

    int step = 1400;

    if (min_x == max_x || min_y == max_y) {
        for (int x = min_x; x <= max_x; x += step) {
            for (int y = min_y; y <= max_y; y += step) {
                perimeter.push_back({x, y});
            }
        }
        return perimeter;
    }

    for (int x = min_x; x <= max_x; x += step) {
        perimeter.push_back({x, min_y});
        perimeter.push_back({x, max_y});
    }

    for (int y = min_y + step; y < max_y; y += step) {
        perimeter.push_back({min_x, y});
        perimeter.push_back({max_x, y});
    }

    return perimeter;
}


int main() {
    ifstream input("C:/Users/mradz/aoc2025/data/zad9_data");
    vector<Point> input_vector;
    vector<Point> sq_points;

    long x,y;
    char comma;
    while (input >> x >> comma >> y ) {
        input_vector.push_back({x, y});
    }
    input.close();

    vector<Point> input_vector2 = input_vector;

    Point first = input_vector[0];
    input_vector.erase(input_vector.begin());
    long long max_size = 0;
    int v = 0;
    while (input_vector.size() > 0) {
        v++;
        cout << v << endl;
        for (int i = 0; i < input_vector.size(); i++) {
            sq_points = getRectanglePerimeter({first,input_vector[i]});
            bool if_in = true;
            for (const auto& p : sq_points) {
                if (isInside(input_vector2, p)==false) {
                    if_in = false;
                    break;
                }
            }
            sq_points.clear();
            if (if_in) {
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

        }
        first = input_vector[0];
        input_vector.erase(input_vector.begin());
    }
    cout << max_size;

    return 0;
}