#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct dna
{
    string s;
    int key;

    dna(string input, int a): s(input), key(a) {}
};

bool comp(const dna &a, const dna &b)
{
    if ( (a.key) < (b.key) )
        return true;
    else
        return false;
}

vector <dna> list_dna;

int main()
{
    int length = 0, count = 0;
    cin >> length >> count;
    char space;
    space = getchar();//get rid of the newline character in the first line
    for(int i = 0; i < count; i++)
    {
        int key = 0;
        string s;
        getline(cin, s);

        for(int j = 0; j < length-1; j++) 
        //the last character won't convey any information regarding sortedness, no need to process
        {
            for(int k = j; k < length; k++)
            {
                if(s[j] > s[k])
                    key++;
            }
        }

        list_dna.push_back( dna(s, key) );
    }

    vector <dna>::iterator beg = list_dna.begin();
    vector <dna>::iterator end = list_dna.end();

    sort(beg, end, comp);

    for(; beg != end; beg++)
    {
        cout << (beg->s) << endl;
    }
}


