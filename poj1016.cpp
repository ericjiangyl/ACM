#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

string itos (long long i);

int main()
{
    char numberbook [16][81];
    while(scanf("%s", numberbook[0]) && numberbook[0][0] != '-')
    {       
        for(int j = 0; j < 15; j++)
        {
            //bucket sort initialize all count to 0
            int count [10];
            for(int i = 0; i < 10; i++)
            {
                count[i] = 0;
            }

            //record how many times each digit appears
            for(int i = 0; i < strlen(numberbook[j]); i++)
                ++count[ numberbook[j][i] - '0' ];

            int pos = 0;
            for(int i = 0; i < 10; i++)
            {
                if(count[i] == 0)
                    continue;
                
                if(count[i] >= 10)
                {
                    numberbook[j+1][pos+1] = count[i]%10 + '0';
                    count[i] /= 10;
                    numberbook[j+1][pos] = count[i] + '0';
                    numberbook[j+1][pos+2] = i + '0';
                    pos += 3;
                }
                else
                {
                    numberbook[j+1][pos] = count[i] + '0';
                    numberbook[j+1][pos+1] = i + '0';
                    pos += 2;
                }              
            }
            numberbook[j+1][pos] = '\0';

            if(!strcmp(numberbook[0], numberbook[1]))
            {
                cout << numberbook[0] << " is self-inventorying" << endl;
                break;
            }

            if(!strcmp(numberbook[j+1],numberbook[j]))
            {
                cout << numberbook[0] << " is self-inventorying after " << j << " steps" << endl;
                break;
            }

            int second_test = 0;
            if(j > 0)
            {
                for(int i = j-1; i >= 0; i--)
                {
                    if(!strcmp(numberbook[i], numberbook[j+1]))
                    {
                        cout << numberbook[0] << " enters an inventory loop of length " << j+1-i << endl;
                        second_test = 1;
                        break;
                    }   
                }
            }
            if(second_test)
                break;

            if(j == 14)
                cout << numberbook[0] << " can not be classified after 15 iterations" << endl;

        }
    }
}
