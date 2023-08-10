#pragma once
#include <Arduino.h>
#include "MessageSprite.h"

class ScrollHandler {
public:
    explicit ScrollHandler(MessageSprite *textSprite)
        : m_textSprite{textSprite}
    {
        this->updateScroll();
    }

    /**
     * Global scroll row Timer
     */
    static uint64_t Timer;

public:
    /**
     * Set the delay in scrolling the label
     * @param delay Delay value in milliseconds
     * @return Ref to this ScrollHandler
     */
    ScrollHandler& setMessageScrollDelay(uint16_t delay);

    /**
     * Set the space between repeats of the label's text in a scrolling row
     * @param spacePixel Space between repeats in pixels
     * @return Ref to this ScrollHandler
     */
    ScrollHandler& setSpaceBetweenRepeats(uint16_t spacePixel);

public:
    /**
     * Scroll the label repeatedly
     */
    void scrollMessage();

    /**
     * Draw the label in the center of the screen
     */
    void centerMessage();

    /**
     * Draw the label in the center or scroll it,
     * based on the pixels width of the label
     */
    void autoScroll();

private:
    /**
     * Calculate how many steps (pixels) enough to scroll the whole label
     * @return Steps
     */
    int16_t calcScrollStepCounter();

    /**
     * Update parameters of the scrolling row
     */
    void updateScroll();

    /**
     * Reset parameters of the scrolling row
     */
    void resetScrollSprite();

    /**
     * Update the scrolling sprite when the label's text is changed
     * @return Update status
     */
    bool newLabelUpdate();

private:
    MessageSprite *m_textSprite;
    uint64_t m_countTime;
    uint32_t m_scrollDelay = 20;
    int16_t m_scrollStepCounter;
    /**
     * Number of pixels will be shifted per a shift
     * If this value is negative, the scrolling will be from right to left
     */
    int16_t m_scrollStep = -3;
    int16_t m_spaceBetweenRepeats = 80;
};


