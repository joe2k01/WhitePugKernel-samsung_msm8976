# AnyKernel2 Ramdisk Mod Script
# osm0sis @ xda-developers

## AnyKernel setup
# begin properties
properties() {
kernel.string=WhitePugKernel by joe2k01 @ xda-developers
do.devicecheck=1
do.modules=0
do.cleanup=0
do.cleanuponabort=0
device.name1=gts210vewifi
device.name2=
device.name3=
device.name4=
device.name5=
} # end properties

# shell variables
block=/dev/block/bootdevice/by-name/boot;
is_slot_device=0;
ramdisk_compression=auto;

## AnyKernel methods (DO NOT CHANGE)
# import patching functions/variables - see for reference
. /tmp/anykernel/tools/ak2-core.sh;


## AnyKernel file attributes
# set permissions/ownership for included ramdisk files
chmod -R 750 $ramdisk/*;
chown -R root:root $ramdisk/*;


## AnyKernel install
dump_boot;

insert_line init.qcom.rc "import /init.wpk.rc" after "import /init.trace.rc" "import /init.wpk.rc\n";

write_boot;

## end install

