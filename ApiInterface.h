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

//    Basic structure established from https://stackoverflow.com/questions/5707957/c-libcurl-json-rest
    std::string downloadJSON(std::string URL);

//    Basic structure established from https://stackoverflow.com/questions/5707957/c-libcurl-json-rest
    static int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in);
};

#endif //TRAVELRIGHT_APIINTERFACE_H
