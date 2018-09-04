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

config_pair pairsFormatInfo_v1_1[] =
{
    { "name", "4k-controlframe-v1" }
};

config_pair pairsFrameBuilder_v1_2[] =
{
    { "dimensions", "1024,540" },
    /*  Mod1: width, height */
    { "fileFormat", "RAW" }
};

config_pair pairsImageRaw_v1_3[] =
{
    { "adjustLen", "0" },
    { "crcMode", "64ISO" },
    { "rawVersion", "1" },
    { "crcOverAllData", "true" },
    { "holes", "3" }
};

config_pair pairsFrameUnbuilder_v1_4[] =
{
    { "alias", "FrameBuilder" }
};

config_pair pairsCodecDispatcher_v1_5[] =
{
    { "process", "ReedSolomon1,Interleaving1,ReedSolomon2,Interleaving2,Cipher" },
    { "MetedataCodingScheme", "MetaData_ReedSolomon1" }
};

config_pair pairsReedSolomon1_v1_6[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "174" }
};

config_pair pairsInterleaving1_v1_7[] =
{
    { "codec", "Interleaving" },
    { "distance", "194" },
    /*  interleaving symboltype; block, frame */
    { "interleavingtype", "block" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsReedSolomon2_v1_8[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "16" },
    { "messageSize", "194" }
};

config_pair pairsInterleaving2_v1_9[] =
{
    { "codec", "Interleaving" },
    { "distance", "32" },
    { "interleavingtype", "frame" },
    /*  interleaving symboltype; byte,bit */
    { "symboltype", "byte" }
};

config_pair pairsCipher_v1_10[] =
{
    { "codec", "Cipher" },
    /*  chipher key ; 'auto' , 'any number supported by the chiper class' */
    { "key", "auto" }
};

config_pair pairsMetaData_ReedSolomon1_v1_11[] =
{
    { "codec", "ReedSolomon" },
    { "byteParityNumber", "20" },
    { "messageSize", "100" }
};

config_pair pairsBaseBuilder_v1_12[] =
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

config_pair pairsDataFrame_v1_13[] =
{
    { "insertPoint", "32,32" },
    { "dimensions", "960,476" },
    /*  Mod2: width - 64, height - 64 */
    /* property key="holeInsertPoint" value="92,92"/>
  <property key="holeDimensions" value="16,16"/*/
    { "subPixelsFactor", "1" },
    { "interpolationSize", "0" }
};

config_pair pairsMetaDataFrame_v1_14[] =
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

config_pair pairsCalibrationBarFrame_v1_15[] =
{
    { "insertPoint", "32,0" },
    { "dimensions", "960,16" },
    /*  Mod5: width - 64, 16 */

};

config_pair pairsReferenceMarkFrame_v1_16[] =
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

config_pair pairsFrameBuilder_v1_17[] =
{
    /*  How to is the distribution colors:
equalSpacing: homogeneous distribution
mostSignificantBits: set the bits data in the most significant of colour */
    { "colorsDistribution", "equalSpacing" }
};

config_pair pairsDataFrame_v1_18[] =
{
    /*  accepted values are: pattern, file (with fileName property in FileDataFrameSource class) and random */
    { "dataFrameSourceType", "file" },
    /*  The values are:
      center - restore the pixel color from the center whit interpolation
      boxed  - restore the pixel color from the interpolation of the transformer box */
    { "restoreType", "center" }
};

config_pair pairsLocateReference_v1_19[] =
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

config_pair pairscrc64_v1_20[] =
{
    { "POLY64REV", "0x42F0E1EBA9EA3693" },
    { "INITIALCRC", "0x0000000000000000" }
};

config_class config_classes_v1[] =
{
    { "FormatInfo", NULL, pairsFormatInfo_v1_1, CONFIG_ARRAY_SIZE(pairsFormatInfo_v1_1) },
    /*  First the geometrical values. These can result in general definition files */
    { "FrameBuilder", NULL, pairsFrameBuilder_v1_2, CONFIG_ARRAY_SIZE(pairsFrameBuilder_v1_2) },
    { "ImageRaw", "1.0.0.0", pairsImageRaw_v1_3, CONFIG_ARRAY_SIZE(pairsImageRaw_v1_3) },
    /*  Note: The frame unbuilder inherits the values from the FrameBuilder 
     through the alias property */
    { "FrameUnbuilder", "1.0.0.0", pairsFrameUnbuilder_v1_4, CONFIG_ARRAY_SIZE(pairsFrameUnbuilder_v1_4) },
    /*  Frame coding scheme */
    { "CodecDispatcher", "1.0.0.0", pairsCodecDispatcher_v1_5, CONFIG_ARRAY_SIZE(pairsCodecDispatcher_v1_5) },
    { "ReedSolomon1", "1.0.0.0", pairsReedSolomon1_v1_6, CONFIG_ARRAY_SIZE(pairsReedSolomon1_v1_6) },
    { "Interleaving1", "1.0.0.0", pairsInterleaving1_v1_7, CONFIG_ARRAY_SIZE(pairsInterleaving1_v1_7) },
    { "ReedSolomon2", "1.0.0.0", pairsReedSolomon2_v1_8, CONFIG_ARRAY_SIZE(pairsReedSolomon2_v1_8) },
    { "Interleaving2", "1.0.0.0", pairsInterleaving2_v1_9, CONFIG_ARRAY_SIZE(pairsInterleaving2_v1_9) },
    { "Cipher", "1.0.0.0", pairsCipher_v1_10, CONFIG_ARRAY_SIZE(pairsCipher_v1_10) },
    { "MetaData_ReedSolomon1", "1.0.0.0", pairsMetaData_ReedSolomon1_v1_11, CONFIG_ARRAY_SIZE(pairsMetaData_ReedSolomon1_v1_11) },
    { "BaseBuilder", NULL, pairsBaseBuilder_v1_12, CONFIG_ARRAY_SIZE(pairsBaseBuilder_v1_12) },
    { "DataFrame", "1.0.0.0", pairsDataFrame_v1_13, CONFIG_ARRAY_SIZE(pairsDataFrame_v1_13) },
    { "MetaDataFrame", "1.0.0.0", pairsMetaDataFrame_v1_14, CONFIG_ARRAY_SIZE(pairsMetaDataFrame_v1_14) },
    { "CalibrationBarFrame", "1.0.0.0", pairsCalibrationBarFrame_v1_15, CONFIG_ARRAY_SIZE(pairsCalibrationBarFrame_v1_15) },
    { "ReferenceMarkFrame", "1.0.0.0", pairsReferenceMarkFrame_v1_16, CONFIG_ARRAY_SIZE(pairsReferenceMarkFrame_v1_16) },
    /*  Secondly, the specific values of work */
    { "FrameBuilder", NULL, pairsFrameBuilder_v1_17, CONFIG_ARRAY_SIZE(pairsFrameBuilder_v1_17) },
    { "DataFrame", "1.0.0.0", pairsDataFrame_v1_18, CONFIG_ARRAY_SIZE(pairsDataFrame_v1_18) },
    /*  http://www.seas.upenn.edu/~bensapp/opencvdocs/ref/opencvref_cv.htm */
    { "LocateReference", "1.0.0.0", pairsLocateReference_v1_19, CONFIG_ARRAY_SIZE(pairsLocateReference_v1_19) },
    { "crc64", NULL, pairscrc64_v1_20, CONFIG_ARRAY_SIZE(pairscrc64_v1_20) }};

config_structure config_source_v1 = { "1.0.0.0", config_classes_v1, CONFIG_ARRAY_SIZE(config_classes_v1) };
