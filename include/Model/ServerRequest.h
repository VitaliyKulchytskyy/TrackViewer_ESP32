#pragma once
#include "ModelBase.h"
#include "utils/global_wifiServer.h"


class ServerRequest: public ModelBase {
public:
    ServerRequest() = default;

public:

    bool isChanged() override {
        if(m_isFirstInvoke) {
            sendGreeting();
            this->m_isFirstInvoke = false;
            return true;
        }

        WiFiClient client = wifiServer.available();

        if (client) {
            while (client.connected())
                while (client.available() > 0) {
                    this->m_request += (char) client.read();
                }

            return true;
        }

        return false;
    }

    String getMessage() override {
        return this->isChanged() ? this->getRequest() : "";
    }

private:
    /**
     * Get the string of a request from the server
     * @return Request from the server
     */
    String getRequest() {
        String temp = this->m_request;
        this->m_request = "";
        return temp;
    }

    void sendGreeting() {
        this->m_request = R"({"artist": "By Karlenko",
                              "track_name": "To see the current track on the YTMusic type 'trackViewer.exe -r' in a terminal",
                              "album_name": "Greeting",
                              "thumb_url": "https://srv2.imgonline.com.ua/result_img/imgonline-com-ua-Resize-n1D0sHeBaGK.jpg"})";
    }

private:
    String m_request = "";
    bool m_isFirstInvoke = true;
};
