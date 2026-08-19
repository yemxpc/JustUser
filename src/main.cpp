#include <iostream>
#include <string>
#include <fstream>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

void check_username(const std::string& site, const std::string& target_url) {
    CURL* curl = curl_easy_init();
    if (curl) {
        long code = 0;

        curl_easy_setopt(curl, CURLOPT_URL, target_url.c_str());
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); 
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3L);

        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);

        if (code == 200) {
            std::cout << "[+] User Found : " << target_url << "\n";
        } 
        else if (code == 403) {
            std::cout << "[?] User May Found | Access Denied = (403) : " << target_url << "\n";
        } 
        else if (code == 405) {
            std::cout << "[?] User May Found | Access Denied = (405) : " << target_url << "\n";
        } 
        else {
            std::cout << "[-] User Couldnt Found : " << site << " " << code << ")\n";
        }

        curl_easy_cleanup(curl);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "USE -> " << argv[0] << " <kullanici_adi>\n";
        return 1;
    }

    std::ifstream file("sites.json");
    if (!file.is_open()) {
        std::cout << "sites.json Couldnt Found\n";
        return 1;
    }

    json sites;
    file >> sites;

    for (auto& [site_name, url_template] : sites.items()) {
        std::string target_url = url_template.get<std::string>() + argv[1];
        check_username(site_name, target_url);
    }

    return 0;
}