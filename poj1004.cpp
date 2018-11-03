#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
    double current = 0, sum = 0, average = 0;
    for(int i = 0; i < 12; i++)
    {
        cin >> current;
        sum += current;
    }

    average = sum / 12;
    cout << '$' <<setiosflags(ios::fixed)<< setprecision(2) << average << endl;
}