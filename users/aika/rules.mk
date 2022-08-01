SRC += aika.c

ifeq ($(strip $(OLED_ENABLE)), yes)
SRC += oled.c \
	   ocean_dream.c
endif
