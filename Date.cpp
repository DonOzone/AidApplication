#include "Date.h"
#include <iomanip>
#include <iostream>

using namespace std;

Date::Date(){
    //default constructor
 cout<<"Entering no-argument constructor" << endl;
    _year = 0;
    _mon  = 0;
    _day  = 0;
    _readErrorCode = NO_ERROR;
    //ctor
}
Date::Date(int yyyy, int mm, int dd){
    _year =yyyy;
    _mon =mm;
    _day=dd;
    _readErrorCode = NO_ERROR;
}
int Date::get_year(){
    return _year;
}
int Date::get_month(){
    return _mon;
}
int Date::get_day(){
    return _day;
}

//overiding operators
        bool Date::operator==(const Date& D)const{
            return _year == D._year && _mon == D._mon && _day == D._day;
        }
        bool Date::operator!=(const Date& D)const{
            if(!(_year == D._year && _mon == D._mon && _day == D._day)){
                    return true;
                }
        }
        bool Date::operator<(const Date& D)const{
            if(_year<D._year) return true;
            if(_year == D._year && _mon < D._mon) return true;
            if(_year == D._year && _mon == D._mon && _day < D._day) {return true;}
            else{ return false;}
        }
        bool Date::operator>(const Date& D)const{
            if(_year>D._year) return true;
            if(_year == D._year && _mon > D._mon) return true;
            if(_year == D._year && _mon == D._mon && _day > D._day) {return true;}
            else{ return false;}
        }
        bool Date::operator<=(const Date& D)const{
            if(_year<=D._year) return true;
            if(_year == D._year && _mon <= D._mon) return true;
            if(_year == D._year && _mon == D._mon && _day <= D._day) {return true;}
            else{ return false;}
        }
        bool Date::operator>=(const Date& D)const{
            if(_year>D._year) return true;
            if(_year == D._year && (_mon > D._mon || _mon == D._mon)) return true;
            if(_year == D._year && _mon == D._mon && (_day > D._day || _day == D._day)) {return true;}
            else{ return false;}
        }


void Date:: errCode(int errorCode){
switch (errorCode){
    case 0:
        _readErrorCode =NO_ERROR;
    break;
    case 1:
        _readErrorCode =CIN_FAILED;
    break;
    case 2:
        _readErrorCode =YEAR_ERROR;
    break;
    case 3:
        _readErrorCode =MON_ERROR;
    break;
    case 4:
        _readErrorCode =DAY_ERROR;
    break;
    }
}
void Date::validate(){
int err;
    if(_year<MIN_YEAR || _year>MAX_YEAR){
        //year error
        err = 2;
    }
    if(_mon<1 || _mon>12){
        //month error
         err = 3;
    }
    if(_day < 1 ||_day > mdays()){
        //day error
         err = 4;
    }
    errCode(err);//sets the error
}

int Date::errCode()const{
    return _readErrorCode;
}
// returns a uniqe value out of date
  // this value is used to compare two dates
  int Date::value()const{
    return _year * 372 + _mon * 31 + _day;
  }


 // mday():
  // returns the day of the month.
  // _mon value must be set for this to work
  // if _mon is invalid, this function returns -1
  // leap years are considered in this logic

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = _mon >= 1 && _mon <= 12 ? _mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
  }
Date::~Date(){
    //destructor activities

}
bool Date::bad()const{
    if(errCode()!=0){
        return true;
    }else{
        return false;
    }
}
/*
std::istream& read(std::istream& istr, const Date& D){
        istr>>D._year;
        istr.ignore(1);
        istr>>D._mon;
        istr.ignore(1);
        istr>>D._day;
    return istr;
}
std::ostream& write(std::ostream& ostr, const Date& D){
    ostr<<D._year<<"/"<<D._mon<<"/"<<D._day<<endl;
return ostr;
}
*/
 void operator<<( std::ostream&, Date D ){
        std::cout << D._year;
        std::cout << '/';
        std::cout << D._mon;
        std::cout << '/';
        std::cout << D._day;
    }
void operator>>(std::istream& istr, Date& D){
    cin>>D._year;
    istr.ignore(1);
    cin>>D._mon;
    istr.ignore(1);
    cin>>D._day;
}



// A fool proof Date entry from console
Date getDate();

int main(){
  Date
    D1,   // value to be recieved from console
    D2(2015,10, 20);
  cout << "Please enter a date to be compared to 2017/10/20."<<endl <<
          "YYYY/MM/DD > ";
  D1= getDate();
  cout <<"Your Entry: "<< D1.value() << endl;
  cout <<"Set by program to 2017/10/20: "<< D2.value() << endl;
  cout << "All the following statements must be correct: " << endl;
  if (D1 > D2){
    cout << D1.value() << " > " << D2.value() << endl;
  }
  else{
    cout << D1.value() << " <= " << D2.value() << endl;
  }
  if (D1 < D2){
    cout << D1.value() << " < " << D2.value() << endl;
  }
  else{
    cout << D1.value() << " >= " << D2.value() << endl;
  }
  if (D1 <= D2){
    cout << D1.value() << " <= " << D2.value() << endl;
  }
  else{
    cout << D1.value() << " > " << D2.value() << endl;
  }
  if (D1 >= D2){
    cout << D1.value() << " >= " << D2.value() << endl;
  }
  else{
    cout << D1.value() << " < " << D2.value() << endl;
  }
  if (D1 == D2){
    cout << D1.value() << " == " << D2.value() << endl;
  }
  else{
    cout << D1.value() << " != " << D2.value() << endl;
  }
  if (D1 != D2){
    cout << D1.value() << " != " << D2.value() << endl;
  }
  else{
    cout << D1.value() << " == " << D2.value() << endl;
  }
  return 0;
}

Date getDate(){
  Date D;
  do{
    cin >> D;      // get D from console
    switch (D.errCode())    {
    case CIN_FAILED:
      cin.clear();
      cout << "Invlid date Entry";
      break;
    case YEAR_ERROR:
      cout << "Invlid year; " << MIN_YEAR << "<= year <= " << MAX_YEAR;
      break;
    case MON_ERROR:
      cout << "Invlid month, 1<=Mon<=12";
      break;
    case DAY_ERROR:
      cout << "Invlid Day, 1<=Day<=" << D.mdays();
    }
    cin.ignore(2000, '\n');
  } while (D.bad() && cout << ", Please try again > ");  // if D is invalid, print ", Please try again > " and loop
  return D;
}
