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

    static size_t save_bytes(void *contents, size_t size, size_t nmemb, void *userp);
    CURL *hnd_;
};


#endif //SCRAPER_FETCH_HPP
