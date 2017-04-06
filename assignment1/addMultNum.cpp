#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void addMultNum(int x, int y) {
    int sum, product;
    sum = x + y;
    product = x * y;
    cout << sum << " " << product << endl;
}

int main() {
    int line_num;
    int x, y;
    string line;
    getline(cin, line);
    istringstream iss(line);
    iss >> a;
    for (int i = 0; i < line_num; i++) {
        getline(cin, line);
        istringstream iss(line);
        iss >> x >> y;
        addMultNum(x,y);
}
    
    return 0;
}
