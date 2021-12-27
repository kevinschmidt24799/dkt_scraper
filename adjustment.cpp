//
// Created by Kevin Schmidt on 12/26/21.
//

#include "adjustment.hpp"

Adjustment::Adjustment(NameList const & previous, NameList const & current)
{
    int position = 0;
    int fake_current_pos = current.leaderboard_.size();
    for (auto const& name : current.leaderboard_)
    {
        int old_position = previous.get_position(name);
        if(old_position == -1)
        {
            old_position = fake_current_pos++;
        }
        movements_.push_back({name, old_position-position});
        ++position;
    }

    int prev_pos = 0;
    for (auto const& name : previous.leaderboard_)
    {
        if(!current.exists(name))
        {
            movements_.push_back({name, prev_pos - position});
            ++position;
        }
        ++prev_pos;
    }

    if(sum_changes() != 0)
    {
        std::cout << (*this);
    }
    assert(sum_changes()==0);
}

std::ostream &operator<<(std::ostream &os, const Adjustment &adjustment)
{
    os << " previous_time: " << adjustment.previous_time_ << " current_time: " << adjustment.current_time_ <<'\n';
    int i = 1;
    for(auto const & m : adjustment.movements_)
    {
        os << i++ << ": " << m << '\n';
    }

    return os;
}

std::ostream &operator<<(std::ostream &os, const Move &move)
{
    os << move.name_ << " change: " << move.change_;
    return os;
}


std::vector<Move>::iterator Adjustment::max_change()
{
    int max_value = 0;
    auto max_i = movements_.end();

    for (auto i = movements_.begin(); i != movements_.end(); ++i)
    {
        if(abs(i->change_) > max_value)
        {
            max_i = i;
            max_value = abs(i->change_);
        }
    }

    return max_i;
}


void Adjustment::step_back(std::vector<Move>::iterator i)
{
    Adjustment temp = (*this);

    int start = i-movements_.begin();

    if(i->change_ > 0)
    {
        auto j = i;
        for (int k = 0; k < i->change_; ++k)
        {
            (++j)->change_ ++;
        }
        i->change_ = 0;
        std::rotate(i, i+1, j+1);
    } else {
        auto j = i;
        for (int k = 0; k < -i->change_; ++k)
        {
            (--j)->change_--;
        }
        i->change_ = 0;
        std::rotate(j, i, i+1);
    }

//    std::cout << "start: " << start << '\n';
//    std::cout << temp << '\n';
//    std::cout << *this;
    assert(sum_changes()==0);

}

void Adjustment::normalize(WinLossRecords &records)
{
    for(auto i = max_change(); i != movements_.end(); i = max_change())
    {
        std::cout << "sum: " << sum_changes() << '\n';
        records.add_event(i->name_, current_time_, i->change_);
        step_back(i);
    }
    std::cout << "========================";
}


int Adjustment::sum_changes()
{
    int sum = 0;
    for (auto const & p: movements_)
    {
        sum += p.change_;
    }
    return sum;
}