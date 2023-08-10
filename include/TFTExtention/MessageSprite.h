#pragma once
#include "Label.h"
#include "Size.h"
#include "examples/320 x 240/All_Free_Fonts_Demo/Free_Fonts.h"


class MessageSprite: public Position, public Size {
public:
    MessageSprite(TFT_eSprite *sprite, Label *label)
            : m_sprite(sprite), m_label(label)
    {}

public:
    /**
     * Get the label
     * @return Label
     */
    Label& getLabel() const;

    /**
     * Get the sprite
     * @return Sprite
     */
    TFT_eSprite& getSprite() const;

    /**
     * Draw the label
     * @return Width of the label in pixels
     */
    int drawLabel();

    /**
     * Get the width of the label
     * @return Width of the label in pixels
     */
    int getLabelPixelWidth() const;

    /**
     * Draw the label in the center of the screen
     */
    void drawCenterLabel();

    /**
     * Update size of the sprite
     * @param extraWidth Width of other objects
     */
    void updateSpriteSize(int extraWidth = 0);

    /**
     * Push the sprite to the screen
     */
    void pushSprite();

    /**
     * Scroll the sprite to dx pixels
     * @param dx Shift (in pixels)
     */
    void scroll(int16_t dx);

    /**
     * Delete the sprite
     */
    void deleteSprite();

private:
    TFT_eSprite* m_sprite;
    Label* m_label;
};