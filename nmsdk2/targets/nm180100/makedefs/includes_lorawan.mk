LORAWAN_DEFINES += -D"REGION_AS923"
LORAWAN_DEFINES += -D"REGION_AU915"
LORAWAN_DEFINES += -D"REGION_EU868"
LORAWAN_DEFINES += -D"REGION_US915"
LORAWAN_DEFINES += -D"REGION_KR920"
LORAWAN_DEFINES += -D"REGION_IN865"
LORAWAN_DEFINES += -DLORAMAC_CLASSB_ENABLED
LORAWAN_DEFINES += -DSOFT_SE
LORAWAN_DEFINES += -DCONTEXT_MANAGEMENT_ENABLED

LORAWAN_INC += -I$(LORAWAN)/src/radio
LORAWAN_INC += -I$(LORAWAN)/src/radio/sx126x
LORAWAN_INC += -I$(LORAWAN)/src/boards
LORAWAN_INC += -I$(LORAWAN)/src/mac
LORAWAN_INC += -I$(LORAWAN)/src/mac/region
LORAWAN_INC += -I$(LORAWAN)/src/system
LORAWAN_INC += -I$(LORAWAN)/src/peripherals/soft-se
LORAWAN_INC += -I$(LORAWAN)/../../targets/nm180100/comms/lorawan/src/boards/nm180100
LORAWAN_INC += -I$(LORAWAN)/../../targets/nm180100/comms/lorawan
