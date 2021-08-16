#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void rules()
{
    system("cls");
    cout << "======CASINO GAME PLAYING RULES=======" << endl;
    cout << "\t1. Choose a number between 1 and 10." << endl;
    cout << "\t2. Winner gets 10 times of the money bet" << endl;
    cout << "\t3. Wrong bet, and you lose the amount you bet\n"
         << endl;
}

int main()
{
    string playerName;
    int balance;
    int bettingAmount;
    int dice;
    int guess;
    char choice[2];
    srand(time(0));
    cout << "===========Welcome to the world of CASINO===========\n"<< endl;
    cout << "Enter player name: ";
    cin >> playerName;
    cout << "Enter the starting balance to play game: $ ";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\nYour current balance is $ " << balance << endl;
        do
        {
            cout << "\nEnter the betting amount to play game: $ ";
            cin >> bettingAmount;
            if (bettingAmount > balance)
            {
                cout << "Betting amount cannot be greater than your balance amount\n\tRe-enter betting amount" << endl;
            }

        } while (bettingAmount > balance);
        do
        {
            cout << "Guess any betting number between 1 and 10: ";
            cin >> guess;
            if (guess <= 0 || guess > 10)
            {
                cout << "\nNumber should be between 1 to 10\n Re-enter number " << endl;
            }
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;
        if (dice == guess)
        {
            cout << "You are in luck and you have won $ " << bettingAmount * 10 << endl;
            balance += bettingAmount * 10;
        }
        else if (dice != guess)
        {
            cout << "Oops, better luck next time !! You lost $ " << bettingAmount << endl;
            balance -= bettingAmount;
        }
        cout << "\nThe winning number was : " << dice << endl;
        cout << playerName << " your new balance is : $ " << balance << endl;

        if (balance == 0)
        {
            cout << "You have no money to play " << endl;
            break;
        }

        cout << "Do you want to play game again? (Y/N): ";
        cin >> choice;
    } while (choice == "Y" || choice == "y");
    cout << "\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << endl;

    return 0;
}