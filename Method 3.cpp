/*
Guest Creator with captcha versions made by discord/github/youtube : subugt
Before using/sharing my captcha creator please give me credits.
also dont forget to leave a star ;)
good luck!
*/

#include <iostream>
#include <string>
#include <enet/enet.h>

std::string getHtml(std::string url) {
    try {
        if (enet_initialize() != 0) {
            std::cerr << "Error initializing ENet" << std::endl;
            return "";
        }

        ENetAddress address;
        ENetHost* client;
        ENetPeer* peer;
        ENetEvent event;
        std::string html;

        if (enet_address_set_host(&address, "www.growtopiagame.com") != 0) {
            std::cerr << "Error setting host address" << std::endl;
            return "";
        }

        address.port = 80;

        client = enet_host_create(NULL, 1, 2, 0, 0);
        if (client == NULL) {
            std::cerr << "Error creating client" << std::endl;
            return "";
        }

        peer = enet_host_connect(client, &address, 2, 0);
        if (peer == NULL) {
            std::cerr << "No available peers for initiating connection" << std::endl;
            return "";
        }

        if (enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
            std::string request = "GET / HTTP/1.1\r\nHost: www.growtopiagame.com\r\n\r\n";
            enet_peer_send(peer, 0, enet_packet_create(request.c_str(), request.length(), ENET_PACKET_FLAG_RELIABLE));

            if (enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_RECEIVE) {
                html = std::string((char*)event.packet->data, event.packet->dataLength);
            }
        }

        enet_peer_disconnect(peer, 0);
        enet_host_flush(client);
        enet_peer_reset(peer);

        enet_host_destroy(client);
        enet_deinitialize();

        return html;
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
    return "";
}

int main() {
    std::string html = getHtml("https://www.growtopiagame.com");
    std::string siteKey = getSiteKey(html);
    std::string response = solveCaptcha("API_KEY", siteKey, "URL");

    // Extract token make post

    return 0;
}
