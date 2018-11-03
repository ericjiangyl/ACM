#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct card
{
    public:
    char suit;
    char number;
    int pos;
    card(char s, char n, int i): suit(s), number(n), pos(i) {}
};

bool comp1(const card &a, const card &b);
int transform_number(char c);
void card_sort(vector <card> &p,vector <card> &p1,vector <card> &p2,vector <card> &p3,vector <card> &p4);
void print_card(vector <card> &p);

int main()
{
    char start_player;
    char cards1 [53];
    char cards2 [53];
    char cards [104];
    while(1)
    {   
        vector <card> p1, p2, p3, p4;
        vector <card> south, west, north, east;
        vector <card> club, diamond, spade, heart;

        //read in three lines every time
        scanf("%c", &start_player);

        //if the first line is '#', it means the program ends
        if(start_player == '#')
            break;
        
        //read in the two card series
        scanf("%s", cards1);
        scanf("%s", cards2);

        //combine two char array into one
        for(int i = 0; i < 52; i++)
            cards[i] = cards1[i];
        for(int i = 0; i < 52; i++)
            cards[i+52] = cards2[i];

        //use pos to record which of the four vector each card should go
        //based on pos%4
        int pos = 1;
        for(int i = 0; i < 104; )
        {
            char s = cards [i++];
            char n = cards [i++];
            switch(s)
            {
                case 'C':
                club.push_back(card(s,n,pos));
                break;
                case 'D':
                diamond.push_back(card(s,n,pos));
                break;
                case 'S':
                spade.push_back(card(s,n,pos));
                break;
                case 'H':
                heart.push_back(card(s,n,pos));
                break;
            }
            ++pos;
        }

        //sort the four card vectors using the card_sort function
        card_sort(club,p1,p2,p3,p4);
        card_sort(diamond,p1,p2,p3,p4);
        card_sort(spade,p1,p2,p3,p4);
        card_sort(heart,p1,p2,p3,p4);

        //assign player at each position the correct set of cards
        switch(start_player)
        {
            case 'S':
            west = p1;
            north = p2;
            east = p3;
            south = p4;
            break;

            case 'W':
            north = p1;
            east = p2;
            south = p3;
            west = p4;
            break;

            case 'N':
            east = p1;
            south = p2;
            west = p3;
            north = p4;
            break;

            case 'E':
            south = p1;
            west = p2;
            north = p3;
            east = p4;
            break;
        }
        cout << "north[1]" << p4[1].suit << endl;

        //print out the cards
        printf("South player:\n");
        print_card(south);
        printf("West player:\n");
        print_card(west);
        printf("North player:\n");
        print_card(north);
        cout << "north[1]" << north[1].suit << endl;
        printf("East player:\n");
        print_card(east);        
    }

    return 0;
}

void print_card (vector <card> &p)
{
    printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
    vector <card>::const_iterator iter = p.begin();
    for(; iter != p.end(); iter++)
    {
        int number = 0;
        if(iter->number <= '9')
        {
            number = iter->number - '0';
            printf("|%d %d", number, number);
        }
        else
            printf("|%c %c", iter->number, iter->number); 
    }
    printf("|\n");

    for(iter = p.begin(); iter != p.end(); iter++)
        printf("| %c ", iter->suit);
    printf("|\n");

    for(iter = p.begin(); iter != p.end(); iter++)
    {
        int number = 0;
        if(iter->number <= '9')
        {
            number = iter->number - '0';
            printf("|%d %d", number, number);
        }
        else
            printf("|%c %c", iter->number, iter->number); 
    }
    printf("|\n");

    printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
}


//compare function to sort cards based on their number
bool comp1(const card &a, const card &b)
{
    int a_number, b_number;
    a_number = transform_number(a.number);
    b_number = transform_number(b.number);
    if(a_number < b_number)
        return true;
    else
        return false;
}

//transform char to int so that we can compare J,Q,K,A with ints
int transform_number(char c)
{
    int i;

    //process number from 2-9
    if(c <= '9')
        return c - '0';
    //process number T,J,Q,K,A
    switch(c)
    {
        case 'T':
        i = 10;
        break;

        case 'J':
        i = 11;
        break;

        case 'Q':
        i = 12;
        break;

        case 'K':
        i = 13;
        break;

        case 'A':
        i = 14;
        break;            
    }
    return i;
}

void card_sort(vector <card> &p,vector <card> &p1,vector <card> &p2,vector <card> &p3,vector <card> &p4)
{
    sort(p.begin(), p.end(), comp1);
    vector <card>::const_iterator iter = p.begin();
    //after sorting each suit vector based on card number
    //we insert each card into p1,p2,p3,p4 based on pos we recorded
    for(; iter != p.end(); iter++)
    {
        int i = (iter->pos) % 4;
        switch(i)
        {
            case 1:
            p1.push_back(*iter);
            break;
            case 2:
            p2.push_back(*iter);
            break;
            case 3:
            p3.push_back(*iter);
            break;
            case 0:
            p4.push_back(*iter);
            break;
        }
    }
}
