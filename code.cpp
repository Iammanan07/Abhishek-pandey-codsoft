#include <iostream>
#include <string>
using namespace std;
 
string PlayerInput(char Ttt[][3], string*, string*);
string Winner(char Ttt[][3], string, string);
void Display(string*, string, string);
 
int main()
{
    char Ttt[3][3]{
       {'-', '-', '-'},
       {'-', '-', '-'},
       {'-', '-', '-'}
    };
    string Plyr1;
    string Plyr2;
 
    cout << "\t\t\t\t     ***  TIC - TAC - TOE  ***\n\n";
    cout << "\t\t\t\t        Welcome to our Game\n\n";
 
    // Player information
 
    cout << "Enter player 1 name : ";
    getline(cin, Plyr1);
    cout << "Enter player 2 name : ";
    getline(cin, Plyr2);
 
    // Input Location format 
 
    cout << "\nChoose following format to enter input\n\n";
    cout << " 1 | 2 | 3 " << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << " 7 | 8 | 9 " << endl << endl;
 
    // Input
    string Winner = PlayerInput(Ttt, &Plyr1, &Plyr2);
    // output
    Display(&Winner, Plyr1, Plyr2);
 
}string PlayerInput(char Ttt[][3], string* P1, string* P2)
{
 
    string p1;
    string p2;
    char ReptValu[10];
   
    string Win;
 
    for (int i = 0; i < 5; i++)
    {
        // Player 1 Input
        cout << *P1 << " turn : ";
        do
        {
            cin >> p1;
             
            if (p1.length() == 1 && p1[0] < 58 && p1[0] > 48 && p1[0] != ReptValu[0] && p1[0] != ReptValu[1]
                && p1[0] != ReptValu[2] && p1[0] != ReptValu[3] && p1[0] != ReptValu[4] && p1[0] != ReptValu[5]
                && p1[0] != ReptValu[6] && p1[0] != ReptValu[7] && p1[0] != ReptValu[8] && p1[0] != ReptValu[9])
            {
                cout << endl;
                break;
            }
            else if (p1[0] == ReptValu[0] || p1[0] == ReptValu[1] || p1[0] == ReptValu[2] || p1[0] == ReptValu[3]
                || p1[0] == ReptValu[4] || p1[0] == ReptValu[5] || p1[0] == ReptValu[6] || p1[0] == ReptValu[7]
                || p1[0] == ReptValu[8] || p1[0] == ReptValu[9])
            {
                cout << "\n * *This position is occupied.Please choose an another position. * *\n\n";
                cout << *P1 << " turn again : ";
            }
            else
            {
                cout << "\nInvalid input.\nPlease enter a natural number from the range 1 to 9.\n\n";
                cout << *P1 << " turn again : ";
            }
        } while (true);
 
        // Storing Player 1 Input in Matrix
 
        if (p1[0] == '1') { Ttt[0][0] = 'X'; }
        if (p1[0] == '2') { Ttt[0][1] = 'X'; }
        if (p1[0] == '3') { Ttt[0][2] = 'X'; }
        if (p1[0] == '4') { Ttt[1][0] = 'X'; }
        if (p1[0] == '5') { Ttt[1][1] = 'X'; }
        if (p1[0] == '6') { Ttt[1][2] = 'X'; }
        if (p1[0] == '7') { Ttt[2][0] = 'X'; }
        if (p1[0] == '8') { Ttt[2][1] = 'X'; }
        if (p1[0] == '9') { Ttt[2][2] = 'X'; }
 
        // Checking winner if there is.
        Win = Winner(Ttt, *P1, *P2);
 
        // showing user input in matrix form 
        cout << " " << Ttt[0][0] << " | " << Ttt[0][1] << " | " << Ttt[0][2];
        cout << "\t\t 1 | 2 | 3 " << endl;
        cout << " " << Ttt[1][0] << " | " << Ttt[1][1] << " | " << Ttt[1][2] ;
        cout << "\t\t 4 | 5 | 6 " << endl;
        cout << " " << Ttt[2][0] << " | " << Ttt[2][1] << " | " << Ttt[2][2] ;
        cout << "\t\t 7 | 8 | 9 " << endl << endl;
 
        if (Win == *P1 || Win == *P2) break; // End the game if there's a winner
        else if (i == 4) { Win = "Draw"; break; }// End the game if game is draw
        ReptValu[i] = p1[0];
        // Player 2 Input
 
        cout << *P2 << " turn : ";
        do
        {
            cin >> p2;
            if (p2.length() == 1 && p2[0] > 48 && p2[0] < 58 && p2[0] != p1[0] && p2[0] != ReptValu[0] &&
                p2[0] != ReptValu[1] && p2[0] != ReptValu[2] && p2[0] != ReptValu[3] && p2[0] != ReptValu[4]
                && p2[0] != ReptValu[5] && p2[0] != ReptValu[6] && p2[0] != ReptValu[7] && p2[0] != ReptValu[8]
                && p2[0] != ReptValu[9])
            {
                cout << endl;
                break;
            }
 
            else if (p2[0] == ReptValu[0] || p2[0] == ReptValu[1] || p2[0] == ReptValu[2] || p2[0] == ReptValu[3]
                || p2[0] == ReptValu[4] || p2[0] == ReptValu[5] || p2[0] == ReptValu[6] || p2[0] == ReptValu[7]
                || p2[0] == ReptValu[8] || p2[0] == ReptValu[9])
                 {
                cout << "\n * *This position is occupied.Please choose an another position. * *\n\n";
                cout << *P2 << " turn again : ";
                 }
            else
            {
                cout << "\nInvalid input.\nPlease enter a natural number from the range 1 to 9.\n\n";
                cout << *P2 << " turn again : ";
            }
        } while (true);
 
        // Storing Player 2 Input in Matrix
 
        if (p2[0] == '1') { Ttt[0][0] = 'O'; }
        if (p2[0] == '2') { Ttt[0][1] = 'O'; }
        if (p2[0] == '3') { Ttt[0][2] = 'O'; }
        if (p2[0] == '4') { Ttt[1][0] = 'O'; }
        if (p2[0] == '5') { Ttt[1][1] = 'O'; }
        if (p2[0] == '6') { Ttt[1][2] = 'O'; }
        if (p2[0] == '7') { Ttt[2][0] = 'O'; }
        if (p2[0] == '8') { Ttt[2][1] = 'O'; }
        if (p2[0] == '9') { Ttt[2][2] = 'O'; }
 
        // Checking winner if there is.
 
        Win = Winner(Ttt, *P1, *P2);
 
        // showing user input in matrix form 
 
        cout << " " << Ttt[0][0] << " | " << Ttt[0][1] << " | " << Ttt[0][2];
        cout << "\t\t 1 | 2 | 3 " << endl;
        cout << " " << Ttt[1][0] << " | " << Ttt[1][1] << " | " << Ttt[1][2];
        cout << "\t\t 4 | 5 | 6 " << endl;
        cout << " " << Ttt[2][0] << " | " << Ttt[2][1] << " | " << Ttt[2][2];
        cout << "\t\t 7 | 8 | 9 " << endl << endl;
 
 
        if (Win == *P1 || Win == *P2) break; // End the game if there's a winner
 
        // storing value in array for not repeating same input by using in if statement
         
        ReptValu[i + 5] = p2[0];
    }
    return Win;
}
 
