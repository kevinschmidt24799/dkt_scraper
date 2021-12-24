//
// Created by Kevin Schmidt on 12/23/21.
//

#include "extract.hpp"
#include <regex>
#include <iostream>

region fill_lb(leaderboard &l, std::string const & data)
{
    std::string temp = data;
    std::smatch matches;
    std::regex am(R"regex(<div class="dropdown-trigger"><button aria-haspopup="true" aria-controls="dropdown-menu" class="button" type="button">([^<]+)<\/button><\/div>)regex");
    std::regex_search(temp, matches, am);
    if(matches[1].str().substr(0,2)=="Am")
    {
        l.r_ = AM;
    }else if(matches[1].str().substr(0,2)=="Eu")
    {
        l.r_ = EU;
    }else if(matches[1].str().substr(0,2)=="As")
    {
        l.r_ = AP;
    }
    temp = matches.suffix();
    std::regex_search(temp, matches, am);

    if(matches[1].str().substr(0,2)!="St"){
        l.r_ = NONS;
        return l.r_;
    }

    std::regex_search(temp, matches, std::regex(R"regex(([^>]+)UTC)regex"));

    l.time_ = matches[1].str();

    if(l.r_ != NONS)
    {
        l.lb_ = extract(data);
    }
    return l.r_;
}

std::vector<point> extract(std::string const & data)
{
    std::string temp = data;
    std::vector<point> names;

    // created using regex101
    std::regex re(R"regex(player-profile\/([^"]+)">)regex");

    std::smatch matches;

    int rank = 1;

    while(std::regex_search(temp, matches, re))
    {
//        std::cout << "size: " << matches.size() << '\n';
//        for (int i = 0; i < matches.size(); ++i)
//        {
//            std::cout << i<< ": " << matches[i] << '\n';
//        }

        names.push_back(point{rank++, matches[1]});
        temp = matches.suffix();
    }
    return names;
}

std::ostream &operator<<(std::ostream& os, point const &c)
{
    os << c.rank_ <<": " << c.name_;
    return os;
}

std::ostream &operator<<(std::ostream& os, leaderboard const &l)
{
    os << "Region: " << region_types[l.r_] << " time: " << l.time_ << '\n';

    if(l.r_ == NONS) return os;

    for(point const & p : l.lb_)
    {
        //os << p << '\n';
    }

    return os;
}
