import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import esp32_ble_tracker
from esphome.const import CONF_ID

CODEOWNERS = ["@owenvoke"]
DEPENDENCIES = ["esp32_ble_tracker"]

CONF_LOG_DEVICES = "log_devices"

mi_scooter_ble_ns = cg.esphome_ns.namespace("mi_scooter_ble")
MiScooterListener = mi_scooter_ble_ns.class_(
    "MiScooterListener", esp32_ble_tracker.ESPBTDeviceListener
)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(MiScooterListener),
        cv.Optional(CONF_LOG_DEVICES, default=False): cv.boolean,
    }
).extend(esp32_ble_tracker.ESP_BLE_DEVICE_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    if CONF_LOG_DEVICES in config:
        cg.add(
            var.set_log_devices(config[CONF_LOG_DEVICES])
        )
    await esp32_ble_tracker.register_ble_device(var, config)
