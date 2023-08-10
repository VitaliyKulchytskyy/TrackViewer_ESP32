#include "TFTExtention/Position.h"


Position &Position::setPosition(int x, int y) {
    this->m_x = x;
    this->m_y = y;
    return *this;
}

int Position::getX() const {
    return this->m_x;
}

int Position::getY() const {
    return this->m_y;
}
