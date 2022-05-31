//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall potok::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall potok::potok(AbsFSys Filesys, bool CreateSuspended)
	: TThread(CreateSuspended)
{
  filesys=Filesys;
}
//---------------------------------------------------------------------------
void __fastcall potok::Execute()
{
	Signature signature;
	UnicodeString proverka;
	byte *dataBuffer = new byte[filesys.razmerClast];
	Iterator iterator=Iterator (filesys);
    sqlite3* datab;
   char* filename="DataBase.db";

	if(sqlite3_open( filename,&datab ))
	{
		sqlite3_close(datab);
	}

	if (Form1->Edit1->Text != ""){
	iterator.StartPosition (StrToLong(Form1->Edit1->Text));
	}
	else  iterator.First();

	if (Form1->Edit3->Text != ""){
	iterator.FinalPosition (StrToLong(Form1->Edit3->Text));
	}
	else iterator.End();
	if (iterator.IsDone()) {
	for (;!iterator.IsStart();iterator.Back()) {
		  if (Form1->RadioGroup1->ItemIndex==0)
		  {
			if (iterator.GetCurrent(dataBuffer))
				{
					proverka=signature.Signature_(dataBuffer, Form1->CheckListBox1->Checked[0], Form1->CheckListBox1->Checked[1], Form1->CheckListBox1->Checked[2], Form1->CheckListBox1->Checked[3], Form1->CheckListBox1->Checked[4]);
					if (proverka!="none")
					{
						AnsiString sql="INSERT INTO FILE (ID, NAME) VALUES ("+(AnsiString)iterator.CurrentPosition()+", \""+proverka+"\" );";
						sqlite3_exec(datab, sql.c_str(), NULL, 0,NULL);
					}
				}
		  }
		  if (Form1->RadioGroup1->ItemIndex==1)
		  {
			if (Pusto_Decorator(iterator).GetCurrent(dataBuffer))
				{
					proverka=signature.Signature_(dataBuffer, Form1->CheckListBox1->Checked[0], Form1->CheckListBox1->Checked[1], Form1->CheckListBox1->Checked[2], Form1->CheckListBox1->Checked[3], Form1->CheckListBox1->Checked[4]);
					if (proverka!="none")
					{
						AnsiString sql="INSERT INTO FILE (ID, NAME) VALUES ("+(AnsiString)iterator.CurrentPosition()+", \""+proverka+"\" );";
						sqlite3_exec(datab, sql.c_str(), NULL, 0,NULL);
					}
				}
		  }

		 }
		}

	else{
	  for (;!iterator.IsDone();iterator.Next()) {
		if (Form1->RadioGroup1->ItemIndex==0)
			{
			if (iterator.GetCurrent(dataBuffer))
				{
					proverka=signature.Signature_(dataBuffer, Form1->CheckListBox1->Checked[0], Form1->CheckListBox1->Checked[1], Form1->CheckListBox1->Checked[2], Form1->CheckListBox1->Checked[3], Form1->CheckListBox1->Checked[4]);
					if (proverka!="none")
					{
						AnsiString sql="INSERT INTO FILE (ID, NAME) VALUES ("+(AnsiString)iterator.CurrentPosition()+", \""+proverka+"\" );";
						sqlite3_exec(datab, sql.c_str(), NULL, 0,NULL);
					}
				}
			}
		  if (Form1->RadioGroup1->ItemIndex==1)
		  {
			if (Pusto_Decorator(iterator).GetCurrent(dataBuffer))
			{
			 proverka=signature.Signature_(dataBuffer, Form1->CheckListBox1->Checked[0], Form1->CheckListBox1->Checked[1], Form1->CheckListBox1->Checked[2], Form1->CheckListBox1->Checked[3], Form1->CheckListBox1->Checked[4]);
					if (proverka!="none")
					{
						AnsiString sql="INSERT INTO FILE (ID, NAME) VALUES ("+(AnsiString)iterator.CurrentPosition()+", \""+proverka+"\" );";
						sqlite3_exec(datab, sql.c_str(), NULL, 0,NULL);
					}
			}
		  }
		}
	}

  Synchronize(&UpdateCaption);
  sqlite3_close(datab);
  delete[] dataBuffer;
}
//---------------------------------------------------------------------------
void __fastcall potok::UpdateCaption()
	 {
	   Form1->OpenDB ();
	   Form1->Button1->Enabled=true;
	 }