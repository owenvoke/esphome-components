#include "mi_scooter_ble.h"

#include "esphome/core/log.h"

#ifdef USE_ESP32

namespace esphome {
    namespace mi_scooter_ble {

        using namespace esp32_ble_tracker;

        static const char *TAG = "mi_scooter_ble";

        // Mi Scooter Pro details
        static const uint16_t SERVICE_UUID_MI_SCOOTER_PRO = 0xFE95;
        static const uint16_t MANUFACTURER_UUID_MI_SCOOTER_PRO = 0x424E;

        bool MiScooterListener::parse_device(const ESPBTDevice &device) {
            const std::string name_prefix = "MIScooter";

            if (device.get_name().rfind(name_prefix, 0) == 0) {
                if (this->log_devices_) {
                    ESP_LOGI(TAG, "Possible Mi Scooter discovered: %s", device.address_str().c_str());

                    return true;
                }
            }

            return false;
        }

        void MiScooterListener::dump_config() {
            ESP_LOGCONFIG(TAG, "Mi Scooter BLE:");
            ESP_LOGCONFIG(TAG, "  Log Devices: %s", this->log_devices_ ? "True" : "False");
        }

    }
}

#endif
