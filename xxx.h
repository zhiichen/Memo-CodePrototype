/* 2.3.0 */     预测为版本信息
/*===================================================================================================================================*/
/*  Copyright DENSO Corporation                                                                                                      */
/*===================================================================================================================================*/
/*  Alert Abg                         功能名称                                                                                               */
/*===================================================================================================================================*/

#ifndef ALTAPP_ABG_H     //用来处理重复include重复定义 和 功能是否实装
#define ALTAPP_ABG_H     //如果没定义，先来定义一个 这样就不会二次定义二次导入

/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*  Version                       版本确认                                                                                          */
/*-----------------------------------------------------------------------------------------------------------------------------------*/
#define ALTAPP_ABG_H_MAJOR                  (2)
#define ALTAPP_ABG_H_MINOR                  (3)
#define ALTAPP_ABG_H_PATCH                  (0)

/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*  Include Files     好像只有prm才include  xxx.h    至于 .c文件只include prm  
.h的include   一般都是空的，想想也是，自己就是个被包含的，你再包含别的，
其他文件包含你再包含你包含的很可能重复包含
   common 什么的包含了更底层的.h比如说spf，还有包含了xxxmgr，貌似也是底层的 ttmgr sound alertmgr什么的                                                                                                               */
/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*  Type Definitions             对外公开的                                                                                                    */
/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*  Defines                                对外公开的                                                                                          */
/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*  Macros                                                                                                                           */
/*-----------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*  Function Prototypes     函数声明  先判断用不用这个功能 tt,wrn或者rmt，有就定义具体的，没有就定义个dummy返回0之类的                                                                            */
/*-----------------------------------------------------------------------------------------------------------------------------------*/
#if((__GRIZZ_WRN_EAT_USE__ == 1) || (__GRIZZ_TT_EAT_USE__ == 1) || (__GRIZZ_RMT_EAT_USE__ == 1))
void vd_g_AltappAbgInit(void);
void vd_g_AltappAbgRoutine(void);
U1   u1_g_AltappAbgOutTt(U1 u1_a_dummy);
U1   u1_g_AltappAbgOutWrn(U1 u1_a_dummy);
U1   u1_g_AltappAbgOutRmt(U1 u1_a_dummy);
#else
#define vd_g_AltappAbgInit                      vd_g_AlertDummyFunc
#define vd_g_AltappAbgRoutine                   vd_g_AlertDummyFunc
#define u1_g_AltappAbgOutTt                     u1_g_AlertRetAlwaysOffEx
#define u1_g_AltappAbgOutWrn(x)                 u1_g_AlertRetAlwaysOff()
#define u1_g_AltappAbgOutRmt                    u1_g_AlertRetAlwaysOffEx
#endif

/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*  Variable Externs                                                                                                                 */
/*-----------------------------------------------------------------------------------------------------------------------------------*/

#endif /* ALTAPP_ABG_H 文件到这结束*/

/*===================================================================================================================================*/
/*                                                                                                                                   */
/*  Change History : see altapp_abg.c                                                                                                */
/*                                                                                                                                   */
/*===================================================================================================================================*/
