#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)	{
        int n,  k;
        cin >> n >> k;

        int groupSize = n / k;
        int remainder = n % k;
        int fullGroupSize = groupSize + 1;

        int answer = ((groupSize*(k-remainder))*(n - groupSize) + (remainder * fullGroupSize)*(n - fullGroupSize)) / 2;

        cout << answer << endl;
    }

    return 0;
}