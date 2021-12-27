//
// Created by Kevin Schmidt on 12/26/21.
//

#include <fstream>
#include "name_list.hpp"

std::set<std::string> get_file_names(std::string const &directory)
{
    std::filesystem::path const path{directory};
    std::set<std::string> file_names;

    for (auto const& dir_entry : std::filesystem::directory_iterator{path})
    {
        file_names.insert(dir_entry.path());
    }
    return file_names;
}

NameList::NameList(std::string const & file_name)
{
    //int count = 0;
    std::ifstream input_stream {file_name};
    for (std::string temp; std::getline(input_stream, temp); ) {
        while(exists(temp))
        {
            temp += "-copy";
            std::cout << "Making new name: " << temp << '\n';
        }
        leaderboard_.push_back(temp);
        //if(++count>=10) break;
    }
    name_ = file_name;
}

int NameList::get_position(std::string const &name) const
{
    auto i = std::find(leaderboard_.begin(), leaderboard_.end(), name);
    if(i == leaderboard_.end()) return -1;
    return i-leaderboard_.begin();
}

bool NameList::exists(std::string const &name) const
{
    return !(std::find(leaderboard_.begin(), leaderboard_.end(), name) == leaderboard_.end());
}





