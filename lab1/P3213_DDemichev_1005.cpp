#include <iostream>

using namespace std;

void f (int k, int s1, int s2);
int N;
int* A;
int m = INT_MAX;

int main()
{
    cin >> N;
    A = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    f(0, 0, 0);
    cout << m;
    return 0;
}

void f (int k, int s1, int s2) {
    if(k == N) {
        m = min(m, abs(s1 - s2));
    }
    else {
        f(k + 1, s1 + A[k], s2);
        f(k + 1, s1, s2 + A[k]);
    }

}