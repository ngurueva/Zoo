//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <System.ImageList.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ImgList.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TLabel *Label1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N13;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TSaveDialog *SaveDialog1;
	TMenuItem *N21;
	TOpenDialog *OpenDialog1;
	TMenuItem *N16;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TMenuItem *N25;
	TPopupMenu *i;
	TMenuItem *N26;
	TMenuItem *N27;
	TMenuItem *N28;
	TImageList *ImageList1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolButton *ToolButton14;
	TToolButton *ToolButton15;
	TToolButton *ToolButton16;
	TStatusBar *StatusBar1;
	TPopupMenu *PopupMenu1;
	TMenuItem *PopupMenu11;
	TMenuItem *N29;
	TMenuItem *N30;
	TMenuItem *N31;
	TMenuItem *N32;
	TMenuItem *N33;
	TMenuItem *N34;
	TMenuItem *N15;
	TMenuItem *N35;
	TMenuItem *N36;
	TMenuItem *N37;
	TMenuItem *N38;
	TMenuItem *N39;
	TMenuItem *N40;
	TMenuItem *N41;
	TMenuItem *N42;
	TMenuItem *N43;
	TToolButton *ToolButton17;
	TToolButton *ToolButton18;
	TToolButton *ToolButton19;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N21Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N20Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall N16Click(TObject *Sender);
	void __fastcall N22Click(TObject *Sender);
	void __fastcall N23Click(TObject *Sender);
	void __fastcall N24Click(TObject *Sender);
	void __fastcall N25Click(TObject *Sender);
	void __fastcall N18Click(TObject *Sender);
	void __fastcall N19Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall N37Click(TObject *Sender);
	void __fastcall N36Click(TObject *Sender);
	void __fastcall N38Click(TObject *Sender);
	void __fastcall N39Click(TObject *Sender);
	void __fastcall N15Click(TObject *Sender);
	void __fastcall N35Click(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall N43Click(TObject *Sender);
	void __fastcall N42Click(TObject *Sender);


private:	// User declarations
		bool dataSaved;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
    		AnsiString currentFileName;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
