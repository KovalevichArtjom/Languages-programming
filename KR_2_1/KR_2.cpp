#include <iostream>
using namespace std;

int min( int numberOne, int numberTwo)
{
    return numberOne < numberTwo ? numberOne : numberTwo;
};

auto min(char typeCharacter, int typeInteger, double typeDouble)
{
    double res = typeCharacter;
   
    if (res > typeInteger) {
        res = typeInteger;
    }

    if (res > typeDouble) {
        res = typeDouble;
    }

    return res;
};

int main()
{   
    int     numberOne, numberTwo, typeInteger;
    char    typeCharacter;
    double  typeDouble;

    cout << "Enter first number with type [int]: ";
    cin >> numberOne;
    cout << "Enter second number with type [int]: ";
    cin >> numberTwo;
    cout << endl << "function min: " << min(numberOne, numberTwo) << endl;

    cout << endl << "Enter character with type [char]:  ";
    cin >> typeCharacter;
    cout << "Enter number with type [int]:  ";
    cin >> typeInteger;
    cout << "Enter number with type [double]:  ";
    cin >> typeDouble;
    cout << endl << "Overloaded function min: " << min(typeCharacter, typeInteger, typeDouble) << endl;

    cin.get();

    return 0;
}

