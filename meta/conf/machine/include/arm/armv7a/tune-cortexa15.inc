DEFAULTTUNE ?= "armv7vethf-neon"

require conf/machine/include/arm/arch-armv7ve.inc

TUNEVALID[cortexa15] = "Enable Cortex-A15 specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'cortexa15', ' -mcpu=cortex-a15', '', d)}"
MACHINEOVERRIDES =. "${@bb.utils.contains('TUNE_FEATURES', 'cortexa15', 'armv7ve:', '', d)}"

# Little Endian base configs
AVAILTUNES += "cortexa15 cortexa15t cortexa15-neon cortexa15t-neon cortexa15-neon-vfpv4 cortexa15t-neon-vfpv4"
ARMPKGARCH:tune-cortexa15             = "cortexa15"
ARMPKGARCH:tune-cortexa15t            = "cortexa15"
ARMPKGARCH:tune-cortexa15-neon        = "cortexa15"
ARMPKGARCH:tune-cortexa15t-neon       = "cortexa15"
ARMPKGARCH:tune-cortexa15-neon-vfpv4  = "cortexa15"
ARMPKGARCH:tune-cortexa15t-neon-vfpv4 = "cortexa15"
# mcpu is used so don't use armv7ve as we don't want march
TUNE_FEATURES:tune-cortexa15             = "arm vfp cortexa15"
TUNE_FEATURES:tune-cortexa15t            = "${TUNE_FEATURES:tune-cortexa15} thumb"
TUNE_FEATURES:tune-cortexa15-neon        = "${TUNE_FEATURES:tune-cortexa15} neon"
TUNE_FEATURES:tune-cortexa15t-neon       = "${TUNE_FEATURES:tune-cortexa15-neon} thumb"
TUNE_FEATURES:tune-cortexa15-neon-vfpv4  = "${TUNE_FEATURES:tune-cortexa15-neon} vfpv4"
TUNE_FEATURES:tune-cortexa15t-neon-vfpv4 = "${TUNE_FEATURES:tune-cortexa15-neon-vfpv4} thumb"
PACKAGE_EXTRA_ARCHS:tune-cortexa15             = "${PACKAGE_EXTRA_ARCHS:tune-armv7ve} cortexa15-vfp"
PACKAGE_EXTRA_ARCHS:tune-cortexa15t            = "${PACKAGE_EXTRA_ARCHS:tune-armv7vet} cortexa15-vfp cortexa15t2-vfp"
PACKAGE_EXTRA_ARCHS:tune-cortexa15-neon        = "${PACKAGE_EXTRA_ARCHS:tune-armv7ve-neon} cortexa15-vfp cortexa15-neon"
PACKAGE_EXTRA_ARCHS:tune-cortexa15t-neon       = "${PACKAGE_EXTRA_ARCHS:tune-armv7vet-neon} cortexa15-vfp cortexa15-neon cortexa15t2-vfp cortexa15t2-neon"
PACKAGE_EXTRA_ARCHS:tune-cortexa15-neon-vfpv4  = "${PACKAGE_EXTRA_ARCHS:tune-armv7ve-neon-vfpv4} cortexa15-vfp cortexa15-neon cortexa15-neon-vfpv4"
PACKAGE_EXTRA_ARCHS:tune-cortexa15t-neon-vfpv4 = "${PACKAGE_EXTRA_ARCHS:tune-armv7vet-neon-vfpv4} cortexa15-vfp cortexa15-neon cortexa15-neon-vfpv4 cortexa15t2-vfp cortexa15t2-neon cortexa15t2-neon-vfpv4"

# HF Tunes
AVAILTUNES += "cortexa15hf cortexa15thf cortexa15hf-neon cortexa15thf-neon cortexa15hf-neon-vfpv4 cortexa15thf-neon-vfpv4"
ARMPKGARCH:tune-cortexa15hf             = "cortexa15"
ARMPKGARCH:tune-cortexa15thf            = "cortexa15"
ARMPKGARCH:tune-cortexa15hf-neon        = "cortexa15"
ARMPKGARCH:tune-cortexa15thf-neon       = "cortexa15"
ARMPKGARCH:tune-cortexa15hf-neon-vfpv4  = "cortexa15"
ARMPKGARCH:tune-cortexa15thf-neon-vfpv4 = "cortexa15"
# mcpu is used so don't use armv7ve as we don't want march
TUNE_FEATURES:tune-cortexa15hf             = "${TUNE_FEATURES:tune-cortexa15} callconvention-hard"
TUNE_FEATURES:tune-cortexa15thf            = "${TUNE_FEATURES:tune-cortexa15t} callconvention-hard"
TUNE_FEATURES:tune-cortexa15hf-neon        = "${TUNE_FEATURES:tune-cortexa15-neon} callconvention-hard"
TUNE_FEATURES:tune-cortexa15thf-neon       = "${TUNE_FEATURES:tune-cortexa15t-neon} callconvention-hard"
TUNE_FEATURES:tune-cortexa15hf-neon-vfpv4  = "${TUNE_FEATURES:tune-cortexa15-neon-vfpv4} callconvention-hard"
TUNE_FEATURES:tune-cortexa15thf-neon-vfpv4 = "${TUNE_FEATURES:tune-cortexa15t-neon-vfpv4} callconvention-hard"
PACKAGE_EXTRA_ARCHS:tune-cortexa15hf             = "${PACKAGE_EXTRA_ARCHS:tune-armv7vehf} cortexa15hf-vfp"
PACKAGE_EXTRA_ARCHS:tune-cortexa15thf            = "${PACKAGE_EXTRA_ARCHS:tune-armv7vethf} cortexa15hf-vfp cortexa15t2hf-vfp"
PACKAGE_EXTRA_ARCHS:tune-cortexa15hf-neon        = "${PACKAGE_EXTRA_ARCHS:tune-armv7vehf-neon} cortexa15hf-vfp cortexa15hf-neon"
PACKAGE_EXTRA_ARCHS:tune-cortexa15thf-neon       = "${PACKAGE_EXTRA_ARCHS:tune-armv7vethf-neon} cortexa15hf-vfp cortexa15hf-neon cortexa15t2hf-vfp cortexa15t2hf-neon"
PACKAGE_EXTRA_ARCHS:tune-cortexa15hf-neon-vfpv4  = "${PACKAGE_EXTRA_ARCHS:tune-armv7vehf-neon-vfpv4} cortexa15hf-vfp cortexa15hf-neon cortexa15hf-neon-vfpv4"
PACKAGE_EXTRA_ARCHS:tune-cortexa15thf-neon-vfpv4 = "${PACKAGE_EXTRA_ARCHS:tune-armv7vethf-neon-vfpv4} cortexa15hf-vfp cortexa15hf-neon cortexa15hf-neon-vfpv4 cortexa15t2hf-vfp cortexa15t2hf-neon cortexa15t2hf-neon-vfpv4"
