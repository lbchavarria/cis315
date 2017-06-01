#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

bool can_split;
vector<string> dict;
string s;
int m;

string bsplit(string x) {
    return "";
}

vector<string> tokenize1(string str) {
    istringstream iss(str);
    vector<string> tokens{istream_iterator<string>{iss},
                          istream_iterator<string>{}};
    return tokens;
}

bool dictionary1(string x) {
   /*check dictionary if x is in dictionary
 * if true, retrun true
 */ 
    vector<string> v = tokenize1(x);
    for (int i = 0; i < v.size(); i++) {
        if (find(dict.begin(), dict.end(), v[i]) == dict.end()) {
            return false;
        }
    }
    return true;
}

string msplit(string x, string str) {
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
    if (x == "") {
        cout << "end of string" << endl;
        return "";
    }
    else {
        for (int i = 0; i < x.length(); i++) {
            str.append(x.substr(0,1));
            string substr2 = x.substr(1);
            cout << "substrings made: " << str << " " << substr2 << endl;
            if (dictionary1(str)) {
                cout << "in dictionary" << endl;
                str.append(" ");
                can_split = true;
            }
            else {
                cout << "not in dictionary" << endl;
                can_split = false;
            }
            cout << "split" << endl;
            str.append(msplit(substr2, str));
        }
    }
    cout << "done" << endl;
    return str;
}

bool memosplit(string x, vector<string> memory, string answer) {
    if (x.length() == 0) {
        s = answer;
        return true;
    }
    else if (find(memory.begin(), memory.end(), x) != memory.end()) {
        return false;
    }
    else {
        int index = 0;
        string word = "";
        while (index < x.length()) {
            word += x.substr(index, 1);
            if (dictionary1(word)) {
                if (memosplit(x.substr(index+1), memory, answer + word + " ")) {
                    return true;
                }
                else {
                    index++;
                }
            }
            else {
                index++;
            }
        }
        memory.push_back(x);
        return false;
    }
}

int main() {
    string str, line;
    int n;
    ifstream in;
    in.open("diction10k.txt"); // change to diction10k.txt
    copy(istream_iterator<string>(in),
         istream_iterator<string>(),
         back_inserter(dict));
    getline(cin, line);
    istringstream iss(line);
    iss >> n;
    for (int i = 1; i <= n; i++) {
        getline(cin, line);
        istringstream iss(line);
        iss >> str;
        cout << "phrase number: " << i << endl;
        cout << str << endl;
        /*cout << "iterative attempt:" << endl;
        string bsplit = bsplit(str);
        if (can_split) {
            cout << "YES, can be split" << endl;
            cout << bsplit << endl << endl;
        }
        else {
            cout << "NO, cannot be split" << endl << endl;
        }*/
        cout << "memoized attempt:" << endl;
        string split = "";
        //split = msplit(str, split);
        vector<string> memory;
        if (memosplit(str, memory, split)) {
            cout << "YES, can be split" << endl;
            cout << s << endl << endl << endl;
        }
        else {
            cout << "NO, cannot be split" << endl << endl << endl;
        }
    }
    return 0;
}
