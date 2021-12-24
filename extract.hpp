//
// Created by Kevin Schmidt on 12/23/21.
//

#ifndef SCRAPER_EXTRACT_HPP
#define SCRAPER_EXTRACT_HPP

#include <vector>
#include <string>
enum region{
    AM, EU, AP, NONS
};
static std::string region_types[] =
        {
                "Americas",
                "Europe",
                "Asia-Pacific",
                "Invalid or Not Standard"
        };

struct point{

    int rank_;
    std::string name_;
    friend std::ostream &operator<<(std::ostream& os, point const &c);
};

struct leaderboard{
    leaderboard()
    {
        r_ = NONS;
    }
    std::vector<point> lb_;
    region r_;
    std::string time_;
    friend std::ostream &operator<<(std::ostream& os, leaderboard const &l);
};


std::vector<point> extract(std::string const & data);
region fill_lb(leaderboard &l, std::string const & data);

#endif //SCRAPER_EXTRACT_HPP
