#ifndef SIXTRACKLIB_COMMON_BE_TRICUB_COEFFICIENTS_C99_H__
#define SIXTRACKLIB_COMMON_BE_TRICUB_COEFFICIENTS_C99_H__

/*
#if !defined(SIXTRL_NO_SYSTEM_INCLUDES)
    #include <stddef.h>
    #include <math.h>
#endif */
/* !defined(SIXTRL_NO_SYSTEM_INCLUDES) */

#if !defined(SIXTRL_NO_INCLUDES)
    #include "sixtracklib/common/definitions.h"
    #include "sixtracklib/common/be_tricub/be_tricub.h"
#endif /* !defined(SIXTRL_NO_INCLUDES) */

#if !defined( _GPUCODE ) && defined( __cplusplus )
extern "C" {
#endif /* !defined( _GPUCODE ) && defined( __cplusplus ) */

SIXTRL_STATIC SIXTRL_FN void NS(tricub_construct_coefs)(
    SIXTRL_ARGPTR_DEC NS(be_tricub_real_t) const* SIXTRL_RESTRICT b,
    SIXTRL_ARGPTR_DEC NS(be_tricub_real_t)* coefs);

#if !defined( _GPUCODE ) && defined( __cplusplus )
}
#endif /* !defined( _GPUCODE ) && defined( __cplusplus ) */

/* ************************************************************************* */
/* ************************************************************************* */

