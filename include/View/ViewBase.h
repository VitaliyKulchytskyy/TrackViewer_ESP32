#pragma once
#include "Model/ServerRequest.h"
#include "Model/NTPRequest.h"
#include "utils/Password.h"
#include "ControllerBase.h"
#include "time.h"
#include "View.h"

namespace ViewBase {
    void mainloop();
    void setup();
}

namespace {
    ServerRequest* serverRequest = new ServerRequest();
    NTPRequest* ntpRequest = new NTPRequest();
    ControllerBase* controllers[2] {new ControllerBase(View::printHeader, ntpRequest),
                                    new ControllerBase(View::printTrackData, serverRequest)};

    bool isSdInserted;
    uint16_t sdCheckTime = 3000;
    uint64_t sdTimer = 0;
}