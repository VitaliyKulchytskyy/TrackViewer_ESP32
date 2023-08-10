#pragma once
#include "Arduino.h"


class ModelBase {
public:
    /**
     * Check whether the model was changed
     * @return Model change state
     */
    virtual bool isChanged() = 0;

    /**
     * Get model message
     */
    virtual String getMessage() = 0;
};
