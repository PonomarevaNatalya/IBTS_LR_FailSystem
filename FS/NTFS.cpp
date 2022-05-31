#include <iostream>
#include "NTFS.h"


	NTFS::NTFS(wchar_t* path)
	{
	byte *dataBuffer = new byte[512];

	ChtenieMBR(path,dataBuffer);

	NTFS_MBR* pNTFS_MBR = (NTFS_MBR*)dataBuffer;

	int BaitSect=Dec10(pNTFS_MBR->BaitSect,sizeof(pNTFS_MBR->BaitSect));
	int SectKlast=Dec10(pNTFS_MBR->SectKlast,sizeof(pNTFS_MBR->SectKlast));
	unsigned long long KolvoSect=Dec10(pNTFS_MBR->KolvoSect,sizeof(pNTFS_MBR->KolvoSect));

	razmerClast=BaitSect*SectKlast;
	kolvoClast=KolvoSect/SectKlast;
	razmer=kolvoClast*razmerClast;
	name="NTFS";

	delete[] dataBuffer;
	}

