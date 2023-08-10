#include "ControllerBase.h"


void ControllerBase::update(Periphery periphery) {
    ViewCallback callback;
    callback.setPeriphery(periphery);
    String message = m_model->getMessage();
    callback.setMessage(message);

    this->m_callback(callback);
}

