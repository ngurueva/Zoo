//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include <System.StrUtils.hpp>

#include <map>
#include <fstream>
#pragma hdrstop
#include <map>
#include "Unit2.h"
#include "Unit1.h"
#include <vector>
#include "About.h"


#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern bool rad;


struct Zoopark {
	int id;
	char species[50]; // ���
	char nickname[50]; // ������
	int age; // �������
	char diet[50]; // ������
	char caregiver[50]; // ��� ��������������
};

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TForm2::FormCreate(TObject *Sender)
{
   StringGrid1->Cells[0][0]="�";
   StringGrid1->Cells[1][0]="���";
   StringGrid1->Cells[2][0]="������";
   StringGrid1->Cells[3][0]="�������";
   StringGrid1->Cells[4][0]="������";
   StringGrid1->Cells[5][0]="��� ��������������";

   Form3 = new TForm3(this);
   Form3->ShowModal();
   Form3->Free();
}
//---------------------------------------------------------------------------



void __fastcall TForm2::N8Click(TObject *Sender)
{
	// ������� ���� ����� ����� ����������
	Form1->Edit1->Clear();
	Form1->Edit2->Clear();
	Form1->Edit3->Clear();
	Form1->Edit4->Clear();
	Form1->Edit5->Clear();


	Form1->Button1->Caption = "��������"; // ��������������� Button1 �� "�������������"
	Form1->ShowModal(); // ��������� Form1

    int rCount;
	for (int i = 0; i < StringGrid1->RowCount; i++)
	{
		  rCount = i;
	}
	StatusBar1->Panels->Items[0]->Text = "����� ���������: " + IntToStr(rCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N10Click(TObject *Sender)
{
	int row = StringGrid1->Row; // �������� ������ ������� ������
	if (row >= 1 && row < StringGrid1->RowCount) // ���������, ��� ������ ������������� ����������
	{
		if (MessageDlg("�� �������, ��� ������ �������: \n" + StringGrid1->Cells[1][row] + " " + StringGrid1->Cells[2][row], mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
			for (int i = row; i < StringGrid1->RowCount - 1; i++)
			{
				for (int j = 0; j < StringGrid1->ColCount; j++)
				{
					StringGrid1->Cells[j][i] = StringGrid1->Cells[j][i + 1]; // �������� ��� ������ ����� �� ���� �������
				}
			}
			StringGrid1->RowCount--; // ��������� ���������� ����� �� 1

			// ��������� ������ �����
			for (int i = 1; i < StringGrid1->RowCount; i++)
			{
				StringGrid1->Cells[0][i] = IntToStr(i);
			}
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm2::N9Click(TObject *Sender)
{
	if (StringGrid1->Row > 0) { // ���� ������� ������
		// ��������� ���� �� Form2 ������� �� ��������� ������
		Form1->Edit1->Text = StringGrid1->Cells[1][StringGrid1->Row];
		Form1->Edit2->Text = StringGrid1->Cells[2][StringGrid1->Row];
		Form1->Edit3->Text = StringGrid1->Cells[3][StringGrid1->Row];
		Form1->Edit4->Text = StringGrid1->Cells[4][StringGrid1->Row];
		Form1->Edit5->Text = StringGrid1->Cells[5][StringGrid1->Row];
		Form1->Button1->Caption = "�������������"; // ��������������� Button1 �� "�������������"
		Form1->ShowModal(); // ��������� Form1
	}
	else {
		ShowMessage("�������� ������ ��� ��������������");
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::N21Click(TObject *Sender)
{
	SaveDialog1->Filter = "Binary files (*.bin)|*.bin";
	SaveDialog1->DefaultExt = "bin";

	if (SaveDialog1->Execute()) {
		std::ofstream outFile(SaveDialog1->FileName.c_str(), std::ios::out | std::ios::binary);
		if (!outFile) {
			ShowMessage("������ ��� �������� �����");
		} else {
            ShowMessage("���� ������� ������");
			outFile.close();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N2Click(TObject *Sender)
{
  	OpenDialog1->Filter = "Binary files (*.bin)|*.bin";
	OpenDialog1->DefaultExt = "bin";
	if (OpenDialog1->Execute()) {
		std::ifstream inFile(OpenDialog1->FileName.c_str(), std::ios::in | std::ios::binary);
		if (!inFile) {
			ShowMessage("������ ��� �������� �����");
		} else {
			currentFileName = OpenDialog1->FileName; // ��������� currentFileName

			Zoopark zoopark ;
			StringGrid1->RowCount = 2; // ��������� � ������ ������ ������
			while (inFile.read((char*)&zoopark, sizeof(Zoopark))) {
				StringGrid1->Cells[0][StringGrid1->RowCount - 1] = zoopark.id;
				StringGrid1->Cells[1][StringGrid1->RowCount - 1] = zoopark.species;
				StringGrid1->Cells[2][StringGrid1->RowCount - 1] = zoopark.nickname;
				StringGrid1->Cells[3][StringGrid1->RowCount - 1] = zoopark.age;
				StringGrid1->Cells[4][StringGrid1->RowCount - 1] = zoopark.diet;
				StringGrid1->Cells[5][StringGrid1->RowCount - 1] = zoopark.caregiver;
				StringGrid1->RowCount++; // ��������� ������ ��� ���������� ��������
			}
			StringGrid1->RowCount--; // ������� ������ ������ � �����
			inFile.close();
		}
	}
	int rCount;
	for (int i = 0; i < StringGrid1->RowCount; i++)
	{
		  rCount = i;
	}
	StatusBar1->Panels->Items[0]->Text = "����� ���������: " + IntToStr(rCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N4Click(TObject *Sender)
{
	SaveDialog1->Filter = "Binary files (*.bin)|*.bin";
	SaveDialog1->DefaultExt = "bin";
	if (SaveDialog1->Execute()) {
		currentFileName = SaveDialog1->FileName; // ��������� currentFileName
		std::ofstream outFile(currentFileName.c_str(), std::ios::out | std::ios::binary);
		if (!outFile) {
			ShowMessage("������ ��� ���������� �����");
		} else {
			Zoopark zoopark;
			for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ���������
				zoopark.id = StrToInt(StringGrid1->Cells[0][i]);
				strncpy(zoopark.species, AnsiString(StringGrid1->Cells[1][i]).c_str(), sizeof(zoopark.species));
				strncpy(zoopark.nickname, AnsiString(StringGrid1->Cells[2][i]).c_str(), sizeof(zoopark.nickname));
				zoopark.age = StrToFloat(StringGrid1->Cells[3][i]);
				strncpy(zoopark.diet, AnsiString(StringGrid1->Cells[4][i]).c_str(), sizeof(zoopark.diet));
				strncpy(zoopark.caregiver, AnsiString(StringGrid1->Cells[5][i]).c_str(), sizeof(zoopark.caregiver));
				outFile.write((char*)&zoopark, sizeof(Zoopark));
			}
			outFile.close();
			ShowMessage("���� ������� ��������");
		}
	}
}

//---------------------------------------------------------------------------

void __fastcall TForm2::N3Click(TObject *Sender)
{
	if (!currentFileName.IsEmpty())
	{
		std::ofstream outFile(currentFileName.c_str(), std::ios::out | std::ios::binary);
		if (!outFile)
		{
			ShowMessage("������ ��� ���������� �����");
		} else {
			Zoopark zoopark;
			for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ���������
				zoopark.id = StrToInt(StringGrid1->Cells[0][i]);
				strncpy(zoopark.species, AnsiString(StringGrid1->Cells[1][i]).c_str(), sizeof(zoopark.species));
				strncpy(zoopark.nickname, AnsiString(StringGrid1->Cells[2][i]).c_str(), sizeof(zoopark.nickname));
				zoopark.age = StrToFloat(StringGrid1->Cells[3][i]);
				strncpy(zoopark.diet, AnsiString(StringGrid1->Cells[4][i]).c_str(), sizeof(zoopark.diet));
				strncpy(zoopark.caregiver, AnsiString(StringGrid1->Cells[5][i]).c_str(), sizeof(zoopark.caregiver));
				outFile.write((char*)&zoopark, sizeof(Zoopark));
			}
			outFile.close();
			ShowMessage("���� ������� ��������");
		}
	}
	else {
		ShowMessage("������: ��� ��������� ����� ��� ����������");
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



void __fastcall TForm2::N20Click(TObject *Sender)
{
	UnicodeString lastModified = "2023-05-24";
	UnicodeString author = "������� ������� \n     nata.gurueva@gmail.com \n    +79240119065";

	UnicodeString message = "���� �������� ��������� ���������: " + lastModified + "\n"
		+ "�����: " + author;

	ShowMessage(message);
}

//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
	// ���������, ��������� �� ������
	if (!dataSaved) {
		if (MessageBox(NULL, L"�� �� ��������� ���� ������. �� ������ ��������� �� ����� �������?", L"��������������", MB_YESNO | MB_ICONQUESTION) == IDYES) {
			N4Click(NULL);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N16Click(TObject *Sender)
{
	UnicodeString searchText = InputBox("�����", "������� �������� ����", "");
	int searchType = MessageDlg("����� �� ������� ����������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);

	// ������ ����������
	if (searchType == mrYes) {
		for (int i = 1; i < StringGrid1->RowCount; i++) {
			if (StringGrid1->Cells[1][i] == searchText) {
				StringGrid1->Row = i; // �������� ��������� ������
				ShowMessage("������ ���: " + searchText + "\n � �������� ������ - " + StringGrid1->Cells[2][i] + "\n ������� - " + StringGrid1->Cells[3][i] + "\n ������ - " + StringGrid1->Cells[4][i] + "\n ������������� - " + StringGrid1->Cells[5][i]);
				return;
			}
		}
    }
	// ������ ������
	else if (searchType == mrNo) {
		for (int i = 1; i < StringGrid1->RowCount; i++) {
			if (AnsiStartsText(searchText, StringGrid1->Cells[1][i])) {
				StringGrid1->Row = i; // �������� ��������� ������
				ShowMessage("������ ���: " + StringGrid1->Cells[1][i] + "\n � �������� ������ - " + StringGrid1->Cells[2][i] + "\n ������� - " + StringGrid1->Cells[3][i] + "\n ������ - " + StringGrid1->Cells[4][i] + "\n ������������� - " + StringGrid1->Cells[5][i]);
				return;
			}
		}
	}
	// ������
	else {
		return;
	}

    ShowMessage("��� �� ������");
}

//---------------------------------------------------------------------------

void __fastcall TForm2::N22Click(TObject *Sender)
{
	UnicodeString searchText = InputBox("�����", "������� ������", "");
	int searchType = MessageDlg("����� �� ������� ����������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);
	// ������ ����������
	if (searchType == mrYes) {
	for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
	   if (StringGrid1->Cells[2][i] == searchText) {
		   StringGrid1->Row = i; // �������� ��������� ������
		   ShowMessage("������� ������: " + searchText + "\n � �������� ��� - " + StringGrid1->Cells[1][i] + "\n ������� - " + StringGrid1->Cells[3][i] + "\n ������ - " + StringGrid1->Cells[4][i] + "\n ������������� - " + StringGrid1->Cells[5][i]);
		   return;
	   }
	}
	}

	// ������ ������
	else if (searchType == mrNo) {
		for (int i = 1; i < StringGrid1->RowCount; i++) {
			if (AnsiStartsText(searchText, StringGrid1->Cells[2][i])) {
				StringGrid1->Row = i; // �������� ��������� ������
				ShowMessage("������ ������: " + StringGrid1->Cells[2][i] + "\n � �������� ��� - " + StringGrid1->Cells[1][i] + "\n ������� - " + StringGrid1->Cells[3][i] + "\n ������ - " + StringGrid1->Cells[4][i] + "\n ������������� - " + StringGrid1->Cells[5][i]);
				return;
			}
		}
	}

        // ������
	else {
		return;
	}

   ShowMessage("������ �� �������");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N23Click(TObject *Sender)
{
	UnicodeString searchText = InputBox("�����", "������� �������", "");
   for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
	   if (StringGrid1->Cells[3][i] == searchText) {
		   StringGrid1->Row = i; // �������� ��������� ������
		   ShowMessage("������ �������� �������: " + searchText + "\n � ��������� - " + StringGrid1->Cells[1][i] + " " + StringGrid1->Cells[2][i] + "\n ������ - " + StringGrid1->Cells[4][i] + "\n ������������� - " + StringGrid1->Cells[5][i]);
		   return;
	   }
   }
   ShowMessage("������� �� ������");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N24Click(TObject *Sender)
{
	UnicodeString searchText = InputBox("�����", "������� ������", "");
	int searchType = MessageDlg("����� �� ������� ����������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);

	// ������ ����������
	if (searchType == mrYes) {
   for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
	   if (StringGrid1->Cells[4][i] == searchText) {
		   StringGrid1->Row = i; // �������� ��������� ������
		   ShowMessage("������ ������: " + searchText + "\n � ��������� - " + StringGrid1->Cells[1][i] + " " + StringGrid1->Cells[2][i] + "\n ������ - " + StringGrid1->Cells[4][i] + "\n ������������� - " + StringGrid1->Cells[5][i]);
		   return;
	   }
   }
   }


	// ������ ������
	else if (searchType == mrNo) {
		for (int i = 1; i < StringGrid1->RowCount; i++) {
			if (AnsiStartsText(searchText, StringGrid1->Cells[4][i])) {
				StringGrid1->Row = i; // �������� ��������� ������
				ShowMessage("������ ������: " + StringGrid1->Cells[4][i] + + "\n � ��������� - " + StringGrid1->Cells[1][i] + " " + StringGrid1->Cells[2][i] + "\n ������ - " + StringGrid1->Cells[4][i] + "\n ������������� - " + StringGrid1->Cells[5][i]);
				return;
			}
		}
	}



		// ������
	else {
		return;
	}

   ShowMessage("������ �� ������");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N25Click(TObject *Sender)
{
	UnicodeString searchText = InputBox("�����", "������� ���", "");
	int searchType = MessageDlg("����� �� ������� ����������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);

    // ������ ����������
	if (searchType == mrYes) {
   for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
	   if (StringGrid1->Cells[5][i] == searchText) {
		   StringGrid1->Row = i; // �������� ��������� ������
		   ShowMessage("������������� ������: " + searchText + "\n � ��������� - " + StringGrid1->Cells[1][i] + " " + StringGrid1->Cells[2][i] + "\n ������� - " + StringGrid1->Cells[3][i] + "\n ������ - " + StringGrid1->Cells[4][i]);
		   return;
	   }
   }
   }

          	// ������ ������
	else if (searchType == mrNo) {
		for (int i = 1; i < StringGrid1->RowCount; i++) {
			if (AnsiStartsText(searchText, StringGrid1->Cells[5][i])) {
				StringGrid1->Row = i; // �������� ��������� ������
				ShowMessage("������������� ������: " + StringGrid1->Cells[5][i] + + "\n � ��������� - " + StringGrid1->Cells[1][i] + " " + StringGrid1->Cells[2][i] + "\n ������� - " + StringGrid1->Cells[3][i] + "\n ������ - " + StringGrid1->Cells[4][i]);
				return;
			}
		}
	}

		// ������
	else {
		return;
	}

   ShowMessage("������� �� �������");
}
//---------------------------------------------------------------------------



void __fastcall TForm2::N18Click(TObject *Sender)
{
ShowMessage("������ 43. ��� ����� ������ � ���� � �������� ����������� ���� �� ��������:\n"
            "- ���\n"
            "- ������\n"
            "- �������\n"
            "- ������\n"
			"- �.�.�. ��������������.\n\n"
			"��������� ������������ ����� ���������� �������� ������� ���� � ���������� "
			"������ ���������, ����������� ���������, ������ �� ������� ����������.");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N19Click(TObject *Sender)
{
	if (FileExists("user_guide.txt")) {
       TStringList *fileContent = new TStringList;
       try {
           fileContent->LoadFromFile("user_guide.txt");
		   ShowMessage(fileContent->Text);
       }
       __finally {
           delete fileContent;
       }
   } else {
       ShowMessage("���� ������� �� ������");
   }
}
//---------------------------------------------------------------------------


std::map<String, int> animalCount;
std::vector<Zoopark> zooparkData;


  std::map<String, int> foodCount;

//---------------------------------------------------------------------------

void __fastcall TForm2::N6Click(TObject *Sender)
{
	Form2->Close();
}

void __fastcall TForm2::FormActivate(TObject *Sender)
{
	int rCount;
	for (int i = 0; i < StringGrid1->RowCount; i++)
	{
		  rCount = i;
	}
	StatusBar1->Panels->Items[0]->Text = "����� ���������: " + IntToStr(rCount);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::StringGrid1SelectCell(TObject *Sender, int ACol, int ARow,
		  bool &CanSelect)
{
	 StatusBar1->Panels->Items[2]->Text = "���������� ������: " + IntToStr(ARow);
	 StatusBar1->Panels->Items[3]->Text = "�������: " + IntToStr(ACol);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::N37Click(TObject *Sender)
{
	for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
		for (int j = i + 1; j < StringGrid1->RowCount; j++) {
			if (StringGrid1->Cells[2][j].CompareIC(StringGrid1->Cells[2][i]) < 0) {
				// ������ ������� ������, ���� �������� � ��������� ������ ������ �������� � �������
				for (int k = 1; k < StringGrid1->ColCount; k++) {
					UnicodeString temp = StringGrid1->Cells[k][i];
					StringGrid1->Cells[k][i] = StringGrid1->Cells[k][j];
					StringGrid1->Cells[k][j] = temp;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::N36Click(TObject *Sender)
{
    for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
		for (int j = i + 1; j < StringGrid1->RowCount; j++) {
			if (StringGrid1->Cells[1][j].CompareIC(StringGrid1->Cells[1][i]) < 0) {
				// ������ ������� ������, ���� �������� � ��������� ������ ������ �������� � �������
				for (int k = 1; k < StringGrid1->ColCount; k++) {
					UnicodeString temp = StringGrid1->Cells[k][i];
					StringGrid1->Cells[k][i] = StringGrid1->Cells[k][j];
					StringGrid1->Cells[k][j] = temp;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N38Click(TObject *Sender)
{
    for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
		for (int j = i + 1; j < StringGrid1->RowCount; j++) {
			if (StringGrid1->Cells[4][j].CompareIC(StringGrid1->Cells[4][i]) < 0) {
				// ������ ������� ������, ���� �������� � ��������� ������ ������ �������� � �������
				for (int k = 1; k < StringGrid1->ColCount; k++) {
					UnicodeString temp = StringGrid1->Cells[k][i];
					StringGrid1->Cells[k][i] = StringGrid1->Cells[k][j];
					StringGrid1->Cells[k][j] = temp;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N39Click(TObject *Sender)
{
	for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
		for (int j = i + 1; j < StringGrid1->RowCount; j++) {
			if (StringGrid1->Cells[5][j].CompareIC(StringGrid1->Cells[5][i]) < 0) {
				// ������ ������� ������, ���� �������� � ��������� ������ ������ �������� � �������
				for (int k = 1; k < StringGrid1->ColCount; k++) {
					UnicodeString temp = StringGrid1->Cells[k][i];
					StringGrid1->Cells[k][i] = StringGrid1->Cells[k][j];
					StringGrid1->Cells[k][j] = temp;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N15Click(TObject *Sender)
{
	for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
		for (int j = i + 1; j < StringGrid1->RowCount; j++) {
			if (StrToInt(StringGrid1->Cells[3][j]) < StrToInt(StringGrid1->Cells[3][i])) {
				// ������ ������� ������, ���� �������� � ��������� ������ ������ �������� � �������
				for (int k = 1; k < StringGrid1->ColCount; k++) {
					UnicodeString temp = StringGrid1->Cells[k][i];
					StringGrid1->Cells[k][i] = StringGrid1->Cells[k][j];
					StringGrid1->Cells[k][j] = temp;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N35Click(TObject *Sender)
{
    for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
		for (int j = i + 1; j < StringGrid1->RowCount; j++) {
			if (StrToInt(StringGrid1->Cells[3][j]) > StrToInt(StringGrid1->Cells[3][i])) {
				// ������ ������� ������, ���� �������� � ��������� ������ ������ �������� � �������
				for (int k = 1; k < StringGrid1->ColCount; k++) {
					UnicodeString temp = StringGrid1->Cells[k][i];
					StringGrid1->Cells[k][i] = StringGrid1->Cells[k][j];
					StringGrid1->Cells[k][j] = temp;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N12Click(TObject *Sender)
{
    for (int i = 1; i < StringGrid1->RowCount; i++) { // �������� � 1, ����� ���������� ��������� �������
		for (int j = i + 1; j < StringGrid1->RowCount; j++) {
			if (StringGrid1->Cells[2][j].CompareIC(StringGrid1->Cells[2][i]) < 0) {
				// ������ ������� ������, ���� �������� � ��������� ������ ������ �������� � �������
				for (int k = 1; k < StringGrid1->ColCount; k++) {
					UnicodeString temp = StringGrid1->Cells[k][i];
					StringGrid1->Cells[k][i] = StringGrid1->Cells[k][j];
					StringGrid1->Cells[k][j] = temp;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N43Click(TObject *Sender)
{
	foodCount.clear();
	for (int i = 1; i < StringGrid1->RowCount; i++)
	{
		String diet = StringGrid1->Cells[4][i];
		TStringList* dietItems = new TStringList;
		try
		{
			dietItems->Delimiter = ',';
			dietItems->DelimitedText = diet;
			for (int j = 0; j < dietItems->Count; j++)
			{
				String foodItem = Trim(dietItems->Strings[j]);
				foodCount[foodItem]++;
			}
		}
		__finally
		{
			delete dietItems;
		}
	}

	String message = "�������� ����������� � ����:\n";
	for (const auto& pair : foodCount)
    {
        message += pair.first + ": " + IntToStr(pair.second) + "\n";
	}

	ShowMessage(message);

    if (MessageDlg("��������� ���������� � ����?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
    {
		std::ofstream out("food_requirements.txt");
        if (out.is_open())
		{
			for (const auto& pair : foodCount)
            {
                out << pair.first.c_str() << ": " << pair.second << std::endl;
            }
            out.close();
			ShowMessage("��������� � food_requirements.txt");
		}
		else
		{
			ShowMessage("�� ������� ������� food_requirements.txt ��� ������");
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N42Click(TObject *Sender)
{
	animalCount.clear();
	for (int i = 1; i < StringGrid1->RowCount; i++)
	{
		String species = StringGrid1->Cells[1][i];
		animalCount[species]++;
	}

    String message = "";
	for (const auto& pair : animalCount)
	{
		message += pair.first + ": " + IntToStr(pair.second) + "\n";
	}

	ShowMessage(message);

	if (MessageDlg("��������� ���������� � ����?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		std::ofstream out("results.txt");
		if (out.is_open())
		{
			for (const auto& pair : animalCount)
			{
				out << pair.first.c_str() << ": " << pair.second << std::endl;
			}
			out.close();
			ShowMessage("����������� � ����� results.txt");
		}
		else
		{
			ShowMessage("�� ������� ������� ���� results.txt ��� ������");
		}
	}
}
//---------------------------------------------------------------------------



