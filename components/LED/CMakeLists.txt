idf_component_register(SRCS "LED.c"
                    INCLUDE_DIRS "include"
                    REQUIRES driver)   # LED.c 用了 driver/gpio.h，必须声明依赖 driver 组件
