//
// Created by codewonderland on 4/25/18.
//

#include "ApiInterface.h"
#include <utility>

std::string ApiInterface::downloadedResponse = "";

void ApiInterface::callApi(std::string url, void (*cb)(std::string), std::string headers[], int size) {

    // Get data and clear buffer for next api call, then send resp to the callback
    std::string resp = downloadJSON(url, headers, size);
    ApiInterface::downloadedResponse = "";

    cb(resp);

}

std::string ApiInterface::downloadJSON(std::string URL, std::string headers[], int size) {
    CURL *curl;
    CURLcode res;
    int i;

    std::ostringstream oss;

    curl = curl_easy_init();

    if (curl)
    {
        struct curl_slist *chunk = nullptr;

        for (i = 0; i < size; i++)
        {
            chunk = curl_slist_append(chunk, headers[i].c_str());
        }


        /* set our custom set of headers */
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

        /* Set url */
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

        /* Establish request is a get */
        curl_easy_setopt(curl, CURLOPT_HTTPGET,1);

        /* give curl a callback function */
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,writer);

        /* Perform request */
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


