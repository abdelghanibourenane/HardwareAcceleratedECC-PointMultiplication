// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xradix2wecc.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XRadix2wecc_CfgInitialize(XRadix2wecc *InstancePtr, XRadix2wecc_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XRadix2wecc_Start(XRadix2wecc *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_AP_CTRL) & 0x80;
    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XRadix2wecc_IsDone(XRadix2wecc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XRadix2wecc_IsIdle(XRadix2wecc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XRadix2wecc_IsReady(XRadix2wecc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XRadix2wecc_EnableAutoRestart(XRadix2wecc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XRadix2wecc_DisableAutoRestart(XRadix2wecc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_AP_CTRL, 0);
}

void XRadix2wecc_Set_k(XRadix2wecc *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_K_DATA, (u32)(Data));
    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_K_DATA + 4, (u32)(Data >> 32));
}

u64 XRadix2wecc_Get_k(XRadix2wecc *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_K_DATA);
    Data += (u64)XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_K_DATA + 4) << 32;
    return Data;
}

void XRadix2wecc_Set_x_o(XRadix2wecc *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_X_O_DATA, (u32)(Data));
    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_X_O_DATA + 4, (u32)(Data >> 32));
}

u64 XRadix2wecc_Get_x_o(XRadix2wecc *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_X_O_DATA);
    Data += (u64)XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_X_O_DATA + 4) << 32;
    return Data;
}

void XRadix2wecc_Set_y_o(XRadix2wecc *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_Y_O_DATA, (u32)(Data));
    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_Y_O_DATA + 4, (u32)(Data >> 32));
}

u64 XRadix2wecc_Get_y_o(XRadix2wecc *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_Y_O_DATA);
    Data += (u64)XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_Y_O_DATA + 4) << 32;
    return Data;
}

void XRadix2wecc_InterruptGlobalEnable(XRadix2wecc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_GIE, 1);
}

void XRadix2wecc_InterruptGlobalDisable(XRadix2wecc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_GIE, 0);
}

void XRadix2wecc_InterruptEnable(XRadix2wecc *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_IER);
    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_IER, Register | Mask);
}

void XRadix2wecc_InterruptDisable(XRadix2wecc *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_IER);
    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_IER, Register & (~Mask));
}

void XRadix2wecc_InterruptClear(XRadix2wecc *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRadix2wecc_WriteReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_ISR, Mask);
}

u32 XRadix2wecc_InterruptGetEnabled(XRadix2wecc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_IER);
}

u32 XRadix2wecc_InterruptGetStatus(XRadix2wecc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRadix2wecc_ReadReg(InstancePtr->Control_BaseAddress, XRADIX2WECC_CONTROL_ADDR_ISR);
}

