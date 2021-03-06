
#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>

//#include "msdk_nvram_camera_exp.h"
//#include "msdk_lens_exp.h"
#include "camera_custom_nvram.h"
#include "camera_custom_lens.h"

const NVRAM_LENS_PARA_STRUCT IMX111AF_LENS_PARA_DEFAULT_VALUE =
{
    //Version
    NVRAM_CAMERA_LENS_FILE_VERSION,

    // Focus Range NVRAM
    {0, 1023},

    // AF NVRAM
    {
        // -------- AF ------------
//<2013/06/18-26042-alberthsiao, Update camera parameters for imx111 and bf3905
        /*{230,//185,//271,// i4Offset
           17,//23, // i4NormalNum
           17,//23, // i4MacroNum
           0, // i4InfIdxOffset
           0, //i4MacroIdxOffset          
    	  {
             0,  10,  20,  30,  40,  50,  60,  70,  80,  90,  
           100, 110, 122, 167, 237, 307, 377,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,   0,   0
         },*/
        {230,//185,//271,// i4Offset
           11,//23, // i4NormalNum
           11,//23, // i4MacroNum
           0, // i4InfIdxOffset
           0, //i4MacroIdxOffset          
    	   {
             0,  20,  40,  60,  80, 100, 122, 167, 237, 307,
           377,   0,   0,   0,   0,   0,   0,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,   0,   0
         },
/*        {230,//185,//271,// i4Offset
//<2013/05/02-24529-alberthsiao, Update camera parameters for imx111
           8,//23, // i4NormalNum
           8,//23, // i4MacroNum
           0, // i4InfIdxOffset
           0, //i4MacroIdxOffset          
    	   {
             0,  20,  40,  60,  80, 100, 122, 167, 237, 307,
           377,   0,   0,   0,   0,   0,   0,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,   0,   0
         },*/
          15, // i4THRES_MAIN;
          10, // i4THRES_SUB;            
          4,  // i4INIT_WAIT;
          {0, 0, 500, 500, 500}, // i4FRAME_WAIT
          0,  // i4DONE_WAIT;
              
          0,  // i4FAIL_POS;

          33,  // i4FRAME_TIME                        
          5,  // i4FIRST_FV_WAIT;
            
          30,  // i4FV_CHANGE_THRES;
          10000,  // i4FV_CHANGE_OFFSET;        
          3,  // i4FV_CHANGE_CNT;
          0,  // i4GS_CHANGE_THRES;    
          15,  // i4GS_CHANGE_OFFSET;    
          5,  // i4GS_CHANGE_CNT;            
          10,  // i4FV_STABLE_THRES;         // percentage -> 0 more stable  
          10000,  // i4FV_STABLE_OFFSET;        // value -> 0 more stable
          8,  // i4FV_STABLE_NUM;           // max = 9 (more stable), reset = 0
          8,  // i4FV_STABLE_CNT;           // max = 9                                      
          12,  // i4FV_1ST_STABLE_THRES;        
          10000,  // i4FV_1ST_STABLE_OFFSET;
          6,  // i4FV_1ST_STABLE_NUM;                        
          6  // i4FV_1ST_STABLE_CNT;      
         },
         
         // -------- ZSD AF ------------
        /*{230,//185,//271,// i4Offset
           17,//23, // i4NormalNum
           17,//23, // i4MacroNum
           0, // i4InfIdxOffset
           0, //i4MacroIdxOffset          
    	  {
             0,  10,  20,  30,  40,  50,  60,  70,  80,  90,  
           100, 110, 122, 167, 237, 307, 377,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,   0,   0
         },*/
        {230,//185,//271,// i4Offset
           11,//23, // i4NormalNum
           11,//23, // i4MacroNum
           0, // i4InfIdxOffset
           0, //i4MacroIdxOffset          
    	   {
             0,  20,  40,  60,  80, 100, 122, 167, 237, 307,
           377,   0,   0,   0,   0,   0,   0,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,   0,   0
         },
/*        {230,//185,//271,// i4Offset
           11,//23, // i4NormalNum
           11,//23, // i4MacroNum
           0, // i4InfIdxOffset
           0, //i4MacroIdxOffset          
    	   {
             0,  20,  40,  60,  80, 100, 122, 167, 237, 307,
           377,   0,   0,   0,   0,   0,   0,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,   0,   0
         },*/
           15, // i4THRES_MAIN;
           10, // i4THRES_SUB;            
           4,  // i4INIT_WAIT;
          {0, 0, 500, 500, 500}, // i4FRAME_WAIT
           0,  // i4DONE_WAIT;
                     
           0,  // i4FAIL_POS;

           44,  // i4FRAME_TIME                                  
           5,  // i4FIRST_FV_WAIT;
                     
           40,  // i4FV_CHANGE_THRES;
           20000,  // i4FV_CHANGE_OFFSET;        
           12,  // i4FV_CHANGE_CNT;
           0,  // i4GS_CHANGE_THRES;    
           20,  // i4GS_CHANGE_OFFSET;    
           12,  // i4GS_CHANGE_CNT;            
           10,  // i4FV_STABLE_THRES;         // percentage -> 0 more stable  
           10000,  // i4FV_STABLE_OFFSET;        // value -> 0 more stable
           8,   // i4FV_STABLE_NUM;           // max = 9 (more stable), reset = 0
           7,   // i4FV_STABLE_CNT;           // max = 9                                      
           20,  // i4FV_1ST_STABLE_THRES;        
           15000,  // i4FV_1ST_STABLE_OFFSET;
           12,  // i4FV_1ST_STABLE_NUM;                        
           10  // i4FV_1ST_STABLE_CNT;         
           }, 
           
           // -------- VAFC ------------
        /*{230,//185,//271,// i4Offset
           17,//23, // i4NormalNum
           17,//23, // i4MacroNum
           0, // i4InfIdxOffset
           0, //i4MacroIdxOffset          
    	  {
             0,  10,  20,  30,  40,  50,  60,  70,  80,  90,  
           100, 110, 122, 167, 237, 307, 377,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,   0,   0
         },*/
        {230,//185,//271,// i4Offset
           11,//23, // i4NormalNum
           11,//23, // i4MacroNum
           0, // i4InfIdxOffset
           0, //i4MacroIdxOffset          
    	   {
             0,  20,  40,  60,  80, 100, 122, 167, 237, 307,
           377,   0,   0,   0,   0,   0,   0,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,   0,   0
         },
/*        {230,//185,//271,// i4Offset
           11,//23, // i4NormalNum
           11,//23, // i4MacroNum
           0, // i4InfIdxOffset
           0, //i4MacroIdxOffset          
    	   {
             0,  20,  40,  60,  80, 100, 122, 167, 237, 307,
           377,   0,   0,   0,   0,   0,   0,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,   0,   0
         },*/
           15, // i4THRES_MAIN;
           10, // i4THRES_SUB;            
           1,  // i4INIT_WAIT;
          {0, 0, 500, 500, 500}, // i4FRAME_WAIT
           0,  // i4DONE_WAIT;
             
           0,  // i4FAIL_POS;

           33,  // i4FRAME_TIME                          
           5,  // i4FIRST_FV_WAIT;
             
           30,  // i4FV_CHANGE_THRES;
           10000,  // i4FV_CHANGE_OFFSET;        
           6,  // i4FV_CHANGE_CNT;
           0,  // i4GS_CHANGE_THRES;    
           15,  // i4GS_CHANGE_OFFSET;    
           5,  // i4GS_CHANGE_CNT;            
           10,  // i4FV_STABLE_THRES;         // percentage -> 0 more stable  
           10000,  // i4FV_STABLE_OFFSET;        // value -> 0 more stable
           8,  // i4FV_STABLE_NUM;           // max = 9 (more stable), reset = 0
           8,  // i4FV_STABLE_CNT;           // max = 9                                      
           12,  // i4FV_1ST_STABLE_THRES;        
           10000,  // i4FV_1ST_STABLE_OFFSET;
           6,  // i4FV_1ST_STABLE_NUM;                        
           6  // i4FV_1ST_STABLE_CNT;      
          },
//>2013/05/02-24529-alberthsiao
#if 0
        // --- sAF_TH ---
         {
          8,   // i4ISONum;
          {100,150,200,300,400,600,800,1600},       // i4ISO[ISO_MAX_NUM];
                  
          6,   // i4GMeanNum;
          {20,55,105,150,180,205},        // i4GMean[GMEAN_MAX_NUM];

          { 73, 76, 73, 71, 72, 89, 89, 89,
		   113,116,114,112,113,127,127,127,
		   172,174,172,171,172,180,180,180},		// i4GMR[3][ISO_MAX_NUM];
          
// ------------------------------------------------------------------------                  
          {0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0},        // i4FV_DC[GMEAN_MAX_NUM][ISO_MAX_NUM];
           
          {50000,50000,50000,50000,50000,50000,50000,50000,
           50000,50000,50000,50000,50000,50000,50000,50000,
           50000,50000,50000,50000,50000,50000,50000,50000,
           50000,50000,50000,50000,50000,50000,50000,50000,
           50000,50000,50000,50000,50000,50000,50000,50000,
           50000,50000,50000,50000,50000,50000,50000,50000},         // i4MIN_TH[GMEAN_MAX_NUM][ISO_MAX_NUM];        

          {   5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5}, // i4HW_TH[GMEAN_MAX_NUM][ISO_MAX_NUM];       
// ------------------------------------------------------------------------
          {0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0},        // i4FV_DC2[GMEAN_MAX_NUM][ISO_MAX_NUM];
           
          {0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0},         // i4MIN_TH2[GMEAN_MAX_NUM][ISO_MAX_NUM];
          
          {   5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5,
              5,5,5,5,5,5,5,5}      // i4HW_TH2[GMEAN_MAX_NUM][ISO_MAX_NUM];       
          
         },
// ------------------------------------------------------------------------

         // --- sZSDAF_TH ---
          {
           8,   // i4ISONum;
           {100,150,200,300,400,600,800,1600},       // i4ISO[ISO_MAX_NUM];
                   
           6,   // i4GMeanNum;
           {20,55,105,150,180,205},        // i4GMean[GMEAN_MAX_NUM];

           { 73, 76, 73, 71, 72, 89, 89, 89,
            113,116,114,112,113,127,127,127,
            172,174,172,171,172,180,180,180},        // i4GMR[3][ISO_MAX_NUM];
           
// ------------------------------------------------------------------------                   
           {0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0},        // i4FV_DC[GMEAN_MAX_NUM][ISO_MAX_NUM];
            
           {50000,50000,50000,50000,50000,50000,50000,50000,
            50000,50000,50000,50000,50000,50000,50000,50000,
            50000,50000,50000,50000,50000,50000,50000,50000,
            50000,50000,50000,50000,50000,50000,50000,50000,
            50000,50000,50000,50000,50000,50000,50000,50000,
            50000,50000,50000,50000,50000,50000,50000,50000},         // i4MIN_TH[GMEAN_MAX_NUM][ISO_MAX_NUM];        
         
           {0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0},       // i4HW_TH[GMEAN_MAX_NUM][ISO_MAX_NUM];       
// ------------------------------------------------------------------------
           {0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0},        // i4FV_DC2[GMEAN_MAX_NUM][ISO_MAX_NUM];
            
           {0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0},         // i4MIN_TH2[GMEAN_MAX_NUM][ISO_MAX_NUM];
           
           {0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0}          // i4HW_TH2[GMEAN_MAX_NUM][ISO_MAX_NUM];       
// ------------------------------------------------------------------------           
          },


#else
//Ori
        // --- sAF_TH ---
         {
          8,   // i4ISONum;
          {100,150,200,300,400,600,800,1600},       // i4ISO[ISO_MAX_NUM];
                  
          6,   // i4GMeanNum;
          {20,55,105,150,180,205},        // i4GMean[GMEAN_MAX_NUM];
          { 89, 90, 89, 89, 89, 89, 89, 88,
           127,127,127,127,127,127,127,126,
           180,181,180,180,180,180,180,180},        // i4GMR[3][ISO_MAX_NUM];
          
// ------------------------------------------------------------------------                  
          { 328, 218,   0, 123, 737, 655, 218,1024,
            273,1475, 492, 369,1352, 437, 983,1707,
              0,   0,   0,   0, 109,   0, 218, 164,
           1720,   0, 164,1024,1707,2389,2389,6636,
              0,   0,2403,   0,5530,1229, 683,2403,
              0,1475,   0,4779,5530, 614,   0, 874},        // i4FV_DC[GMEAN_MAX_NUM][ISO_MAX_NUM];
           
          {150000,150000,150000,120000,80000,50000,30000,30000,
           150000,150000,150000,120000,80000,50000,30000,30000,
           150000,150000,150000,120000,80000,50000,30000,30000,
           150000,150000,150000,120000,80000,50000,30000,30000,
           150000,150000,150000,120000,80000,50000,30000,30000,
           150000,150000,150000,120000,80000,50000,30000,30000},         // i4MIN_TH[GMEAN_MAX_NUM][ISO_MAX_NUM];        

          {2,2,3,3,3,4,4,5,
           2,3,3,3,3,4,6,5,
           2,2,2,2,2,2,2,2,
           3,2,2,5,5,5,5,9,
           3,3,4,3,9,3,5,4,
           2,6,3,5,9,3,4,4}, // i4HW_TH[GMEAN_MAX_NUM][ISO_MAX_NUM];       
// ------------------------------------------------------------------------
          {0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0},        // i4FV_DC2[GMEAN_MAX_NUM][ISO_MAX_NUM];
           
          {0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0},         // i4MIN_TH2[GMEAN_MAX_NUM][ISO_MAX_NUM];
          
          {4,5,4,4,5,5,6,6,
           4,5,5,4,5,6,7,7,
           3,4,5,5,4,7,5,7,
           3,4,4,4,6,4,6,9,
           4,4,4,4,5,5,6,8,
           4,5,5,5,5,6,7,6}          // i4HW_TH2[GMEAN_MAX_NUM][ISO_MAX_NUM];       
          
         },

         // --- sZSDAF_TH ---
          {
           8,   // i4ISONum;
           {100,150,200,300,400,600,800,1600},       // i4ISO[ISO_MAX_NUM];
                   
           6,   // i4GMeanNum;
           {20,55,105,150,180,205},        // i4GMean[GMEAN_MAX_NUM];

           { 89, 89, 88, 88, 80, 76, 74, 71,
            127,127,126,126,119,118,114,112,
            180,180,180,180,176,175,173,171},        // i4GMR[3][ISO_MAX_NUM];
           
// ------------------------------------------------------------------------                   
           {273,765,546,2403,1109,1106,1338,1935   ,
            1638,1529,1529,1536,2089,1311,2488,2478,
            14,27,41,369,765,645,1167,853          ,
            1280,1280,1195,1171,3318,3413,4437,5192,
            109,546,382,1365,597,1106,3318,1748    ,
            55,218,218,655,2294,1877,860,1505      },        // i4FV_DC[GMEAN_MAX_NUM][ISO_MAX_NUM];
            
           {80000,80000,80000,80000,80000,50000,30000,30000,
            80000,80000,80000,80000,80000,50000,30000,30000,
            80000,80000,80000,80000,80000,50000,30000,30000,
            80000,80000,80000,80000,80000,50000,30000,30000,
            80000,80000,80000,80000,80000,50000,30000,30000,
            80000,80000,80000,80000,80000,50000,30000,30000},         // i4MIN_TH[GMEAN_MAX_NUM][ISO_MAX_NUM];        
           
          {    4,4,4,4,5, 6, 7, 9,
	            4,4,4,5,6, 8, 9,11,
	            2,2,2,2,2, 3, 3, 5,
	            5,5,5,7,9,10,10,13,
	            4,4,4,4,5, 6, 6, 8,
	            4,4,4,4,4, 5, 6, 7}, // i4HW_TH[GMEAN_MAX_NUM][ISO_MAX_NUM];       

           {0,0,0,0,0,0,0,0,
	          0,0,0,0,0,0,0,0,
	          0,0,0,0,0,0,0,0,
	          0,0,0,0,0,0,0,0,
	          0,0,0,0,0,0,0,0,
	          0,0,0,0,0,0,0,0},        // i4FV_DC2[GMEAN_MAX_NUM][ISO_MAX_NUM];
            
           {0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0},         // i4MIN_TH2[GMEAN_MAX_NUM][ISO_MAX_NUM];
           
           {7,7,6,8,9,11,9,11    ,
	          8,6,9,8,12,12,16,14  ,
            6,8,6,7,9,9,9,9      ,
            6,5,4,7,8,12,11,15   ,
            12,11,9,8,9,10,12,11 ,
            6,8,7,8,9,8,10,10    } // i4HW_TH2[GMEAN_MAX_NUM][ISO_MAX_NUM];       
           
          },
#endif

          1, // i4VAFC_FAIL_CNT;
          0, // i4CHANGE_CNT_DELTA;

          0, // i4LV_THRES;

          18, // i4WIN_PERCENT_W;
          24, // i4WIN_PERCENT_H;                
          250,  // i4InfPos;
          20, //i4AFC_STEP_SIZE;

          {
              {0, 10, 100, 150, 200}, // back to bestpos step
              { 0,   0,   0,   0,   0}  // hysteresis compensate step
          },

          {0, 0, 150, 250, 350}, // back jump
          500,  //i4BackJumpPos

          80, // i4FDWinPercent;
          60, // i4FDSizeDiff;

          3,   //i4StatGain          

          {0,0,0,0,0,0,0,0,0,0,
           0,0,0,0,0,0,0,0,0,0}// i4Coef[20];
    },

    {0}
};
//>2013/06/18-26042-alberthsiao

UINT32 IMX111AF_getDefaultData(VOID *pDataBuf, UINT32 size)
{
    UINT32 dataSize = sizeof(NVRAM_LENS_PARA_STRUCT);

    if ((pDataBuf == NULL) || (size < dataSize))
    {
        return 1;
    }

    // copy from Buff to global struct
    memcpy(pDataBuf, &IMX111AF_LENS_PARA_DEFAULT_VALUE, dataSize);

    return 0;
}

PFUNC_GETLENSDEFAULT pIMX111AF_getDefaultData = IMX111AF_getDefaultData;


