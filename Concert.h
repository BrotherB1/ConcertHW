/*****************************************************************
Concert.h Stores information about individual concerts, including
its name, the amount its desired by, date (in year, month, and day),
and possible friends to bring with you.

@author Luke Bassett
@version Fall 2017
*****************************************************************/

#ifndef CONCERT_CONCERT_H
#define CONCERT_CONCERT_H



#include <string>
#include <vector>
#include <ctime>

class Concert {

private:

//Comments and variables taken from Ira Woodring

// Who will be performing?
    std::string concertName;

// A list of the people you want
// to take with you.  May be empty
// or arbitrarily full.
    std::vector<std::string> friends;

// A value from 1-10 concerning how
// badly you want to see this show.
    int desire;

// The date of the show
// See http://en.cppreference.com/w/cpp/chrono/c/tm
    std::tm date;

public:

    /*****************************************************************
    Constructor initializes the Concert instant variables to simple
    bases.
    *****************************************************************/
    Concert();

    /*****************************************************************
    Constructor initializes the Concert instant variables to values
    that has been passed into them from a Main Function

    @param concert is the name of the concert
    @param friendList is the list of possible friends to attend te concert
    @param desireAmt is the level of desire for the concert
    @param concertDate is the date of the concert.
    *****************************************************************/
    Concert(std::string concert, std::vector<std::string> friendList, int desireAmt, std::tm concertDate);

    std::string getConcertName() const;

    std::string setConcertName(std::string concert);

    std::vector<std::string> getFriends() const;

    std::string getOneFriend(int f) const;

    std::vector<std::string> setFriend(std::string f);

    int getDesire() const;

    int setDesire(int desireNum);

    std::tm getDate() const;

    int getMonth() const;

    int getDay() const;

    int getYear() const;

    int setMonth(int month);

    int setDay(int day);

    int setYear(int year);

    std::tm setDate(int year, int month, int day);

    std::tm setDate(std::tm Date);

    //Overloaded < function
    bool operator <(const Concert& c) const;

    //Overload operator function for << symbol.
    friend std::ostream& operator<<(std::ostream& os, const Concert& ct);
};


#endif //CONCERT_CONCERT_H
