#ifndef __POINT__
#define __POINT__
class Point{
public:
  Point(int, int);
  
  int X;
  int Y;
  bool operator==(const Point);
  bool operator!=(const Point);
};
#endif