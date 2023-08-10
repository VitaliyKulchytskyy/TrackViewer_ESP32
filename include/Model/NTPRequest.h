#pragma once
#include "ModelBase.h"


class NTPRequest: public ModelBase {
public:
    /**
     * Setup the NTP
     */
    static void setupNTP();

public:
    bool isChanged() override;

    String getMessage() override;

private:
    /**
     * Get the name of a day by a week number
     * @param wday Number of week
     * @return Week name
     */
    const char* getWdayName(int wday) const;

private:
    uint64_t m_timer = 0;
    const char* m_wdayName[7]{"SU", "MN", "TU", "WE", "TH", "FR", "ST"};
};
