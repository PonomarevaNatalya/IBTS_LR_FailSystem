#include <iostream>
#include "Factory.h"

	Factory::Factory(){}
	AbsFSys Factory::CreateFS(wchar_t* path)
{
	AbsFSys File;
	int fs=0;
	byte *dataBuffer = new byte[512];
	if(File.ChtenieMBR(path, dataBuffer))
	{
	fs=DetectionFS(dataBuffer);
	}
	delete[]  dataBuffer;

	switch (fs){

	case(1):
	File=exFAT(path);
	break;

	case(2):
	File=FAT32(path);
	break;

	case(3):
	File=NTFS(path);
	break;

	case(0):
	File=NoFS();
	break;
	}
	return  File;
}


int Factory::DetectionFS(byte *dataBuffer)
{
	  byte exfat[5]={69, 88, 70, 65, 84};
	  byte fat32[8]={77, 83, 68, 79, 83, 53, 46, 48};
	  byte ntfs[4]={78, 84, 70, 83};

	   for(int i=0;i<sizeof(exfat);i++)
	   {
		if(exfat[i]!=dataBuffer[i+3])
		break;
		if(i==sizeof(exfat)-1)
		return 1;
	   }
	   for(int i=0;i<sizeof(fat32);i++)
	   {
		if(fat32[i]!=dataBuffer[i+3])
		break;
		if(i==sizeof(fat32)-1)
		return 2;
	   }
	   for(int i=0;i<sizeof(ntfs);i++)
	   {
		if(ntfs[i]!=dataBuffer[i+3])
		break;
		if(i==sizeof(ntfs)-1)
		return 3;
	   }
		return 0;

}
