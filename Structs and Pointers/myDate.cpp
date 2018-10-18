/*
 Name: Brian Drennan
 Class: CECS 282-05
 Project Name: Prog 2 - Structs and Pointers
 Due Date: 10/17/2018
 */

#include "myDate.hpp"
#include <string>
#include <iostream>

using namespace std;

void  J2G(int JD, int &m, int &d, int &y){
    
    int I = 0;
    int J = 0;
    int K = 0;
    int L = 0;
    int N = 0;
    
    L= JD+68569;
    N= 4*L/146097;
    L= L-(146097*N+3)/4;
    I= 4000*(L+1)/1461001;
    L= L-1461*I/4+31;
    J= 80*L/2447;
    K= L-2447*J/80;
    L= J/11;
    J= J+2-12*L;
    I= 100*(N-49)+I+L;
    
    y = I;
    m = J;
    d = K;
}

int G2J(int d, int m, int y){
    int I = y;
    int J = m;
    int K = d;
    
    int JD= K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
    
    return JD;
}

myDate::myDate(){
    month = 5;
    day = 11;
    year = 1959;
}

myDate::myDate(int m, int d, int y){
    int JD = G2J(d, m, y);
    int m1 = 0;
    int d1 = 0;
    int y1 = 0;
    J2G(JD, m1, d1, y1);
    
    if(m1 == m && d1 == d && y1 == y){
        month = m;
        day = d;
        year = y;
    }
    else {
        month = 5;
        day = 11;
        year = 1959;
    }
}

myDate::myDate(int JDate){
    //need to account for leap years 
    int m1 = 0;
    int d1 = 0;
    int y1 = 0;
    J2G(JDate, m1, d1, y1);
    month = m1;
    day = d1;
    year = y1;
}

void myDate::display(){
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    cout << months[month - 1] << " " << day << ", " << year;
}

string myDate::displayDateString(){
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    string date = months[month - 1] + " " + to_string(day) + ", " + to_string(year);
    
    return date;
}

void myDate::increaseDate(int x){
    int JD = G2J(day, month, year);
    JD += x;
    J2G(JD, month, day, year);
}

void myDate::decreaseDate(int x){
    int JD = G2J(day, month, year);
    JD -= x;
    J2G(JD, month, day, year);
}

int myDate::daysBetween(myDate D){
    int dB = 0;
    
    int tempD = D.day;
    int tempM = D.month;
    int tempY = D.year;
    
    int tempJD = G2J(tempD, tempM, tempY);
    int JD = G2J(day, month, year);
    
    dB = tempJD - JD;
    
    return dB;
}

string myDate::dayName(){
    string dName[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    int JD = G2J(day, month, year);
    int temp = JD % 7;

    return dName[temp];
}

int myDate::getMonth(){
    return month;
}

int myDate::getDay(){
    return day;
}

int myDate::getYear(){
    return year;
}

int myDate::dayOfYear(){
    int JDStart = G2J(1, 1, year);
    int JDCurrent = G2J(day, month, year);
    
    int diff = JDCurrent - JDStart;
    
    return diff + 1;
}


