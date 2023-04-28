#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
    // The regex pattern
    string pattern = "^(tac|(tac){2,}(tic(tac)+)*(tic)?)$";
    regex re(pattern);

    string testString;

    // Read input from STDIN
    while (getline(cin, testString)) {
        // Check if the test string matches the pattern
        if (regex_match(testString, re)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}