string Winner(char Ttt[][3], string P1, string P2)
{
    string Winner = " ";
 
    // condition for player 1 as winner
    if ((Ttt[0][0] == 'X' && Ttt[0][1] == 'X' && Ttt[0][2] == 'X') ||
        (Ttt[1][0] == 'X' && Ttt[1][1] == 'X' && Ttt[1][2] == 'X') ||
        (Ttt[2][0] == 'X' && Ttt[2][1] == 'X' && Ttt[2][2] == 'X') ||
        (Ttt[0][0] == 'X' && Ttt[1][0] == 'X' && Ttt[2][0] == 'X') ||
        (Ttt[0][1] == 'X' && Ttt[1][1] == 'X' && Ttt[2][1] == 'X') ||
        (Ttt[0][2] == 'X' && Ttt[1][2] == 'X' && Ttt[2][2] == 'X') ||
        (Ttt[0][0] == 'X' && Ttt[1][1] == 'X' && Ttt[2][2] == 'X') ||
        (Ttt[0][2] == 'X' && Ttt[1][1] == 'X' && Ttt[2][0] == 'X'))
    {
        Winner = P1;
    }
    // condition for player 2 as winner
    if ((Ttt[0][0] == 'O' && Ttt[0][1] == 'O' && Ttt[0][2] == 'O') ||
        (Ttt[1][0] == 'O' && Ttt[1][1] == 'O' && Ttt[1][2] == 'O') ||
        (Ttt[2][0] == 'O' && Ttt[2][1] == 'O' && Ttt[2][2] == 'O') ||
        (Ttt[0][0] == 'O' && Ttt[1][0] == 'O' && Ttt[2][0] == 'O') ||
        (Ttt[0][1] == 'O' && Ttt[1][1] == 'O' && Ttt[2][1] == 'O') ||
        (Ttt[0][2] == 'O' && Ttt[1][2] == 'O' && Ttt[2][2] == 'O') ||
        (Ttt[0][0] == 'O' && Ttt[1][1] == 'O' && Ttt[2][2] == 'O') ||
        (Ttt[0][2] == 'O' && Ttt[1][1] == 'O' && Ttt[2][0] == 'O'))
    {
        Winner = P2;
    }
 
    return Winner;
}
void Display(string* W, string P1, string P2)
{
    // showing result if there is winner
    if (*W == P1 || *W == P2)
    {
        cout << "\n\n\t\t\t\t\t        Winner of Game is : " << *W << endl << endl;
    }
    // showing result if  Game is Draw
    else cout << "\t\t\t\t\t\t\tGame is Draw \n";
 
    cout << "\t\t\t\t\t *** Thank You for using our Game Program ***\n";
    cout << "\t\t\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";
 
}