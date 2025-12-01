#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib> //for random numbers in the games
#include <ctime> //for srand for true randomization

using namespace std;
char play; // Globalizing play variable to quit program
#include "./addGameFunction.cpp"  // inclusion of separate files for game and start functions
#include "./subGameFunction.cpp"
#include "./multGameFunction.cpp"
#include "./divGameFunction.cpp"

//main function
int main() {
    srand(time(NULL));
    int recentScore = 0;
    int sessionHighScore =0;
    int choice;
    int gameMode;
    string name;
    cout << "\n---WELCOME TO MATH INFINITE RUNNER---\n";
    cout << "\n-------------------------------------\n";
    cout << "   Enter a name for the leaderboard : ";
    cin >> name;
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
                    cout << "Choose your game mode!\n 1. Demo \n 2. Infinite Easy \n 3. Infinite Challenge \n";
                    cout << "Your choice (1-3): ";
                    cin >> gameMode;
                    additionGameFunction(gameMode, recentScore);
                    break;
                case 2:
                    cout << "YOU HAVE CHOSEN TO PLAY THE SUBTRACTION GAME!!";
                    cout << "Choose your game mode!\n 1. Demo \n 2. Infinite Easy \n 3. Infinite Challenge \n";
                    cout << "Your choice (1-3): ";
                    cin >> gameMode;
                    subtractionGameFunction(gameMode, recentScore);
                    break;
                case 3:
                    cout << "YOU HAVE CHOSEN TO PLAY THE MULTIPLICATION GAME!!";
                    cout << "Choose your game mode!\n 1. Demo \n 2. Infinite Easy \n 3. Infinite Challenge \n";
                    cout << "Your choice (1-3): ";
                    cin >> gameMode;
                    multiplicationGameFunction(gameMode, recentScore);
                    break;
                case 4:
                    cout << "YOU HAVE CHOSEN TO PLAY THE DIVISION GAME!!";
                    cout << "Choose your game mode!\n 1. Demo \n 2. Infinite Easy \n 3. Infinite Challenge \n";
                    cout << "Your choice (1-3): ";
                    cin >> gameMode;
                    divisionGameFunction(gameMode, recentScore);
                    break;
                default:
                    cout << "Please enter a valid choice\n";
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                    }

        }
            if (recentScore > sessionHighScore) {
                sessionHighScore = recentScore;
            }
}
    cout << "\nTHANK YOU FOR PLAYING MATH INFINITE RUNNER\n";
    cout << "PLAY AGAIN ANYTIME!!";
    //Instantiating file in case it doesn't exist yet
    ofstream outLeaderboard;
    outLeaderboard.open("..//leaderboard.txt",ios::app);
    outLeaderboard << sessionHighScore << " points scored by: " << name << "!" << endl;
    outLeaderboard.close();

    return 0;
}

// cant we very easily combine this into one function or am i thinking wrong? also, not meaning for it to look as if im doing nothing, 
// im trying to figure out how in the world to do the actual infinite running game part of this (which i assume were still trying to do if possible? if not mb for actually doing nothing then lol)
// we can make the choosing game and game mode into one function but it would become too long and too messy if we put every game into one function
// for the infinite part I was going to try so make it so the game keeps running until the player gets something wrong, like having just a 10 question demo and an actually infinite game


//From Kell
//Fixed the looping so you can actually say no to it now, as long as you rely on the global play variable the loop should work and you don't have to pass one into the game function which gets really messy fast.
//Added leaderboard functionality, if we want we can add the ability to read and organize it
