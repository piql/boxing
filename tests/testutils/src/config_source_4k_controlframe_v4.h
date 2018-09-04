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

config_pair pairsFormatInfo_v4_1[] =
{
    { "name", "4k-controlframe-v4" },
    { "shortDescription", "4k control data frame format" },
    { "description", "Frames are generated using the Generic Preservation Format v1.0 printed on a 4096x2160 raster" }
};

config_pair pairsFrameFormat_v4_2[] =
{
    { "type", "GPFv1.0" },
    { "width", "1024" },
    { "height", "540" },
    { "border", "1" },
    { "borderGap", "1" },
    { "cornerMarkSize", "32" },
    { "cornerMarkGap", "1" },
    { "tilesPerColumn", "4" },
    /*  color dept = log2(levelsPerSymbol) */
    { "maxLevelsPerSymbol", "2" }
};

config_pair pairsFrameBuilder_v4_3[] =
{
    /*  builder spesific */
    /*  <property key="dimensions" value="4096,2160"/> */
    /*  The type is: TIF, RAW, BMP, PNG */
    { "fileFormat", "RAW" }
};

config_pair pairsImageRaw_v4_4[] =
{
    /*  builder spesific */
    { "rawVersion", "1" },
    { "holes", "3" }
};

config_pair pairsFrameUnbuilder_v4_5[] =
{
    /*  builder spesific */
    { "alias", "FrameBuilder" }
};

config_pair pairsCodecDispatcher_v4_6[] =
{
    /*  The order the encoder process is specified, default value: encode */
    { "order", "decode" },
    /*  symbol alignment default: bit */
    { "symbolAlignment", "byte" },
    /*  <property key="process" value="SyncPointInserter,Modulator,Cipher,Interleaving2,ReedSolomon2,Interleaving1,ReedSolomon1"/> */
    { "DataCodingScheme", "SyncPointInserter,Modulator,Cipher,Interleaving2,ReedSolomon2,Interleaving1,ReedSolomon1" },
    { "MetadataCodingScheme", "MetaData_Modulator,MetaData_Cipher,MetaData_ReedSolomon1" }
};

config_pair pairsReedSolomon1_v4_7[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "172" }
};

config_pair pairsInterleaving1_v4_8[] =
{
    { "codec", "Interleaving" },
    { "distance", "192" },
    /*  interleaving symboltype; block, frame */
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsReedSolomon2_v4_9[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "16" },
    { "messageSize", "192" }
};

