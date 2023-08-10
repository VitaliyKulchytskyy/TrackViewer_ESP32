#include "TFTExtention/Size.h"

Size &Size::setSize(int width, int height) {
    this->m_width = width;
    this->m_height = height;
    return *this;
}

int Size::getWidth() const {
    return this->m_width;
}

int Size::getHeight() const {
    return this->m_height;
}
