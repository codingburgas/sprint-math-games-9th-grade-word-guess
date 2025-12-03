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
