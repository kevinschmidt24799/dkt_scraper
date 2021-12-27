//
// Created by Kevin Schmidt on 12/23/21.
//

#include "fetch.hpp"

Fetch::Fetch()
{
    hnd_ = curl_easy_init();
    curl_easy_setopt(hnd_, CURLOPT_BUFFERSIZE, 102400L);
    curl_easy_setopt(hnd_, CURLOPT_USERAGENT, "curl/7.77.0");
    curl_easy_setopt(hnd_, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(hnd_, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
    curl_easy_setopt(hnd_, CURLOPT_TCP_KEEPALIVE, 1L);

}

Fetch::~Fetch()
{
    curl_easy_cleanup(hnd_);
    hnd_ = NULL;
}


size_t Fetch::save_bytes(void *contents, size_t size, size_t nmemb, void *userp)
{
    auto realsize = size * nmemb;
    auto temp = (std::string *)userp;
    temp->append((char *)contents, realsize);

    return realsize;
}


std::string Fetch::read(const std::string &url)
{
    std::string out;
    curl_easy_setopt(hnd_, CURLOPT_URL, url.c_str());

    curl_easy_setopt(hnd_, CURLOPT_WRITEFUNCTION, save_bytes);
    curl_easy_setopt(hnd_, CURLOPT_WRITEDATA, (void *) &out);

    curl_easy_perform(hnd_);

    return out;
}


