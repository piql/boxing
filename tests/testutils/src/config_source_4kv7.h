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

config_pair pairsFormatInfo_4kv7_1[] =
{
    { "name", "4kv7" },
    { "shortDescription", "4k data frame format" },
    { "description", "Frames are generated using the Generic Preservation Format v1.0 printed on a 4096x2160 raster" }
};

config_pair pairsFrameFormat_4kv7_2[] =
{
    { "type", "GPFv1.0" },
    { "width", "4096" },
    { "height", "2160" },
    { "border", "1" },
    { "borderGap", "1" },
    { "cornerMarkSize", "32" },
    { "cornerMarkGap", "1" },
    { "tilesPerColumn", "4" },
    /*  color dept = log2(levelsPerSymbol) */
    { "maxLevelsPerSymbol", "4" }
};

config_pair pairsFrameBuilder_4kv7_3[] =
{
    /*  builder spesific */
    /*  <property key="dimensions" value="4096,2160"/> */
    /*  The type is: TIF, RAW, BMP, PNG */
    { "fileFormat", "RAW" }
};

config_pair pairsImageRaw_4kv7_4[] =
{
    /*  builder spesific */
    { "rawVersion", "1" },
    { "holes", "3" }
};

config_pair pairsFrameUnbuilder_4kv7_5[] =
{
    /*  builder spesific */
    { "alias", "FrameBuilder" }
};

config_pair pairsCodecDispatcher_4kv7_6[] =
{
    /*  The order the encoder process is specified, default value: encode */
    { "order", "decode" },
    /*  symbol alignment default: bit */
    { "symbolAlignment", "byte" },
    { "DataCodingScheme", "SyncPointInserter,Modulator,Cipher,Interleaving_inner,ReedSolomon_inner,Interleaving_outer,ReedSolomon_outer" },
    { "MetadataCodingScheme", "MetaData_Modulator,MetaData_Interleaving1,MetaData_ReedSolomon1" }
};

config_pair pairsReedSolomon_outer_4kv7_7[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "10" },
    { "messageSize", "197" }
};

config_pair pairsInterleaving_outer_4kv7_8[] =
{
    { "codec", "Interleaving" },
    { "distance", "207" },
    /*  interleaving symboltype; block, frame */
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsReedSolomon_inner_4kv7_9[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "48" },
    { "messageSize", "207" }
};

