//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "Pusto_Decorator.h"
#include "Signature.h"
#include "sqlite3.h"
#include "AbsFSys.h"
//---------------------------------------------------------------------------
class potok : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	AbsFSys filesys;
	__fastcall potok(AbsFSys Filesys, bool CreateSuspended);
    void __fastcall UpdateCaption();
};
//---------------------------------------------------------------------------
#endif
