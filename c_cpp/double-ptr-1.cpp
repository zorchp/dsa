#include <iostream>
using namespace std;

// algo: in-place
void move2head(char* s) {
    // move `*` to the head of array
    int n{};
    while (s[n] != '\0') ++n;
    int j{n - 1};
    for (int i{n - 1}; i >= 0; --i) {
        if (s[i] != '*') //
            s[j--] = s[i];
    }
    while (~j) s[j--] = '*';
}

void move2end(char* s) {
    // move `*` to the end of array
    int j{};
    for (int i{}; s[i] != '\0'; ++i) {
        if (s[i] != '*') s[j++] = s[i];
    }
    while (s[j]) //
        s[j++] = '*';
    // s[j] = '\0'; // cut
}

int main(int argc, char const* argv[]) {
    char s[] = "A*b*cde**";
    cout << s << endl;
    // move2head(s);
    move2end(s);
    cout << s << endl;
    return 0;
}