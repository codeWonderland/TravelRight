//
// Created by codewonderland on 4/25/18.
//

#include "ApiInterface.h"
#include <utility>

std::string ApiInterface::downloadedResponse = "";

void ApiInterface::callApi(std::string url, void (*cb)(std::string)) {

    // Get data and clear buffer for next api call, then send resp to the callback
    std::string resp = downloadJSON(url);
    ApiInterface::downloadedResponse = "";

    cb(resp);

}

std::string ApiInterface::downloadJSON(std::string URL) {
    CURL *curl;
    CURLcode res;

    std::ostringstream oss;

    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPGET,1);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,writer);
        res = curl_easy_perform(curl);

        if (CURLE_OK == res)
        {
            char *ct;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            if((CURLE_OK == res) && ct)
                return downloadedResponse;
        }
    }
}

int ApiInterface::writer(char *data, size_t size, size_t nmemb, std::string *buffer_in) {

    // Append Data to Buffer and return size of data
    downloadedResponse.append(data);

    return static_cast<int>(size * nmemb);

}


