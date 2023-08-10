#pragma once
#include "vector"
#include "Periphery.h"
#include "Arduino.h"


class ViewCallback {
public:
    /**
     * Set the message of the callback
     * @param message New message
     */
    void setMessage(const String& message);

    /**
     * Get the message of the callback
     * @return Callback message
     */
    String getMessage() const;

    /**
     * Set the information about the periphery of the device
     * @param periphery External information about the parameters of the device
     */
    void setPeriphery(Periphery periphery);

    /**
     * Get the information about the periphery of the device
     */
    Periphery getPeriphery() const;

    /**
     * Check whether the callback message was changed
     * @return Callback change state
     */
    bool isNewMessage() const;

private:
    bool m_update = false;
    Periphery m_periphery{};
    String m_message;
};
