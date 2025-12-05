#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void drawHangman(int mistakes, int maxMistakes)
{
    int totalParts = 6, parts = (mistakes * totalParts) / maxMistakes;
    char head = ' ', body = ' ', leftArm = ' ', rightArm = ' ', leftLeg = ' ', rightLeg = ' ';

    if (parts > totalParts) {
        parts = totalParts;
    }
    switch (parts) {
    case 6: {
        rightLeg = '\\';
    }
    case 5: {
        leftLeg = '/';
    }
    case 4: {
        rightArm = '\\';
    }
    case 3: {
        leftArm = '/';
    }
    case 2: {
        body = '|';
    }
    case 1: {
        head = 'O';
    }
    }

    cout << "  +----+" << endl;
    cout << "  |    |" << endl;
    cout << "  |    " << head << endl;
    cout << "  |   " << leftArm << body << rightArm << endl;
    cout << "  |   " << leftLeg << " " << rightLeg << endl;
    cout << "  |" << endl;
    cout << "======" << endl;
}

void hangman(string word, int length, int maxMistakes) {
    int mistakes = 0, wrongLetterArrayIndex = 0;
    char guess, lettersTried[127];
    bool won = false, letterFound = false, letterUncovered[30], wordUncovered = false, wrongLetterFound = false;
    for (int i = 0; i < 30; i++) {
        letterUncovered[i] = false;
    }
    while (mistakes < maxMistakes) {

        for (int i = 0; i < length; i++) {
            if (!letterUncovered[i]) {
                wordUncovered = false;
                break;
            }
            else {
                wordUncovered = true;
            }
        }
        if (wordUncovered) {
            cout << endl << "YOU WON!, THE WORD WAS '" << word << "'! MISTAKES MADE: " << mistakes << "/" << maxMistakes << "!" << endl;
            won = true;
            break;
        }
        drawHangman(mistakes, maxMistakes);
        cout << "WRONG LETTERS: ";
        for (int i = 0; i < wrongLetterArrayIndex; i++) {
            cout << lettersTried[i] << " ";
        }
        cout << endl << "THE WORD: ";
        for (int i = 0; i < length; i++) {
            if (!letterUncovered[i]) {
                cout << "_";
            }
            else {
                cout << word[i];
            }
        }
        cout << endl;
        cout << "TAKE A GUESS: ";
        cin >> guess;
        for (int i = 0; i < length; i++) {
            if (toupper(guess) == toupper(word[i])) {
                letterFound = true;
                letterUncovered[i] = true;
            }
        }