config_pair pairsInterleaving2_v4_10[] =
{
    { "codec", "Interleaving" },
    { "distance", "239" },
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsCipher_v4_11[] =
{
    { "codec", "Cipher" },
    /*  chipher key ; 'auto' , 'any number supported by the chiper class' */
    { "key", "auto" }
};

config_pair pairsModulator_v4_12[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsSyncPointInserter_v4_13[] =
{
    { "codec", "SyncPointInserter" },
    { "SyncPointDistancePixel", "100" },
    { "SyncPointRadiusPixel", "2" },
    { "DataOrientation", "1" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsMetaData_ReedSolomon1_v4_14[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "99" },
    /* <property key="messageSize" value="32"/> */

};

config_pair pairsMetaData_Modulator_v4_15[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsMetaData_Cipher_v4_16[] =
{
    { "codec", "Cipher" },
    /*  chipher key ; 'auto' , 'any number supported by the chiper class' */
    { "key", "1" }
};

config_pair pairsFrameUnbuilder_v4_17[] =
{
    { "alias", "FrameBuilder" }
};

config_pair pairsBaseBuilder_v4_18[] =
{
    /*  property key="forceTraced" value="false"/ */
    { "blockSize", "1" },
    { "scalingFactor", "4" }
};

config_pair pairsFrameBuilder_v4_19[] =
{
    { "dimensions", "4092,2156" },
    /*  The type is: TIF, RAW, BMP, PNG */
    { "fileFormat", "TIF" }
};

config_pair pairscrc64_v4_20[] =
{
    /*  this can be optional */
    { "POLY64REV", "0x42F0E1EBA9EA3693" },
    { "INITIALCRC", "0x0000000000000000" }
};

config_pair pairscrc32_v4_21[] =
{
    /*  used by metadata */
    /*  this can be optional */
    { "POLY32REV", "0x42F0E1EBA9EA3693" },
    { "INITIALCRC", "0x0000000000000000" }
};

config_class config_classes_v4[] =
{
    { "FormatInfo", NULL, pairsFormatInfo_v4_1, CONFIG_ARRAY_SIZE(pairsFormatInfo_v4_1) },
    { "FrameFormat", NULL, pairsFrameFormat_v4_2, CONFIG_ARRAY_SIZE(pairsFrameFormat_v4_2) },
    /*  First the geometrical values. These can result in general definition files */
    { "FrameBuilder", NULL, pairsFrameBuilder_v4_3, CONFIG_ARRAY_SIZE(pairsFrameBuilder_v4_3) },
    { "ImageRaw", "1.0.0.0", pairsImageRaw_v4_4, CONFIG_ARRAY_SIZE(pairsImageRaw_v4_4) },
    /*  Note: The frame unbuilder inherits the values from the FrameBuilder 
       through the alias property */
    { "FrameUnbuilder", "1.0.0.0", pairsFrameUnbuilder_v4_5, CONFIG_ARRAY_SIZE(pairsFrameUnbuilder_v4_5) },
    /*  Frame coding scheme */
    { "CodecDispatcher", NULL, pairsCodecDispatcher_v4_6, CONFIG_ARRAY_SIZE(pairsCodecDispatcher_v4_6) },
    { "ReedSolomon1", NULL, pairsReedSolomon1_v4_7, CONFIG_ARRAY_SIZE(pairsReedSolomon1_v4_7) },
    { "Interleaving1", NULL, pairsInterleaving1_v4_8, CONFIG_ARRAY_SIZE(pairsInterleaving1_v4_8) },
    { "ReedSolomon2", NULL, pairsReedSolomon2_v4_9, CONFIG_ARRAY_SIZE(pairsReedSolomon2_v4_9) },
    { "Interleaving2", NULL, pairsInterleaving2_v4_10, CONFIG_ARRAY_SIZE(pairsInterleaving2_v4_10) },
    { "Cipher", NULL, pairsCipher_v4_11, CONFIG_ARRAY_SIZE(pairsCipher_v4_11) },
    { "Modulator", NULL, pairsModulator_v4_12, CONFIG_ARRAY_SIZE(pairsModulator_v4_12) },
    { "SyncPointInserter", NULL, pairsSyncPointInserter_v4_13, CONFIG_ARRAY_SIZE(pairsSyncPointInserter_v4_13) },
    { "MetaData_ReedSolomon1", NULL, pairsMetaData_ReedSolomon1_v4_14, CONFIG_ARRAY_SIZE(pairsMetaData_ReedSolomon1_v4_14) },
    { "MetaData_Modulator", NULL, pairsMetaData_Modulator_v4_15, CONFIG_ARRAY_SIZE(pairsMetaData_Modulator_v4_15) },
    { "MetaData_Cipher", NULL, pairsMetaData_Cipher_v4_16, CONFIG_ARRAY_SIZE(pairsMetaData_Cipher_v4_16) },
    /*  Note: The frame unbuilder inherits the values from the FrameBuilder 
       through the alias property */
    { "FrameUnbuilder", "1.0.0.0", pairsFrameUnbuilder_v4_17, CONFIG_ARRAY_SIZE(pairsFrameUnbuilder_v4_17) },
    { "BaseBuilder", NULL, pairsBaseBuilder_v4_18, CONFIG_ARRAY_SIZE(pairsBaseBuilder_v4_18) },
    /*  First the geometrical values. These can result in general definition files */
    { "FrameBuilder", NULL, pairsFrameBuilder_v4_19, CONFIG_ARRAY_SIZE(pairsFrameBuilder_v4_19) },
    { "crc64", NULL, pairscrc64_v4_20, CONFIG_ARRAY_SIZE(pairscrc64_v4_20) },
    { "crc32", NULL, pairscrc32_v4_21, CONFIG_ARRAY_SIZE(pairscrc32_v4_21) }};

config_structure config_source_v4 = { "1.0.0.0", config_classes_v4, CONFIG_ARRAY_SIZE(config_classes_v4) };
