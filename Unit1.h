//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "VirtualTrees.hpp"
#include <Vcl.CheckLst.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label3;
	TButton *Button3;
	TEdit *Edit2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit3;
	TLabel *Label7;
	TRadioGroup *RadioGroup1;
	TVirtualStringTree *VirtualStringTree1;
	TButton *Button2;
	TButton *Button4;
	TCheckListBox *CheckListBox1;
	TLabel *Label2;

	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
		  TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void OpenDB();
    class potok *yaPotok;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
typedef struct{

	int nomer;
	UnicodeString type;
} Struct;
#endif
