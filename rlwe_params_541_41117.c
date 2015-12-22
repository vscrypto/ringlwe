/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */
	
#include <inttypes.h>
#include "rlwe_params_541_41117.h"

const RINGELT m = 541, muwords = 9; /* key (mu) is m-1 bits */

const RINGELT q = 41117, qmod4 = 1;

const RINGELT B = 5, BB = 11, LOG2B = 4, BMASK = 0xf;

const RINGELT small_coeff_table[11] = {41112, 41113, 41114, 41115, 41116, 0, 1, 2, 3, 4, 5};

const RINGELT q_1_4 = 10279, q_2_4 = 20558, q_3_4 = 30838;
const RINGELT r0_l = 15418, r0_u = 35978, r1_l = 5138, r1_u = 25699;	


/* Public Parameter a. Each a parameter rejection sampled from non-overlapping
 * segments of the digits of e.
 * Note that this is held in the FFT / CRT basis.*/
const RINGELT a[541] = {
        0X54AE, 0X461F, 0X35D1, 0X76F5, 0X0BFE, 0X4AD8, 0X772B, 0X0943, 
        0X323D, 0X7448, 0X2328, 0X02D0, 0X57F8, 0X70EC, 0X97B8, 0X7088, 
        0X4BA5, 0X9E59, 0X467C, 0X71CC, 0X4AA7, 0X78F1, 0X8623, 0X1813, 
        0X08C1, 0X7D1E, 0X601E, 0X230A, 0X2471, 0X4C8C, 0X8509, 0X63DD, 
        0X7C1F, 0X2935, 0X5C50, 0X8DAF, 0X3783, 0X451E, 0X3605, 0X4CB1, 
        0X9D4B, 0X6952, 0X8B7F, 0X98EC, 0X7D6E, 0X7579, 0X43C9, 0X22F1, 
        0X36D5, 0X23BB, 0X6FCC, 0X8E94, 0X8580, 0X0BB5, 0X14BA, 0X04EE, 
        0X9AD0, 0X3E3D, 0X731F, 0X8949, 0X587E, 0X7F0F, 0X9295, 0X55CF, 
        0X0BD5, 0X229B, 0X5F9F, 0X59D4, 0X4B3B, 0X6F2B, 0X4A34, 0X9FE5, 
        0X6E8E, 0X7A97, 0X03EA, 0X36AE, 0X8920, 0X624A, 0X5091, 0X2776, 
        0X4992, 0X1B7A, 0X0E43, 0X29F4, 0X9AC3, 0X30B3, 0X553A, 0X8124, 
        0X08C2, 0X1950, 0X54B5, 0X954A, 0X6252, 0X74C9, 0X8BE0, 0X5B8D, 
        0X92C0, 0X286B, 0X4455, 0X3E90, 0X2DB2, 0X2AB3, 0X43E3, 0X87AF, 
        0X6900, 0X047E, 0X3B18, 0X8E94, 0X8843, 0X17F4, 0X4C0E, 0X26F8, 
        0X71B7, 0X9C53, 0X58C1, 0X96C1, 0X1F12, 0X1681, 0X0872, 0X06C3, 
        0X21A1, 0X4BD8, 0X7105, 0X65E7, 0X273D, 0X56FA, 0X5B6A, 0X6639, 
        0X4671, 0X9C67, 0X900F, 0X182A, 0X7967, 0X63C4, 0X18EF, 0X42C8, 
        0X8E29, 0X84A7, 0X1184, 0X02F6, 0X062B, 0X5ABC, 0X141F, 0X2EC8, 
        0X28D1, 0X715D, 0X5C4D, 0X046F, 0X552A, 0X128E, 0X1EF5, 0X153D, 
        0X541F, 0X57F1, 0X97A2, 0X4CAC, 0X1B08, 0X9F83, 0X52BA, 0X68C4, 
        0X698E, 0X5BC4, 0X2EDA, 0X926C, 0X9FEB, 0X0A9C, 0X2359, 0X9FDA, 
        0X883D, 0X6D1B, 0X3B02, 0X5B6F, 0X5F81, 0X9BA4, 0X3B5D, 0X5C09, 
        0X7B71, 0X5284, 0X18F5, 0X7F41, 0X6C6E, 0X6C0B, 0X53A8, 0X9155, 
        0X29B2, 0X608F, 0X4A72, 0X78C2, 0X514A, 0X262A, 0X4B4A, 0X3C78, 
        0X52D1, 0X4B41, 0X8F86, 0X37AA, 0X4A86, 0X44AE, 0X4E45, 0X8AB0, 
        0X124F, 0X08F9, 0X1F70, 0X513F, 0X08CE, 0X6D76, 0X37D1, 0X0528, 
        0X368E, 0X152F, 0X6409, 0X4045, 0X9539, 0X6F38, 0X4B0A, 0X90CC, 
        0X73AE, 0X188F, 0X984E, 0X4913, 0X1953, 0X4278, 0X9C3D, 0X45BE, 
        0X64DB, 0X50C5, 0X1158, 0X1A90, 0X69BF, 0X0EBC, 0X1AFE, 0X6F7D, 
        0X3E2C, 0X9F21, 0X1328, 0X0FC1, 0X0599, 0X6980, 0X4941, 0X52A2, 
        0X6D18, 0X5694, 0X596F, 0X5C93, 0X0D33, 0X6F64, 0X4D1C, 0X1A47, 
        0X7BC0, 0X1C99, 0X9794, 0X3856, 0X3B72, 0X7CF5, 0X30E4, 0X2D23, 
        0X0FE1, 0X84D4, 0X1135, 0X01D7, 0X8883, 0X8ACC, 0X659B, 0X9627, 
        0X3D72, 0X8344, 0X9F8E, 0X315F, 0X05FB, 0X1965, 0X99A7, 0X294D, 
        0X09DB, 0XA04C, 0X21E3, 0X2FD9, 0X3CF2, 0X23C5, 0X7242, 0X41F6, 
        0X5862, 0X1E4E, 0XA066, 0X0DE9, 0X4AE7, 0X9861, 0X43D5, 0X0BCF, 
        0X239B, 0X25FC, 0X7AB6, 0X5829, 0X2235, 0X0FA0, 0X759A, 0X587F, 
        0X4DF8, 0X1EEB, 0X259D, 0X2D33, 0X229F, 0X52A6, 0X063F, 0X2B63, 
        0X3363, 0X0CB6, 0X1660, 0X2063, 0X9CEA, 0X8333, 0X298B, 0X983B, 
        0X8B83, 0X4E08, 0X43BF, 0X6DF8, 0X41A0, 0X3786, 0XA066, 0X7E47, 
        0X9966, 0X6A2E, 0X5DF7, 0X7CB7, 0X1A67, 0X6EDF, 0X4A2D, 0X6CD1, 
        0X5C26, 0X6C4E, 0X70B3, 0X8616, 0X6F28, 0X284C, 0X02EC, 0X3543, 
        0X25EA, 0X3E31, 0X21C8, 0X79CF, 0X7CEF, 0X19E0, 0X6E50, 0X39DC, 
        0X81B4, 0X7933, 0X8C92, 0X50E7, 0X93A4, 0X1ED1, 0X1A93, 0X2949, 
        0X0B92, 0X9F2D, 0X475A, 0X5576, 0X281C, 0X8B1C, 0X6D5E, 0X7BF2, 
        0X5FFA, 0X5AFB, 0X4CE9, 0X2A18, 0X26CA, 0X4E56, 0X5C61, 0X0CC7, 
        0X1DB4, 0X5B87, 0X21ED, 0X786E, 0X7B27, 0X667A, 0X2E55, 0X0730, 
        0X56E8, 0X8A82, 0X111C, 0X339C, 0X10B8, 0X0C17, 0X71F4, 0X4DA2, 
        0X0819, 0X4166, 0X5B67, 0X941B, 0X150A, 0X435E, 0X3CF1, 0X8508, 
        0X12B0, 0X191F, 0X5E33, 0X95CF, 0X5DF6, 0X4B2D, 0X9C5B, 0X203E, 
        0X04D7, 0X17E2, 0X2F89, 0X17ED, 0X0AD6, 0X9947, 0X651E, 0X782C, 
        0X1AFE, 0X5070, 0X9848, 0X2F55, 0X6CFF, 0X65E0, 0X8D55, 0X2A7D, 
        0X7436, 0X6CFE, 0X4453, 0X903D, 0X4839, 0X2C96, 0X6AE3, 0X95C9, 
        0X299A, 0X16DA, 0X3DDF, 0X8682, 0X91A6, 0X76E4, 0X5779, 0X45AD, 
        0X2520, 0X73A0, 0X74EF, 0X44F9, 0X1D46, 0X3FDF, 0X3C4C, 0X1335, 
        0X4889, 0X9F8E, 0X5586, 0X6605, 0X5999, 0X7F1C, 0X6181, 0X20D1, 
        0X707C, 0X11A7, 0X3462, 0X404C, 0X8019, 0X1244, 0X14C5, 0X09BD, 
        0X505B, 0X9769, 0X95FE, 0X6280, 0X3AF1, 0X4393, 0X64EE, 0X1971, 
        0X7DB2, 0X76A1, 0X0EA1, 0X1BBA, 0X5395, 0X3983, 0X8EE9, 0X2E25, 
        0X54E4, 0X68C1, 0X48F1, 0X30E7, 0X4A24, 0X6489, 0X7D47, 0X357F, 
        0X3D88, 0X8E7C, 0X0D54, 0XA08E, 0X051A, 0X2547, 0X2639, 0X6A5F, 
        0X3954, 0X850B, 0X2CBE, 0X6143, 0X5467, 0X397C, 0X6B91, 0X3E55, 
        0X2E81, 0X82B2, 0X5B36, 0X766A, 0X9B52, 0X384A, 0X3371, 0X0C0F, 
        0X9027, 0X924A, 0X7345, 0X1F7A, 0X42F6, 0X306B, 0X76E8, 0X3883, 
        0X837F, 0X3A58, 0X4939, 0X9846, 0XA033, 0X5759, 0X80C4, 0X89C8, 
        0X7D3E, 0X5E20, 0X2363, 0X9C53, 0X4DCE, 0X26C0, 0X545E, 0X7761, 
        0X48D0, 0X9186, 0X7822, 0X6457, 0X14B7, 0X92A8, 0X8A07, 0X920E, 
        0X59E8, 0X0C47, 0X5E99, 0X0979, 0X0C75
        };

