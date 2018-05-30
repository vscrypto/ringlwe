/* This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * See LICENSE for complete information.
 */
	
static const FFTSHORT W[512] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 7394, 9893, 5101, 3014, 9042, 2548, 7644, 10643, 7351, 9764, 4714, 1853, 5559, 4388, 875, 2625, 7875, 11336, 9430, 3712, 11136, 8830, 1912, 5736, 4919, 2468, 7404, 9923, 5191, 3284, 9852, 4978, 2645, 7935, 11516, 9970, 5332, 3707, 11121, 8785, 1777, 5331, 3704, 11112, 8758, 1696, 5088, 2975, 8925, 2197, 6591, 7484, 10163, 5911, 5444, 4043, 12129, 11809, 10849, 7969, 11618, 10276, 6250, 6461, 7094, 8993, 2401, 7203, 9320, 3382, 10146, 5860, 5291, 3584, 10752, 7678, 10745, 7657, 10682, 7468, 10115, 5767, 5012, 2747, 8241, 145, 435, 1305, 3915, 11745, 10657, 7393, 9890, 5092, 2987, 8961, 2305, 6915, 8456, 790, 2370, 7110, 9041, 2545, 7635, 10616, 7270, 9521, 3985, 11955, 11287, 9283, 3271, 9813, 4861, 2294, 6882, 8357, 493, 1479, 4437, 1022, 3066, 9198, 3016, 9048, 2566, 7698, 10805, 7837, 11222, 9088, 2686, 8058, 11885, 11077, 8653, 1381, 4143, 140, 420, 1260, 3780, 11340, 9442, 3748, 11244, 9154, 2884, 8652, 1378, 4134, 113, 339, 1017, 3051, 9153, 2881, 8643, 1351, 4053, 12159, 11899, 11119, 8779, 1759, 5277, 3542, 10626, 7300, 9611, 4255, 476, 1428, 4284, 563, 1689, 5067, 2912, 8736, 1630, 4890, 2381, 7143, 9140, 2842, 8526, 1000, 3000, 9000, 2422, 7266, 9509, 3949, 11847, 10963, 8311, 355, 1065, 3195, 9585, 4177, 242, 726, 2178, 6534, 7313, 9650, 4372, 827, 2481, 7443, 10040, 5542, 4337, 722, 2166, 6498, 7205, 9326, 3400, 10200, 6022, 5777, 5042, 2837, 8511, 955, 2865, 8595, 1207, 3621, 10863, 8011, 11744, 10654, 7384, 9863, 5011, 2744, 8232, 118, 354, 1062, 3186, 9558, 4096, 12288, 12286, 12280, 12262, 12208, 12046, 11560, 10102, 5728, 4895, 2396, 7188, 9275, 3247, 9741, 4645, 1646, 4938, 2525, 7575, 10436, 6730, 7901, 11414, 9664, 4414, 953, 2859, 8577, 1153, 3459, 10377, 6553, 7370, 9821, 4885, 2366, 7098, 9005, 2437, 7311, 9644, 4354, 773, 2319, 6957, 8582, 1168, 3504, 10512, 6958, 8585, 1177, 3531, 10593, 7201, 9314, 3364, 10092, 5698, 4805, 2126, 6378, 6845, 8246, 160, 480, 1440, 4320, 671, 2013, 6039, 5828, 5195, 3296, 9888, 5086, 2969, 8907, 2143, 6429, 6998, 8705, 1537, 4611, 1544, 4632, 1607, 4821, 2174, 6522, 7277, 9542, 4048, 12144, 11854, 10984, 8374, 544, 1632, 4896, 2399, 7197, 9302, 3328, 9984, 5374, 3833, 11499, 9919, 5179, 3248, 9744, 4654, 1673, 5019, 2768, 8304, 334, 1002, 3006, 9018, 2476, 7428, 9995, 5407, 3932, 11796, 10810, 7852, 11267, 9223, 3091, 9273, 3241, 9723, 4591, 1484, 4452, 1067, 3201, 9603, 4231, 404, 1212, 3636, 10908, 8146, 12149, 11869, 11029, 8509, 949, 2847, 8541, 1045, 3135, 9405, 3637, 10911, 8155, 12176, 11950, 11272, 9238, 3136, 9408, 3646, 10938, 8236, 130, 390, 1170, 3510, 10530, 7012, 8747, 1663, 4989, 2678, 8034, 11813, 10861, 8005, 11726, 10600, 7222, 9377, 3553, 10659, 7399, 9908, 5146, 3149, 9447, 3763, 11289, 9289, 3289, 9867, 5023, 2780, 8340, 442, 1326, 3978, 11934, 11224, 9094, 2704, 8112, 12047, 11563, 10111, 5755, 4976, 2639, 7917, 11462, 9808, 4846, 2249, 6747, 7952, 11567, 10123, 5791, 5084, 2963, 8889, 2089, 6267, 6512, 7247, 9452, 3778, 11334, 9424, 3694, 11082, 8668, 1426, 4278, 545, 1635, 4905, 2426, 7278, 9545, 4057, 12171, 11935, 11227, 9103, 2731, 8193};

