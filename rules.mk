SRC += muse.c

# Bootloader selection
# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu


# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output

## Build Options
##   change to "no" to disable the options, or define them in the makefile.mk in 
##   the appropriate keymap folder that will get included automatically
##
#BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
#MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
#EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
#CONSOLE_ENABLE = no         # Console for debug(+400)
#COMMAND_ENABLE = yes        # Commands for debug and configuration
#BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
##MIDI_ENABLE = no            # MIDI controls
##AUDIO_ENABLE = no           # Audio output on port C6
#UNICODE_ENABLE = no         # Unicode
#BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
#RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight. 
##TAP_DANCE_ENABLE = yes      # Enables the double-tap functionality of keys

## Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
#SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend

