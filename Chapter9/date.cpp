#include <iostream>
#include "../std_lib_facilities.h"
#include "Chrono.h"
using namespace std;


namespace Chrono {

    Date::Date(int yy, Month mm, int dd)
        :y(yy), m(mm), d(dd)
        {
            if(!is_date(yy, mm, dd)) throw Invalid{};
        }

    const Date& default_date()
    {
        static Date dd {2001, Date::Month::jan, 1};
        return dd;
    }

    Date::Date()
        : y(default_date().year()),
          m(default_date().month()),
          d(default_date().day())
    {
    }

    void Date::add_day(int n){
        d+=n;
        if(d > 31) error("add_day() results in invalid date");
    }

    void Date::add_month(int n){
        //;
    }
    void Date::add_year(int n){
        if(m == Date::Month::feb && d == 29 && !leapyear(y+n)){
            m = Month::mar;
            d = 1;
        }
        y+=n;
    }

    bool is_date(int y, Date::Month m, int d){

        if(d<= 0) return false;

        if(m<Date::Month::jan || Date::Month::dec < m) return false;

        int days_in_month = 31;

        switch(m){
            case Date::Month::feb:
                days_in_month = (leapyear(y))?29:28;
                break;
            case Date::Month::apr: case Date::Month::jun: case Date::Month::sep: case Date::Month::nov:
                days_in_month = 30;
                break;
            default:
                days_in_month = 31;
                break;
        }

        if(days_in_month<d) return false;

        return true;
    }

    bool leapyear(int y){
        if(y % 4 == 0 && y % 100 != 0) return true;
        return false;
    }
    
    bool operator==(const Date& a, const Date& b){
        return a.year() == b.year()
            && a.month() == b.month()
            && a.day() == b.day();
    }

    bool operator!=(const Date& a, const Date& b){
        return !(a==b);
    }

    ostream& operator<<(ostream& os, const Date& d){
        return os << '(' << d.year()
                    << ',' << int(d.month())
                    << ',' <<d.day() << ')';
    }

    istream& operator>>(istream& is, Date& dd){
        int y,m,d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if(!is) return is;
        if(ch1 != '(' || ch2 != ',' || ch3 != 'm' || ch4 != ')'){
            is.clear(ios_base::failbit);
            return is;
        }

        dd = Date(y, Date::Month(m), d);

        return is;
    }

    const Date first_date = Date(1800, Date::Month::jan, 1);
    const Day first_day = wednesday;
    int first = static_cast<int>(first_day);

    int months(Date::Month m){
        switch (m) {
            case Date::Month::jan: return 0;
            case Date::Month::feb: return 31;
            case Date::Month::mar: return 31 + 28;
            case Date::Month::apr: return 31 + 30 + 31;
            case Date::Month::may: return 31 + 28 + 31 + 30;
            case Date::Month::jun: return 31 + 28 + 31 + 30 + 31;
            case Date::Month::jul: return 31 + 28 + 31 + 30 + 31 + 30;
            case Date::Month::aug: return 31 + 28 + 31 + 30 + 31 + 30 + 31;
            case Date::Month::sep: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
            case Date::Month::oct: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
            case Date::Month::nov: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
            case Date::Month::dec: return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31; + 30 + 31 + 30;
        }
    }

    int no_leapyears(int y){
        int leaps = 0;
        for(int i=y; i>=first_date.year(); i--){
            if(i % 4 == 0 && i % 100 != 0) leaps++;
        }
        return leaps;
    }

    long number_of_days(const Date& d){
        if(d.year() < first_date.year()) error("number_of_days before start year");
        int years = d.year() - first_date.year();
        int days = d.day() - first_date.day();
        int mon = months(d.month()) + no_leapyears(d.year());
        int total = (365 * years) + days + mon;
        return total;
    }

  string day_in_string(Day d){
        switch (d)
        {
            case monday: return "Monday";
            case tuesday: return "Tuesday";
            case wednesday: return "Wednesday";
            case thursday: return "Thursday";
            case friday: return "Friday";
            case saturday: return "Saturday";
            case sunday: return "Sunday";
        }
        return "Unknown";
    }

    string days[]{
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    };

    Day day_of_week(const Date& d){
        int offset = number_of_days(d);
        int result = (first + offset) % 7;
        string today_day = Chrono::days[result];
        Day day = Day(result);

        return day;
    }

    Date next_Sunday(const Date d)
    {
        // days of the month
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        Day day = day_of_week(d);

        // check how many days till next sunday
        int n = 6;
        n -= day;
        if (n == 0)
        {
            n = 6;
        }

        int newDay = d.day() + n;
       
        Date::Month m = d.month();
        int monthIndex = static_cast<int>(m) - 1;
        int nextMonth = monthIndex;
        int year = 0;

        while (newDay > months[nextMonth])
        {
            newDay -= months[nextMonth];
            nextMonth++;
            
            if (nextMonth > 11)
            {
                nextMonth = 0;
                year++;
            }
        }

        Date::Month newMonth = static_cast<Date::Month>(nextMonth + 1);
        int newYear = d.year() + year;

        Date newDate = Date(newYear, newMonth, newDay);

        cout << "Next Sunday is: " << endl;
        return newDate;
    }

    
    Date next_weekday(const Date& d){
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        Day day = day_of_week(d);
        int newDay = 0;
        if(day < 4 || day == 6){
            newDay = d.day() + 1;
        } else if ( day == 5) {
            newDay = d.day() + 2;
        } else if (day == 4){
            newDay = d.day() + 3;
        }
        
        //----start of same as sunday
         Date::Month m = d.month();
        int monthIndex = static_cast<int>(m) - 1;
        int nextMonth = monthIndex;
        int year = 0;

        while (newDay > months[nextMonth])
        {
            newDay -= months[nextMonth];
            nextMonth++;
            
            if (nextMonth > 11)
            {
                nextMonth = 0;
                year++;
            }
        }

        Date::Month newMonth = static_cast<Date::Month>(nextMonth + 1);
        int newYear = d.year() + year;

        Date newDate = Date(newYear, newMonth, newDay);
        //------------------- same as nextSunday


        cout<< "next weekday: " << endl;
         return newDate;
    }
}

int main()
{

    Chrono::Date today(2028, Chrono::Date::Month::feb, 29);
    cout << today << endl;
    cout << next_Sunday(today) << endl;
    cout << next_weekday(today) << endl;
    
}