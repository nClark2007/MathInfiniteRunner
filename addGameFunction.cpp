//
// Created by Kell Dacus on 11/22/25.
//
// starter code by Nat Clark on 11/26/25.
void additionGameFunction(int mode, int &compareScore) {
    int points = 0;
    bool correct = true;
    if (mode == 1) { //demo game mode not infinite
        cout << "Game Mode: Demo!!";
        cout << "\nReady... \nSet... \nGO!!! \n";
        for (int i = 1; i <= 10; i++) {
            int x = rand() % 10 + 1;
            int y = rand() % 10 + 1;
            int answer = x + y;
            int inputAnswer = 0;
            cout << x << " + " << y << " = ";
            cin >> inputAnswer;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
            if (inputAnswer == answer) {
                cout << "CORRECT!! Next question!\n";
                points++;
            } else {
                cout << "WRONG!! Next question!\n";
            }
        }
        cout << "You finished with " << points << "/10 points!! \n";
    }
    if (mode == 2) {
        cout << "Game Mode: Infinite Easy!!";
        cout << "\nReady... \nSet... \nGO!!! \n";
        do {
            int x = rand() % 10 + 1;
            int y = rand() % 10 + 1;
            int answer = x + y;
            int inputAnswer = 0;
            cout << x << " + " << y << " = ";
            cin >> inputAnswer;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
            if (inputAnswer == answer) {
                correct = true;
                points++;
            } else {
                correct = false;
                cout << "WRONG!!" << endl;
            }
        } while (correct == true);
        cout << "You finished with " << points << " points!! \n";
    }
    if (mode == 3) {
        cout << "Game Mode: Infinite Challenge!!";
        cout << "\nReady... \nSet... \nGO!!! \n";
        do {
            int x = rand() % 100 + 1;
            int y = rand() % 100 + 1;
            int answer = x + y;
            int inputAnswer = 0;
            cout << x << " + " << y << " = ";
            cin >> inputAnswer;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
            }
            if (inputAnswer == answer) {
                correct = true;
                points++;
            } else {
                correct = false;
                cout << "WRONG!!" << endl;
            }
        } while (correct == true);
        cout << "You finished with " << points << " points!! \n";
    }
    compareScore = points;
    cout << "Would you like to play again? (y/n) ";
    cin >> play;
}