//
// Created by Kevin Schmidt on 12/23/21.
//

#ifndef SCRAPER_EXTRACT_HPP
#define SCRAPER_EXTRACT_HPP

#include <vector>
#include <string>
#include <array>

enum class Region{
    AM, EU, AP, NONS
};
enum class Form{
    STD, W, C, BG, M
};
static std::array<std::string,4> region_types
        {
                "Americas",
                "Europe",
                "Asia-Pacific",
                "Invalid or Not Standard"
        };

static std::array<std::string,5> format_types
        {
                "Standard",
                "Wild",
                "Classic",
                "Battlegrounds",
                "Mercenaries"
        };

struct Point{

    int rank_;
    std::string name_;
    friend std::ostream &operator<<(std::ostream& os, Point const &c);
};

struct Leaderboard{
    Leaderboard(){};
    std::vector<Point> lb_;
    Region region_{Region::NONS};
    Form format_{Form::STD};
    std::string time_;
    friend std::ostream &operator<<(std::ostream& os, Leaderboard const &l);
    void save();
};


std::vector<Point> extract(std::string const & data);
Region fill_lb(Leaderboard &l, std::string const & data);

#endif //SCRAPER_EXTRACT_HPP
