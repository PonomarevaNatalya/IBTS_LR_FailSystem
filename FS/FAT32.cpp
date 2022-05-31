#include <iostream>
#include "FAT32.h"

FAT32::FAT32(wchar_t* path)
	{
	byte *dataBuffer = new byte[512];

	ChtenieMBR(path,dataBuffer);

	FAT32_MBR* pFAT32_MBR = (FAT32_MBR*)dataBuffer;

	int BaitSect=Dec10(pFAT32_MBR->BaitSect,sizeof(pFAT32_MBR->BaitSect));
	int SectKlast=Dec10(pFAT32_MBR->SectKlast,sizeof(pFAT32_MBR->SectKlast));
	unsigned long long KolvoSect=Dec10(pFAT32_MBR->KolvoSect,sizeof(pFAT32_MBR->KolvoSect));
	int  Rezerv=Dec10(pFAT32_MBR->Rezerv,sizeof(pFAT32_MBR->Rezerv));
	int kolvoCopyFat=Dec10(pFAT32_MBR->kolvoCopyFat,sizeof(pFAT32_MBR->kolvoCopyFat));
	unsigned long long razmerFat=Dec10(pFAT32_MBR->razmerFat,sizeof(pFAT32_MBR->razmerFat));

	razmerClast=BaitSect*SectKlast;
	kolvoClast=(KolvoSect-Rezerv-kolvoCopyFat*razmerFat)/SectKlast;
	razmer=kolvoClast*razmerClast;
    name="FAT32";

	delete[] dataBuffer;
	}
