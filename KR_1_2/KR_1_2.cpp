#include <iostream>
#include <conio.h>
#include <windows.h>
#include <map>
using namespace std;

int main()
{

	class Point
	{
		private:
			int x;
			int y;

		public: Point(int crtX, int crtY)
		{
			x = crtX;
			y = crtY;
		}
	};

	class Rect
	{
	private:
		Point	lt;
		Point	rb;
		const	int ANGLE = 1;
		HANDLE	out_handle	= GetStdHandle(STD_OUTPUT_HANDLE);
		COORD	coordinate	= { };
		map		<char, int> figure = {
			{ 196, 0 },		//	─
			{ 179, 0 },		//	│
			{ 218, ANGLE },	//	┌
			{ 191, ANGLE }, //	┐
			{ 217, ANGLE },	//	┘
			{ 192, ANGLE },	//	└
		};

		public: Rect(Point a, Point b) :lt(a), rb(b)
		{
			build();
			//draw();
		}

		private: void build()
		{
			for (auto it = figure.begin(); it != figure.end(); it++)
			{
				figure.at(it->first) = 2;
			}
		}

		private: void draw()
		{
			for (auto it = figure.begin(); it != figure.end(); it++)
			{	
				setCursor(0, 10);
				for (auto number = 0; number < (it->second); number++)
				{
					cout << it->first << endl;
				}
			}
		}

		private: void setCursor(int x, int y)
		{
			coordinate.X = y;
			coordinate.Y = x;

			SetConsoleCursorPosition(out_handle, coordinate);
		}

	};

	Point	pointBegin	=	Point(0, 0);
	Point	pointEnd	=	Point(10, 10);
	Rect	$Rect		=	Rect(pointBegin, pointEnd);

	cin.get();

	return 0;
}