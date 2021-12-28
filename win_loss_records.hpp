//
// Created by Kevin Schmidt on 12/26/21.
//

#ifndef SCRAPER_WIN_LOSS_RECORDS_HPP
#define SCRAPER_WIN_LOSS_RECORDS_HPP

#include <map>
#include <string>
#include <vector>
#include <ostream>

struct Event
{
    std::string date_;
    int start_;
    int change_;
};

struct Record
{

    std::vector<Event> history_;
    int wins_{0};
    int losses_{0};

    friend std::ostream &operator<<(std::ostream &os, const Record &record);
};

struct WinLossRecords
{
    std::map<std::string, Record> people_;

    void add_event(std::string const &name, std::string const &date, int start, int change);

    friend std::ostream &operator<<(std::ostream &os, const WinLossRecords &records);
};


#endif //SCRAPER_WIN_LOSS_RECORDS_HPP
