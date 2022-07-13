#include <iostream>
using namespace std;
int pow(int base, int exp)
{
    if (exp == 1)
        return base;
    if (exp == 0)
        return 1;
    return base * pow(base, exp - 1);
}
int main()
{
    int n;
    cout << "enter the degree of function: ";
    cin >> n;
    int poly[n + 1];
    for (int i = n; i >= 0; i--)
    {
        cout << "enter the coefficient of "
             << "n^" << i << ": ";
        cin >> poly[i];
    }
    cout << "The polynomial is: " << endl;
    for (int i = n; i >= 0; i--)
    {
        if (poly[i] != 0 && i != 0)
            cout << poly[i] << "n^" << i << " + ";
        if (i == 0)
            cout << poly[0] << endl;
    }
    int input;
    cout << "enter an element of which you find the value: ";
    cin >> input;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int power = pow(input, i);
        power *= poly[i];
        ans += power;
    }
    cout << "The anser is : " << ans << endl;
}