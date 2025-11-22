#include <iostream>
#include <cstdlib> //for random numbers in the games
#include <ctime> //for srand for true randomization


using namespace std;

//global functions for the interactive games
void addition_start(char ask);
void subtraction_start(char ask);
void multiplication_start(char ask);
void division_start(char ask);
void addition_game(int gameMode, char ask);
void subtraction_game(int gameMode, char ask);
void multiplication_game(int gameMode, char ask);
void division_game(int gameMode, char ask);
#include "./addGameFunction.cpp"  // inclusion of separate files for game and start functions
#include "./subGameFunction.cpp"
#include "./multGameFunction.cpp"
#include "./divGameFunction.cpp"

//main function
char play; // Globalizing play variable to quit program
int main() {
    srand(time(NULL));
    int choice;
    cout << "\n---WELCOME TO MATH INFINITE RUNNER---\n";
    cout << "-------------------------------------\n";
    cout << "   Would you like to play? (y/n) ";
    bool continuePlay = false;
    while (continuePlay == false) { // Input handling
        cin >> play;
        if (tolower(play) == 'y' || play == 'n') {
            continuePlay = true;
        } else cout << "Please enter a valid choice\n";
    }
        while (tolower(play) == 'y') {
            cout << "   1. Addition \n   2. Subtraction \n   3. Multiplication \n   4. Division \n";
            cout << "   Your choice (1-4): ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "YOU HAVE CHOSEN TO PLAY THE ADDITION GAME!!";
                    addition_start(play);
                    break;
                case 2:
                    cout << "YOU HAVE CHOSEN TO PLAY THE SUBTRACTION GAME!!";
                    subtraction_start(play);
                    break;
                case 3:
                    cout << "YOU HAVE CHOSEN TO PLAY THE MULTIPLICATION GAME!!";
                    multiplication_start(play);
                    break;
                case 4:
                    cout << "YOU HAVE CHOSEN TO PLAY THE DIVISION GAME!!";
                    division_start(play);
                    break;
                default:
                    cout << "Please enter a valid choice\n";
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                    }

        }
}
    cout << "\nTHANK YOU FOR PLAYING MATH INFINITE RUNNER\n";
    cout << "PLAY AGAIN ANYTIME!!";
    return 0;
}

//choose game mode for addition
void addition_start(char ask) {
    int gameMode;
    cout << "\n Choose your game mode!! \n";
    cout << "   1. Beginner \n   2. Easy \n   3. Normal \n   4. Hard \n";
    cout << "   Your choice (1-4): ";
    cin >> gameMode;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
    }
    if (gameMode == 1 || gameMode == 2 || gameMode == 3 || gameMode == 4) {
       addition_game(gameMode, ask);
    } else {
        cout << "Please enter a valid choice\n";
        addition_start(ask);
    }
}
//actual game for addition
void addition_game(int gameMode, char ask) {
    int points = 0;
    if (gameMode == 1) { //beginner game mode
        cout << "Game Mode: Beginner!!";
        cout << "Ready... \nSet... \nGO!!! \n";
        for (int i = 1; i <= 10; i++) {
            int x = rand() % 10 + 1;
            int y = rand() % 10 + 1;
            int answer = x + y;
            int inputAnswer = 0;
            cout << "Question " << i << " : " << x << " + " << y << " = ";
            cin >> inputAnswer;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
            if (inputAnswer == answer) {
                cout << "CORRECT!! \nNext question!\n";
                points++;
            } else {
                cout << "WRONG!! \nNext question!\n";
            }
        }
        cout << "You finished with " << points << "/10 points!! \n";
    }
    else if (gameMode == 2) { //easy game mode
        cout << "Game Mode: Easy!!";
        cout << "Ready... \nSet... \nGO!!! \n";
        for (int i = 1; i <= 15; i++) {
            int x = rand() % 20 + 1;
            int y = rand() % 20 + 1;
            int answer = x + y;
            int inputAnswer = 0;
            cout << "Question " << i << " : " << x << " + " << y << " = ";
            cin >> inputAnswer;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
            if (inputAnswer == answer) {
                cout << "\nCORRECT!! \nNext question!\n";
                points += 2;
            } else {
                cout << "\nWRONG!! \nNext question!\n";
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
        cout << "You finished with " << points << "/30 points!! \n";
    }
    else if (gameMode == 3) { //normal game mode
        cout << "Game Mode: Normal!!";
        cout << "Ready... \nSet... \nGO!!! \n";
        for (int i = 1; i <= 20; i++) {
            int x = rand() % 100 + 1;
            int y = rand() % 100 + 1;
            int answer = x + y;
            int inputAnswer = 0;
            cout << "Question " << i << " : " << x << " + " << y << " = ";
            cin >> inputAnswer;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
            if (inputAnswer == answer) {
                cout << "\nCORRECT!! \nNext question!";
                points += 3;
            } else {
                cout << "\nWRONG!! \nNext question!";
            }
        }
        cout << "You finished with " << points << "/60 points!! \n";
    }
    else if (gameMode == 4) { //hard game mode
        cout << "Game Mode: Hard!!";
        cout << "Ready... \nSet... \nGO!!! \n";
        for (int i = 1; i <= 10; i++) {
            int x = rand() % 1000 + 1;
            int y = rand() % 1000 + 1;
            int answer = x + y;
            int inputAnswer = 0;
            cout << "Question " << i << " : " << x << " + " << y << " = ";
            cin >> inputAnswer;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
            if (inputAnswer == answer) {
                cout << "\nCORRECT!! \nNext question!";
                points += 10;
            } else {
                cout << "\nWRONG!! \nNext question!";
            }
        }
        cout << "You finished with " << points << "/100 points!! \n";
    }
    cout << "Would you like to play again? (y/n)";
    bool validAsk = false;
    while (validAsk == false ) {
        cin >> ask;
        if (tolower(ask) == 'n' || tolower(ask) == 'y') {
            validAsk = true;
        } else {
            cout << "Please enter a valid choice\n";
            cout << "Would you like to play again? (y/n)";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> ask;
        }
    }
    play = ask;
}
//choose game mode for subtraction
void subtraction_start(char ask) {

}
//choose game mode for multiplication
void multiplication_start(char ask) {

}
//choose game mode for division
void division_start(char ask) {

}
