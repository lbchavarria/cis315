#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> path_list;

<<<<<<< HEAD
int pathCount(map<int, vector<int> > map, int start, int end) {
    int count = 0;
    if (map[start].empty()) {
=======
int pathCount(map<int, vector<int> > map, int start, int end, int count) {
    count = 1;
    if (map[start].size() == 0) {
>>>>>>> 713daf660a606b6afe8138ed8f0324089f4e5d94
        count = 0;
        return count;
    }
    for (int i = 0; i < map[start].size(); i++) {
<<<<<<< HEAD
        count += 1 + pathCount(map, map[start][i], end);
=======
        count += pathCount(map, map[start][i], end, count);
>>>>>>> 713daf660a606b6afe8138ed8f0324089f4e5d94
        if (map[start][i] == end) {
            path_list.push_back(count);
        }
    }
    return count;
}

void printPaths(int graph_num, int path_num) {
    int min = 0;
    int max = 0;
    for (int i = 0; i < path_list.size(); i++) {
        if (i == 0) {
            min = path_list[i];
            max = path_list[i];
        }
        else {
            if (path_list[i] < min) {
                min = path_list[i];
            }
            if (path_list[i] > max) {
                max = path_list[i];
            }
        }
    }
    cout << "graph number: " << graph_num << endl;
    cout << "Shortest path: " << min << endl;
    cout << "Longest path: " << max << endl;
    cout << "Number of paths: " << path_num << endl;
    cout << endl;
}

void clearPathList() {
    path_list.clear();
}

int getLine(string line) {
    int n;
    getline(cin, line);
    istringstream iss(line);
    iss >> n;
    return n;
}

int main() {
    map<int, vector<int> > map;
    int x, y, graph_num,  node_num, edge_num, path_num;
    int a = 0;
    string line;
    getline(cin, line);
    istringstream iss(line);
    iss >> graph_num;
    for (int i = 1; i <= graph_num; i++) {
        map.clear();
        //getline(cin, line);
        //istringstream iss(line);
        //iss >> node_num;
        node_num = getLine(line);
        getline(cin, line);
        istringstream iss(line);
        iss >> edge_num;
        for (int j = 0; j < edge_num; j++) {
            getline(cin, line);
            istringstream iss(line);
            iss >> x >> y;
            map[x].push_back(y);
        }
        int a = 0;
        a = pathCount(map, 1, node_num, a);
        path_num = path_list.size();
        printPaths(i, path_num);
        clearPathList();
    }
    return 0;
}
