#----------------------------------------------------------------------------
#       MAKEFILE
#
#	Controlling makefile for File Assistant
#
#	Created:	1st August 2005
#
#	Copyright (C) 1995-2005 T Swann
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
#	Target to make
#	--------------

#PATH 		:= /c/devkitPro/devkitPSP/bin:$(PATH)

STATICLIB = libosl.a
TARGET := OSLib
PSP_FW_VERSION=371

#----------------------------------------------------------------------------
#	Project folders
#	---------------

SOURCE_DIR :=
INCLUDE_DIR :=

#----------------------------------------------------------------------------
#	Source to make
#	--------------

PSPMATHOBJS := 	            $(SOURCE_DIR)libpspmath/printMatrixFloat.o \
                            $(SOURCE_DIR)libpspmath/vfpu_srand.o \
                            $(SOURCE_DIR)libpspmath/vfpu_randf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_rand_8888.o \
                            $(SOURCE_DIR)libpspmath/vfpu_identity_matrix.o \
                            $(SOURCE_DIR)libpspmath/vfpu_translate_matrix.o \
                            $(SOURCE_DIR)libpspmath/vfpu_perspective_matrix.o \
                            $(SOURCE_DIR)libpspmath/vfpu_ortho_matrix.o \
                            $(SOURCE_DIR)libpspmath/vfpu_sinf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_cosf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_tanf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_asinf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_acosf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_atanf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_sinhf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_coshf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_tanhf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_sincos.o \
                            $(SOURCE_DIR)libpspmath/vfpu_expf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_logf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_fabsf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_sqrtf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_powf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_fmodf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_fminf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_fmaxf.o \
                            $(SOURCE_DIR)libpspmath/vfpu_ease_in_out.o \
                            $(SOURCE_DIR)libpspmath/vfpu_normalize_vector.o \
                            $(SOURCE_DIR)libpspmath/vfpu_zero_vector.o \
                            $(SOURCE_DIR)libpspmath/vfpu_scale_vector.o \
                            $(SOURCE_DIR)libpspmath/vfpu_add_vector.o \
                            $(SOURCE_DIR)libpspmath/vfpu_envmap_matrix.o \
                            $(SOURCE_DIR)libpspmath/vfpu_sphere_to_cartesian.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_identity.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_copy.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_multiply.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_normalize.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_exp.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_ln.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_sample_linear.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_from_euler.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_to_matrix.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_sample_hermite.o \
                            $(SOURCE_DIR)libpspmath/vfpu_quaternion_hermite_tangent.o

LIBOBJS :=					$(PSPMATHOBJS) \
                            $(SOURCE_DIR)oslib.o \
                            $(SOURCE_DIR)vfpu.o \
                            $(SOURCE_DIR)drawing.o \
							$(SOURCE_DIR)image.o \
							$(SOURCE_DIR)palette.o \
							$(SOURCE_DIR)shape.o \
							$(SOURCE_DIR)map.o \
							$(SOURCE_DIR)messagebox.o \
							$(SOURCE_DIR)oslHandleLoadNoFailError.o \
							$(SOURCE_DIR)keys.o \
							$(SOURCE_DIR)text.o \
							$(SOURCE_DIR)vram_mgr.o \
							$(SOURCE_DIR)stub.o \
							$(SOURCE_DIR)audio/audio.o \
							$(SOURCE_DIR)audio/bgm.o \
							$(SOURCE_DIR)audio/mod.o \
							$(SOURCE_DIR)audio/media.o \
							$(SOURCE_DIR)usb.o \
							$(SOURCE_DIR)dialog.o \
							$(SOURCE_DIR)osk.o \
							$(SOURCE_DIR)saveload.o \
							$(SOURCE_DIR)net.o \
							$(SOURCE_DIR)browser.o \
                            $(SOURCE_DIR)vfile/VirtualFile.o \
							$(SOURCE_DIR)vfile/vfsFile.o \
							$(SOURCE_DIR)image/oslConvertImageTo.o \
							$(SOURCE_DIR)image/oslSetImagePixel.o \
							$(SOURCE_DIR)image/oslGetImagePixel.o \
							$(SOURCE_DIR)image/oslDrawImage.o \
							$(SOURCE_DIR)image/oslDrawImageSimple.o \
							$(SOURCE_DIR)image/oslDrawImageBig.o \
							$(SOURCE_DIR)image/oslLockImage.o \
							$(SOURCE_DIR)image/oslMoveImageTo.o \
							$(SOURCE_DIR)image/oslSwizzleImage.o \
							$(SOURCE_DIR)image/oslUnswizzleImage.o \
							$(SOURCE_DIR)image/oslSetDrawBuffer.o \
							$(SOURCE_DIR)image/oslResetImageProperties.o \
							$(SOURCE_DIR)jpeg/gba-jpeg-decode.o \
							$(SOURCE_DIR)gif/dev2gif.o $(SOURCE_DIR)gif/dgif_lib.o $(SOURCE_DIR)gif/egif_lib.o $(SOURCE_DIR)gif/gif_err.o $(SOURCE_DIR)gif/gifalloc.o $(SOURCE_DIR)gif/quantize.o \
							$(SOURCE_DIR)Special/oslLoadImageFilePNG.o	\
							$(SOURCE_DIR)Special/oslWriteImageFilePNG.o	\
							$(SOURCE_DIR)Special/oslLoadImageFileJPG.o	\
							$(SOURCE_DIR)Special/oslLoadImageFileGIF.o	\
							$(SOURCE_DIR)Special/oslLoadImageFile.o	\
							$(SOURCE_DIR)Special/oslWriteImageFile.o \
							$(SOURCE_DIR)splash/oslShowSplashScreen1.o \
							$(SOURCE_DIR)splash/oslShowSplashScreen2.o \
							$(SOURCE_DIR)mem/oslGetRamStatus.o \
                            $(SOURCE_DIR)intraFont/intraFont.o

