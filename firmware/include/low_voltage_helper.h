#pragma once

#include <inttypes.h>

// Operating voltages from various sources
static constexpr uint16_t kLiIonMinOperatingMV= 18000; // 6 * 3.7V (14500 cells), min voltage = 3V/ea
static constexpr uint16_t kAAMinOperatingMV = 5850;
static constexpr uint16_t kUsbMinOperatingMV = 4850;

// Startup threshold voltages to determine whether power source is
// - USB: 4.85 - 5.1 V operating
// - 6x AA NiMH/Alkaline: 6 - 7.2 V / 6 - 9 V operating
// - 6x 14500 (3.7 V nominal): 18 - 25.2 V operating
static constexpr uint16_t kLiIonThresholdMV = 9000;
static constexpr uint16_t kAAThresholdMV = 5250; // top end of USB tolerance

static constexpr uint16_t kLVCountThreshold = 500; // 500 cycles

enum class powerSource_e {PWR_AA, PWR_USB, PWR_LI};

class LowVoltageHelper {
  private:
    static powerSource_e m_pwrSource;
    static uint16_t minOperatingMV;

  public:
    static void init(uint16_t initVoltageMV);
    static void update(uint16_t currVoltageMV);
    static bool isLowVoltage();
    static void lowVoltageAlertCheck();
};