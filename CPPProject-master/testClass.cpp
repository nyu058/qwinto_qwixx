#ifdef TEST
#include "QwintoRow.h"
#include "QwintoScoreSheet.h"
#include "QwintoPlayer.h"
#include "QwixxPlayer.h"
#include "QwixxRow.h"
#include "QwixxScoreSheet.h"
#include "RollOfDice.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main()
{
    cout << "This is the test class for all the classes" << endl;
    int index;
    bool test = true;
    char a;
    while (test)
    {
        test = false;
        cout << "You can test folling classes:" << endl
             << "1.QwintoPlayer" << endl
             << "2.QwintoRow" << endl
             << "3.QwintoScoreSheet" << endl
             << "4.QwixxPlayer" << endl
             << "5.QwixxRow" << endl
             << "6.QwixxScoreSheet" << endl
             << "7.RollOfDice" << endl
             << "Input index to start test:" << endl;
        cin >> index;

        if (index == 1)
        {
            Colour red = Colour::RED;
            Colour yellow = Colour::YELLOW;
            Dice *a = new Dice(red);
            Dice *b = new Dice(yellow);
            RollOfDice rd;
            rd.add(*a);
            rd.add(*b);
            rd.roll();
            QwintoScoreSheet qtss = QwintoScoreSheet("myName");
            QwintoPlayer qtpyr = QwintoPlayer(qtss);
            qtpyr.inputBeforeRoll(rd);
            qtpyr.inputAfterRoll(rd);
            break;
        }
        if (index == 2)
        {
            QwintoRow<Colour::RED> red;
            red[2] = 3;
            QwintoRow<Colour::YELLOW> yellow;
            yellow[5] = 6;
            QwintoRow<Colour::BLUE> blue;
            blue[7] = 13;
            cout << red << endl;
            cout << yellow << endl;
            cout << red << endl;
            break;
        }
        if (index == 3)
        {
            Colour red = Colour::RED;
            Colour yellow = Colour::YELLOW;
            Dice *a = new Dice(red);
            Dice *b = new Dice(yellow);
            RollOfDice rd;
            rd.add(*a);
            rd.add(*b);
            rd.roll();
            QwintoScoreSheet qtss = QwintoScoreSheet("myName");
            cout << qtss << endl;
            qtss.validate(rd, red, 7);
            qtss.score(rd, Colour::BLUE, 7);
        }
        if (index == 4)
        {
            cout << "Testing QwixxPlayer.cpp" << endl;
            cout << "Build a player named test and set him active" << endl;
            string playerName = "test";
            QwintoScoreSheet *qtss = new QwintoScoreSheet(playerName);
            QwintoPlayer *player = new QwintoPlayer(*qtss);
            (*player).active = true;
            cout << "Build roll of dice, add dice and roll" << endl;
            RollOfDice rd;
            (*player).inputBeforeRoll(rd);
            rd.roll();
            cout << "Show score sheet, let player make choice" << endl;
            (*player).inputBeforeRoll(rd);
            cout << "End of test" << endl;
        }
        if (index == 5)
        {
            cout << "Testing QwixxRow.cpp" << endl;
            cout << "Build a vector row red and list row green" << endl;
            QwixxRow<vector<int>, Colour::RED> redRow;
            QwixxRow<list<int>, Colour::GREEN> greenRow;
            RollOfDice rodR, rodG;
            Colour red = Colour::RED;
            Colour green = Colour::GREEN;
            Dice *reddice = new Dice(red);
            Dice *greendice = new Dice(green);
            rodR.add(*reddice);
            rodG.add(*greendice);
            rodR.roll();
            rodG.roll();
            cout << "Print two rows" << endl;
            cout << "Red: " << redRow << endl;
            cout << "Green: " << greenRow << endl;
            cout << "Add roll of dice";
            redRow += rodR;
            greenRow += rodG;
            cout << "Print two rows" << endl;
            cout << "Red: " << redRow << endl;
            cout << "Green: " << greenRow << endl;
            cout << "All input should be validated" << endl;
            cout << "End of test" << endl;
        }
        if (index == 6)
        {
            cout << "Testing QwixxScoreSheet.cpp" << endl;
            cout << "You can test this by testing QwixxPlayer.cpp" << endl;
            cout << "End of Test" << endl;
        }
        if (index == 7)
        {
            cout << "Testing RollOfDice.cpp" << endl;
            cout << "You can test this by testing any ohter class above." << endl;
            cout << "End of Test" << endl;
        }

        cout << "Keep testing? y/n" << endl;
        cin >> a;
        if (a == 'y')
            test = true;
    }
    return 0;
}
#endif