#include <iostream>
#include "fetch.hpp"
#include "extract.hpp"

int main()
{
    int i = 0;
    leaderboard l;
    do
    {
        Fetch f;
        std::string s = f.read("https://www.d0nkey.top/leaderboard?database_id=" + std::to_string(1970000 - i));
        fill_lb(l, s);
        if (l.r_ != NONS)
        {
            std::cout << 1970000 - i << " " << l;
        }
        i+=100;
    }while(l.time_.substr(0,7)!="2021-11");
}

