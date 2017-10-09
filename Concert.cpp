/*****************************************************************
Concert.cpp describes the function of all methods in
Concert.h.

@author Luke Bassett
@version Fall 2017
*****************************************************************/

#include "Concert.h"
#include <iostream>

/*****************************************************************
    Constructor initializes the Concert instant variables to simple
    bases.
    *****************************************************************/
Concert:: Concert(){
    concertName = " ";
    friends.clear();
    desire = 0;
    date.tm_mday = 0;
}

/*****************************************************************
    Constructor initializes the Concert instant variables to values
    that has been passed into them from a Main Function

    @param concert is the name of the concert
    @param friendList is the list of possible friends to attend te concert
    @param desireAmt is the level of desire for the concert
    @param concertDate is the date of the concert.
    *****************************************************************/
Concert:: Concert(std::string concert, std::vector<std::string> friendList, int desireAmt, std::tm concertDate){
    concertName = concert;
    friends = friendList;
    desire = desireAmt;
    date = concertDate;
}

std::string Concert:: getConcertName() const{
    return concertName;
}

std::vector<std::string> Concert:: getFriends() const{
    return friends;
}

std::string Concert:: getOneFriend(int f) const{
    return friends[f];
}

int Concert:: getDesire() const{
    return desire;
}

std::tm Concert:: getDate() const{
    return date;
}

int Concert:: getMonth() const{
    return date.tm_mon;
}

int Concert:: getDay() const{
    return date.tm_mday;
}

int Concert:: getYear() const{
    return date.tm_year;
}

std::string Concert:: setConcertName(std::string concert){
    return concertName = concert;
}

std::vector<std::string> Concert:: setFriend(std::string addFriend){
    friends.push_back(addFriend);

    return friends;
}

int Concert:: setDesire(int desireNum){
    return desire = desireNum;
}

int Concert:: setMonth(int month){
    return date.tm_mon = month;
}

int Concert:: setDay(int day){
    return date.tm_mday = day;
}

int Concert:: setYear(int year){
    return date.tm_year = year;
}

std::tm Concert:: setDate(std::tm Date) {
    return date = Date;
}

std::tm Concert:: setDate(int year, int month, int day){
    date.tm_year = year;
    date.tm_mon = month;
    date.tm_mday = day;
    return date;
}

// With help from https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm
/*****************************************************************
    Function that allows the less than operator to compare concerts

    @param c is the concert being compared to and initial concert.
    *****************************************************************/
bool Concert:: operator <(const Concert& c) const {
    if(date.tm_year < c.getYear()){
        return true;
    }
    if(date.tm_year > c.getYear()){
        return false;
    }
    if(date.tm_mon < c.getMonth()){
        return true;
    }
    if(date.tm_mon > c.getMonth()){
        return false;
    }
    if(date.tm_mday < c.getDay()){
        return true;
    }
    if(date.tm_mday > c.getDay()){
        return false;
    }
    if(c.getDesire()< desire){
        return true;
    }

    return false;


}