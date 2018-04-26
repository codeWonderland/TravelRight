//
// Created by codewonderland on 4/25/18.
//

#ifndef TRAVELRIGHT_APIINTERFACE_H
#define TRAVELRIGHT_APIINTERFACE_H

#include <cstdio>
#include <curl/curl.h>
#include <sstream>

class ApiInterface
{
public:
    static std::string downloadedResponse;

    void callApi(std::string url, void (*cb)(std::string));

    std::string downloadJSON(std::string URL);

    static int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in);
};

#endif //TRAVELRIGHT_APIINTERFACE_H
