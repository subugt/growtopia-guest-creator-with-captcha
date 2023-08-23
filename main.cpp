// note this one for developers
// Don't forget to give credit when using
//
// discord : dsc.gg/powerproxy
// discord developer : 
//
//
// note its made on 24/08/2023
//
// feel free to using with credits :)
//made with httplib
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
// Function to solve captcha
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
