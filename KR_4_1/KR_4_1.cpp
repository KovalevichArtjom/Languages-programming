#include <iostream>
using namespace std;

class num {
public:
    int number;

    num(int number)
    {
        this->number = number;
    };

    virtual void shownum()
    {
        cout << "num: " << this->number << endl;
    }
};

class outoct : public num {
public:
    outoct(int number) :num(number) {};

    void shownum() override
    {
        cout << "outoct: " << oct << this->number << endl;
    }
};

class outhex : public num {
public:
    outhex(int number) :num(number) {};

    void shownum() override
    {
        cout << "outhex: " << hex << this->number << endl;
    }
};

int main()
{
    num     $num    = num(13);
    outoct  $outoct = outoct(13);
    outhex  $outhex = outhex(13);

    $num.shownum();
    $outoct.shownum();
    $outhex.shownum();

    cin.get();
    return 0;
}
