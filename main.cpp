#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

/** Function to callback the api result */
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    s->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    std::string apiKey = "Y6SDU2TRDEIIDF0U";
    std::string ticker;

    std::cout << "Enter the ticker that you want see: ";
    std::cin >> ticker;

    std::string url = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + ticker + "&apikey=" + apiKey;

    CURL* curl = curl_easy_init();
    CURLcode res;
    std::string response;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "Error requesting: " << curl_easy_strerror(res) << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Failed to initialize curl." << std::endl;
        return 1;
    }

    try {
        json data = json::parse(response);

        if (data.contains("Global Quote") && !data["Global Quote"].empty()) {
            json quote = data["Global Quote"];
            std::string price = quote["05. price"];
            std::string change = quote["09. change"];
            std::string changePercent = quote["10. change percent"];

            std::cout << "\nPrice of " << ticker << ":\n";
            std::cout << "Actual Price: US$ " << price << "\n";
            std::cout << "Change: " << change << " (" << changePercent << ")\n";
        } else {
            std::cerr << "API error: " << data.value("Error Message", "Data not found or rate limit") << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "JSON Error: " << e.what() << std::endl;
        std::cerr << "Raw response: " << response << std::endl;
    }

    return 0;
}