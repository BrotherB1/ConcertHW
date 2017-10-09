/*****************************************************************
Main Function that instantiates several concert objects, with
varying dates, desires, names, and friends. It places them into
an array and is sorted first by date, then by desire.

@author Luke Bassett
@version Fall 2017
*****************************************************************/

#include <iostream>
#include "Concert.h"
#include <algorithm>
#include <functional>

int main() {
    //create Vector of concert objects
    std::vector <Concert> concert;

    //initialize all concert objects
    Concert c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;

    c1.setConcertName("Halloween Haunt");
    c1.setDesire(7);
    c1.setDate(2000, 2, 27);
    c1.setFriend("Jackie");
    c1.setFriend("Steve");

    c2.setDate(1999, 4, 5);
    c2.setConcertName("Thanksgiving Things");
    c2.setDesire(9);
    c2.setFriend(c1.getOneFriend(0));
    c2.setFriend("Hannah");

    c3 = Concert("Christmas Cheer", c1.getFriends(), 3, c1.getDate());
    c3.setFriend("Lillie");
    c3.setDate(1999, 12, 7);

    c4.setConcertName("Summer Surprises");
    c4.setDesire(2);
    c4.setDate(1998, 5, 5);
    c4.setFriend("Jackie");
    c4.setFriend("Steve");

    c5 = Concert("Labor Luxuries", c1.getFriends(), 4, c3.getDate());
    c5.setFriend("Aaron");
    c5.setDate(c2.getDate());

    c6.setConcertName("New Years' News");
    c6.setDesire(6);
    c6.setDate(1990, 11, 5);
    c6.setFriend("Jarod");
    c6.setFriend("Trevor");

    c7 = Concert("Easter Extravaganza", c1.getFriends(), 10, c3.getDate());
    c7.setFriend("Lee");
    c7.setMonth(8);
    c7.setDay(17);
    c7.setYear(2000);

    c8 = Concert("Winter Wonderland", c1.getFriends(), 8, c6.getDate());
    c8.setFriend("Fred");

    c9.setConcertName("Fall Festivities");
    c9.setDesire(3);
    c9.setDate(2001, 9, 13);
    c9.setFriend(c8.getOneFriend(1));
    c9.setFriend("Kayla");

    c10 = Concert("Spring Show", c8.getFriends(), 2, c7.getDate());
    c10.setFriend("Susan");

    //define vector of concerts
    concert = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10};

    //with help from http://en.cppreference.com/w/cpp/algorithm/sort
    //sorts through the concert vector, putting earliest dates first
    std::sort(concert.begin(), concert.end());

    std:: cout << "Your order of upcoming concerts is: " << "\n" <<std::endl;

    //prints all concerts in sorted order
    for(int i =0; i < concert.size(); i++){
        std:: cout << concert[i] << "\n";
    }
    return 0;
}

// With help from https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
/*****************************************************************
    Overload operator of << to allow it to print Concert objects

    @param os is the steam in which the output is places
    @param ct is the concert object that is being printed
    *****************************************************************/
std::ostream& operator<<(std::ostream& os, const Concert& ct)
{
    os << ct.getConcertName() << " is on " << ct.getMonth() << "/";
    os << ct.getDay()<< "/" << ct.getYear() << " with ";
    os << ct.getDesire() << " desire." << "\n";

    return os;
}