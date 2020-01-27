#include <iostream>
#include <conio.h>
#include <windows.h>
#include <map>
#include <array>
#include <stdlib.h>
using namespace std;

int main()
{

	class Point
	{
		public:
			int x, y;

		public: Point(int crtX, int crtY)
		{
			x = crtX;
			y = crtY;
		}
	};

	class Rect
	{
	private:
		Point	lt, rb;
		int		currentPointX, currentPointY;
		const	int ANGLE = 1;
		HANDLE	out_handle	= GetStdHandle(STD_OUTPUT_HANDLE);
		COORD	coordinate	= { };
		array	<int, 8> mapping { {218, 196, 191, 179, 217, 196, 192, 179} };
		map		<char, int> figure = {
			{ 218, 0 },	//	┌
			{ 196, 0 },	//	─
			{ 191, 0 }, //	┐
			{ 179, 0 },	//	│
			{ 217, 0 },	//	┘
			{ 192, 0 },	//	└
		};

		public: Rect(Point a, Point b) :lt(a), rb(b)
		{
			currentPointX = lt.x;
			currentPointY = lt.y;

			build();
			draw();
		}

		private: void build()
		{
			for (auto it = figure.begin(); it != figure.end(); it++)
			{
				switch (it->first)
				{
				case (char) 196: 
					figure.at(it->first) = (rb.x - lt.x) - (ANGLE + ANGLE);
					break;
				case (char) 179:
					figure.at(it->first) = (rb.y - lt.y) - (ANGLE + ANGLE);
					break;
				default:
					figure.at(it->first) = ANGLE;
					break;
				}
			}
		}

		private: void draw()
		{

			for (auto& key : mapping)
			{	
				auto element = figure.find((char)key);

				if (element != figure.end()) {
					char crtElement = element->first;
					int countElement = element->second;

					for (auto number = 0; number < countElement; number++)
					{

						setCursor(crtElement);
						cout << crtElement;

					}
				}
			}
		}

		private: void setCursor(char chr)
		{

			switch (chr)
			{
			case (char) 179:
				if (currentPointX > lt.x) {
					currentPointY++;
				}
				else {
					currentPointY--;
				}

				break;
			case (char) 191:
				currentPointX++;
				break;
			case (char) 192:
				currentPointX--;
				break;
			case (char) 196:
				if (currentPointY > lt.y) {
					currentPointX--;
				}
				else {
					currentPointX++;
				}
				
				break;
			case (char) 217:
				currentPointY++;
				break;
			}

			coordinate.X = currentPointX;
			coordinate.Y = currentPointY;

			SetConsoleCursorPosition(out_handle, coordinate);
		}

		public: ~Rect()
		{
			coordinate.X = 0;
			coordinate.Y = 23;

			SetConsoleCursorPosition(out_handle, coordinate);
		}

	};


	int		heightRect, widthRect = 0;
	Point	pointBegin	= Point(0, 0);

	cout << "Enter height: " ;
	cin >> heightRect;
	cout << "Enter width: ";
	cin >> widthRect;

	system("cls");

	Point	pointEnd	= Point(widthRect, heightRect);
	Rect	$Rect		= Rect(pointBegin, pointEnd);

	cin.get();

	return 0;
}