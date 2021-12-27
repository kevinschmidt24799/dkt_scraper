//
// Created by Kevin Schmidt on 12/26/21.
//

#ifndef SCRAPER_ADJUSTMENT_HPP
#define SCRAPER_ADJUSTMENT_HPP
#include <string>
#include <ostream>
#include "name_list.hpp"
#include "win_loss_records.hpp"

struct Move
{
    friend std::ostream &operator<<(std::ostream &os, const Move &move);

    std::string name_;
    int change_;
};

struct Adjustment
{
    std::vector<Move> movements_;
    std::string previous_time_;
    std::string current_time_;

    Adjustment(NameList const & previous, NameList const & current);

    friend std::ostream &operator<<(std::ostream &os,  Adjustment const &adjustment);

    std::vector<Move>::iterator max_change();

    void step_back(std::vector<Move>::iterator i);

    void normalize(WinLossRecords &records);

    int sum_changes();

};


#endif //SCRAPER_ADJUSTMENT_HPP
