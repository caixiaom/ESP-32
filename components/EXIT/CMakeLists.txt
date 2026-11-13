idf_component_register(SRCS "EXIT.c"
                    INCLUDE_DIRS "include"
                    REQUIRES driver LED)   # LED: for "LED.h"; driver: for "driver/gpio.h"
