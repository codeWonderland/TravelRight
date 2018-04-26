//
// Created by codewonderland on 4/25/18.
//

#include "ApiInterface.h"
#include <utility>

std::string ApiInterface::downloadedResponse = "";

void ApiInterface::callApi(std::string url, void (*cb)(std::string)) {
    cb(downloadJSON(std::move(url)));
}

std::string ApiInterface::downloadJSON(std::string URL) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers= nullptr; // init to NULL is important
    std::ostringstream oss;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charsets: utf-8");
    curl = curl_easy_init();

    if (curl)
    {
//        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
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

    curl_slist_free_all(headers);
}

int ApiInterface::writer(char *data, size_t size, size_t nmemb, std::string *buffer_in) {

    // Is there anything in the buffer?
    if (buffer_in != nullptr)
    {
        // Append the data to the buffer
//        buffer_in->append(data);

        // How much did we write?
        downloadedResponse = data;

        return static_cast<int>(size * nmemb);
    }

    return 0;
}


