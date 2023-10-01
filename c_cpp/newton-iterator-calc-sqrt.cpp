#include <cstdio>
#include <iostream>

using namespace std;


double my_sqrt(double x) {
    double ans = x;
    while (fabs(ans * ans - x) > 1e-12)
        ans = (ans + x / ans) / 2.;
    return ans;
}

int main(int argc, char *argv[]) {
    printf("%.12f\n", my_sqrt(2));
    return 0;
}
