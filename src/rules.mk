OLED_DRIVER_ENABLE = no   # Enables the use of OLED displays
ENCODER_ENABLE = no       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow

LEADER_ENABLE = no        # Enable the leader key feature. See readme.md.
SPACE_CADET_ENABLE = no    # I don't use that feature, so ... saving some space.
#RAW_ENABLE = yes           # Enable raw hid for testing some fun stuff.
#OLED_BRIGHTNESS = 70       # Make the oleds a bit dimmer.
#OLED_UPDATE_INTERVAL = 100 # Only update oled once every 500ms.

TAP_DANCE_ENABLE = yes      # Enable the tap dance feature.
CONSOLE_ENBALE = no        # Enable debugging console
BACKLIGHT_ENABLE = no      # Enable background light
LED_MATRIX_ENABLE = no
RGB_MATRIX_ENABLE = no
SEQUENCER_ENABLE = no
TERMINAL_ENABLE = no
UNICODE_ENABLE = no
WPM_ENABLE = no
MOUSEKEY_ENABLE = no

VPATH  +=  keyboards/gboards/
COMBO_ENABLE = yes


SRC += features/leader.c