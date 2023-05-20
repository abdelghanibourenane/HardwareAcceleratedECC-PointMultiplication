// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xradix2wecc.h"

extern XRadix2wecc_Config XRadix2wecc_ConfigTable[];

XRadix2wecc_Config *XRadix2wecc_LookupConfig(u16 DeviceId) {
	XRadix2wecc_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XRADIX2WECC_NUM_INSTANCES; Index++) {
		if (XRadix2wecc_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XRadix2wecc_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XRadix2wecc_Initialize(XRadix2wecc *InstancePtr, u16 DeviceId) {
	XRadix2wecc_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XRadix2wecc_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XRadix2wecc_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

