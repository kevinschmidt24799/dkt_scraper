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

    return 0;
}

