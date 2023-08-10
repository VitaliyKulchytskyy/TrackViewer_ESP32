#include "View/ViewBase.h"


void setup() {
    Serial.begin(9600);
    ViewBase::setup();
}

void loop() {
    ViewBase::mainloop();
}