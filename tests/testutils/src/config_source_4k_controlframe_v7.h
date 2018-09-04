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

config_pair pairsFormatInfo_v7_1[] =
{
    { "name", "4k-controlframe-v7" },
    { "shortDescription", "4k control data frame format" },
    { "description", "Frames are generated using the Generic Preservation Format v1.1 printed on a 4096x2160 raster" }
};

config_pair pairsFrameFormat_v7_2[] =
{
    { "type", "GPFv1.1" },
    { "width", "1024" },
    { "height", "540" },
    { "border", "1" },
    { "borderGap", "1" },
    { "cornerMarkSize", "32" },
    { "cornerMarkGap", "1" },
    { "tilesPerColumn", "4" },
    { "refBarSyncDistance", "66" },
    { "refBarSyncOffset", "16" },
    /*  color dept = log2(maxLevelsPerSymbol) */
    { "maxLevelsPerSymbol", "2" }
};

config_pair pairsFrameRaster_v7_3[] =
{
    { "width", "4096" },
    { "height", "2160" },
    { "scalingFactor", "4" }
};

config_pair pairsCodecDispatcher_v7_4[] =
{
    /*  Frame coding scheme */
    { "version", "1.0" },
    /*  The order the encoder process is specified, default value: encode */
    { "order", "decode" },
    /*  symbol alignment default: bit */
    { "symbolAlignment", "byte" },
    { "DataCodingScheme", "SyncPointInserter,Modulator,Cipher,FInterleave,RS_inner,XInterleave,RS_outer,CRC,PacketHeader" },
    { "MetadataCodingScheme", "MetaData_Modulator,MetaData_Cipher,MetaData_XInterleave,MetaData_ReedSolomon,MetaData_CRC,PacketHeader" }
};

config_pair pairsPacketHeader_v7_5[] =
{
    { "codec", "PacketHeader" }
};

config_pair pairsCRC_v7_6[] =
{
    { "codec", "CRC64" },
    { "polynom", "0x42F0E1EBA9EA3693" },
    { "seed", "0x0000000000000000" }
};

config_pair pairsRS_outer_v7_7[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "172" }
};

config_pair pairsXInterleave_v7_8[] =
{
    { "codec", "Interleaving" },
    { "distance", "192" },
    /*  interleaving symboltype; block, frame */
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte, bit */
    { "symboltype", "byte" }
};

config_pair pairsRS_inner_v7_9[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "16" },
    { "messageSize", "192" }
};

config_pair pairsFInterleave_v7_10[] =
{
    { "codec", "Interleaving" },
    { "distance", "239" },
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte, bit */
    { "symboltype", "byte" }
};

config_pair pairsCipher_v7_11[] =
{
    { "codec", "Cipher" },
    /*  chipher key ; 'auto' , 'any number supported by the chiper class' */
    { "key", "auto" }
};

config_pair pairsModulator_v7_12[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsSyncPointInserter_v7_13[] =
{
    { "codec", "SyncPointInserter" },
    { "SyncPointDistancePixel", "100" },
    { "SyncPointRadiusPixel", "2" },
    { "DataOrientation", "1" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsMetaData_CRC_v7_14[] =
{
    { "codec", "CRC32" },
    { "polynom", "0x1EDC6F41" },
    { "seed", "0x00000000" }
};

config_pair pairsMetaData_ReedSolomon_v7_15[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "99" }
};

config_pair pairsMetaData_XInterleave_v7_16[] =
{
    { "codec", "Interleaving" },
    { "distance", "247" },
    /*  interleaving symboltype; block, frame */
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsMetaData_Modulator_v7_17[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsMetaData_Cipher_v7_18[] =
{
    { "codec", "Cipher" },
    /*  chipher key ; 'auto' , 'any number supported by the chiper class' */
    { "key", "1" }
};

config_class config_classes_v7[] =
{
    { "FormatInfo", NULL, pairsFormatInfo_v7_1, CONFIG_ARRAY_SIZE(pairsFormatInfo_v7_1) },
    { "FrameFormat", NULL, pairsFrameFormat_v7_2, CONFIG_ARRAY_SIZE(pairsFrameFormat_v7_2) },
    { "FrameRaster", NULL, pairsFrameRaster_v7_3, CONFIG_ARRAY_SIZE(pairsFrameRaster_v7_3) },
    { "CodecDispatcher", NULL, pairsCodecDispatcher_v7_4, CONFIG_ARRAY_SIZE(pairsCodecDispatcher_v7_4) },
    { "PacketHeader", NULL, pairsPacketHeader_v7_5, CONFIG_ARRAY_SIZE(pairsPacketHeader_v7_5) },
    { "CRC", NULL, pairsCRC_v7_6, CONFIG_ARRAY_SIZE(pairsCRC_v7_6) },
    { "RS_outer", NULL, pairsRS_outer_v7_7, CONFIG_ARRAY_SIZE(pairsRS_outer_v7_7) },
    { "XInterleave", NULL, pairsXInterleave_v7_8, CONFIG_ARRAY_SIZE(pairsXInterleave_v7_8) },
    { "RS_inner", NULL, pairsRS_inner_v7_9, CONFIG_ARRAY_SIZE(pairsRS_inner_v7_9) },
    { "FInterleave", NULL, pairsFInterleave_v7_10, CONFIG_ARRAY_SIZE(pairsFInterleave_v7_10) },
    { "Cipher", NULL, pairsCipher_v7_11, CONFIG_ARRAY_SIZE(pairsCipher_v7_11) },
    { "Modulator", NULL, pairsModulator_v7_12, CONFIG_ARRAY_SIZE(pairsModulator_v7_12) },
    { "SyncPointInserter", NULL, pairsSyncPointInserter_v7_13, CONFIG_ARRAY_SIZE(pairsSyncPointInserter_v7_13) },
    { "MetaData_CRC", NULL, pairsMetaData_CRC_v7_14, CONFIG_ARRAY_SIZE(pairsMetaData_CRC_v7_14) },
    { "MetaData_ReedSolomon", NULL, pairsMetaData_ReedSolomon_v7_15, CONFIG_ARRAY_SIZE(pairsMetaData_ReedSolomon_v7_15) },
    { "MetaData_XInterleave", NULL, pairsMetaData_XInterleave_v7_16, CONFIG_ARRAY_SIZE(pairsMetaData_XInterleave_v7_16) },
    { "MetaData_Modulator", NULL, pairsMetaData_Modulator_v7_17, CONFIG_ARRAY_SIZE(pairsMetaData_Modulator_v7_17) },
    { "MetaData_Cipher", NULL, pairsMetaData_Cipher_v7_18, CONFIG_ARRAY_SIZE(pairsMetaData_Cipher_v7_18) }};

config_structure config_source_v7 = { "1.0.0.0", config_classes_v7, CONFIG_ARRAY_SIZE(config_classes_v7) };