static const FFTSHORT W_rev[512] = {1, 8193, 2731, 9103, 11227, 11935, 12171, 4057, 9545, 7278, 2426, 4905, 1635, 545, 4278, 1426, 8668, 11082, 3694, 9424, 11334, 3778, 9452, 7247, 6512, 6267, 2089, 8889, 2963, 5084, 5791, 10123, 11567, 7952, 6747, 2249, 4846, 9808, 11462, 7917, 2639, 4976, 5755, 10111, 11563, 12047, 8112, 2704, 9094, 11224, 11934, 3978, 1326, 442, 8340, 2780, 5023, 9867, 3289, 9289, 11289, 3763, 9447, 3149, 5146, 9908, 7399, 10659, 3553, 9377, 7222, 10600, 11726, 8005, 10861, 11813, 8034, 2678, 4989, 1663, 8747, 7012, 10530, 3510, 1170, 390, 130, 8236, 10938, 3646, 9408, 3136, 9238, 11272, 11950, 12176, 8155, 10911, 3637, 9405, 3135, 1045, 8541, 2847, 949, 8509, 11029, 11869, 12149, 8146, 10908, 3636, 1212, 404, 4231, 9603, 3201, 1067, 4452, 1484, 4591, 9723, 3241, 9273, 3091, 9223, 11267, 7852, 10810, 11796, 3932, 5407, 9995, 7428, 2476, 9018, 3006, 1002, 334, 8304, 2768, 5019, 1673, 4654, 9744, 3248, 5179, 9919, 11499, 3833, 5374, 9984, 3328, 9302, 7197, 2399, 4896, 1632, 544, 8374, 10984, 11854, 12144, 4048, 9542, 7277, 6522, 2174, 4821, 1607, 4632, 1544, 4611, 1537, 8705, 6998, 6429, 2143, 8907, 2969, 5086, 9888, 3296, 5195, 5828, 6039, 2013, 671, 4320, 1440, 480, 160, 8246, 6845, 6378, 2126, 4805, 5698, 10092, 3364, 9314, 7201, 10593, 3531, 1177, 8585, 6958, 10512, 3504, 1168, 8582, 6957, 2319, 773, 4354, 9644, 7311, 2437, 9005, 7098, 2366, 4885, 9821, 7370, 6553, 10377, 3459, 1153, 8577, 2859, 953, 4414, 9664, 11414, 7901, 6730, 10436, 7575, 2525, 4938, 1646, 4645, 9741, 3247, 9275, 7188, 2396, 4895, 5728, 10102, 11560, 12046, 12208, 12262, 12280, 12286, 12288, 4096, 9558, 3186, 1062, 354, 118, 8232, 2744, 5011, 9863, 7384, 10654, 11744, 8011, 10863, 3621, 1207, 8595, 2865, 955, 8511, 2837, 5042, 5777, 6022, 10200, 3400, 9326, 7205, 6498, 2166, 722, 4337, 5542, 10040, 7443, 2481, 827, 4372, 9650, 7313, 6534, 2178, 726, 242, 4177, 9585, 3195, 1065, 355, 8311, 10963, 11847, 3949, 9509, 7266, 2422, 9000, 3000, 1000, 8526, 2842, 9140, 7143, 2381, 4890, 1630, 8736, 2912, 5067, 1689, 563, 4284, 1428, 476, 4255, 9611, 7300, 10626, 3542, 5277, 1759, 8779, 11119, 11899, 12159, 4053, 1351, 8643, 2881, 9153, 3051, 1017, 339, 113, 4134, 1378, 8652, 2884, 9154, 11244, 3748, 9442, 11340, 3780, 1260, 420, 140, 4143, 1381, 8653, 11077, 11885, 8058, 2686, 9088, 11222, 7837, 10805, 7698, 2566, 9048, 3016, 9198, 3066, 1022, 4437, 1479, 493, 8357, 6882, 2294, 4861, 9813, 3271, 9283, 11287, 11955, 3985, 9521, 7270, 10616, 7635, 2545, 9041, 7110, 2370, 790, 8456, 6915, 2305, 8961, 2987, 5092, 9890, 7393, 10657, 11745, 3915, 1305, 435, 145, 8241, 2747, 5012, 5767, 10115, 7468, 10682, 7657, 10745, 7678, 10752, 3584, 5291, 5860, 10146, 3382, 9320, 7203, 2401, 8993, 7094, 6461, 6250, 10276, 11618, 7969, 10849, 11809, 12129, 4043, 5444, 5911, 10163, 7484, 6591, 2197, 8925, 2975, 5088, 1696, 8758, 11112, 3704, 5331, 1777, 8785, 11121, 3707, 5332, 9970, 11516, 7935, 2645, 4978, 9852, 3284, 5191, 9923, 7404, 2468, 4919, 5736, 1912, 8830, 11136, 3712, 9430, 11336, 7875, 2625, 875, 4388, 5559, 1853, 4714, 9764, 7351, 10643, 7644, 2548, 9042, 3014, 5101, 9893, 7394, 6561, 2187, 729, 243, 81, 27, 9, 3};

