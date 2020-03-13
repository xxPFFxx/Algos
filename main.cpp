#include <iostream>
#include <algorithm>

using namespace std;

void heapDivide (int i, int s1, int s2);
int N;
int s;
int* A;
int m = INT_MAX;

int main()
{
    cin >> N;

    A = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        s += A[i];
    }

    heapDivide(0, 0, 0);
    cout << m;

    getchar();
    getchar();

    return 0;
}

void heapDivide (int i, int s1, int s2) {
    if(i == N) {
        m = min(m, abs(s1 - s2));
    }  else {
        heapDivide(i + 1, s1 + A[i], s2);
        heapDivide(i + 1, s1, s2 + A[i]);
    }

}