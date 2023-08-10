#include "TFTExtention/MessageSprite.h"

Label& MessageSprite::getLabel() const {
    return *this->m_label;
}

TFT_eSprite& MessageSprite::getSprite() const {
    return *this->m_sprite;
}

int MessageSprite::drawLabel() {
    this->m_sprite->drawString(this->m_label->getLabelText(),
                               this->m_label->getX(),
                               this->m_label->getY(),
                               GFXFF);

    return m_sprite->textWidth(this->m_label->getLabelText());
}

int MessageSprite::getLabelPixelWidth() const {
    return m_sprite->textWidth(this->m_label->getLabelText());
}

void MessageSprite::drawCenterLabel() {
    this->m_sprite->drawCentreString(this->m_label->getLabelText(),
                                     this->getWidth() / 2,
                                     this->m_label->getY(),
                                     GFXFF);
}

void MessageSprite::updateSpriteSize(int extraWidth) {
    this->m_sprite->createSprite(this->getWidth() + extraWidth,
                                 this->getHeight());
}

void MessageSprite::pushSprite() {
    this->m_sprite->pushSprite(this->getX(),
                               this->getY());
}

void MessageSprite::scroll(int16_t dx) {
    this->m_sprite->scroll(dx);
}

void MessageSprite::deleteSprite() {
    this->m_sprite->deleteSprite();
}



