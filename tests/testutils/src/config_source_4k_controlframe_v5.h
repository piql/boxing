// *****************************************************************************
// ** This file is generated automatically by convertxmltocsource application **
// *****************************************************************************

#if !defined(CONFIG_SOURCE_DEFINITIONS)
#define CONFIG_SOURCE_DEFINITIONS
#define CONFIG_ARRAY_SIZE(a)   sizeof(a) / sizeof(a[0])

typedef struct config_pair_s
{
    const char* key;
    const char* value;
}config_pair;

typedef struct config_class_s
{
    const char* name;
    const char* version;
    config_pair * pairs;
    unsigned int count;
}config_class;

typedef struct config_structure_s
{
    const char * version;
    config_class * classes;
    const unsigned int count;
}config_structure;

#endif // CONFIG_SOURCE_DEFINITIONS

config_pair pairsFormatInfo_v5_1[] =
{
    { "name", "4k-controlframe-v5" },
    { "shortDescription", "4k control data frame format" },
    { "description", "Frames are generated using the Generic Preservation Format v1.0 printed on a 4096x2160 raster" }
};

config_pair pairsFrameFormat_v5_2[] =
{
    { "type", "GPFv1.0" },
    { "width", "1024" },
    { "height", "540" },
    { "border", "1" },
    { "borderGap", "1" },
    { "cornerMarkSize", "32" },
    { "cornerMarkGap", "1" },
    { "tilesPerColumn", "4" },
    /*  color dept = log2(maxLevelsPerSymbol) */
    { "maxLevelsPerSymbol", "2" }
};

config_pair pairsFrameRaster_v5_3[] =
{
    { "width", "4096" },
    { "height", "2160" },
    { "scalingFactor", "4" }
};

config_pair pairsCodecDispatcher_v5_4[] =
{
    /*  Frame coding scheme */
    /*  The order the encoder process is specified, default value: encode */
    { "order", "decode" },
    /*  symbol alignment default: bit */
    { "symbolAlignment", "byte" },
    { "DataCodingScheme", "SyncPointInserter,Modulator,Cipher,Interleaving_inner,ReedSolomon_inner,Interleaving_outer,ReedSolomon_outer" },
    { "MetadataCodingScheme", "MetaData_Modulator,MetaData_Cipher,MetaData_ReedSolomon" }
};

config_pair pairsReedSolomon_outer_v5_5[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "172" }
};

config_pair pairsInterleaving_outer_v5_6[] =
{
    { "codec", "Interleaving" },
    { "distance", "192" },
    /*  interleaving symboltype; block, frame */
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte, bit */
    { "symboltype", "byte" }
};

config_pair pairsReedSolomon_inner_v5_7[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "16" },
    { "messageSize", "192" }
};

config_pair pairsInterleaving_inner_v5_8[] =
{
    { "codec", "Interleaving" },
    { "distance", "239" },
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte, bit */
    { "symboltype", "byte" }
};

config_pair pairsCipher_v5_9[] =
{
    { "codec", "Cipher" },
    /*  chipher key ; 'auto' , 'any number supported by the chiper class' */
    { "key", "auto" }
};

config_pair pairsModulator_v5_10[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsSyncPointInserter_v5_11[] =
{
    { "codec", "SyncPointInserter" },
    { "SyncPointDistancePixel", "100" },
    { "SyncPointRadiusPixel", "2" },
    { "DataOrientation", "1" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsMetaData_ReedSolomon_v5_12[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "99" },
    /* <property key="messageSize" value="32"/> */

};

config_pair pairsMetaData_Modulator_v5_13[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsMetaData_Cipher_v5_14[] =
{
    { "codec", "Cipher" },
    /*  chipher key ; 'auto' , 'any number supported by the chiper class' */
    { "key", "1" }
};

config_pair pairscrc64_v5_15[] =
{
    { "POLY64REV", "0x42F0E1EBA9EA3693" },
    { "INITIALCRC", "0x0000000000000000" }
};

config_pair pairscrc32_v5_16[] =
{
    { "POLY32REV", "0x42F0E1EBA9EA3693" },
    { "INITIALCRC", "0x0000000000000000" }
};

config_class config_classes_v5[] =
{
    { "FormatInfo", NULL, pairsFormatInfo_v5_1, CONFIG_ARRAY_SIZE(pairsFormatInfo_v5_1) },
    { "FrameFormat", NULL, pairsFrameFormat_v5_2, CONFIG_ARRAY_SIZE(pairsFrameFormat_v5_2) },
    { "FrameRaster", NULL, pairsFrameRaster_v5_3, CONFIG_ARRAY_SIZE(pairsFrameRaster_v5_3) },
    { "CodecDispatcher", NULL, pairsCodecDispatcher_v5_4, CONFIG_ARRAY_SIZE(pairsCodecDispatcher_v5_4) },
    { "ReedSolomon_outer", NULL, pairsReedSolomon_outer_v5_5, CONFIG_ARRAY_SIZE(pairsReedSolomon_outer_v5_5) },
    { "Interleaving_outer", NULL, pairsInterleaving_outer_v5_6, CONFIG_ARRAY_SIZE(pairsInterleaving_outer_v5_6) },
    { "ReedSolomon_inner", NULL, pairsReedSolomon_inner_v5_7, CONFIG_ARRAY_SIZE(pairsReedSolomon_inner_v5_7) },
    { "Interleaving_inner", NULL, pairsInterleaving_inner_v5_8, CONFIG_ARRAY_SIZE(pairsInterleaving_inner_v5_8) },
    { "Cipher", NULL, pairsCipher_v5_9, CONFIG_ARRAY_SIZE(pairsCipher_v5_9) },
    { "Modulator", NULL, pairsModulator_v5_10, CONFIG_ARRAY_SIZE(pairsModulator_v5_10) },
    { "SyncPointInserter", NULL, pairsSyncPointInserter_v5_11, CONFIG_ARRAY_SIZE(pairsSyncPointInserter_v5_11) },
    { "MetaData_ReedSolomon", NULL, pairsMetaData_ReedSolomon_v5_12, CONFIG_ARRAY_SIZE(pairsMetaData_ReedSolomon_v5_12) },
    { "MetaData_Modulator", NULL, pairsMetaData_Modulator_v5_13, CONFIG_ARRAY_SIZE(pairsMetaData_Modulator_v5_13) },
    { "MetaData_Cipher", NULL, pairsMetaData_Cipher_v5_14, CONFIG_ARRAY_SIZE(pairsMetaData_Cipher_v5_14) },
    { "crc64", NULL, pairscrc64_v5_15, CONFIG_ARRAY_SIZE(pairscrc64_v5_15) },
    { "crc32", NULL, pairscrc32_v5_16, CONFIG_ARRAY_SIZE(pairscrc32_v5_16) }};

config_structure config_source_v5 = { "1.0.0.0", config_classes_v5, CONFIG_ARRAY_SIZE(config_classes_v5) };