#if !defined( _GPUCODE ) && defined( __cplusplus )
extern "C" {
#endif /* !defined( _GPUCODE ) && defined( __cplusplus ) */

SIXTRL_INLINE void NS(tricub_construct_coefs)(
    SIXTRL_ARGPTR_DEC NS(be_tricub_real_t) const* SIXTRL_RESTRICT b,
    SIXTRL_ARGPTR_DEC NS(be_tricub_real_t)* coefs)
{

    NS(be_tricub_real_t) const tri_consts[9] = {2.0, 3.0, 4.0, 6.0, 8.0, 9.0, 12.0, 18.0, 27.0};

    coefs[0] = b[0];
    coefs[2] = -(tri_consts[1] * b[0]);
    coefs[3] = tri_consts[0] * b[0];
    coefs[8] = -(tri_consts[1] * b[0]);
    coefs[10] = tri_consts[5] * b[0];
    coefs[11] = -(tri_consts[3] * b[0]);
    coefs[12] = tri_consts[0] * b[0];
    coefs[14] = -(tri_consts[3] * b[0]);
    coefs[15] = tri_consts[2] * b[0];
    coefs[32] = -(tri_consts[1] * b[0]);
    coefs[34] = tri_consts[5] * b[0];
    coefs[35] = -(tri_consts[3] * b[0]);
    coefs[40] = tri_consts[5] * b[0];
    coefs[42] = -(tri_consts[8] * b[0]);
    coefs[43] = tri_consts[7] * b[0];
    coefs[44] = -(tri_consts[3] * b[0]);
    coefs[46] = tri_consts[7] * b[0];
    coefs[47] = -(tri_consts[6] * b[0]);
    coefs[48] = tri_consts[0] * b[0];
    coefs[50] = -(tri_consts[3] * b[0]);
    coefs[51] = tri_consts[2] * b[0];
    coefs[56] = -(tri_consts[3] * b[0]);
    coefs[58] = tri_consts[7] * b[0];
    coefs[59] = -(tri_consts[6] * b[0]);
    coefs[60] = tri_consts[2] * b[0];
    coefs[62] = -(tri_consts[6] * b[0]);
    coefs[63] = tri_consts[4] * b[0];
    coefs[2] += tri_consts[1] * b[1];
    coefs[3] -= tri_consts[0] * b[1];
    coefs[10] -= tri_consts[5] * b[1];
    coefs[11] += tri_consts[3] * b[1];
    coefs[14] += tri_consts[3] * b[1];
    coefs[15] -= tri_consts[2] * b[1];
    coefs[34] -= tri_consts[5] * b[1];
    coefs[35] += tri_consts[3] * b[1];
    coefs[42] += tri_consts[8] * b[1];
    coefs[43] -= tri_consts[7] * b[1];
    coefs[46] -= tri_consts[7] * b[1];
    coefs[47] += tri_consts[6] * b[1];
    coefs[50] += tri_consts[3] * b[1];
    coefs[51] -= tri_consts[2] * b[1];
    coefs[58] -= tri_consts[7] * b[1];
    coefs[59] += tri_consts[6] * b[1];
    coefs[62] += tri_consts[6] * b[1];
    coefs[63] -= tri_consts[4] * b[1];
    coefs[8] += tri_consts[1] * b[2];
    coefs[10] -= tri_consts[5] * b[2];
    coefs[11] += tri_consts[3] * b[2];
    coefs[12] -= tri_consts[0] * b[2];
    coefs[14] += tri_consts[3] * b[2];
    coefs[15] -= tri_consts[2] * b[2];
    coefs[40] -= tri_consts[5] * b[2];
    coefs[42] += tri_consts[8] * b[2];
    coefs[43] -= tri_consts[7] * b[2];
    coefs[44] += tri_consts[3] * b[2];
    coefs[46] -= tri_consts[7] * b[2];
    coefs[47] += tri_consts[6] * b[2];
    coefs[56] += tri_consts[3] * b[2];
    coefs[58] -= tri_consts[7] * b[2];
    coefs[59] += tri_consts[6] * b[2];
    coefs[60] -= tri_consts[2] * b[2];
    coefs[62] += tri_consts[6] * b[2];
    coefs[63] -= tri_consts[4] * b[2];
    coefs[10] += tri_consts[5] * b[3];
    coefs[11] -= tri_consts[3] * b[3];
    coefs[14] -= tri_consts[3] * b[3];
    coefs[15] += tri_consts[2] * b[3];
    coefs[42] -= tri_consts[8] * b[3];
    coefs[43] += tri_consts[7] * b[3];
    coefs[46] += tri_consts[7] * b[3];
    coefs[47] -= tri_consts[6] * b[3];
    coefs[58] += tri_consts[7] * b[3];
    coefs[59] -= tri_consts[6] * b[3];
    coefs[62] -= tri_consts[6] * b[3];
    coefs[63] += tri_consts[4] * b[3];
    coefs[32] += tri_consts[1] * b[4];
    coefs[34] -= tri_consts[5] * b[4];
    coefs[35] += tri_consts[3] * b[4];
    coefs[40] -= tri_consts[5] * b[4];
    coefs[42] += tri_consts[8] * b[4];
    coefs[43] -= tri_consts[7] * b[4];
    coefs[44] += tri_consts[3] * b[4];
    coefs[46] -= tri_consts[7] * b[4];
    coefs[47] += tri_consts[6] * b[4];
    coefs[48] -= tri_consts[0] * b[4];
    coefs[50] += tri_consts[3] * b[4];
    coefs[51] -= tri_consts[2] * b[4];
    coefs[56] += tri_consts[3] * b[4];
    coefs[58] -= tri_consts[7] * b[4];
    coefs[59] += tri_consts[6] * b[4];
    coefs[60] -= tri_consts[2] * b[4];
    coefs[62] += tri_consts[6] * b[4];
    coefs[63] -= tri_consts[4] * b[4];
    coefs[34] += tri_consts[5] * b[5];
    coefs[35] -= tri_consts[3] * b[5];
    coefs[42] -= tri_consts[8] * b[5];
    coefs[43] += tri_consts[7] * b[5];
    coefs[46] += tri_consts[7] * b[5];
    coefs[47] -= tri_consts[6] * b[5];
    coefs[50] -= tri_consts[3] * b[5];
    coefs[51] += tri_consts[2] * b[5];
    coefs[58] += tri_consts[7] * b[5];
    coefs[59] -= tri_consts[6] * b[5];
    coefs[62] -= tri_consts[6] * b[5];
    coefs[63] += tri_consts[4] * b[5];
    coefs[40] += tri_consts[5] * b[6];
    coefs[42] -= tri_consts[8] * b[6];
    coefs[43] += tri_consts[7] * b[6];
    coefs[44] -= tri_consts[3] * b[6];
    coefs[46] += tri_consts[7] * b[6];
    coefs[47] -= tri_consts[6] * b[6];
    coefs[56] -= tri_consts[3] * b[6];
    coefs[58] += tri_consts[7] * b[6];
    coefs[59] -= tri_consts[6] * b[6];
    coefs[60] += tri_consts[2] * b[6];
    coefs[62] -= tri_consts[6] * b[6];
    coefs[63] += tri_consts[4] * b[6];
    coefs[42] += tri_consts[8] * b[7];
    coefs[43] -= tri_consts[7] * b[7];
    coefs[46] -= tri_consts[7] * b[7];
    coefs[47] += tri_consts[6] * b[7];
    coefs[58] -= tri_consts[7] * b[7];
    coefs[59] += tri_consts[6] * b[7];
    coefs[62] += tri_consts[6] * b[7];
    coefs[63] -= tri_consts[4] * b[7];
    coefs[1] = b[8];
    coefs[2] -= tri_consts[0] * b[8];
    coefs[3] += b[8];
    coefs[9] = -(tri_consts[1] * b[8]);
    coefs[10] += tri_consts[3] * b[8];
    coefs[11] -= tri_consts[1] * b[8];
    coefs[13] = tri_consts[0] * b[8];
    coefs[14] -= tri_consts[2] * b[8];
    coefs[15] += tri_consts[0] * b[8];
    coefs[33] = -(tri_consts[1] * b[8]);
    coefs[34] += tri_consts[3] * b[8];
    coefs[35] -= tri_consts[1] * b[8];
    coefs[41] = tri_consts[5] * b[8];
    coefs[42] -= tri_consts[7] * b[8];
    coefs[43] += tri_consts[5] * b[8];
    coefs[45] = -(tri_consts[3] * b[8]);
    coefs[46] += tri_consts[6] * b[8];
    coefs[47] -= tri_consts[3] * b[8];
    coefs[49] = tri_consts[0] * b[8];
    coefs[50] -= tri_consts[2] * b[8];
    coefs[51] += tri_consts[0] * b[8];
    coefs[57] = -(tri_consts[3] * b[8]);
    coefs[58] += tri_consts[6] * b[8];
    coefs[59] -= tri_consts[3] * b[8];
    coefs[61] = tri_consts[2] * b[8];
    coefs[62] -= tri_consts[4] * b[8];
    coefs[63] += tri_consts[2] * b[8];
    coefs[2] -= b[9];
    coefs[3] += b[9];
    coefs[10] += tri_consts[1] * b[9];
    coefs[11] -= tri_consts[1] * b[9];
    coefs[14] -= tri_consts[0] * b[9];
    coefs[15] += tri_consts[0] * b[9];
    coefs[34] += tri_consts[1] * b[9];
    coefs[35] -= tri_consts[1] * b[9];
    coefs[42] -= tri_consts[5] * b[9];
    coefs[43] += tri_consts[5] * b[9];
    coefs[46] += tri_consts[3] * b[9];
    coefs[47] -= tri_consts[3] * b[9];
    coefs[50] -= tri_consts[0] * b[9];
    coefs[51] += tri_consts[0] * b[9];
    coefs[58] += tri_consts[3] * b[9];
    coefs[59] -= tri_consts[3] * b[9];
    coefs[62] -= tri_consts[2] * b[9];
    coefs[63] += tri_consts[2] * b[9];
    coefs[9] += tri_consts[1] * b[10];
    coefs[10] -= tri_consts[3] * b[10];
    coefs[11] += tri_consts[1] * b[10];
    coefs[13] -= tri_consts[0] * b[10];
    coefs[14] += tri_consts[2] * b[10];
    coefs[15] -= tri_consts[0] * b[10];
    coefs[41] -= tri_consts[5] * b[10];
    coefs[42] += tri_consts[7] * b[10];
    coefs[43] -= tri_consts[5] * b[10];
    coefs[45] += tri_consts[3] * b[10];
    coefs[46] -= tri_consts[6] * b[10];
    coefs[47] += tri_consts[3] * b[10];
    coefs[57] += tri_consts[3] * b[10];
    coefs[58] -= tri_consts[6] * b[10];
    coefs[59] += tri_consts[3] * b[10];
    coefs[61] -= tri_consts[2] * b[10];
    coefs[62] += tri_consts[4] * b[10];
    coefs[63] -= tri_consts[2] * b[10];
    coefs[10] -= tri_consts[1] * b[11];
    coefs[11] += tri_consts[1] * b[11];
    coefs[14] += tri_consts[0] * b[11];
    coefs[15] -= tri_consts[0] * b[11];
    coefs[42] += tri_consts[5] * b[11];
    coefs[43] -= tri_consts[5] * b[11];
    coefs[46] -= tri_consts[3] * b[11];
    coefs[47] += tri_consts[3] * b[11];
    coefs[58] -= tri_consts[3] * b[11];
    coefs[59] += tri_consts[3] * b[11];
    coefs[62] += tri_consts[2] * b[11];
    coefs[63] -= tri_consts[2] * b[11];
    coefs[33] += tri_consts[1] * b[12];
    coefs[34] -= tri_consts[3] * b[12];
    coefs[35] += tri_consts[1] * b[12];
    coefs[41] -= tri_consts[5] * b[12];
    coefs[42] += tri_consts[7] * b[12];
    coefs[43] -= tri_consts[5] * b[12];
    coefs[45] += tri_consts[3] * b[12];
    coefs[46] -= tri_consts[6] * b[12];
    coefs[47] += tri_consts[3] * b[12];
    coefs[49] -= tri_consts[0] * b[12];
    coefs[50] += tri_consts[2] * b[12];
    coefs[51] -= tri_consts[0] * b[12];
    coefs[57] += tri_consts[3] * b[12];
    coefs[58] -= tri_consts[6] * b[12];
    coefs[59] += tri_consts[3] * b[12];
    coefs[61] -= tri_consts[2] * b[12];
    coefs[62] += tri_consts[4] * b[12];
    coefs[63] -= tri_consts[2] * b[12];
    coefs[34] -= tri_consts[1] * b[13];
    coefs[35] += tri_consts[1] * b[13];
    coefs[42] += tri_consts[5] * b[13];
    coefs[43] -= tri_consts[5] * b[13];
    coefs[46] -= tri_consts[3] * b[13];
    coefs[47] += tri_consts[3] * b[13];
    coefs[50] += tri_consts[0] * b[13];
    coefs[51] -= tri_consts[0] * b[13];
    coefs[58] -= tri_consts[3] * b[13];
    coefs[59] += tri_consts[3] * b[13];
    coefs[62] += tri_consts[2] * b[13];
    coefs[63] -= tri_consts[2] * b[13];
    coefs[41] += tri_consts[5] * b[14];
    coefs[42] -= tri_consts[7] * b[14];
    coefs[43] += tri_consts[5] * b[14];
    coefs[45] -= tri_consts[3] * b[14];
    coefs[46] += tri_consts[6] * b[14];
    coefs[47] -= tri_consts[3] * b[14];
    coefs[57] -= tri_consts[3] * b[14];
    coefs[58] += tri_consts[6] * b[14];
    coefs[59] -= tri_consts[3] * b[14];
    coefs[61] += tri_consts[2] * b[14];
    coefs[62] -= tri_consts[4] * b[14];
    coefs[63] += tri_consts[2] * b[14];
    coefs[42] -= tri_consts[5] * b[15];
    coefs[43] += tri_consts[5] * b[15];
    coefs[46] += tri_consts[3] * b[15];
    coefs[47] -= tri_consts[3] * b[15];
    coefs[58] += tri_consts[3] * b[15];
    coefs[59] -= tri_consts[3] * b[15];
    coefs[62] -= tri_consts[2] * b[15];
    coefs[63] += tri_consts[2] * b[15];
    coefs[4] = b[16];
    coefs[6] = -(tri_consts[1] * b[16]);
    coefs[7] = tri_consts[0] * b[16];
    coefs[8] -= tri_consts[0] * b[16];
    coefs[10] += tri_consts[3] * b[16];
    coefs[11] -= tri_consts[2] * b[16];
    coefs[12] += b[16];
    coefs[14] -= tri_consts[1] * b[16];
    coefs[15] += tri_consts[0] * b[16];
    coefs[36] = -(tri_consts[1] * b[16]);
    coefs[38] = tri_consts[5] * b[16];
    coefs[39] = -(tri_consts[3] * b[16]);
    coefs[40] += tri_consts[3] * b[16];
    coefs[42] -= tri_consts[7] * b[16];
    coefs[43] += tri_consts[6] * b[16];
    coefs[44] -= tri_consts[1] * b[16];
    coefs[46] += tri_consts[5] * b[16];
    coefs[47] -= tri_consts[3] * b[16];
    coefs[52] = tri_consts[0] * b[16];
    coefs[54] = -(tri_consts[3] * b[16]);
    coefs[55] = tri_consts[2] * b[16];
    coefs[56] -= tri_consts[2] * b[16];
    coefs[58] += tri_consts[6] * b[16];
    coefs[59] -= tri_consts[4] * b[16];
    coefs[60] += tri_consts[0] * b[16];
    coefs[62] -= tri_consts[3] * b[16];
    coefs[63] += tri_consts[2] * b[16];
    coefs[6] += tri_consts[1] * b[17];
    coefs[7] -= tri_consts[0] * b[17];
    coefs[10] -= tri_consts[3] * b[17];
    coefs[11] += tri_consts[2] * b[17];
    coefs[14] += tri_consts[1] * b[17];
    coefs[15] -= tri_consts[0] * b[17];
    coefs[38] -= tri_consts[5] * b[17];
    coefs[39] += tri_consts[3] * b[17];
    coefs[42] += tri_consts[7] * b[17];
    coefs[43] -= tri_consts[6] * b[17];
    coefs[46] -= tri_consts[5] * b[17];
    coefs[47] += tri_consts[3] * b[17];
    coefs[54] += tri_consts[3] * b[17];
    coefs[55] -= tri_consts[2] * b[17];
    coefs[58] -= tri_consts[6] * b[17];
    coefs[59] += tri_consts[4] * b[17];
    coefs[62] += tri_consts[3] * b[17];
    coefs[63] -= tri_consts[2] * b[17];
    coefs[8] -= b[18];
    coefs[10] += tri_consts[1] * b[18];
    coefs[11] -= tri_consts[0] * b[18];
    coefs[12] += b[18];
    coefs[14] -= tri_consts[1] * b[18];
    coefs[15] += tri_consts[0] * b[18];
    coefs[40] += tri_consts[1] * b[18];
    coefs[42] -= tri_consts[5] * b[18];
    coefs[43] += tri_consts[3] * b[18];
    coefs[44] -= tri_consts[1] * b[18];
    coefs[46] += tri_consts[5] * b[18];
    coefs[47] -= tri_consts[3] * b[18];
    coefs[56] -= tri_consts[0] * b[18];
    coefs[58] += tri_consts[3] * b[18];
    coefs[59] -= tri_consts[2] * b[18];
    coefs[60] += tri_consts[0] * b[18];
    coefs[62] -= tri_consts[3] * b[18];
    coefs[63] += tri_consts[2] * b[18];
    coefs[10] -= tri_consts[1] * b[19];
    coefs[11] += tri_consts[0] * b[19];
    coefs[14] += tri_consts[1] * b[19];
    coefs[15] -= tri_consts[0] * b[19];
    coefs[42] += tri_consts[5] * b[19];
    coefs[43] -= tri_consts[3] * b[19];
    coefs[46] -= tri_consts[5] * b[19];
    coefs[47] += tri_consts[3] * b[19];
    coefs[58] -= tri_consts[3] * b[19];
    coefs[59] += tri_consts[2] * b[19];
    coefs[62] += tri_consts[3] * b[19];
    coefs[63] -= tri_consts[2] * b[19];
    coefs[36] += tri_consts[1] * b[20];
    coefs[38] -= tri_consts[5] * b[20];
    coefs[39] += tri_consts[3] * b[20];
    coefs[40] -= tri_consts[3] * b[20];
    coefs[42] += tri_consts[7] * b[20];
    coefs[43] -= tri_consts[6] * b[20];
    coefs[44] += tri_consts[1] * b[20];
    coefs[46] -= tri_consts[5] * b[20];
    coefs[47] += tri_consts[3] * b[20];
    coefs[52] -= tri_consts[0] * b[20];
    coefs[54] += tri_consts[3] * b[20];
    coefs[55] -= tri_consts[2] * b[20];
    coefs[56] += tri_consts[2] * b[20];
    coefs[58] -= tri_consts[6] * b[20];
    coefs[59] += tri_consts[4] * b[20];
    coefs[60] -= tri_consts[0] * b[20];
    coefs[62] += tri_consts[3] * b[20];
    coefs[63] -= tri_consts[2] * b[20];
    coefs[38] += tri_consts[5] * b[21];
    coefs[39] -= tri_consts[3] * b[21];
    coefs[42] -= tri_consts[7] * b[21];
    coefs[43] += tri_consts[6] * b[21];
    coefs[46] += tri_consts[5] * b[21];
    coefs[47] -= tri_consts[3] * b[21];
    coefs[54] -= tri_consts[3] * b[21];
    coefs[55] += tri_consts[2] * b[21];
    coefs[58] += tri_consts[6] * b[21];
    coefs[59] -= tri_consts[4] * b[21];
    coefs[62] -= tri_consts[3] * b[21];
    coefs[63] += tri_consts[2] * b[21];
    coefs[40] -= tri_consts[1] * b[22];
    coefs[42] += tri_consts[5] * b[22];
    coefs[43] -= tri_consts[3] * b[22];
    coefs[44] += tri_consts[1] * b[22];
    coefs[46] -= tri_consts[5] * b[22];
    coefs[47] += tri_consts[3] * b[22];
    coefs[56] += tri_consts[0] * b[22];
    coefs[58] -= tri_consts[3] * b[22];
    coefs[59] += tri_consts[2] * b[22];
    coefs[60] -= tri_consts[0] * b[22];
    coefs[62] += tri_consts[3] * b[22];
    coefs[63] -= tri_consts[2] * b[22];
    coefs[42] -= tri_consts[5] * b[23];
    coefs[43] += tri_consts[3] * b[23];
    coefs[46] += tri_consts[5] * b[23];
    coefs[47] -= tri_consts[3] * b[23];
    coefs[58] += tri_consts[3] * b[23];
    coefs[59] -= tri_consts[2] * b[23];
    coefs[62] -= tri_consts[3] * b[23];
    coefs[63] += tri_consts[2] * b[23];
    coefs[16] = b[24];
    coefs[18] = -(tri_consts[1] * b[24]);
    coefs[19] = tri_consts[0] * b[24];
    coefs[24] = -(tri_consts[1] * b[24]);
    coefs[26] = tri_consts[5] * b[24];
    coefs[27] = -(tri_consts[3] * b[24]);
    coefs[28] = tri_consts[0] * b[24];
    coefs[30] = -(tri_consts[3] * b[24]);
    coefs[31] = tri_consts[2] * b[24];
    coefs[32] -= tri_consts[0] * b[24];
    coefs[34] += tri_consts[3] * b[24];
    coefs[35] -= tri_consts[2] * b[24];
    coefs[40] += tri_consts[3] * b[24];
    coefs[42] -= tri_consts[7] * b[24];
    coefs[43] += tri_consts[6] * b[24];
    coefs[44] -= tri_consts[2] * b[24];
    coefs[46] += tri_consts[6] * b[24];
    coefs[47] -= tri_consts[4] * b[24];
    coefs[48] += b[24];
    coefs[50] -= tri_consts[1] * b[24];
    coefs[51] += tri_consts[0] * b[24];
    coefs[56] -= tri_consts[1] * b[24];
    coefs[58] += tri_consts[5] * b[24];
    coefs[59] -= tri_consts[3] * b[24];
    coefs[60] += tri_consts[0] * b[24];
    coefs[62] -= tri_consts[3] * b[24];
    coefs[63] += tri_consts[2] * b[24];
    coefs[18] += tri_consts[1] * b[25];
    coefs[19] -= tri_consts[0] * b[25];
    coefs[26] -= tri_consts[5] * b[25];
    coefs[27] += tri_consts[3] * b[25];
    coefs[30] += tri_consts[3] * b[25];
    coefs[31] -= tri_consts[2] * b[25];
    coefs[34] -= tri_consts[3] * b[25];
    coefs[35] += tri_consts[2] * b[25];
    coefs[42] += tri_consts[7] * b[25];
    coefs[43] -= tri_consts[6] * b[25];
    coefs[46] -= tri_consts[6] * b[25];
    coefs[47] += tri_consts[4] * b[25];
    coefs[50] += tri_consts[1] * b[25];
    coefs[51] -= tri_consts[0] * b[25];
    coefs[58] -= tri_consts[5] * b[25];
    coefs[59] += tri_consts[3] * b[25];
    coefs[62] += tri_consts[3] * b[25];
    coefs[63] -= tri_consts[2] * b[25];
    coefs[24] += tri_consts[1] * b[26];
    coefs[26] -= tri_consts[5] * b[26];
    coefs[27] += tri_consts[3] * b[26];
    coefs[28] -= tri_consts[0] * b[26];
    coefs[30] += tri_consts[3] * b[26];
    coefs[31] -= tri_consts[2] * b[26];
    coefs[40] -= tri_consts[3] * b[26];
    coefs[42] += tri_consts[7] * b[26];
    coefs[43] -= tri_consts[6] * b[26];
    coefs[44] += tri_consts[2] * b[26];
    coefs[46] -= tri_consts[6] * b[26];
    coefs[47] += tri_consts[4] * b[26];
    coefs[56] += tri_consts[1] * b[26];
    coefs[58] -= tri_consts[5] * b[26];
    coefs[59] += tri_consts[3] * b[26];
    coefs[60] -= tri_consts[0] * b[26];
    coefs[62] += tri_consts[3] * b[26];
    coefs[63] -= tri_consts[2] * b[26];
    coefs[26] += tri_consts[5] * b[27];
    coefs[27] -= tri_consts[3] * b[27];
    coefs[30] -= tri_consts[3] * b[27];
    coefs[31] += tri_consts[2] * b[27];
    coefs[42] -= tri_consts[7] * b[27];
    coefs[43] += tri_consts[6] * b[27];
    coefs[46] += tri_consts[6] * b[27];
    coefs[47] -= tri_consts[4] * b[27];
    coefs[58] += tri_consts[5] * b[27];
    coefs[59] -= tri_consts[3] * b[27];
    coefs[62] -= tri_consts[3] * b[27];
    coefs[63] += tri_consts[2] * b[27];
    coefs[32] -= b[28];
    coefs[34] += tri_consts[1] * b[28];
    coefs[35] -= tri_consts[0] * b[28];
    coefs[40] += tri_consts[1] * b[28];
    coefs[42] -= tri_consts[5] * b[28];
    coefs[43] += tri_consts[3] * b[28];
    coefs[44] -= tri_consts[0] * b[28];
    coefs[46] += tri_consts[3] * b[28];
    coefs[47] -= tri_consts[2] * b[28];
    coefs[48] += b[28];
    coefs[50] -= tri_consts[1] * b[28];
    coefs[51] += tri_consts[0] * b[28];
    coefs[56] -= tri_consts[1] * b[28];
    coefs[58] += tri_consts[5] * b[28];
    coefs[59] -= tri_consts[3] * b[28];
    coefs[60] += tri_consts[0] * b[28];
    coefs[62] -= tri_consts[3] * b[28];
    coefs[63] += tri_consts[2] * b[28];
    coefs[34] -= tri_consts[1] * b[29];
    coefs[35] += tri_consts[0] * b[29];
    coefs[42] += tri_consts[5] * b[29];
    coefs[43] -= tri_consts[3] * b[29];
    coefs[46] -= tri_consts[3] * b[29];
    coefs[47] += tri_consts[2] * b[29];
    coefs[50] += tri_consts[1] * b[29];
    coefs[51] -= tri_consts[0] * b[29];
    coefs[58] -= tri_consts[5] * b[29];
    coefs[59] += tri_consts[3] * b[29];
    coefs[62] += tri_consts[3] * b[29];
    coefs[63] -= tri_consts[2] * b[29];
    coefs[40] -= tri_consts[1] * b[30];
    coefs[42] += tri_consts[5] * b[30];
    coefs[43] -= tri_consts[3] * b[30];
    coefs[44] += tri_consts[0] * b[30];
    coefs[46] -= tri_consts[3] * b[30];
    coefs[47] += tri_consts[2] * b[30];
    coefs[56] += tri_consts[1] * b[30];
    coefs[58] -= tri_consts[5] * b[30];
    coefs[59] += tri_consts[3] * b[30];
    coefs[60] -= tri_consts[0] * b[30];
    coefs[62] += tri_consts[3] * b[30];
    coefs[63] -= tri_consts[2] * b[30];
    coefs[42] -= tri_consts[5] * b[31];
    coefs[43] += tri_consts[3] * b[31];
    coefs[46] += tri_consts[3] * b[31];
    coefs[47] -= tri_consts[2] * b[31];
    coefs[58] += tri_consts[5] * b[31];
    coefs[59] -= tri_consts[3] * b[31];
    coefs[62] -= tri_consts[3] * b[31];
    coefs[63] += tri_consts[2] * b[31];
    coefs[5] = b[32];
    coefs[6] -= tri_consts[0] * b[32];
    coefs[7] += b[32];
    coefs[9] -= tri_consts[0] * b[32];
    coefs[10] += tri_consts[2] * b[32];
    coefs[11] -= tri_consts[0] * b[32];
    coefs[13] += b[32];
    coefs[14] -= tri_consts[0] * b[32];
    coefs[15] += b[32];
    coefs[37] = -(tri_consts[1] * b[32]);
    coefs[38] += tri_consts[3] * b[32];
    coefs[39] -= tri_consts[1] * b[32];
    coefs[41] += tri_consts[3] * b[32];
    coefs[42] -= tri_consts[6] * b[32];
    coefs[43] += tri_consts[3] * b[32];
    coefs[45] -= tri_consts[1] * b[32];
    coefs[46] += tri_consts[3] * b[32];
    coefs[47] -= tri_consts[1] * b[32];
    coefs[53] = tri_consts[0] * b[32];
    coefs[54] -= tri_consts[2] * b[32];
    coefs[55] += tri_consts[0] * b[32];
    coefs[57] -= tri_consts[2] * b[32];
    coefs[58] += tri_consts[4] * b[32];
    coefs[59] -= tri_consts[2] * b[32];
    coefs[61] += tri_consts[0] * b[32];
    coefs[62] -= tri_consts[2] * b[32];
    coefs[63] += tri_consts[0] * b[32];
    coefs[6] -= b[33];
    coefs[7] += b[33];
    coefs[10] += tri_consts[0] * b[33];
    coefs[11] -= tri_consts[0] * b[33];
    coefs[14] -= b[33];
    coefs[15] += b[33];
    coefs[38] += tri_consts[1] * b[33];
    coefs[39] -= tri_consts[1] * b[33];
    coefs[42] -= tri_consts[3] * b[33];
    coefs[43] += tri_consts[3] * b[33];
    coefs[46] += tri_consts[1] * b[33];
    coefs[47] -= tri_consts[1] * b[33];
    coefs[54] -= tri_consts[0] * b[33];
    coefs[55] += tri_consts[0] * b[33];
    coefs[58] += tri_consts[2] * b[33];
    coefs[59] -= tri_consts[2] * b[33];
    coefs[62] -= tri_consts[0] * b[33];
    coefs[63] += tri_consts[0] * b[33];
    coefs[9] -= b[34];
    coefs[10] += tri_consts[0] * b[34];
    coefs[11] -= b[34];
    coefs[13] += b[34];
    coefs[14] -= tri_consts[0] * b[34];
    coefs[15] += b[34];
    coefs[41] += tri_consts[1] * b[34];
    coefs[42] -= tri_consts[3] * b[34];
    coefs[43] += tri_consts[1] * b[34];
    coefs[45] -= tri_consts[1] * b[34];
    coefs[46] += tri_consts[3] * b[34];
    coefs[47] -= tri_consts[1] * b[34];
    coefs[57] -= tri_consts[0] * b[34];
    coefs[58] += tri_consts[2] * b[34];
    coefs[59] -= tri_consts[0] * b[34];
    coefs[61] += tri_consts[0] * b[34];
    coefs[62] -= tri_consts[2] * b[34];
    coefs[63] += tri_consts[0] * b[34];
    coefs[10] += b[35];
    coefs[11] -= b[35];
    coefs[14] -= b[35];
    coefs[15] += b[35];
    coefs[42] -= tri_consts[1] * b[35];
    coefs[43] += tri_consts[1] * b[35];
    coefs[46] += tri_consts[1] * b[35];
    coefs[47] -= tri_consts[1] * b[35];
    coefs[58] += tri_consts[0] * b[35];
    coefs[59] -= tri_consts[0] * b[35];
    coefs[62] -= tri_consts[0] * b[35];
    coefs[63] += tri_consts[0] * b[35];
    coefs[37] += tri_consts[1] * b[36];
    coefs[38] -= tri_consts[3] * b[36];
    coefs[39] += tri_consts[1] * b[36];
    coefs[41] -= tri_consts[3] * b[36];
    coefs[42] += tri_consts[6] * b[36];
    coefs[43] -= tri_consts[3] * b[36];
    coefs[45] += tri_consts[1] * b[36];
    coefs[46] -= tri_consts[3] * b[36];
    coefs[47] += tri_consts[1] * b[36];
    coefs[53] -= tri_consts[0] * b[36];
    coefs[54] += tri_consts[2] * b[36];
    coefs[55] -= tri_consts[0] * b[36];
    coefs[57] += tri_consts[2] * b[36];
    coefs[58] -= tri_consts[4] * b[36];
    coefs[59] += tri_consts[2] * b[36];
    coefs[61] -= tri_consts[0] * b[36];
    coefs[62] += tri_consts[2] * b[36];
    coefs[63] -= tri_consts[0] * b[36];
    coefs[38] -= tri_consts[1] * b[37];
    coefs[39] += tri_consts[1] * b[37];
    coefs[42] += tri_consts[3] * b[37];
    coefs[43] -= tri_consts[3] * b[37];
    coefs[46] -= tri_consts[1] * b[37];
    coefs[47] += tri_consts[1] * b[37];
    coefs[54] += tri_consts[0] * b[37];
    coefs[55] -= tri_consts[0] * b[37];
    coefs[58] -= tri_consts[2] * b[37];
    coefs[59] += tri_consts[2] * b[37];
    coefs[62] += tri_consts[0] * b[37];
    coefs[63] -= tri_consts[0] * b[37];
    coefs[41] -= tri_consts[1] * b[38];
    coefs[42] += tri_consts[3] * b[38];
    coefs[43] -= tri_consts[1] * b[38];
    coefs[45] += tri_consts[1] * b[38];
    coefs[46] -= tri_consts[3] * b[38];
    coefs[47] += tri_consts[1] * b[38];
    coefs[57] += tri_consts[0] * b[38];
    coefs[58] -= tri_consts[2] * b[38];
    coefs[59] += tri_consts[0] * b[38];
    coefs[61] -= tri_consts[0] * b[38];
    coefs[62] += tri_consts[2] * b[38];
    coefs[63] -= tri_consts[0] * b[38];
    coefs[42] += tri_consts[1] * b[39];
    coefs[43] -= tri_consts[1] * b[39];
    coefs[46] -= tri_consts[1] * b[39];
    coefs[47] += tri_consts[1] * b[39];
    coefs[58] -= tri_consts[0] * b[39];
    coefs[59] += tri_consts[0] * b[39];
    coefs[62] += tri_consts[0] * b[39];
    coefs[63] -= tri_consts[0] * b[39];
    coefs[17] = b[40];
    coefs[18] -= tri_consts[0] * b[40];
    coefs[19] += b[40];
    coefs[25] = -(tri_consts[1] * b[40]);
    coefs[26] += tri_consts[3] * b[40];
    coefs[27] -= tri_consts[1] * b[40];
    coefs[29] = tri_consts[0] * b[40];
    coefs[30] -= tri_consts[2] * b[40];
    coefs[31] += tri_consts[0] * b[40];
    coefs[33] -= tri_consts[0] * b[40];
    coefs[34] += tri_consts[2] * b[40];
    coefs[35] -= tri_consts[0] * b[40];
    coefs[41] += tri_consts[3] * b[40];
    coefs[42] -= tri_consts[6] * b[40];
    coefs[43] += tri_consts[3] * b[40];
    coefs[45] -= tri_consts[2] * b[40];
    coefs[46] += tri_consts[4] * b[40];
    coefs[47] -= tri_consts[2] * b[40];
    coefs[49] += b[40];
    coefs[50] -= tri_consts[0] * b[40];
    coefs[51] += b[40];
    coefs[57] -= tri_consts[1] * b[40];
    coefs[58] += tri_consts[3] * b[40];
    coefs[59] -= tri_consts[1] * b[40];
    coefs[61] += tri_consts[0] * b[40];
    coefs[62] -= tri_consts[2] * b[40];
    coefs[63] += tri_consts[0] * b[40];
    coefs[18] -= b[41];
    coefs[19] += b[41];
    coefs[26] += tri_consts[1] * b[41];
    coefs[27] -= tri_consts[1] * b[41];
    coefs[30] -= tri_consts[0] * b[41];
    coefs[31] += tri_consts[0] * b[41];
    coefs[34] += tri_consts[0] * b[41];
    coefs[35] -= tri_consts[0] * b[41];
    coefs[42] -= tri_consts[3] * b[41];
    coefs[43] += tri_consts[3] * b[41];
    coefs[46] += tri_consts[2] * b[41];
    coefs[47] -= tri_consts[2] * b[41];
    coefs[50] -= b[41];
    coefs[51] += b[41];
    coefs[58] += tri_consts[1] * b[41];
    coefs[59] -= tri_consts[1] * b[41];
    coefs[62] -= tri_consts[0] * b[41];
    coefs[63] += tri_consts[0] * b[41];
    coefs[25] += tri_consts[1] * b[42];
    coefs[26] -= tri_consts[3] * b[42];
    coefs[27] += tri_consts[1] * b[42];
    coefs[29] -= tri_consts[0] * b[42];
    coefs[30] += tri_consts[2] * b[42];
    coefs[31] -= tri_consts[0] * b[42];
    coefs[41] -= tri_consts[3] * b[42];
    coefs[42] += tri_consts[6] * b[42];
    coefs[43] -= tri_consts[3] * b[42];
    coefs[45] += tri_consts[2] * b[42];
    coefs[46] -= tri_consts[4] * b[42];
    coefs[47] += tri_consts[2] * b[42];
    coefs[57] += tri_consts[1] * b[42];
    coefs[58] -= tri_consts[3] * b[42];
    coefs[59] += tri_consts[1] * b[42];
    coefs[61] -= tri_consts[0] * b[42];
    coefs[62] += tri_consts[2] * b[42];
    coefs[63] -= tri_consts[0] * b[42];
    coefs[26] -= tri_consts[1] * b[43];
    coefs[27] += tri_consts[1] * b[43];
    coefs[30] += tri_consts[0] * b[43];
    coefs[31] -= tri_consts[0] * b[43];
    coefs[42] += tri_consts[3] * b[43];
    coefs[43] -= tri_consts[3] * b[43];
    coefs[46] -= tri_consts[2] * b[43];
    coefs[47] += tri_consts[2] * b[43];
    coefs[58] -= tri_consts[1] * b[43];
    coefs[59] += tri_consts[1] * b[43];
    coefs[62] += tri_consts[0] * b[43];
    coefs[63] -= tri_consts[0] * b[43];
    coefs[33] -= b[44];
    coefs[34] += tri_consts[0] * b[44];
    coefs[35] -= b[44];
    coefs[41] += tri_consts[1] * b[44];
    coefs[42] -= tri_consts[3] * b[44];
    coefs[43] += tri_consts[1] * b[44];
    coefs[45] -= tri_consts[0] * b[44];
    coefs[46] += tri_consts[2] * b[44];
    coefs[47] -= tri_consts[0] * b[44];
    coefs[49] += b[44];
    coefs[50] -= tri_consts[0] * b[44];
    coefs[51] += b[44];
    coefs[57] -= tri_consts[1] * b[44];
    coefs[58] += tri_consts[3] * b[44];
    coefs[59] -= tri_consts[1] * b[44];
    coefs[61] += tri_consts[0] * b[44];
    coefs[62] -= tri_consts[2] * b[44];
    coefs[63] += tri_consts[0] * b[44];
    coefs[34] += b[45];
    coefs[35] -= b[45];
    coefs[42] -= tri_consts[1] * b[45];
    coefs[43] += tri_consts[1] * b[45];
    coefs[46] += tri_consts[0] * b[45];
    coefs[47] -= tri_consts[0] * b[45];
    coefs[50] -= b[45];
    coefs[51] += b[45];
    coefs[58] += tri_consts[1] * b[45];
    coefs[59] -= tri_consts[1] * b[45];
    coefs[62] -= tri_consts[0] * b[45];
    coefs[63] += tri_consts[0] * b[45];
    coefs[41] -= tri_consts[1] * b[46];
    coefs[42] += tri_consts[3] * b[46];
    coefs[43] -= tri_consts[1] * b[46];
    coefs[45] += tri_consts[0] * b[46];
    coefs[46] -= tri_consts[2] * b[46];
    coefs[47] += tri_consts[0] * b[46];
    coefs[57] += tri_consts[1] * b[46];
    coefs[58] -= tri_consts[3] * b[46];
    coefs[59] += tri_consts[1] * b[46];
    coefs[61] -= tri_consts[0] * b[46];
    coefs[62] += tri_consts[2] * b[46];
    coefs[63] -= tri_consts[0] * b[46];
    coefs[42] += tri_consts[1] * b[47];
    coefs[43] -= tri_consts[1] * b[47];
    coefs[46] -= tri_consts[0] * b[47];
    coefs[47] += tri_consts[0] * b[47];
    coefs[58] -= tri_consts[1] * b[47];
    coefs[59] += tri_consts[1] * b[47];
    coefs[62] += tri_consts[0] * b[47];
    coefs[63] -= tri_consts[0] * b[47];
    coefs[20] = b[48];
    coefs[22] = -(tri_consts[1] * b[48]);
    coefs[23] = tri_consts[0] * b[48];
    coefs[24] -= tri_consts[0] * b[48];
    coefs[26] += tri_consts[3] * b[48];
    coefs[27] -= tri_consts[2] * b[48];
    coefs[28] += b[48];
    coefs[30] -= tri_consts[1] * b[48];
    coefs[31] += tri_consts[0] * b[48];
    coefs[36] -= tri_consts[0] * b[48];
    coefs[38] += tri_consts[3] * b[48];
    coefs[39] -= tri_consts[2] * b[48];
    coefs[40] += tri_consts[2] * b[48];
    coefs[42] -= tri_consts[6] * b[48];
    coefs[43] += tri_consts[4] * b[48];
    coefs[44] -= tri_consts[0] * b[48];
    coefs[46] += tri_consts[3] * b[48];
    coefs[47] -= tri_consts[2] * b[48];
    coefs[52] += b[48];
    coefs[54] -= tri_consts[1] * b[48];
    coefs[55] += tri_consts[0] * b[48];
    coefs[56] -= tri_consts[0] * b[48];
    coefs[58] += tri_consts[3] * b[48];
    coefs[59] -= tri_consts[2] * b[48];
    coefs[60] += b[48];
    coefs[62] -= tri_consts[1] * b[48];
    coefs[63] += tri_consts[0] * b[48];
    coefs[22] += tri_consts[1] * b[49];
    coefs[23] -= tri_consts[0] * b[49];
    coefs[26] -= tri_consts[3] * b[49];
    coefs[27] += tri_consts[2] * b[49];
    coefs[30] += tri_consts[1] * b[49];
    coefs[31] -= tri_consts[0] * b[49];
    coefs[38] -= tri_consts[3] * b[49];
    coefs[39] += tri_consts[2] * b[49];
    coefs[42] += tri_consts[6] * b[49];
    coefs[43] -= tri_consts[4] * b[49];
    coefs[46] -= tri_consts[3] * b[49];
    coefs[47] += tri_consts[2] * b[49];
    coefs[54] += tri_consts[1] * b[49];
    coefs[55] -= tri_consts[0] * b[49];
    coefs[58] -= tri_consts[3] * b[49];
    coefs[59] += tri_consts[2] * b[49];
    coefs[62] += tri_consts[1] * b[49];
    coefs[63] -= tri_consts[0] * b[49];
    coefs[24] -= b[50];
    coefs[26] += tri_consts[1] * b[50];
    coefs[27] -= tri_consts[0] * b[50];
    coefs[28] += b[50];
    coefs[30] -= tri_consts[1] * b[50];
    coefs[31] += tri_consts[0] * b[50];
    coefs[40] += tri_consts[0] * b[50];
    coefs[42] -= tri_consts[3] * b[50];
    coefs[43] += tri_consts[2] * b[50];
    coefs[44] -= tri_consts[0] * b[50];
    coefs[46] += tri_consts[3] * b[50];
    coefs[47] -= tri_consts[2] * b[50];
    coefs[56] -= b[50];
    coefs[58] += tri_consts[1] * b[50];
    coefs[59] -= tri_consts[0] * b[50];
    coefs[60] += b[50];
    coefs[62] -= tri_consts[1] * b[50];
    coefs[63] += tri_consts[0] * b[50];
    coefs[26] -= tri_consts[1] * b[51];
    coefs[27] += tri_consts[0] * b[51];
    coefs[30] += tri_consts[1] * b[51];
    coefs[31] -= tri_consts[0] * b[51];
    coefs[42] += tri_consts[3] * b[51];
    coefs[43] -= tri_consts[2] * b[51];
    coefs[46] -= tri_consts[3] * b[51];
    coefs[47] += tri_consts[2] * b[51];
    coefs[58] -= tri_consts[1] * b[51];
    coefs[59] += tri_consts[0] * b[51];
    coefs[62] += tri_consts[1] * b[51];
    coefs[63] -= tri_consts[0] * b[51];
    coefs[36] -= b[52];
    coefs[38] += tri_consts[1] * b[52];
    coefs[39] -= tri_consts[0] * b[52];
    coefs[40] += tri_consts[0] * b[52];
    coefs[42] -= tri_consts[3] * b[52];
    coefs[43] += tri_consts[2] * b[52];
    coefs[44] -= b[52];
    coefs[46] += tri_consts[1] * b[52];
    coefs[47] -= tri_consts[0] * b[52];
    coefs[52] += b[52];
    coefs[54] -= tri_consts[1] * b[52];
    coefs[55] += tri_consts[0] * b[52];
    coefs[56] -= tri_consts[0] * b[52];
    coefs[58] += tri_consts[3] * b[52];
    coefs[59] -= tri_consts[2] * b[52];
    coefs[60] += b[52];
    coefs[62] -= tri_consts[1] * b[52];
    coefs[63] += tri_consts[0] * b[52];
    coefs[38] -= tri_consts[1] * b[53];
    coefs[39] += tri_consts[0] * b[53];
    coefs[42] += tri_consts[3] * b[53];
    coefs[43] -= tri_consts[2] * b[53];
    coefs[46] -= tri_consts[1] * b[53];
    coefs[47] += tri_consts[0] * b[53];
    coefs[54] += tri_consts[1] * b[53];
    coefs[55] -= tri_consts[0] * b[53];
    coefs[58] -= tri_consts[3] * b[53];
    coefs[59] += tri_consts[2] * b[53];
    coefs[62] += tri_consts[1] * b[53];
    coefs[63] -= tri_consts[0] * b[53];
    coefs[40] += b[54];
    coefs[42] -= tri_consts[1] * b[54];
    coefs[43] += tri_consts[0] * b[54];
    coefs[44] -= b[54];
    coefs[46] += tri_consts[1] * b[54];
    coefs[47] -= tri_consts[0] * b[54];
    coefs[56] -= b[54];
    coefs[58] += tri_consts[1] * b[54];
    coefs[59] -= tri_consts[0] * b[54];
    coefs[60] += b[54];
    coefs[62] -= tri_consts[1] * b[54];
    coefs[63] += tri_consts[0] * b[54];
    coefs[42] += tri_consts[1] * b[55];
    coefs[43] -= tri_consts[0] * b[55];
    coefs[46] -= tri_consts[1] * b[55];
    coefs[47] += tri_consts[0] * b[55];
    coefs[58] -= tri_consts[1] * b[55];
    coefs[59] += tri_consts[0] * b[55];
    coefs[62] += tri_consts[1] * b[55];
    coefs[63] -= tri_consts[0] * b[55];
    coefs[21] = b[56];
    coefs[22] -= tri_consts[0] * b[56];
    coefs[23] += b[56];
    coefs[25] -= tri_consts[0] * b[56];
    coefs[26] += tri_consts[2] * b[56];
    coefs[27] -= tri_consts[0] * b[56];
    coefs[29] += b[56];
    coefs[30] -= tri_consts[0] * b[56];
    coefs[31] += b[56];
    coefs[37] -= tri_consts[0] * b[56];
    coefs[38] += tri_consts[2] * b[56];
    coefs[39] -= tri_consts[0] * b[56];
    coefs[41] += tri_consts[2] * b[56];
    coefs[42] -= tri_consts[4] * b[56];
    coefs[43] += tri_consts[2] * b[56];
    coefs[45] -= tri_consts[0] * b[56];
    coefs[46] += tri_consts[2] * b[56];
    coefs[47] -= tri_consts[0] * b[56];
    coefs[53] += b[56];
    coefs[54] -= tri_consts[0] * b[56];
    coefs[55] += b[56];
    coefs[57] -= tri_consts[0] * b[56];
    coefs[58] += tri_consts[2] * b[56];
    coefs[59] -= tri_consts[0] * b[56];
    coefs[61] += b[56];
    coefs[62] -= tri_consts[0] * b[56];
    coefs[63] += b[56];
    coefs[22] -= b[57];
    coefs[23] += b[57];
    coefs[26] += tri_consts[0] * b[57];
    coefs[27] -= tri_consts[0] * b[57];
    coefs[30] -= b[57];
    coefs[31] += b[57];
    coefs[38] += tri_consts[0] * b[57];
    coefs[39] -= tri_consts[0] * b[57];
    coefs[42] -= tri_consts[2] * b[57];
    coefs[43] += tri_consts[2] * b[57];
    coefs[46] += tri_consts[0] * b[57];
    coefs[47] -= tri_consts[0] * b[57];
    coefs[54] -= b[57];
    coefs[55] += b[57];
    coefs[58] += tri_consts[0] * b[57];
    coefs[59] -= tri_consts[0] * b[57];
    coefs[62] -= b[57];
    coefs[63] += b[57];
    coefs[25] -= b[58];
    coefs[26] += tri_consts[0] * b[58];
    coefs[27] -= b[58];
    coefs[29] += b[58];
    coefs[30] -= tri_consts[0] * b[58];
    coefs[31] += b[58];
    coefs[41] += tri_consts[0] * b[58];
    coefs[42] -= tri_consts[2] * b[58];
    coefs[43] += tri_consts[0] * b[58];
    coefs[45] -= tri_consts[0] * b[58];
    coefs[46] += tri_consts[2] * b[58];
    coefs[47] -= tri_consts[0] * b[58];
    coefs[57] -= b[58];
    coefs[58] += tri_consts[0] * b[58];
    coefs[59] -= b[58];
    coefs[61] += b[58];
    coefs[62] -= tri_consts[0] * b[58];
    coefs[63] += b[58];
    coefs[26] += b[59];
    coefs[27] -= b[59];
    coefs[30] -= b[59];
    coefs[31] += b[59];
    coefs[42] -= tri_consts[0] * b[59];
    coefs[43] += tri_consts[0] * b[59];
    coefs[46] += tri_consts[0] * b[59];
    coefs[47] -= tri_consts[0] * b[59];
    coefs[58] += b[59];
    coefs[59] -= b[59];
    coefs[62] -= b[59];
    coefs[63] += b[59];
    coefs[37] -= b[60];
    coefs[38] += tri_consts[0] * b[60];
    coefs[39] -= b[60];
    coefs[41] += tri_consts[0] * b[60];
    coefs[42] -= tri_consts[2] * b[60];
    coefs[43] += tri_consts[0] * b[60];
    coefs[45] -= b[60];
    coefs[46] += tri_consts[0] * b[60];
    coefs[47] -= b[60];
    coefs[53] += b[60];
    coefs[54] -= tri_consts[0] * b[60];
    coefs[55] += b[60];
    coefs[57] -= tri_consts[0] * b[60];
    coefs[58] += tri_consts[2] * b[60];
    coefs[59] -= tri_consts[0] * b[60];
    coefs[61] += b[60];
    coefs[62] -= tri_consts[0] * b[60];
    coefs[63] += b[60];
    coefs[38] += b[61];
    coefs[39] -= b[61];
    coefs[42] -= tri_consts[0] * b[61];
    coefs[43] += tri_consts[0] * b[61];
    coefs[46] += b[61];
    coefs[47] -= b[61];
    coefs[54] -= b[61];
    coefs[55] += b[61];
    coefs[58] += tri_consts[0] * b[61];
    coefs[59] -= tri_consts[0] * b[61];
    coefs[62] -= b[61];
    coefs[63] += b[61];
    coefs[41] += b[62];
    coefs[42] -= tri_consts[0] * b[62];
    coefs[43] += b[62];
    coefs[45] -= b[62];
    coefs[46] += tri_consts[0] * b[62];
    coefs[47] -= b[62];
    coefs[57] -= b[62];
    coefs[58] += tri_consts[0] * b[62];
    coefs[59] -= b[62];
    coefs[61] += b[62];
    coefs[62] -= tri_consts[0] * b[62];
    coefs[63] += b[62];
    coefs[42] -= b[63];
    coefs[43] += b[63];
    coefs[46] += b[63];
    coefs[47] -= b[63];
    coefs[58] += b[63];
    coefs[59] -= b[63];
    coefs[62] -= b[63];
    coefs[63] += b[63];

    return;
}


#if !defined( _GPUCODE ) && defined( __cplusplus )
}
#endif /* !defined( _GPUCODE ) && defined( __cplusplus ) */

#endif /* SIXTRACKLIB_COMMON_BE_TRICUB_COEFFICIENTS_C99_H__ */


