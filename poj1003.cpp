//Yilun Jiang
//6/27/2018
//http://poj.org/problem?id=1003

#include <iostream>

using namespace std;

double length [1000000];
int result [1000000];

int main()
{
    int pos = 0;
    cin >> length[pos];

    while(length[pos] != 0.00)
    {
        int count = 1;
        int base = 2;
        double add_length = 1.0/base;

        while(add_length < length[pos])
        {
            add_length += 1.0/(++base);
            ++count;
        }
        result[pos] = count;
        cin >> length[++pos];
    }

    for(int i = 0; i < pos; i++)
    {
        cout << result[i] << " card(s)" << endl;
    }

}