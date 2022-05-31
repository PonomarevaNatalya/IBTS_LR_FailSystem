#include "Signature.h"


UnicodeString Signature::Signature_(BYTE *dataBuffer, bool Pdf, bool Office, bool Z7, bool Vmdk, bool Png){

	byte pdf[7]={0x25,0x50,0x44,0x46,0x2D,0x31,0x2E}; //Adobe Acrobat pdf;ai;ait %PDF\x2D1\x2E
	byte office[11]={0x5F,0x54,0x79,0x70,0x65,0x73,0x5D,0x2E,0x78,0x6D,0x6C}; //MS Office 2007+ docx;xlsx;pptx _Types\]\.xml
	byte z7[5]={0x37,0x7A,0xBC,0xAF,0x27}; //7-Zip Archive 7z 7z\xBC\xAF\x27
	byte vmdk[8]={0x4B,0x44,0x4D,0x56,0x01,0x00,0x00,0x00}; //VMware 4 Virtual Disk vmdk KDMV.\x00\x00\x00
	byte png[8]={0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A}; //PNG png \x89PNG\x0D\x0A\x1A\x0A

	if(Pdf)
		{if(Poisk(pdf,7,dataBuffer))
			return "Pdf";
		}
	if(Office)
		{
		for (int i=0; i<512; i++){
			 for(int j=0; j<11;j++){
					if(office[j]!=dataBuffer[i+j])
					break;
					if (j==10)
					return "office";
				}
            }

		}
	if(Z7)
		{if(Poisk(z7,5,dataBuffer))
			return "z7";
		}
	if(Vmdk)
		{if(Poisk(vmdk,8,dataBuffer))
			return "vmdk";
		}
	if(Png)
		{if(Poisk(png,8,dataBuffer))
			return "png";
		}


	return "none";

}

bool Signature::Poisk(BYTE sign[],int length,BYTE *dataBuffer){
	for(int i=0; i<length;i++)
	{
	  if(sign[i]!=dataBuffer[i])
		return false;
	}
	return true;
}
