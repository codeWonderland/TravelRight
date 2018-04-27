/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2015, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
/* <DESC>
 * Simple HTTPS GET
 * </DESC>
 */
#include <iostream>
#include "ApiInterface.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"

#include "include/nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;

void echo(std::string jsonMsg) {
    std::cout << jsonMsg;

    while (jsonMsg.find('<U+000D>') < -1)

    auto json = json::parse(jsonMsg);

    // Output {"project":"rapidjson","stars":11}
    std::cout << json.dump(4) << std::endl;
}

int main(int argc, const char *argv[])
{
    // TODO: Get input from user and replace ' ' with '+' via assembly
    //std::string url = "https://maps.googleapis.com/maps/api/directions/json?origin=23947&destination=05401&key=AIzaSyCSyN9jsmW-VcwTgKvTopbA32jkloM2CnQ";

    std::string url = "http://open.mapquestapi.com/directions/v2/route?key=6Qg1GnBelmtrj3XZKBGKTcSApr8Bcb8Q";

    std::string from = "23947", to = "05401";

    url += "&from=" + from + "&to=" + to;

    std::string headers[] = {};

    ApiInterface myInterface = ApiInterface();
    myInterface.callApi(url, &echo, headers, 0);
    return 0;
}
