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
    char b;
    char c;
    int a;
    int x, y;
    string line;
    //cin.get(b);
    getline(cin, line);
    istringstream iss(line);
    iss >> a;
    //int a = (int) b;
    cout << b;
    cout << a << endl; 
    //string line;
    for (int i = 0; i < a; i++) {
        getline(cin, line);
        istringstream iss(line);
        iss >> x >> y;
        addMultNum(x,y);
}
    
    return 0;
}
