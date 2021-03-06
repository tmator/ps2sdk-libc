#
#  @(#)Makefile 1.4 95/01/18
#
#  ====================================================
#  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
#
#  Developed at SunSoft, a Sun Microsystems, Inc. business.
#  Permission to use, copy, modify, and distribute this
#  software is freely granted, provided that this notice
#  is preserved.
#  ====================================================
#
#

# NOTE: if scalb's second arguement is an int, then one must
# define _SCALB_INT in CFLAGS. The default prototype of scalb
# is double scalb(double, double)
#

# NOTE: Define FENV_SOFTFLOAT in CFLAGS to use an emulated
#       floating point environment.

EE_LIB = libm.a

#SOFTFLOAT_FLAGS = -msoft-float -DFENV_SOFTFLOAT
EE_CFLAGS = -std=c99 -fno-builtin -D__LITTLE_ENDIAN -O3

EE_OBJS = k_rem_pio2.o   k_cos.o          k_sin.o          k_tan.o        \
	k_cosf.o         k_sinf.o         k_tanf.o         b_exp.o        \
	b_log.o          b_tgamma.o \
	s_fabs.o         e_fmod.o         e_exp.o          e_log.o        \
	e_log10.o        e_pow.o          e_sqrt.o         s_sin.o        \
	s_cos.o          s_tan.o          e_asin.o         e_acos.o       \
	s_atan.o         e_atan2.o        e_sinh.o         e_cosh.o       \
	s_tanh.o         s_ceil.o         s_floor.o        s_frexp.o      \
	s_scalbn.o       s_modf.o \
	e_acosh.o        s_asinh.o        e_atanh.o        s_hypot.o      \
	e_j0.o           e_j1.o           e_jn.o           e_lgamma.o     \
	e_lgamma_r.o     e_log2.o         e_rem_pio2.o     e_remainder.o  \
	s_cbrt.o         s_copysign.o     s_erf.o          s_fpclassify.o \
	s_exp2.o         s_expm1.o        s_isfinite.o     s_ilogb.o      \
	s_isnan.o        s_log1p.o        s_logb.o         s_nextafter.o  \
	s_rint.o         s_signgam.o      s_significand.o  s_trunc.o      \
	s_remquo.o       s_fdim.o         s_fma.o          s_fmax.o       \
	s_fmin.o         s_round.o        s_lround.o       s_llround.o    \
	s_nearbyint.o    s_lrint.o        s_llrint.o       s_isnormal.o   \
	s_isinf.o        s_nan.o \
	e_acosf.o        e_powf.o         s_cosf.o         e_acoshf.o     \
	e_remainderf.o   s_erff.o         s_modff.o        e_asinf.o      \
	e_rem_pio2f.o    s_exp2f.o        s_nextafterf.o   e_atan2f.o     \
	s_expm1f.o       s_remquof.o      e_atanhf.o       e_jnf.o        \
	e_sinhf.o        s_fabsf.o        s_rintf.o        e_coshf.o      \
	e_sqrtf.o        s_floorf.o       e_expf.o         s_fmaxf.o      \
	s_scalbnf.o      e_fmodf.o        s_fminf.o        s_hypotf.o     \
	s_frexpf.o       s_sinf.o         e_j0f.o          s_ilogbf.o     \
	s_tanf.o         e_j1f.o          s_asinhf.o       s_tanhf.o      \
	s_significandf.o s_atanf.o        s_truncf.o       e_log10f.o     \
	s_cbrtf.o        e_logf.o         s_log1pf.o       e_log2f.o      \
	s_logbf.o        s_ceilf.o        s_fmaf.o         s_copysignf.o  \
	e_lgammaf.o      e_lgammaf_r.o    s_roundf.o       s_signbit.o    \
	s_lrintf.o       s_llrintf.o      s_lroundf.o      s_llroundf.o   \
	fenv.o

include $(PS2SDKSRC)/Defs.make
include $(PS2SDKSRC)/ee/Rules.lib.make
include $(PS2SDKSRC)/ee/Rules.make

release-libm-dirs:
	$(MKDIR) -p $(PS2SDK)/ee/libc
	$(MKDIR) -p $(PS2SDK)/ee/libc/lib
	$(MKDIR) -p $(PS2SDK)/ee/libc/include
	$(MKDIR) -p $(PS2SDK)/ee/libc/include/sys


release-libm-lib:
	@if test $(EE_LIB) ; then \
	   $(ECHO) Installing $(EE_LIB) to $(PS2SDK)/ee/libc/lib ; \
	   cp -f $(EE_LIB) $(PS2SDK)/ee/libc/lib ; \
	   cp -f $(EE_LIB:%.a=%.erl) $(PS2SDK)/ee/libc/lib ; \
	   chmod 644 $(PS2SDK)/ee/libc/lib/`basename $(EE_LIB)` $(PS2SDK)/ee/libc/lib/`basename $(EE_LIB:%.a=%.erl)`; \
	fi;

release-libm-include:
	@if test -d include ; then \
	   for file in include/*; do \
	      if test -f $$file ; then \
	         $(ECHO) Installing $$file to $(PS2SDK)/ee/libc/include ; \
	         cp -f $$file $(PS2SDK)/ee/libc/include ; \
	         chmod 644 $(PS2SDK)/ee/libc/include/`basename $$file` ; \
	      fi \
	   done; \
	fi;

release: release-libm-dirs release-libm-lib release-libm-include

release-libm-clean:
	rm -f $(PS2SDK)/ee/libc/include/sys/*.h
	rm -f $(PS2SDK)/ee/libc/include/*.h
	rm -f $(PS2SDK)/ee/libc/lib/*

