//Yilun Jiang
//6/28/2018
//http://poj.org/problem?id=1005

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int count;
    cin >> count;

    for(int i = 0; i < count; i++)
    {
        double x = 0, y = 0;
        cin >> x >> y;
        double area = 3.1415926 * (pow(x,2)+pow(y,2)) / 2;
        int year;
        year = area / 50;
        year++;
        printf("Property %d: This property will begin eroding in year %d.\n", i+1, year);
    }

    cout << "END OF OUTPUT." << endl;
}