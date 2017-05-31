#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

boolean can_split;

string msplit(string x) {
    /*check if word is in array
 * if true return value
 * else 
 * for 1 to length of x
 * split into two variables, first is first character of x, second is remaining characters of x
 * check if first variable is in dictionary
 * if true store in array
 * run split on second variable
 * return divided substring
 */
    if (dictionary(x)) {
        
    }
    else {
        for (int i = 0; i < x.length(); i++) {
            
        }
    }
}

string bsplit(string x) {

}

bool dictionary(string x, vector<string> dict) {
   /*check dictionary if x is in dictionary
 * if true, retrun true
 */ 
    for (int i = 0; i < dict.size(); i++) {
        if (x == dict[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<char> s;
    string str, line;
    int n;
    ifstream in;
    in.open("dictionMed.txt") // change to diction10k.txt
    getline(cin, line);
    istringstream iss(line);
    iss >> n;
    for (i = 1; i <= n; i++) {
        getline(cin, line);
        istringstream iss(line);
        iss >> str;
        bsplit(str);
        msplit(str);
    }
    return 0;
}
