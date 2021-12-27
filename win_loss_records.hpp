//
// Created by Kevin Schmidt on 12/26/21.
//

#ifndef SCRAPER_WIN_LOSS_RECORDS_HPP
#define SCRAPER_WIN_LOSS_RECORDS_HPP

#include <map>
#include <string>
#include <vector>

struct Event
{
    std::string date_;
    int change_;
};

struct Record
{
    std::vector<Event> history_;
    int wins_;
    int losses_;
};

struct WinLossRecords
{
    std::map<std::string, Record> people_;

    void add_event(std::string const &name, std::string const &date, int change);
};


#endif //SCRAPER_WIN_LOSS_RECORDS_HPP
