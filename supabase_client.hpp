#pragma once //for once include

#include <string>
#include <iostream>
#include <curl/curl.h>//http request and response
#include <nlohmann/json.hpp> //json lib

namespace supabase {

//for not collision of name

using json = nlohmann::json;
//easy to use json var

inline void insert(const std::string& url, const std::string& api_key, const json& data) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL." << std::endl;
        return;
    }
/*CURL's init. error message and hundling*/

    std::string json_str = data.dump();
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, ("apikey: " + api_key).c_str());
    headers = curl_slist_append(headers, ("Authorization: Bearer " + api_key).c_str());
    headers = curl_slist_append(headers, "Prefer: return=representation");

/* JSON Object to string
   To send json is clear
   apikey,Bearer token
   and response
 */

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());
    curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    curl_easy_setopt(curl, CURLOPT_URL, "https://YOUR SUPABASE URL/rest/v1/TABLE NAME");

/*
  url to json sending
*/

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
    } else {
        std::cout << "Insert successful." << std::endl;
    }

// error hundling

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
//free of memory
}

} // namespace supabase

