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

config_pair pairsFormatInfo_v2_1[] =
{
    { "name", "4k-controlframe-v2" }
};

config_pair pairsFrameBuilder_v2_2[] =
{
    { "dimensions", "1024,540" },
    /*  Mod1: width, height */
    { "fileFormat", "RAW" }
};

config_pair pairsImageRaw_v2_3[] =
{
    { "adjustLen", "0" },
    { "crcMode", "64ISO" },
    { "rawVersion", "1" },
    { "crcOverAllData", "true" },
    { "holes", "3" }
};

config_pair pairsFrameUnbuilder_v2_4[] =
{
    { "alias", "FrameBuilder" }
};

config_pair pairsCodecDispatcher_v2_5[] =
{
    /*  The order the encoder process is specified, default value: encode */
    { "order", "decode" },
    /*  symbol alignment default: bit */
    { "symbolAlignment", "byte" },
    { "process", "Modulator,Cipher,Interleaving2,ReedSolomon2,Interleaving1,ReedSolomon1" },
    { "MetedataCodingScheme", "MetaData_Modulator,MetaData_ReedSolomon1" }
};

config_pair pairsReedSolomon1_v2_6[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "174" }
};

config_pair pairsInterleaving1_v2_7[] =
{
    { "codec", "Interleaving" },
    { "distance", "194" },
    /*  interleaving symboltype; block, frame */
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsReedSolomon2_v2_8[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "16" },
    { "messageSize", "194" }
};

