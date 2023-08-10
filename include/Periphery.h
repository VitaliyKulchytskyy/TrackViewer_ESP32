#include "Arduino.h"


/**
 * Store information about the parameters of the device
 */
struct Periphery {
public:
    Periphery(bool isSDInserted, uint8_t chargeLevel)
        : IsSDInserted{isSDInserted}, ChargeLevel{chargeLevel}
    {}

    Periphery() = default;

public:
    /// Get/Set information about the SD card
    bool IsSDInserted{};

    /// Get/Set information about the charge level
    uint8_t ChargeLevel{};
};
