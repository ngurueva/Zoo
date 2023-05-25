//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<cctype>
#include<System.Character.hpp>

#include "Unit1.h"
#include "Unit2.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
if (Edit1->Text.IsEmpty() || Edit2->Text.IsEmpty() || Edit3->Text.IsEmpty() ||
		Edit4->Text.IsEmpty() || Edit5->Text.IsEmpty()) {
		ShowMessage("Пожалуйста, заполните все поля");
	} else {
		if (Button1->Caption == "Добавить") {
            Edit1->Text = Edit1->Text.SubString(1,1).UpperCase()+ Edit1->Text.SubString(2,Edit1->Text.Length());
			Edit2->Text = Edit2->Text.SubString(1,1).UpperCase()+ Edit2->Text.SubString(2,Edit2->Text.Length());
			Edit4->Text = Edit4->Text.SubString(1,1).UpperCase()+ Edit4->Text.SubString(2,Edit4->Text.Length());
			Edit5->Text = Edit5->Text.SubString(1,1).UpperCase()+ Edit5->Text.SubString(2,Edit5->Text.Length());

			Form2->StringGrid1->RowCount++; // Добавляем новую строку
			int lastRow = Form2->StringGrid1->RowCount - 1; // Индекс последней строки
			Form2->StringGrid1->Cells[0][lastRow] = IntToStr(lastRow); // №
			Form2->StringGrid1->Cells[1][lastRow] = Edit1->Text; // Вид
			Form2->StringGrid1->Cells[2][lastRow] = Edit2->Text; // Кличка
			Form2->StringGrid1->Cells[3][lastRow] = Edit3->Text; // Возраст
			Form2->StringGrid1->Cells[4][lastRow] = Edit4->Text; // Рацион
			Form2->StringGrid1->Cells[5][lastRow] = Edit5->Text; // ФИО отвественного

			// Очищаем поля ввода после добавления
			Edit1->Clear();
			Edit2->Clear();
			Edit3->Clear();
			Edit4->Clear();
			Edit5->Clear();

			Close();
		}
		else if (Button1->Caption == "Редактировать") {

        Edit1->SetFocus();
		Edit1->Text = Edit1->Text.SubString(1,1).UpperCase()+ Edit1->Text.SubString(2,Edit1->Text.Length());
		Edit2->Text = Edit2->Text.SubString(1,1).UpperCase()+Edit2->Text.SubString(2,Edit2->Text.Length());
		Edit4->Text = Edit4->Text.SubString(1,1).UpperCase()+Edit4->Text.SubString(2,Edit4->Text.Length());
		Edit5->Text = Edit5->Text.SubString(1,1).UpperCase()+Edit5->Text.SubString(2,Edit5->Text.Length());

			int lastRow = Form2->StringGrid1->Row; // Индекс выбранной строки
			Form2->StringGrid1->Cells[1][lastRow] = Edit1->Text; // Вид
			Form2->StringGrid1->Cells[2][lastRow] = Edit2->Text; // Кличка
			Form2->StringGrid1->Cells[3][lastRow] = Edit3->Text; // Возраст
			Form2->StringGrid1->Cells[4][lastRow] = Edit4->Text; // Рацион
			Form2->StringGrid1->Cells[5][lastRow] = Edit5->Text; // ФИО отвественного

		// Очищаем поля ввода после добавления
		Edit1->Clear();
		Edit2->Clear();
		Edit3->Clear();
		Edit4->Clear();
		Edit5->Clear();

		Close();
	}


}

}
//---------------------------------------------------------------------------

//Переводить фокус на следующий компонент---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN) Edit2->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN) Edit3->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN) Edit4->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN) Edit5->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit5KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if(Key == VK_RETURN) Button1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key){
	if(!Character::IsLetter(Key) && Key != VK_BACK && Key!=VK_RETURN && Key!=VK_SPACE)
	{
		ShowMessage("Введите только буквы");  Key = 0; // Отменить ввод
	}
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2KeyPress(TObject *Sender, System::WideChar &Key){
	if(!Character::IsLetter(Key) && Key != VK_BACK && Key!=VK_RETURN && Key!=VK_SPACE)
	{
		ShowMessage("Введите только буквы");  Key = 0; // Отменить ввод
	}
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3KeyPress(TObject *Sender, System::WideChar &Key){
	if (!std::isdigit(Key) && Key != VK_BACK && Key!=VK_RETURN) // Если это не цифра и не клавиша Backspace
	{
		ShowMessage("Введите только цыфры");  Key = 0; // Отменить ввод
	}
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4KeyPress(TObject *Sender, System::WideChar &Key){
	if(!Character::IsLetter(Key) && Key != VK_BACK && Key!=VK_RETURN && Key!=VK_SPACE)
	{
		ShowMessage("Введите только буквы");  Key = 0; // Отменить ввод
	}
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit5KeyPress(TObject *Sender, System::WideChar &Key){
	if(!Character::IsLetter(Key) && Key != VK_BACK && Key!=VK_RETURN && Key!=VK_SPACE)
	{
		ShowMessage("Введите только буквы");  Key = 0; // Отменить ввод
	}
 }
