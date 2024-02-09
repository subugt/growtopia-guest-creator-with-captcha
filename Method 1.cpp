// Note: This code is intended for developers. Please remember to give credit when using.

// Discord: dsc.gg/powerproxy
// Discord developer:

// Note: Created on 24/08/2023

// Feel free to use with proper credits :)
// Made with httplib

#include <iostream>
#include <string>
#include <regex>
#include <httplib.h>
#include <jsoncpp/json/json.h>

std::string getHtml(std::string url) {
    httplib::Client client(url);
    httplib::Response res = client.Get("/");
    if (res) {
        return res->body;
    }
    return "";
}

std::string getSiteKey(std::string html) {
    // Same regex logic
    return matches[1];
}

std::string solveCaptcha(std::string apiKey, std::string siteKey, std::string url) {
    // Captcha solving logic
    return response;
}

int main() {
    std::string html = getHtml("https://www.growtopiagame.com");
    std::string siteKey = getSiteKey(html);
    std::string response = solveCaptcha("API_KEY", siteKey, "URL");
    
    // Extract tokens, make POST request
    httplib::Client client("www.growtopiagame.com");
    httplib::Request req("POST", "/player/validate");
    
    // Add parameters, headers
    
    auto res = client.send(req);
    if (res->status == 200) {
        // Handle response
    }
    
    return 0;
}
