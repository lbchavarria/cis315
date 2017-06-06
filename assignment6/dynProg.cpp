#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

vector<string> dict;
string s;
int m;

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
/*
bool botsplit(string x) {
    if (x == "") {
        return false;
    }
    if (x.length() == 1) {
        if (dictionary1(x)) {
            s = x;
            return true;
        }
        else {
            return false;
        }
    }
    vector<bool> t(x.length()+1, false);
    t[0] = true;
    for (int i = 0; i <= x.length(); i++) {
        for (int j = 0; j < i; j++) {
            if (dictionary1(x.substr(j, i))) {
                s.append(x.substr(j, i));
                s.append(" ");
                t[i] = true;
            }
        }
    }
    return t[x.length()];
}*/

bool botsplit(string x) {
    if (x == "") {
        return false;
    }
    vector<bool> t(x.length()+1, false);
    t[0] = true;
    for (int i = 1; i <= x.length(); ++i) {
        for (int j = 1; j <= i; ++j) {
            string temp = x.substr(j-1, i-j+1);
            if (t[j-1] && dictionary1(temp)) {
                s.append(temp);
                s.append(" ");
                t[i] = true;
            }
        }
    }
    return t[x.length()];
}
/*
bool botsplit(string x) {
    if (x.length() == 0) {
        return false;
    }
    int index = 0;
    int last = 0;
    vector<bool> t(x.length()+1, false);
    t[0] = true;
    string word = "";
    while (index < x.length()) {
        word += x.substr(index, 1);
        if (t[last] && dictionary1(word)) {
            word += " ";
            t[index] = true;
            last = index;
            index++;
        }
        else {
            index++;
        }
    }
    s = word;
    return t[last];
}*/
/*
bool botsplit(string x) {
    if (x == "") {
        return false;
    }
    vector<bool> t(x.length()+1);
    t[0] = true;
    for (int i = 0; i < x.length(); i++) {
        for (int j = 1; j <= x.length()-i; j++) {
            if (t[i] && dictionary1(x.substr(i,j))) {
                t[i] = true;
                s.append(x.substr(i, j));
                s.append(" ");
                //i += j;
                break;
            }
        }
    }
    return t[0];
}*/

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
        cout << str << endl << endl;
        cout << "iterative attempt:" << endl;
        //string bsplit = bsplit(str);
        if (botsplit(str)) {
            cout << "YES, can be split" << endl;
            cout << s << endl << endl;
        }
        else {
            cout << "NO, cannot be split" << endl << endl;
        }
        s = "";
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
