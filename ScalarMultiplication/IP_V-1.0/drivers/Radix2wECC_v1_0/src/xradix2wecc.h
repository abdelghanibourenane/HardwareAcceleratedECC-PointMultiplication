// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XRADIX2WECC_H
#define XRADIX2WECC_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xradix2wecc_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
} XRadix2wecc_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XRadix2wecc;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XRadix2wecc_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XRadix2wecc_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XRadix2wecc_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XRadix2wecc_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XRadix2wecc_Initialize(XRadix2wecc *InstancePtr, u16 DeviceId);
XRadix2wecc_Config* XRadix2wecc_LookupConfig(u16 DeviceId);
int XRadix2wecc_CfgInitialize(XRadix2wecc *InstancePtr, XRadix2wecc_Config *ConfigPtr);
#else
int XRadix2wecc_Initialize(XRadix2wecc *InstancePtr, const char* InstanceName);
int XRadix2wecc_Release(XRadix2wecc *InstancePtr);
#endif

void XRadix2wecc_Start(XRadix2wecc *InstancePtr);
u32 XRadix2wecc_IsDone(XRadix2wecc *InstancePtr);
u32 XRadix2wecc_IsIdle(XRadix2wecc *InstancePtr);
u32 XRadix2wecc_IsReady(XRadix2wecc *InstancePtr);
void XRadix2wecc_EnableAutoRestart(XRadix2wecc *InstancePtr);
void XRadix2wecc_DisableAutoRestart(XRadix2wecc *InstancePtr);

void XRadix2wecc_Set_k(XRadix2wecc *InstancePtr, u64 Data);
u64 XRadix2wecc_Get_k(XRadix2wecc *InstancePtr);
void XRadix2wecc_Set_x_o(XRadix2wecc *InstancePtr, u64 Data);
u64 XRadix2wecc_Get_x_o(XRadix2wecc *InstancePtr);
void XRadix2wecc_Set_y_o(XRadix2wecc *InstancePtr, u64 Data);
u64 XRadix2wecc_Get_y_o(XRadix2wecc *InstancePtr);

void XRadix2wecc_InterruptGlobalEnable(XRadix2wecc *InstancePtr);
void XRadix2wecc_InterruptGlobalDisable(XRadix2wecc *InstancePtr);
void XRadix2wecc_InterruptEnable(XRadix2wecc *InstancePtr, u32 Mask);
void XRadix2wecc_InterruptDisable(XRadix2wecc *InstancePtr, u32 Mask);
void XRadix2wecc_InterruptClear(XRadix2wecc *InstancePtr, u32 Mask);
u32 XRadix2wecc_InterruptGetEnabled(XRadix2wecc *InstancePtr);
u32 XRadix2wecc_InterruptGetStatus(XRadix2wecc *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
