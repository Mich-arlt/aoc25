#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;


void findGroup(string node, map<string, vector<string>>& graf, set<string>& visited, vector<string>& act_group) {
    visited.insert(node);
    act_group.push_back(node);

    for (const string& sasiad : graf[node]) {
        if (visited.find(sasiad) == visited.end()) {
            findGroup(sasiad, graf, visited, act_group);
        }
    }
}

struct Point3D {
    int id; 
    double x, y, z;
};

struct Connection {
    int id_a;
    int id_b;
    double distance;
};

double calculateDistance(const Point3D& p1, const Point3D& p2) {
    return sqrt(pow(p1.x - p2.x, 2) +
                pow(p1.y - p2.y, 2) +
                pow(p1.z - p2.z, 2));
}

bool compareConnections(const Connection& a, const Connection& b) {
    return a.distance < b.distance;
}

    int main() {
    
        vector<Point3D> points;
        string filename = "C:/Users/mradz/aoc2025/data/zad8_data";
        ifstream file(filename);
    
        double x, y, z;
        char comma; 
        int line_counter = 1;
    
        while (file >> x >> comma >> y >> comma >> z) {
            points.push_back({line_counter, x, y, z});
            line_counter++;
        }
        file.close();
    
        vector<Connection> results;
    
        long long estimated_pairs = (long long)points.size() * (points.size() - 1) / 2;
        results.reserve(estimated_pairs);

        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = i + 1; j < points.size(); j++) {
                double dist = calculateDistance(points[i], points[j]);
                // cout<<points[i].id<<" "<< points[j].id<<" "<< dist<<endl;
                results.push_back({points[i].id, points[j].id, dist});
            }
        }

        sort(results.begin(), results.end(), compareConnections);
        vector<pair<string, string>> best_res;
        for (size_t i = 0; i < 1000; i++) {
            // cout << to_string(results[i].id_a)<<" "<<to_string(results[i].id_b)<<" "<<to_string(results[i].distance) << endl;
            best_res.push_back({to_string(results[i].id_a),to_string(results[i].id_b)});
        }
        map<string, vector<string>> graf;

        for (const auto& para : best_res) {
            string u = para.first;
            string v = para.second;
            
            graf[u].push_back(v);
            graf[v].push_back(u);
        }

        set<string> visited; 

        vector<int> all_groups;

        for (auto const& [node, nibrs] : graf) {
            if (visited.find(node) == visited.end()) {
                vector<string> new_group;
                findGroup(node, graf, visited, new_group);

                all_groups.push_back(new_group.size());
            }
        }
        sort(all_groups.begin(), all_groups.end(),greater<int>());
        long long sum = 1;

        for (int i = 0; i < 3; i++) {
            cout << all_groups[i] << endl;
            sum *= all_groups[i];
        }
        cout << "\n----------------" << endl;
        cout << sum << endl;
        cout << "\n----------------" << endl;

        return 0;

}