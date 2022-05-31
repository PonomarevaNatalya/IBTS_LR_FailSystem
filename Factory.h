#include <tchar.h>
#include <windows.h>
#include "exFAT.h"
#include "FAT32.h"
#include "NoFS.h"
#include "NTFS.h"
 class Factory
{
public:
	Factory();
	AbsFSys CreateFS(wchar_t* path);

private:
int DetectionFS(byte *dataBuffer);
};
