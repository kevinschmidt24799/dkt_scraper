#include <iostream>
#include "fetch.hpp"
#include "extract.hpp"

int main()
{
    int i = 1946534;
    while(true){
        Fetch f;
        Leaderboard l;

        std::string s = f.read("https://www.d0nkey.top/leaderboard?database_id=" + std::to_string( i));
        fill_lb(l, s);
        if(l.time_.substr(0,7)=="2021-10")break;

        if(l.time_.substr(0,7)=="2021-11" && l.region_!=Region::NONS)
        {
            l.save();
            std::cout << "adding " <<i <<": " <<l;
        }else{
            std::cout << "skipping " <<i <<": " <<l;
        }
        i--;
    }
}

