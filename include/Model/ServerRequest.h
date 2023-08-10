#pragma once
#include "ModelBase.h"
#include "utils/global_wifiServer.h"


class ServerRequest: public ModelBase {
public:
    ServerRequest() = default;

public:

    bool isChanged() override {
        WiFiClient client = wifiServer.available();

        if (client) {
            while (client.connected())
                while (client.available() > 0)
                    this->m_request += (char) client.read();

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

private:
    String m_request = "";
};
