#include "Model/NTPRequest.h"


bool NTPRequest::isChanged() {
    uint64_t timerNow = millis();
    if(timerNow - m_timer >= 1000) {
        this->m_timer = timerNow;
        return true;
    }

    return false;
}

String NTPRequest::getMessage() {
    char headerText[64];

    struct tm timeinfo;
    getLocalTime(&timeinfo);

    sprintf(headerText, "%s %02i.%02i.20%02i %02i:%02i:%02i",
                       getWdayName(timeinfo.tm_wday),
                       timeinfo.tm_mday,
                       timeinfo.tm_mon + 1,
                       timeinfo.tm_year - 100,
                       timeinfo.tm_hour,
                       timeinfo.tm_min,
                       timeinfo.tm_sec);

    return headerText;
}

const char *NTPRequest::getWdayName(int wday) const {
    return (wday >= 0 && wday < 7) ? this->m_wdayName[wday] : "UN";
}

void NTPRequest::setupNTP() {
    const char* ntpServer = "pool.ntp.org";
    const long gmtOffset_sec = 7200;
    const int daylightOffset_sec = 3600;

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}
