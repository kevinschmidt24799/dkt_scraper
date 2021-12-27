//
// Created by Kevin Schmidt on 12/23/21.
//

#include "extract.hpp"
#include <regex>
#include <iostream>
#include <filesystem>
#include <fstream>


Region fill_lb(Leaderboard &l, std::string const & data)
{
    std::string temp = data;
    std::smatch matches;
    std::regex am(R"regex(<div class="dropdown-trigger"><button aria-haspopup="true" aria-controls="dropdown-menu" class="button" type="button">([^<]+)<\/button><\/div>)regex");
    std::regex_search(temp, matches, am);

    for (int i = 0; i < region_types.size(); i ++)
    {
        if (matches[1].str() == region_types[i])
        {
            l.region_ = (Region)i;
            break;
        }
    }

    temp = matches.suffix();

    std::regex_search(temp, matches, am);

    for (int i = 0; i < format_types.size(); i ++)
    {
        if (matches[1].str() == format_types[i])
        {
            l.format_ = (Form)i;
            break;
        }
    }

    std::regex_search(temp, matches, std::regex(R"regex(([^>]+)UTC)regex"));

    l.time_ = matches[1].str();
    l.time_ = l.time_.substr(0, l.time_.size()-1);

    l.lb_ = extract(data);

    return l.region_;
}

std::vector<Point> extract(std::string const & data)
{
    std::string temp = data;
    std::vector<Point> names;

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

        names.push_back(Point{rank++, matches[1]});
        temp = matches.suffix();
    }
    return names;
}

std::ostream &operator<<(std::ostream& os, Point const &c)
{
    os << c.rank_ <<": " << c.name_;
    return os;
}

std::ostream &operator<<(std::ostream& os, Leaderboard const &l)
{
    os << "Region: " << region_types[(int)l.region_];
    if(l.region_==Region::NONS) return os << '\n';

    return os << " format: "<<format_types[(int)l.format_]<< " time: " << l.time_ << '\n';

//    for(Point const & p : l.lb_)
//    {
//        os << p << '\n';
//    }

}



void Leaderboard::save()
{
    std::string dir;
    dir+=region_types[(int)region_];
    dir+='/';
    dir+=format_types[(int)format_];
    std::filesystem::create_directories(dir);

    dir+='/';
    dir+=time_+".txt";

    std::ofstream of(dir, std::ios::trunc);

    for(Point const &p : lb_)
    {
        of << p.name_ << "\n";
    }

}









