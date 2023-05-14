#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, vector<string> > tags;
int main() {
    int n;
    cin >> n;
    string s;
    bool c1=false, c2=false, c3=false;
    string att = "", tag="";
    vector< vector<string> > atts;
    while (getline(cin, s)) {
        c1 = c2 = c3 = false;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '"') {
                c1 = !c1;
                continue;
            }
            if (s[i] == '\'') {
                c2 = !c2;
                continue;
            }
            if (s[i] == '\\') {
                i++;
                continue;
            }
            if (c1 || c2)
                continue;
            if (s[i] == '>')
                c3 = true;
            if (s[i] == '<')
                c3 = false;
            if (c3) continue;
            if (s[i] == '<') {
                i++;
                if (s[i] == '/') {
                    while (s[i] != '>')
                        i++;
                    c3 = true;
                    continue;
                }
                tag = "";
                while (s[i] != ' ' && s[i] != '>')
                    tag += s[i++];
                tags[tag].push_back("");
                if (s[i] == '>')
                    c3 = true;
                continue;
            }
            if ((s[i] == '=' || s[i] == ' ') && att != "") {
                tags[tag].push_back(att);
                att = "";
            }
            if (s[i] >= 'a' && s[i] <= 'z')
                att += s[i];
        }
    }
    for (auto i=tags.begin(); i!=tags.end(); i++) {
        sort(i->second.begin(), i->second.end());
        for (int j=1; j<i->second.size(); j++) {
            if (i->second[j] == i->second[j-1]) {
                i->second.erase(i->second.begin()+j-1);
                j--;
            }
        }
        cout << i->first << ":";
        for (int j=0; j<i->second.size(); j++) {
            if (j>1) cout << ",";
            cout << i->second[j];
        }
        cout << "\n";
    }
    return 0;
}
