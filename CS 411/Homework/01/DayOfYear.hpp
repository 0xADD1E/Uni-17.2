class DayOfYear {
public:
  DayOfYear(int monthValue, int dayValue);
  DayOfYear(int monthValue);
  DayOfYear();

  void input( );
  void output( );

  int setDayOfYear(int month, int day);
  int getMonth();
  int getDay();

private:
  int dayOfYear;
  static int monthLengths[];
};
