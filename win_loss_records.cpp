//
// Created by Kevin Schmidt on 12/26/21.
//

#include "win_loss_records.hpp"
#include "iostream"

void WinLossRecords::add_event(std::string const &name, std::string const &date, int change)
{
    people_[name].history_.push_back({date, change});

    if(change > 0)
    {
        people_[name].wins_++;
    }else{
        people_[name].losses_++;
    }

    std::cout  << name << " " << date << " " << change << '\n';
}

std::ostream &operator<<(std::ostream &os, const WinLossRecords &records)
{
    for (auto const & p : records.people_)
    {
        os << p.first << ": " << p.second << '\n';
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Record &record)
{
    os << record.wins_ << " - " << record.losses_;
    return os;
}
