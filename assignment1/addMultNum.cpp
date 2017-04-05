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
    int x, y;
    cin.get(b);
    int a = (int) b;
    cout << b << endl;
    cout << a << endl; 
    string line;
    for (int i = 0; i < 1; i++) {
        getline(cin, line);
        istringstream iss(line);
        iss >> x >> y;
        addMultNum(x,y);
}
    
    return 0;
}