OBJS :=						$(LIBOBJS)

#----------------------------------------------------------------------------
#	Additional includes
#	-------------------

INCDIR   :=					$(INCDIR) \
							$(INCLUDE_DIR)

#----------------------------------------------------------------------------
#	Addditional libraries
#	---------------------
SDK_LIBS :=					-lpspsdk \
							-lpspctrl -lpsphprm \
							-lpspumd \
							-lpsprtc \
							-lpspgu -lpspgum \
							-lpspaudiolib \
							-lpspaudio \
							-lpsppower \
							-lpspusb -lpspusbstor \
                            -lpsputility \
                            -lpspssl -lpsphttp -lpspwlan

EXTERN_LIBS :=				-lpng \
							-lz

LIBS :=						$(EXTERN_LIBS) \
							$(SDK_LIBS) \
							-lm

#----------------------------------------------------------------------------
#	Preprocesser defines
#	--------------------

DEFINES :=					-D_DEBUG \
							-DPSP

#----------------------------------------------------------------------------
#	Compiler settings
#	-----------------

CFLAGS :=					$(DEFINES) -O2 -G0 -g -Wall -DHAVE_AV_CONFIG_H -fno-strict-aliasing -fverbose-asm
#CFLAGS :=					$(DEFINES) -O2 -G0 -g -frename-registers -ffast-math -fomit-frame-pointer -Wall -DHAVE_AV_CONFIG_H -fno-strict-aliasing
CXXFLAGS :=					$(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS :=					$(CFLAGS)

LIBDIR :=

LDFLAGS :=

#----------------------------------------------------------------------------
#	PBP parameters
#	--------------

EXTRA_TARGETS :=			EBOOT.PBP
#PSP_EBOOT_ICON :=			../ICON0.PNG
#PSP_EBOOT_PIC1 :=			../PIC1.PNG
PSP_EBOOT_TITLE :=			Oldschool Library for PSP

#----------------------------------------------------------------------------
#	Default build settings
#	----------------------

PSPSDK :=					$(shell psp-config --pspsdk-path)

include						$(PSPSDK)/lib/build.mak

#----------------------------------------------------------------------------
#	Copy to PSP
#	-----------

oslDrawMap.o: oslDrawMap.c
	$(CC) $(addprefix -I,$(INCDIR)) $(CFLAGS) -O3 -c -o $@ $<

lib: $(STATICLIB)

$(STATICLIB): $(LIBOBJS)
	$(AR) rcs $@ $(LIBOBJS)
	$(RANLIB) $@

ifneq ($VS_PATH),)
CC       = psp-gcc
endif

kx-install: kxploit
ifeq ($(PSP_MOUNT),)
		@echo '*** Error: $$(PSP_MOUNT) undefined. Please set it to for example /cygdrive/e'
		@echo if your PSP is mounted to E: in cygwin.
else
		cp -r $(TARGET) $(PSP_MOUNT)/PSP/GAME/
		cp -r $(TARGET)% $(PSP_MOUNT)/PSP/GAME/
		cp $(TARGET).elf $(PSP_MOUNT)/PSP/GAME/$(TARGET)
		cp -r -u "../Data" $(PSP_MOUNT)/PSP/GAME/$(TARGET)
endif