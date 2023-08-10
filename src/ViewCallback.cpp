#include "ViewCallback.h"


void ViewCallback::setMessage(const String& message) {
    if(message != m_message) {
        this->m_message = message;
        this->m_update = true;
    } else {
        this->m_update = false;
    }
}

String ViewCallback::getMessage() const {
    return this->m_message;
}

bool ViewCallback::isNewMessage() const {
    return !(this->m_message == "") && this->m_update;
}

void ViewCallback::setPeriphery(Periphery periphery) {
    this->m_periphery = periphery;
}

Periphery ViewCallback::getPeriphery() const {
    return this->m_periphery;
}
