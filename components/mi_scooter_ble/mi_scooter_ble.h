#pragma once

#include <vector>

#include "esphome/components/esp32_ble_tracker/esp32_ble_tracker.h"
#include "esphome/core/component.h"

#ifdef USE_ESP32

namespace esphome {
    namespace mi_scooter_ble {

        using namespace esp32_ble_tracker;

        class MiScooterListener : public Component, public ESPBTDeviceListener {
            public:
                bool parse_device(const ESPBTDevice &device) override;
                void dump_config() override;
                void set_log_devices(bool log_devices) {
                    log_devices_ = log_devices;
                }

            protected:
                bool log_devices_;
        };

    }
}

#endif
