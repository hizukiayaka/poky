DEFAULTTUNE ?= "cortexa32"

require conf/machine/include/arm/arch-armv8a.inc

TUNEVALID[cortexa32] = "Enable Cortex-A32 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexa32', ' -mcpu=cortex-a32', '', d)}"

# Little Endian base configs
AVAILTUNES += "cortexa32 cortexa32-crypto"
ARMPKGARCH_tune-cortexa32             = "cortexa32"
ARMPKGARCH_tune-cortexa32-crypto      = "cortexa32"
TUNE_FEATURES_tune-cortexa32          = "${TUNE_FEATURES_tune-armv8a-crc} cortexa32"
TUNE_FEATURES_tune-cortexa32-crypto   = "${TUNE_FEATURES_tune-armv8a-crc-crypto} cortexa32"
PACKAGE_EXTRA_ARCHS_tune-cortexa32             = "${PACKAGE_EXTRA_ARCHS_tune-armv8a-crc} cortexa32"
PACKAGE_EXTRA_ARCHS_tune-cortexa32-crypto      = "${PACKAGE_EXTRA_ARCHS_tune-armv8a-crc-crypto} cortexa32 cortexa32-crypto"
