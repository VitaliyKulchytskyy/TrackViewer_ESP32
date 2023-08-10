#include "View/ViewBase.h"


bool setupSD() {
    return SD.begin(15);
}

void setupWiFi() {
    WiFi.begin(Password::ssid, Password::password);
    while (WiFi.status() != WL_CONNECTED);
    wifiServer.begin();
}

void ViewBase::mainloop() {
    ScrollHandler::Timer = millis();
    for(auto& controller : controllers) {
        controller->update({isSdInserted, 0});
    }

    if(ScrollHandler::Timer - sdTimer >= sdCheckTime) {
        isSdInserted = setupSD();
        sdTimer = ScrollHandler::Timer;
    }
}

void ViewBase::setup() {
    setupWiFi();
    NTPRequest::setupNTP();
    isSdInserted = setupSD();
    View::setupView();
}