static const FFTSHORT W_sqrt[256] = {10968, 8326, 400, 1200, 3600, 10800, 7822, 11177, 8953, 2281, 6843, 8240, 142, 426, 1278, 3834, 11502, 9928, 5206, 3329, 9987, 5383, 3860, 11580, 10162, 5908, 5435, 4016, 12048, 11566, 10120, 5782, 5057, 2882, 8646, 1360, 4080, 12240, 12142, 11848, 10966, 8320, 382, 1146, 3438, 10314, 6364, 6803, 8120, 12071, 11635, 10327, 6403, 6920, 8471, 835, 2505, 7515, 10256, 6190, 6281, 6554, 7373, 9830, 4912, 2447, 7341, 9734, 4624, 1583, 4749, 1958, 5874, 5333, 3710, 11130, 8812, 1858, 5574, 4433, 1010, 3030, 9090, 2692, 8076, 11939, 11239, 9139, 2839, 8517, 973, 2919, 8757, 1693, 5079, 2948, 8844, 1954, 5862, 5297, 3602, 10806, 7840, 11231, 9115, 2767, 8301, 325, 975, 2925, 8775, 1747, 5241, 3434, 10302, 6328, 6695, 7796, 11099, 8719, 1579, 4737, 1922, 5766, 5009, 2738, 8214, 64, 192, 576, 1728, 5184, 3263, 9789, 4789, 2078, 6234, 6413, 6950, 8561, 1105, 3315, 9945, 5257, 3482, 10446, 6760, 7991, 11684, 10474, 6844, 8243, 151, 453, 1359, 4077, 12231, 12115, 11767, 10723, 7591, 10484, 6874, 8333, 421, 1263, 3789, 11367, 9523, 3991, 11973, 11341, 9445, 3757, 11271, 9235, 3127, 9381, 3565, 10695, 7507, 10232, 6118, 6065, 5906, 5429, 3998, 11994, 11404, 9634, 4324, 683, 2049, 6147, 6152, 6167, 6212, 6347, 6752, 7967, 11612, 10258, 6196, 6299, 6608, 7535, 10316, 6370, 6821, 8174, 12233, 12121, 11785, 10777, 7753, 10970, 8332, 418, 1254, 3762, 11286, 9280, 3262, 9786, 4780, 2051, 6153, 6170, 6221, 6374, 6833, 8210, 52, 156, 468, 1404, 4212, 347, 1041, 3123, 9369, 3529, 10587, 7183, 9260, 3202, 9606, 4240, 431, 1293, 3879, 11637, 10333, 6421, 6974, 8633};

static const FFTSHORT W_sqrt_rev[256] = {3656, 5315, 5868, 1956, 652, 8410, 10996, 11858, 8049, 2683, 9087, 3029, 5106, 1702, 8760, 2920, 9166, 11248, 11942, 8077, 10885, 11821, 12133, 12237, 4079, 5456, 5915, 6068, 6119, 6136, 10238, 7509, 2503, 9027, 3009, 1003, 8527, 11035, 11871, 3957, 1319, 4536, 1512, 504, 168, 56, 4115, 5468, 5919, 1973, 4754, 5681, 5990, 6093, 2031, 677, 4322, 5537, 5942, 6077, 6122, 6137, 6142, 10240, 11606, 7965, 2655, 885, 295, 8291, 6860, 6383, 6224, 6171, 2057, 4782, 1594, 8724, 2908, 9162, 3054, 1018, 8532, 2844, 948, 316, 8298, 2766, 922, 8500, 11026, 11868, 3956, 5415, 1805, 4698, 1566, 522, 174, 58, 8212, 10930, 11836, 12138, 4046, 5445, 1815, 605, 4298, 5529, 1843, 8807, 7032, 2344, 8974, 11184, 3728, 5339, 5876, 6055, 10211, 7500, 2500, 9026, 7105, 10561, 11713, 12097, 12225, 4075, 9551, 7280, 6523, 10367, 7552, 10710, 3570, 1190, 4493, 5594, 5961, 1987, 8855, 7048, 10542, 3514, 9364, 11314, 11964, 3988, 9522, 3174, 1058, 4449, 1483, 8687, 6992, 6427, 10335, 3445, 9341, 7210, 10596, 3532, 9370, 11316, 3772, 9450, 3150, 1050, 350, 4213, 9597, 3199, 9259, 11279, 7856, 6715, 10431, 3477, 1159, 8579, 6956, 6415, 10331, 7540, 10706, 7665, 2555, 4948, 9842, 7377, 2459, 4916, 5735, 6008, 6099, 2033, 4774, 9784, 11454, 3818, 5369, 5886, 1962, 654, 218, 4169, 5486, 5925, 1975, 8851, 11143, 11907, 3969, 1323, 441, 147, 49, 8209, 10929, 3643, 9407, 7232, 6507, 2169, 723, 241, 8273, 6854, 6381, 2127, 709, 8429, 6906, 2302, 8960, 7083, 2361, 787, 8455, 11011, 11863, 12147, 4049, 5446, 10008, 3336, 1112, 4467, 1489, 8689, 11089, 11889, 3963, 1321};
