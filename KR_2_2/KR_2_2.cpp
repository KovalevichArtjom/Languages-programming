#include <iostream>
using namespace std;


class vektorIntegerNumbers
{
private:
    int* calculation;
public:
    int* vector;
    int SIZE_ARR;

public: 
    vektorIntegerNumbers(int* vector, int size) : vector(vector), SIZE_ARR(size) 
    { 
        calculation = new int[this->SIZE_ARR];
    };
  
    void display()
    {
        cout << " Values vektor: { ";
        for (int i = 0; i < this->SIZE_ARR; i++) {
            cout << this->vector[i] << " ";
        }
        cout << "}" << endl;

    }
    
    vektorIntegerNumbers operator + (vektorIntegerNumbers vektorSecond)
    {

        for (int i = 0; i < this->SIZE_ARR; i++) {
            this->calculation[i] = this->vector[i] + vektorSecond.vector[i];
        }
        return vektorIntegerNumbers(this->calculation, SIZE_ARR);
    }

    vektorIntegerNumbers operator += (vektorIntegerNumbers vektorSecond)
    {

        for (int i = 0; i < this->SIZE_ARR; i++) {
            this->vector[i] = this->vector[i] + vektorSecond.vector[i];
        }
        return *this;
    }

    vektorIntegerNumbers operator -= (vektorIntegerNumbers vektorSecond)
    {

        for (int i = 0; i < this->SIZE_ARR; i++) {
            this->vector[i] = this->vector[i] - vektorSecond.vector[i];
        }
        return *this;
    }

};


int main()
{
    const int SIZE_ARR = 3;
    int firstVektor[SIZE_ARR]   = { 1, 2, 3 };
    int secondVektor[SIZE_ARR]  = { 2, 2, 3 };

    vektorIntegerNumbers vektorFirst    = vektorIntegerNumbers(firstVektor, SIZE_ARR);
    vektorIntegerNumbers vektorSecond   = vektorIntegerNumbers(secondVektor, SIZE_ARR);
    
    vektorIntegerNumbers vektorFour     = vektorFirst += vektorSecond;
    vektorIntegerNumbers vektorThree    = vektorFirst + vektorSecond;
    vektorIntegerNumbers vektorFive     = vektorFirst -= vektorSecond;

    vektorFirst.display();
    vektorSecond.display();
    cout << endl;
    
    vektorFour.display();
    vektorThree.display();
    vektorFive.display();

    cin.get();

    return 0;
}