#ifndef DATE_H
#define DATE_H
//defination of the errors
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR  3
#define DAY_ERROR  4

//defineation of the max and min
#define MIN_YEAR 2000
#define MAX_YEAR 2030

class Date
{
    public:
        Date();
        Date(int,int,int);
        ~Date();
        int _year; //holds the year, a four digit between MIN_YEAR and MAX_YEAR
        int _mon;  //month of the year, between 1 to 12
        int _day;   //Day of the month, note the leap year
        int _readErrorCode;  //Holds an error code to determine if date value is valid or not

        int mdays() const;

        //getter methods for the date
        int get_year();
        int get_month();
        int get_day();
        bool operator==(const Date& D)const;
        bool operator!=(const Date& D)const;
        bool operator<(const Date& D)const;
        bool operator>(const Date& D)const;
        bool operator<=(const Date& D)const;
        bool operator>=(const Date& D)const;

        //accessor or getter functions
        int errCode()const; //returns the _readErrorCode value
        bool bad()const;    //returns true if _readErrorCode is not equal to zero
        void validate();//checks if the date is correct
                int value() const;

    protected:
    private:
        void errCode(int errorCode); //sets the -readErrorCode member-variable to one of the values mentioned

};
//std::istream& read(std::istream& istr, Date& D);
//std::ostream& write(std::ostream& ostr, const Date& D) ;


#endif // DATE_H
