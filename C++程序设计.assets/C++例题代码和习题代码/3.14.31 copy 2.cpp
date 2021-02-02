#include <iostream>
#include <cmath>
using namespace std;
class Point
{
private:
  double x, y;
  friend class Line;

public:
  Point(double i = 0, double j = 0)
  {
    x = i;
    y = j;
  }
  Point(Point &p)
  {
    x = p.x;
    y = p.y;
  }
};

class Line
{
private:
  Point p1, p2;

public:
  Line(Point &xp1, Point &xp2) : p1(xp1), p2(xp2) {}
  double GetLength();
};

double Line::GetLength()
{
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}

int main()
{
  Point p1, p2(6, 8);
  Line L1(p1, p2);
  cout << L1.GetLength() << endl;
  return 0;
}