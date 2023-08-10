#pragma once
#include "Model/ModelBase.h"
#include "ViewCallback.h"


using callback_t = void (*)(ViewCallback&);

class ControllerBase {
public:
    ControllerBase(callback_t callback, ModelBase* model)
            : m_callback{callback}, m_model{model}
    {}

public:
    /**
     * Update a view by requesting a related model
     * @param periphery External information about the parameters of the device
     */
    void update(Periphery periphery);

protected:
    callback_t m_callback;
    ModelBase* m_model;
};
