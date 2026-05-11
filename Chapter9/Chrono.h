#include "../std_lib_facilities.h"

namespace Chrono
{

    class Date{
    public:
        enum class Month
        {
            jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
        };

        class Invalid{};

        Date(int y, Month m, int d);
        Date();

        // non-modifying operations:
        int day() const { return d; }
        Month month() const { return m; }
        int year() const { return y; }

        // modifying operations:
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);

    private:
        int y;
        Month m;
        int d;
    }; // end of class Date()

    //----------------------------------------------------------
    
    bool is_date(int y, Date::Month m, int d); // true for valid state

    //----------------------------------------------------------

    bool leapyear(int y); //true if y is a leap year
    
    //----------------------------------------------------------

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    //----------------------------------------------------------

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, const Date& d);

    //----------------------------------------------------------

    enum Day {
         monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday
    };
    Day day_of_week(const Date& d);
    Date check_date(const Date d);
    Date next_Sunday(const Date d);
    Date next_weekday(const Date& d);
}