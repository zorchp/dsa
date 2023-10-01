#include <bits/stdc++.h>

using namespace std;

bool haveConflict(vector<string>& event1, vector<string>& event2) {
    int h1{}, m1{}, h2{}, m2{};
    sscanf("%d:%d", event1[0].c_str(), &h1, &m1);
    sscanf("%d:%d", event1[1].c_str(), &h2, &m2);
    int st1{h1 * 60 + m1}, en1{h2 * 60 + m2};
    cout << st1 << endl;
    cout << en1 << endl;
    sscanf("%d:%d", event2[0].c_str(), &h1, &m1);
    sscanf("%d:%d", event2[1].c_str(), &h2, &m2);
    int st2{h1 * 60 + m1}, en2{h2 * 60 + m2};
    cout << st1 << endl;
    cout << en1 << endl;
    cout << st2 << endl;
    cout << en2 << endl;
    return (min(en1, en2) - max(st1, st2)) >= 0;
}

int main(int argc, char* argv[]) {
    vector<string> v1{"10:00", "11:00"}, v2{"14:00", "15:00"};
    cout << haveConflict(v1, v2);
    return 0;
}
