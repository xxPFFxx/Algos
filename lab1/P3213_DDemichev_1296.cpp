#include <iostream>

using namespace std;

int main() {
    int n, cur, max, x;

    cin >> n;
    cur = 0;
    max = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;
        cur += x;

        if (cur > max) {
            max = cur;
        }
        if (cur < 0) {
            cur = 0;
        }
    }

    cout << max << endl;
    return 0;
}