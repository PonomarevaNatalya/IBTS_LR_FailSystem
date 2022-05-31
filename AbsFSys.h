#pragma once
#include <iostream>
#include <string.h>
#include "Unit1.h"
class AbsFSys {
protected:
    HANDLE fileHander;
	long Dec10(byte per_A[],int size);

public:
	unsigned long long razmer;
	unsigned long long kolvoClast;
	int razmerClast;
	UnicodeString name;
	bool ReedCluster(int nomer, byte *outBuffer);
	bool ChtenieMBR(wchar_t* fileName, byte *dataBuffer);
};
