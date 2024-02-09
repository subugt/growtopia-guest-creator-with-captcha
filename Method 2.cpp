#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

std::string getHtml(std::string url) {
    try {
        boost::asio::io_context io_context;

        udp::resolver resolver(io_context);
        udp::resolver::results_type endpoints =
            resolver.resolve(udp::v4(), "www.growtopiagame.com", "http");

        udp::socket socket(io_context, udp::v4());
        socket.connect(*endpoints.begin());

        std::string request = "GET / HTTP/1.1\r\nHost: www.growtopiagame.com\r\n\r\n";
        socket.send(boost::asio::buffer(request));

        boost::array<char, 4096> recv_buffer;
        boost::system::error_code error;
        size_t len = socket.receive(boost::asio::buffer(recv_buffer), 0, error);

        if (!error)
            return std::string(recv_buffer.data(), len);
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return "";
}

std::string getSiteKey(std::string html) {
    std::regex regex("<input.*?name=\"sitekey\".*?value=\"(.*?)\"");
    std::smatch match;
    if (std::regex_search(html, match, regex)) {
        return match[1];
    }
    return "";
}

std::string solveCaptcha(std::string apiKey, std::string siteKey, std::string url) {
  // captcha
    return response; 
}

int main() {
    std::string html = getHtml("https://www.growtopiagame.com");
    std::string siteKey = getSiteKey(html);
    std::string response = solveCaptcha("API_KEY", siteKey, "URL");

   //Extract tokens make pos
    boost::asio::io_context io_context;
    udp::resolver resolver(io_context);
    udp::resolver::results_type endpoints =
        resolver.resolve(udp::v4(), "www.growtopiagame.com", "http");

    udp::socket socket(io_context, udp::v4());
    socket.connect(*endpoints.begin());

    std::string request = "POST /player/validate HTTP/1.1\r\nHost: www.growtopiagame.com\r\n\r\n";
    socket.send(boost::asio::buffer(request));

    boost::array<char, 4096> recv_buffer;
    boost::system::error_code error;
    size_t len = socket.receive(boost::asio::buffer(recv_buffer), 0, error);

    if (!error) {
        // rn i will leave blank maybe you can print errors or send webhook.
    }

    return 0;
}
