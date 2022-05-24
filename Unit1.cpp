//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include <sstream>
#include <iterator>
#include "Unit1.h"
#include "Factory.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AbsFSys filesys;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	  wchar_t *fileName = L"\\\\.\\K:";
	  filesys = FAT32(fileName);
	  Label1->Caption=L"Размер кластера: ";
	  Label1->Caption+=filesys.razmerClast;
	  Label1->Caption+=L"\nКоличество кластеров: ";
	  Label1->Caption+=filesys.kolvoClast;
	  Label1->Caption+=L"\nРазмер ФС: ";
	  Label1->Caption+=filesys.razmer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
long nomer;
   byte *dataBuffer = new byte[filesys.razmerClast];
  if (Edit1->Text == "") {
	  nomer=0;
  }
  else
    nomer=StrToLong(Edit1->Text);
  if (filesys.ReedCluster(nomer, dataBuffer))
  {
   String s1;
	Label2->Caption = "";
			for (int i = 0; i < filesys.razmerClast; i++)
		{
		s1 += reinterpret_cast<char*>(dataBuffer)[i];
		if(i%64 == 63)
		{
			String s2;
		   std::stringstream ss;
			for (const auto &item : s1) {
				if (int(item)>65280) {
					 ss << std::hex << int(item)-65280;
				}
				 else

				if (int(item)<=15) {
					ss << std::hex << "0" << int(item);
				}
				else
				ss << std::hex << int(item);
				ss << " ";
			}
		   //	s2 = ss.str();
			Label2->Caption += s2;
			Label2->Caption += "\n";
			s1="";
		}
		}
  }
  delete[] dataBuffer;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	  UnicodeString  str1 = "\\\\.\\";
	  UnicodeString  str2 = Edit2->Text;
	  UnicodeString  str4 = str1+str2+":";

wchar_t *fileName = str4.t_str();
	  Factory factory;
	  filesys = factory.CreateFS(fileName);
	  Label1->Caption=L"Название ФС: ";
	  Label1->Caption+=filesys.name;
	  Label1->Caption+=L"\nРазмер кластера: ";
	  Label1->Caption+=filesys.razmerClast;
	  Label1->Caption+=L"\nКоличество кластеров: ";
	  Label1->Caption+=filesys.kolvoClast;
	  Label1->Caption+=L"\nРазмер ФС: ";
	  Label1->Caption+=filesys.razmer;
}
//---------------------------------------------------------------------------

