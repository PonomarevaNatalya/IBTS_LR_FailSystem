#pragma once
#include <iostream>
#include <string.h>
class AbsFSys {
protected:

	HANDLE fileHander;

	long Dec10(byte per_A[],int size)
{
	long sum=0;
	for (int i = 0; i < size; i++)
	{
		sum+=per_A[i]*std::pow(16,i*2);
	}
	return sum;
}




public:
	unsigned long long razmer;
	unsigned long long kolvoClast;
	int razmerClast;
	AnsiString name;

	bool ReedCluster(int nomer, byte *outBuffer){

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=razmerClast*nomer;

	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
	  ShowMessage (L"Ошибка установки курсора.");
	  CloseHandle (fileHander);
	   return false;
	 }

	 DWORD bytesToRead=razmerClast;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,outBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
		ShowMessage (L"Ошибка чтения.");
	   CloseHandle (fileHander);
	   return false;
	 }
	 return true;
	}


    bool ChtenieMBR(wchar_t* fileName, byte *dataBuffer){

	fileHander=CreateFileW(fileName,
	GENERIC_READ,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	OPEN_EXISTING,
	FILE_ATTRIBUTE_NORMAL,
	NULL);

	if(fileHander == INVALID_HANDLE_VALUE)
	{
	ShowMessage (L"Не удалось открыть диск.\nИспользуйте запуск exe-файла с правами администратора.");
	CloseHandle (fileHander);
	  return false;
	}

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=0;

	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
	  ShowMessage (L"Ошибка установки курсора.");
	  CloseHandle (fileHander);
		return false;
	 }

	 DWORD bytesToRead=512;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,dataBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
		ShowMessage (L"Ошибка чтения.");
		CloseHandle (fileHander);
		return false;
	 }

	   return true;
	}
};