config_pair pairsInterleaving_inner_4kv7_10[] =
{
    { "codec", "Interleaving" },
    { "distance", "248" },
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsCipher_4kv7_11[] =
{
    { "codec", "Cipher" },
    /*  chipher key ; 'auto' , 'any number supported by the chiper class' */
    { "key", "auto" }
};

config_pair pairsModulator_4kv7_12[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsSyncPointInserter_4kv7_13[] =
{
    { "codec", "SyncPointInserter" },
    { "SyncPointDistancePixel", "100" },
    { "SyncPointRadiusPixel", "3" },
    { "DataOrientation", "1" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsMetaData_ReedSolomon1_4kv7_14[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "40" },
    { "messageSize", "211" },
    /* <property key="messageSize" value="32"/> */

};

config_pair pairsMetaData_Interleaving1_4kv7_15[] =
{
    { "codec", "Interleaving" },
    { "distance", "251" },
    /* <property key="distance" value="42"/>*/
    /*  interleaving symboltype; block, frame */
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsMetaData_Modulator_4kv7_16[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsFrameUnbuilder_4kv7_17[] =
{
    { "alias", "FrameBuilder" }
};

config_pair pairsBaseBuilder_4kv7_18[] =
{
    /*  builder spesific */
    { "blockSize", "1" },
    /*  not neddded by the unboxer remove it */
    { "colorDepth", "2" },
    /*  FOUND IN METADTA */

};

config_pair pairsFrameBuilder_4kv7_19[] =
{
    { "dimensions", "4092,2156" },
    /*  The type is: TIF, RAW, BMP, PNG */
    { "fileFormat", "TIF" }
};

config_pair pairscrc64_4kv7_20[] =
{
    /*  this can be optional */
    { "POLY64REV", "0x42F0E1EBA9EA3693" },
    { "INITIALCRC", "0x0000000000000000" }
};

config_pair pairscrc32_4kv7_21[] =
{
    /*  used by metadata */
    /*  this can be optional */
    { "POLY32REV", "0x42F0E1EBA9EA3693" },
    { "INITIALCRC", "0x0000000000000000" }
};

config_class config_classes_4kv7[] =
{
    { "FormatInfo", NULL, pairsFormatInfo_4kv7_1, CONFIG_ARRAY_SIZE(pairsFormatInfo_4kv7_1) },
    { "FrameFormat", NULL, pairsFrameFormat_4kv7_2, CONFIG_ARRAY_SIZE(pairsFrameFormat_4kv7_2) },
    /*  First the geometrical values. These can result in general definition files */
    { "FrameBuilder", NULL, pairsFrameBuilder_4kv7_3, CONFIG_ARRAY_SIZE(pairsFrameBuilder_4kv7_3) },
    { "ImageRaw", "1.0.0.0", pairsImageRaw_4kv7_4, CONFIG_ARRAY_SIZE(pairsImageRaw_4kv7_4) },
    /*  Note: The frame unbuilder inherits the values from the FrameBuilder 
       through the alias property */
    { "FrameUnbuilder", "1.0.0.0", pairsFrameUnbuilder_4kv7_5, CONFIG_ARRAY_SIZE(pairsFrameUnbuilder_4kv7_5) },
    /*  Frame coding scheme */
    { "CodecDispatcher", NULL, pairsCodecDispatcher_4kv7_6, CONFIG_ARRAY_SIZE(pairsCodecDispatcher_4kv7_6) },
    { "ReedSolomon_outer", NULL, pairsReedSolomon_outer_4kv7_7, CONFIG_ARRAY_SIZE(pairsReedSolomon_outer_4kv7_7) },
    { "Interleaving_outer", NULL, pairsInterleaving_outer_4kv7_8, CONFIG_ARRAY_SIZE(pairsInterleaving_outer_4kv7_8) },
    { "ReedSolomon_inner", NULL, pairsReedSolomon_inner_4kv7_9, CONFIG_ARRAY_SIZE(pairsReedSolomon_inner_4kv7_9) },
    { "Interleaving_inner", NULL, pairsInterleaving_inner_4kv7_10, CONFIG_ARRAY_SIZE(pairsInterleaving_inner_4kv7_10) },
    { "Cipher", NULL, pairsCipher_4kv7_11, CONFIG_ARRAY_SIZE(pairsCipher_4kv7_11) },
    { "Modulator", NULL, pairsModulator_4kv7_12, CONFIG_ARRAY_SIZE(pairsModulator_4kv7_12) },
    { "SyncPointInserter", NULL, pairsSyncPointInserter_4kv7_13, CONFIG_ARRAY_SIZE(pairsSyncPointInserter_4kv7_13) },
    { "MetaData_ReedSolomon1", NULL, pairsMetaData_ReedSolomon1_4kv7_14, CONFIG_ARRAY_SIZE(pairsMetaData_ReedSolomon1_4kv7_14) },
    { "MetaData_Interleaving1", NULL, pairsMetaData_Interleaving1_4kv7_15, CONFIG_ARRAY_SIZE(pairsMetaData_Interleaving1_4kv7_15) },
    { "MetaData_Modulator", NULL, pairsMetaData_Modulator_4kv7_16, CONFIG_ARRAY_SIZE(pairsMetaData_Modulator_4kv7_16) },
    /*  <class key="MetaDataFrame" version="1.0.0.0"> 
    </class> */
    /*  Note: The frame unbuilder inherits the values from the FrameBuilder 
       through the alias property */
    { "FrameUnbuilder", "1.0.0.0", pairsFrameUnbuilder_4kv7_17, CONFIG_ARRAY_SIZE(pairsFrameUnbuilder_4kv7_17) },
    { "BaseBuilder", NULL, pairsBaseBuilder_4kv7_18, CONFIG_ARRAY_SIZE(pairsBaseBuilder_4kv7_18) },
    /*  First the geometrical values. These can result in general definition files */
    { "FrameBuilder", NULL, pairsFrameBuilder_4kv7_19, CONFIG_ARRAY_SIZE(pairsFrameBuilder_4kv7_19) },
    /*  <class key="DataFrame" version="1.0.0.0"> */
    /*  builder spesific */
    /*  accepted values are: pattern, file (with fileName property in FileDataFrameSource class) and random */
    /* <property key="dataFrameSourceType" value="file"/>*/
    /*  </class> */
    { "crc64", NULL, pairscrc64_4kv7_20, CONFIG_ARRAY_SIZE(pairscrc64_4kv7_20) },
    { "crc32", NULL, pairscrc32_4kv7_21, CONFIG_ARRAY_SIZE(pairscrc32_4kv7_21) }};

config_structure config_source_4kv7 = { "1.0.0.0", config_classes_4kv7, CONFIG_ARRAY_SIZE(config_classes_4kv7) };
