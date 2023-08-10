#include "TFTExtention/ScrollHandler.h"

uint64_t ScrollHandler::Timer = 0;

ScrollHandler& ScrollHandler::setMessageScrollDelay(uint16_t delay) {
    this->m_scrollDelay = delay;
    return *this;
}

ScrollHandler& ScrollHandler::setSpaceBetweenRepeats(uint16_t spacePixel) {
    this->m_spaceBetweenRepeats = spacePixel;
    return *this;
}

void ScrollHandler::scrollMessage() {
    this->newLabelUpdate();

    if(Timer - m_countTime >= m_scrollDelay) {
        this->m_scrollStepCounter--;

        if(m_scrollStepCounter <= 0)
            this->updateScroll();

        m_textSprite->pushSprite();
        m_textSprite->scroll(m_scrollStep);
        this->m_countTime = Timer;
    }
}

void ScrollHandler::centerMessage() {
    this->newLabelUpdate();

    this->m_textSprite->updateSpriteSize();
    this->m_textSprite->drawCenterLabel();
    this->m_textSprite->pushSprite();
}

void ScrollHandler::autoScroll() {
    if(this->m_textSprite->getLabelPixelWidth() <= this->m_textSprite->getWidth())
        centerMessage();
    else
        scrollMessage();
}

int16_t ScrollHandler::calcScrollStepCounter() {
    return (this->m_textSprite->drawLabel() / abs(this->m_scrollStep)) + this->m_spaceBetweenRepeats;
}

void ScrollHandler::updateScroll() {
    int widthPixel = this->m_textSprite->drawLabel();
    this->m_textSprite->updateSpriteSize(widthPixel);
    this->m_scrollStepCounter = this->calcScrollStepCounter();
}

void ScrollHandler::resetScrollSprite() {
    this->m_textSprite->deleteSprite();
    this->m_scrollStepCounter = 0;
}

bool ScrollHandler::newLabelUpdate() {
    if(this->m_textSprite->getLabel().isNewLabel()) {
        this->resetScrollSprite();
        return true;
    }

    return false;
}
