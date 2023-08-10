#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Position.h"


class Label: public Position  {
public:
    Label() = default;
    Label(String& label) : m_label(label) {}

public:
    /**
     * Set a new text
     * @param text New label text
     * @return Ref to this Label
     */
    Label& setLabelText(String& text);

    /**
     * Set a new text
     * @param text New label text
     * @return Ptr to this Label
     */
    Label& setLabelText(const char* text);

    /**
     * Get the text of the label
     * @return Text of the label
     */
    String getLabelText() const;

    /**
     * Get the length of the label's text
     * @return length of the label's text
     */
    int length() const;

    /**
     * Check whether the label has changed the text
     * @return Check status
     */
    bool isNewLabel();

private:
    String m_label = "";
    bool m_isNewMessage;
};