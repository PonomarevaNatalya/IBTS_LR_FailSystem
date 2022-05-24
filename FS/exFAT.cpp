#include <iostream>
#include "exFAT.h"

class exFAT : public AbsFSys
{
public:
	exFAT(wchar_t* path)
	{
	byte *dataBuffer = new byte[512];

	ChtenieMBR(path,dataBuffer);

	exFAT_MBR* pexFAT_MBR = (exFAT_MBR*)dataBuffer;

	unsigned long long Kolvoclast=Dec10(pexFAT_MBR->Kolvoclast,sizeof(pexFAT_MBR->Kolvoclast));
	int razm2Sec=Dec10(pexFAT_MBR->razm2Sec,sizeof(pexFAT_MBR->razm2Sec));
	int  clastMnoz=Dec10(pexFAT_MBR->clastMnoz,sizeof(pexFAT_MBR->clastMnoz));

	kolvoClast=Kolvoclast;
	razmerClast=std::pow(2,razm2Sec)*std::pow(2,clastMnoz);
	razmer=razmerClast*kolvoClast;
	name="exFAT";

	delete[] dataBuffer;
	}

	
};
