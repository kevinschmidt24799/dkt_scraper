//
// Created by Kevin Schmidt on 12/26/21.
//

#ifndef SCRAPER_NAME_LIST_HPP
#define SCRAPER_NAME_LIST_HPP

#include <filesystem>
#include <string>
#include <set>
#include <iostream>
#include <vector>

std::set<std::string> get_file_names(std::string const &directory);

struct NameList
{
    std::string name_;
    std::vector<std::string> leaderboard_;
    NameList(std::string const & file_name);

    int get_position(std::string const &name) const;
    bool exists(std::string const &name) const;

};


#endif //SCRAPER_NAME_LIST_HPP
