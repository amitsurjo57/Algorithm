#include <iostream>
using namespace std;

int modularExponentiation(int a, int k, int m)
{
    if (k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return a % m;
    }

    if (k % 2 == 0)
    {
        int halfPower = modularExponentiation(a, k / 2, m);
        return (halfPower * halfPower) % m;
    }
    else
    {
        return (a * modularExponentiation(a, k - 1, m)) % m;
    }
}

int main()
{
    int a, k, m;

    cout << "Enter base (a): ";
    cin >> a;
    cout << "Enter exponent (k): ";
    cin >> k;
    cout << "Enter modulus (m): ";
    cin >> m;

    if (m <= 0)
    {
        cout << "Modulus must be a positive integer." << endl;
        return 1;
    }

    int result = modularExponentiation(a, k, m);
    cout << result;

    return 0;
}