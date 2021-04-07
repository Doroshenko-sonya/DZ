#include <iostream>
using namespace std;

int main() {
    string str;
    int count = 0,
        first = -1,
        last = -1;

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ',') {
            if (count == 0) {
                first = i;
            }
            count += 1;
            last = i;
        }
    }

    cout << "a) " << first << endl << "b) " << last << endl << "c) " << count << endl;
}