//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include <sstream>
#include "Unit1.h"
#include "Unit2.h"
#include "Factory.h"
#include "sqlite3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
AbsFSys filesys;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	yaPotok = NULL;
	VirtualStringTree1->NodeDataSize =sizeof(Struct);
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	  UnicodeString  str1 = "\\\\.\\";
	  UnicodeString  str2 = Edit2->Text;
	  UnicodeString  str4 = str1+str2+":";

wchar_t *fileName = str4.t_str();
	  Factory factory;
	  filesys = factory.CreateFS(fileName);
	  if (filesys.name != "Unknown FS") {
	   Button1->Enabled=true;
	  }
	  else Button1->Enabled=false;
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




void __fastcall TForm1::Button1Click(TObject *Sender)
{
	yaPotok=new potok(filesys,false);
    Button1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
if (Edit1->Text != "" && StrToLong(Edit1->Text)>filesys.kolvoClast )
{
ShowMessage(L"Ошибка, значение больше допустимого.");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Exit(TObject *Sender)
{
if (Edit3->Text != "" && StrToLong(Edit3->Text)>filesys.kolvoClast )
{
ShowMessage(L"Ошибка, значение больше допустимого.");
}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button2Click(TObject *Sender)
{
  sqlite3* datab;
   char* filename="DataBase.db";
   PVirtualNode choiseStr=VirtualStringTree1->GetFirstSelected();
   if(choiseStr==NULL) return;

Struct *nodeData=(Struct*)VirtualStringTree1->GetNodeData(choiseStr);
AnsiString str="Delete from file where id = "+(AnsiString)nodeData->nomer+" ;";

   sqlite3_stmt *pStmt;
   char* errmsg;

if(sqlite3_open( filename,&datab ))
{
	sqlite3_close(datab);
}

int result=sqlite3_prepare_v2(datab,str.c_str(),-1,&pStmt,NULL);
if(result!=SQLITE_OK)
{
	errmsg=(char*)sqlite3_errmsg(datab);
	sqlite3_close(datab);
	return;
}

result=sqlite3_step(pStmt);
if(result!=SQLITE_DONE)
{
	sqlite3_finalize(pStmt);
	sqlite3_close(datab);
	return;
}

sqlite3_finalize(pStmt);
sqlite3_close(datab);
OpenDB ();
}



//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
 sqlite3* datab;
   char* filename="DataBase.db";
   AnsiString str="Delete from file ;";
   sqlite3_stmt *pStmt;
   char* errmsg;

if(sqlite3_open( filename,&datab ))
{
	sqlite3_close(datab);
}

int result=sqlite3_prepare_v2(datab,str.c_str(),-1,&pStmt,NULL);
if(result!=SQLITE_OK)
{
	errmsg=(char*)sqlite3_errmsg(datab);
	sqlite3_close(datab);
	return;
}

result=sqlite3_step(pStmt);
if(result!=SQLITE_DONE)
{
	sqlite3_finalize(pStmt);
	sqlite3_close(datab);
	return;
}
	sqlite3_finalize(pStmt);
	sqlite3_close(datab);
    VirtualStringTree1->Clear();
}

void TForm1::OpenDB()
{
VirtualStringTree1->Clear();
   VirtualStringTree1->BeginUpdate();

		 char* filename = "DataBase.db";
		 AnsiString str="Select * from file ;";
		 sqlite3 *datab;
		 sqlite3_stmt *pStmt;
		 const char *errmsg;

		if (sqlite3_open(filename,&datab))
			{
		ShowMessage("Can't open database: " + (String)sqlite3_errmsg(datab));
		sqlite3_close(datab);
		return;
			}
		int resault = sqlite3_prepare_v2(datab, str.c_str(), -1, &pStmt, NULL);
		if (resault != SQLITE_OK)
		{
			errmsg = sqlite3_errmsg(datab);
		}

		while (true)
		{
			resault = (sqlite3_step(pStmt));
			if (resault != SQLITE_ROW) {
			   break;
			}
			PVirtualNode entryNode = VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);
			Struct *nodeData = (Struct*) VirtualStringTree1->GetNodeData(entryNode);
			int col = sqlite3_data_count(pStmt);

			for(int k=0; k<col; k++)
			{
			AnsiString otwet;
			otwet.printf("%s",sqlite3_column_text(pStmt, k));
				  switch (k) {
					case 0:
					  {
						  nodeData->nomer =otwet.ToInt();;
						  break;
					  }
					case 1:
					  {
						  nodeData->type = UnicodeString(otwet);
						  break;
					  }

				  }

			}

		}

	sqlite3_finalize(pStmt);
	sqlite3_close(datab);
 VirtualStringTree1->EndUpdate();
}
void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
 if(Node == NULL) return;
	  Struct *nodeData = (Struct*) VirtualStringTree1->GetNodeData(Node);

	  switch (Column) {
	  case 0:
	  {
		  CellText = (UnicodeString)nodeData->nomer;
		  break;
	  }
	  case 1:
	  {
		  CellText = nodeData->type;
		  break;
	  }

	  }
}
//---------------------------------------------------------------------------

