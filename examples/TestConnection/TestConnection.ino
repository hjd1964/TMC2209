#include <Arduino.h>

// use SoftwareSerial library to communicate with TMC2209
//#define TMC2209_SOFTWARE_SERIAL

#include <TMC2209.h>

// Instantiate TMC2209
TMC2209Stepper stepper_driver;

const long SERIAL_BAUD_RATE = 115200;
const int DELAY = 2000;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  delay(DELAY);

  // use SoftwareSerial library to communicate with TMC2209 (rx -1 for read disable)
  //stepper_driver.setup(115200, 0, 18, 17); // baud, device address, rx, tx

  // use HardwareSerial library to communicate with TMC2209 (only ESP32 allows specifying the pins)
  stepper_driver.setup(Serial2, 460800, 2, 4, 23); // hardware serial, baud, device address, rx, tx
}

void loop()
{
  Serial.println("*************************");

  TMC2209Stepper::Settings settings = stepper_driver.getSettings();
  Serial.print("settings.is_communicating = ");
  Serial.println(settings.is_communicating);

  if (settings.is_communicating) {
    Serial.print("settings.is_setup = ");
    Serial.println(settings.is_setup);
    Serial.print("settings.enabled = ");
    Serial.println(settings.enabled);
    Serial.print("settings.microsteps_per_step = ");
    Serial.println(settings.microsteps_per_step);
    Serial.print("settings.inverse_motor_direction_enabled = ");
    Serial.println(settings.inverse_motor_direction_enabled);
    Serial.print("settings.stealth_chop_enabled = ");
    Serial.println(settings.stealth_chop_enabled);

    Serial.print("settings.standstill_mode = ");
    switch (settings.standstill_mode)
    {
      case TMC2209Stepper::NORMAL:
        Serial.println("normal");
        break;
      case TMC2209Stepper::FREEWHEELING:
        Serial.println("freewheeling");
        break;
      case TMC2209Stepper::STRONG_BRAKING:
        Serial.println("strong_braking");
        break;
      case TMC2209Stepper::BRAKING:
        Serial.println("braking");
        break;
    }
    Serial.print("settings.irun_percent = ");
    Serial.println(settings.irun_percent);
    Serial.print("settings.irun_register_value = ");
    Serial.println(settings.irun_register_value);
    Serial.print("settings.ihold_percent = ");
    Serial.println(settings.ihold_percent);
    Serial.print("settings.ihold_register_value = ");
    Serial.println(settings.ihold_register_value);
    Serial.print("settings.iholddelay_percent = ");
    Serial.println(settings.iholddelay_percent);
    Serial.print("settings.iholddelay_register_value = ");
    Serial.println(settings.iholddelay_register_value);
    Serial.print("settings.automatic_current_scaling_enabled = ");
    Serial.println(settings.automatic_current_scaling_enabled);
    Serial.print("settings.automatic_gradient_adaptation_enabled = ");
    Serial.println(settings.automatic_gradient_adaptation_enabled);
    Serial.print("settings.pwm_offset = ");
    Serial.println(settings.pwm_offset);
    Serial.print("settings.pwm_gradient = ");
    Serial.println(settings.pwm_gradient);
    Serial.print("settings.cool_step_enabled = ");
    Serial.println(settings.cool_step_enabled);
    Serial.print("settings.analog_current_scaling_enabled = ");
    Serial.println(settings.analog_current_scaling_enabled);
    Serial.print("settings.internal_sense_resistors_enabled = ");
    Serial.println(settings.internal_sense_resistors_enabled);
    Serial.println("");
  
    bool disabled_by_input_pin = stepper_driver.disabledByInputPin();
    Serial.print("disabled_by_input_pin = ");
    Serial.println(disabled_by_input_pin);
    Serial.println("");
  
    TMC2209Stepper::Status status = stepper_driver.getStatus();
    Serial.print("status.over_temperature_warning = ");
    Serial.println(status.over_temperature_warning);
    Serial.print("status.over_temperature_shutdown = ");
    Serial.println(status.over_temperature_shutdown);
    Serial.print("status.short_to_ground_a = ");
    Serial.println(status.short_to_ground_a);
    Serial.print("status.short_to_ground_b = ");
    Serial.println(status.short_to_ground_b);
    Serial.print("status.low_side_short_a = ");
    Serial.println(status.low_side_short_a);
    Serial.print("status.low_side_short_b = ");
    Serial.println(status.low_side_short_b);
    Serial.print("status.open_load_a = ");
    Serial.println(status.open_load_a);
    Serial.print("status.open_load_b = ");
    Serial.println(status.open_load_b);
    Serial.print("status.over_temperature_120c = ");
    Serial.println(status.over_temperature_120c);
    Serial.print("status.over_temperature_143c = ");
    Serial.println(status.over_temperature_143c);
    Serial.print("status.over_temperature_150c = ");
    Serial.println(status.over_temperature_150c);
    Serial.print("status.over_temperature_157c = ");
    Serial.println(status.over_temperature_157c);
    Serial.print("status.current_scaling = ");
    Serial.println(status.current_scaling);
    Serial.print("status.stealth_chop_mode = ");
    Serial.println(status.stealth_chop_mode);
    Serial.print("status.standstill = ");
    Serial.println(status.standstill);
    Serial.println("");
  }

  Serial.println("*************************");
  Serial.println("");
  delay(DELAY);
}