config_pair pairsInterleaving2_v2_9[] =
{
    { "codec", "Interleaving" },
    { "distance", "32" },
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsCipher_v2_10[] =
{
    { "codec", "Cipher" },
    /*  chipher key ; 'auto' , 'any number supported by the chiper class' */
    { "key", "auto" }
};

config_pair pairsModulator_v2_11[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsMetaData_ReedSolomon1_v2_12[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "100" }
};

config_pair pairsMetaData_Modulator_v2_13[] =
{
    { "codec", "Modulator" },
    /*  NumBitsPerPixel; auto - any supported color depth */
    { "NumBitsPerPixel", "auto" }
};

config_pair pairsBaseBuilder_v2_14[] =
{
    /*  property key="forceTraced" value="false"/ */
    { "blockSize", "1" },
    { "scalingFactor", "4" },
    { "colorDepth", "1" },
    /*  Mask color components tells us that we have to use to encode the elements.
     0000 0001  (1) ==>  Use B component only (R = G = 0)
     0000 0010  (2) ==>  Use G component only (R = B = 0)
     0000 0100  (4) ==>  Use R component only (G = B = 0)
     0000 0011  (3) ==>  Use GB components (R = 0)
     0000 0101  (5) ==>  Use RB components (G = 0)
     0000 0110  (6) ==>  Use RG components (B = 0)
     0000 0111  (7) ==>  Use RGB components
     0000 1000  (8)  ==>  gray (same in R, G and B component)
     0000 1001  (9)  |
     0000 1010  (10) |
     0000 1011  (11) |
     0000 1100  (12) |    If first bit is on, assume gray model
     0000 1101  (13) |
     0000 1110  (14) |
     0000 1111  (15) ==>
     xxxx 0000  (0  or > 15) ==>  ERROR */
    { "componentMask", "8" }
};

config_pair pairsDataFrame_v2_15[] =
{
    { "insertPoint", "32,32" },
    { "dimensions", "960,476" },
    /*  Mod2: width - 64, height - 64 */
    /* property key="holeInsertPoint" value="92,92"/>
  <property key="holeDimensions" value="16,16"/*/
    { "subPixelsFactor", "1" },
    { "interpolationSize", "0" }
};

config_pair pairsMetaDataFrame_v2_16[] =
{
    { "insertPoint", "32,524" },
    /*  Mod3: 32, height - 16 */
    { "dimensions", "960,16" },
    /*  Mod4: width - 64, 16 */
    { "bitPixelsSize", "4" },
    { "subPixelsFactor", "100" },
    { "interpolationSize", "0" },
    { "recordingDensities", "40,40,40" },
    { "filmType", "4210752" },
    { "linLog", "1052688" },
    /*  The values are:
      center - restore the pixel color from the center whit interpolation
      boxed  - restore the pixel color from the interpolation of the transformer box */
    { "restoreType", "center" },
    { "valuesInOrder", "frameNumber,fileSize,fileId,dataSize,dataCrc,symbolsperpixel,contentType,cipherKey" },
    { "codeingScheme", "MetedataCodingScheme" }
};

config_pair pairsCalibrationBarFrame_v2_17[] =
{
    { "insertPoint", "32,0" },
    { "dimensions", "960,16" },
    /*  Mod5: width - 64, 16 */

};

config_pair pairsReferenceMarkFrame_v2_18[] =
{
    { "dimensions", "32,32" },
    { "insertPointTL", "0,0" },
    { "fileTL", "etc/resources/reference_mark.png" },
    { "insertPointTR", "992,0" },
    /*  Mod6: width - 32, 0 */
    { "fileTR", "etc/resources/reference_mark.png" },
    { "insertPointBL", "0,508" },
    /*  Mod7: 0, height - 32 */
    { "fileBL", "etc/resources/reference_mark.png" },
    { "insertPointBR", "992,508" },
    /*  Mod8: width - 32, height - 32 */
    { "fileBR", "etc/resources/reference_mark.png" },
    /* property key="insertPointCT" value="92,92"/>
  <property key="fileCT" value="/home/jmcruz/Archivator/pics/reference_pattern_1_1.png"/*/

};

config_pair pairsFrameBuilder_v2_19[] =
{
    /*  How to is the distribution colors:
equalSpacing: homogeneous distribution
mostSignificantBits: set the bits data in the most significant of colour */
    { "colorsDistribution", "equalSpacing" }
};

config_pair pairsDataFrame_v2_20[] =
{
    /*  accepted values are: pattern, file (with fileName property in FileDataFrameSource class) and random */
    { "dataFrameSourceType", "file" },
    /*  The values are:
      center - restore the pixel color from the center whit interpolation
      boxed  - restore the pixel color from the interpolation of the transformer box */
    { "restoreType", "center" }
};

config_pair pairsLocateReference_v2_21[] =
{
    /*  Values for Canny Algorithm:
         Min and max values for thres hold      threshHold1 and threshHold2 0/50
         Aperture size for Sobel Operator       apertureSobel               5

         http://en.wikipedia.org/wiki/Canny_edge_detector */
    { "thresHold1", "0" },
    { "thresHold2", "50" },
    /*  The aperture size for Sobel must be 1, 3, 5 or 7 */
    { "apertureSobel", "5" },
    /*  Steps process Min value is 2 */
    { "steps", "10" },
    { "jump", "5" },
    { "maxProcess", "20" },
    /*  Min and Max values for area of squares
         In this case the area of square is 16x16 = 256
         The scale factor is from 2.5 to 3.5, and so
         minArea = 256 * (3 - .5) * (3 - .5) = 1600.0
         maxArea = 256 * (3 + .5) * (3 + .5) = 3136.0 */
    { "minArea", "500.0" },
    { "maxArea", "3136.0" },
    /*  Max value for cosine of 90º angle
         Approx. rectangular angle */
    { "cosineLimit", "0.1" },
    /*  Min distance for duplication erase  based in gravity center
        This value is aprox to (6 + 0.5) / 2.0 */
    { "minDistanceCOG", "3.25" }
};

config_pair pairscrc64_v2_22[] =
{
    { "POLY64REV", "0x42F0E1EBA9EA3693" },
    { "INITIALCRC", "0x0000000000000000" }
};

config_class config_classes_v2[] =
{
    { "FormatInfo", NULL, pairsFormatInfo_v2_1, CONFIG_ARRAY_SIZE(pairsFormatInfo_v2_1) },
    /*  First the geometrical values. These can result in general definition files */
    { "FrameBuilder", NULL, pairsFrameBuilder_v2_2, CONFIG_ARRAY_SIZE(pairsFrameBuilder_v2_2) },
    { "ImageRaw", "1.0.0.0", pairsImageRaw_v2_3, CONFIG_ARRAY_SIZE(pairsImageRaw_v2_3) },
    /*  Note: The frame unbuilder inherits the values from the FrameBuilder 
     through the alias property */
    { "FrameUnbuilder", "1.0.0.0", pairsFrameUnbuilder_v2_4, CONFIG_ARRAY_SIZE(pairsFrameUnbuilder_v2_4) },
    /*  Frame coding scheme */
    { "CodecDispatcher", "1.0.0.0", pairsCodecDispatcher_v2_5, CONFIG_ARRAY_SIZE(pairsCodecDispatcher_v2_5) },
    { "ReedSolomon1", "1.0.0.0", pairsReedSolomon1_v2_6, CONFIG_ARRAY_SIZE(pairsReedSolomon1_v2_6) },
    { "Interleaving1", "1.0.0.0", pairsInterleaving1_v2_7, CONFIG_ARRAY_SIZE(pairsInterleaving1_v2_7) },
    { "ReedSolomon2", "1.0.0.0", pairsReedSolomon2_v2_8, CONFIG_ARRAY_SIZE(pairsReedSolomon2_v2_8) },
    { "Interleaving2", "1.0.0.0", pairsInterleaving2_v2_9, CONFIG_ARRAY_SIZE(pairsInterleaving2_v2_9) },
    { "Cipher", "1.0.0.0", pairsCipher_v2_10, CONFIG_ARRAY_SIZE(pairsCipher_v2_10) },
    { "Modulator", "1.0.0.0", pairsModulator_v2_11, CONFIG_ARRAY_SIZE(pairsModulator_v2_11) },
    { "MetaData_ReedSolomon1", "1.0.0.0", pairsMetaData_ReedSolomon1_v2_12, CONFIG_ARRAY_SIZE(pairsMetaData_ReedSolomon1_v2_12) },
    { "MetaData_Modulator", "1.0.0.0", pairsMetaData_Modulator_v2_13, CONFIG_ARRAY_SIZE(pairsMetaData_Modulator_v2_13) },
    { "BaseBuilder", NULL, pairsBaseBuilder_v2_14, CONFIG_ARRAY_SIZE(pairsBaseBuilder_v2_14) },
    { "DataFrame", "1.0.0.0", pairsDataFrame_v2_15, CONFIG_ARRAY_SIZE(pairsDataFrame_v2_15) },
    { "MetaDataFrame", "1.0.0.0", pairsMetaDataFrame_v2_16, CONFIG_ARRAY_SIZE(pairsMetaDataFrame_v2_16) },
    { "CalibrationBarFrame", "1.0.0.0", pairsCalibrationBarFrame_v2_17, CONFIG_ARRAY_SIZE(pairsCalibrationBarFrame_v2_17) },
    { "ReferenceMarkFrame", "1.0.0.0", pairsReferenceMarkFrame_v2_18, CONFIG_ARRAY_SIZE(pairsReferenceMarkFrame_v2_18) },
    /*  Secondly, the specific values of work */
    { "FrameBuilder", NULL, pairsFrameBuilder_v2_19, CONFIG_ARRAY_SIZE(pairsFrameBuilder_v2_19) },
    { "DataFrame", "1.0.0.0", pairsDataFrame_v2_20, CONFIG_ARRAY_SIZE(pairsDataFrame_v2_20) },
    /*  http://www.seas.upenn.edu/~bensapp/opencvdocs/ref/opencvref_cv.htm */
    { "LocateReference", "1.0.0.0", pairsLocateReference_v2_21, CONFIG_ARRAY_SIZE(pairsLocateReference_v2_21) },
    { "crc64", NULL, pairscrc64_v2_22, CONFIG_ARRAY_SIZE(pairscrc64_v2_22) }};

config_structure config_source_v2 = { "1.0.0.0", config_classes_v2, CONFIG_ARRAY_SIZE(config_classes_v2) };
