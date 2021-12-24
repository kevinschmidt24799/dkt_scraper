//
// Created by Kevin Schmidt on 12/23/21.
//

#ifndef SCRAPER_FETCH_HPP
#define SCRAPER_FETCH_HPP

#include <string>
#include <curl/curl.h>

class Fetch
{
public:
    Fetch();
    std::string read (std::string const &url);

    ~Fetch();

    Fetch &operator=(Fetch const &other) = delete;
    Fetch(Fetch const &other) = delete;

private:
    CURL *hnd_;
};


#endif //SCRAPER_FETCH_HPP
