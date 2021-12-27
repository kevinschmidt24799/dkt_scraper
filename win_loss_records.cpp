//
// Created by Kevin Schmidt on 12/26/21.
//

#include "win_loss_records.hpp"
#include "iostream"

void WinLossRecords::add_event(std::string const &name, std::string const &date, int change)
{
    std::cout  << name << " " << date << " " << change << '\n';
}
