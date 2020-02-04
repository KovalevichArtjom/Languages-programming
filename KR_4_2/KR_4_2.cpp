#include <iostream>
using namespace std;

class figure {
public:
	int colorFigure;

	virtual void create() = 0;
	virtual void remove() = 0;
	virtual void draw() = 0;
	virtual void setSize() =0;
	virtual void setCoordinate() = 0;
	virtual void setColorFigure(int color) {
		this->colorFigure = color;
	}
};


int main()
{

	cin.get();

	return 0;
}