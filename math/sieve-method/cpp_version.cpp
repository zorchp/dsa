#include <iostream>
#include <bitset>

using namespace std;
#define X 1e7
constexpr int maxn = X + 10;
bitset<maxn> pri;
int primes[maxn];

void era() {
    int N = X, cnt = 0;
    double s = clock();
    for (int i = 2; i * i <= N; ++i) {
        if (!pri[i]) {
            for (int j = i * i; j <= N; j += i)
                pri[j] = 1;
        }
    }
    // count primes
    for (int i = 2; i <= N; i++)
        if (!pri[i])
            cnt++;
    double e = clock();
    printf("%d\ntime = %.0lftic", cnt, e - s);
    /*5761455
time = 4252883tic[Finished in 4.9s]*/
}

void euler() {
    int N = X, cnt = 0;
    double s = clock();
    for (int i = 2; i <= N; ++i) {
        if (!pri[i])
            primes[cnt++] = i; // record ans
        for (int j{}; i * primes[j] <= N; ++j) {
            pri[i * primes[j]] = 1; // seive non-primes
            if (i % primes[j] == 0)
                break;
        }
    }
    double e = clock();
    printf("%d\ntime = %.0lftic", cnt, e - s);
    /*5761455
time = 2730051tic[Finished in 3.5s]*/
}

int main(int argc, char const* argv[]) {
    era();
    // euler();
    return 0;
}
