#include "TFTExtention/Label.h"


Label &Label::setLabelText(String &text) {
    if(text == m_label)
        return *this;

    this->m_isNewMessage = true;
    this->m_label = text;
    return *this;
}

Label &Label::setLabelText(const char *text) {
    if(text == m_label.c_str())
        return *this;

    this->m_isNewMessage = true;
    this->m_label = text;
    return *this;
}

String Label::getLabelText() const {
    return this->m_label;
}

int Label::length() const {
    return this->m_label.length();
}

bool Label::isNewLabel() {
    if(m_isNewMessage) {
        this->m_isNewMessage = false;
        return true;
    }

    return false;
}

