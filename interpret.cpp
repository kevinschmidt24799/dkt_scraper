//
// Created by Kevin Schmidt on 12/26/21.
//
#include "name_list.hpp"
#include "adjustment.hpp"
#include "win_loss_records.hpp"

int main()
{

    auto fn = get_file_names(".");

    auto n = fn.begin();
    auto p2 = std::make_shared<NameList>(*n++);

    WinLossRecords wlr;
    while(n != fn.end()){
        auto p1 = p2;
        p2 = std::make_shared<NameList>(*n++);

        std::cout << "comparing " << p1->name_ << " with " << p2->name_ <<'\n';
        //do stuff here (p1, p2)

        Adjustment a{*p1, *p2};
        a.normalize(wlr);
        //std::cout << a;
    }

    std::cout << wlr;

    for(auto const & p : wlr.people_)
    {
        for(auto const & e : p.second.history_)
        {
            if(e.start_ < 200 && e.start_+e.change_ < 200 && e.change_ != 1){
                std::cout << e.start_ << "---" << e.change_ << '\n';
            }
        }
    }

    return 0;
}

