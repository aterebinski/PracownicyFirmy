#pragma once
#include "ComboBoxItem.h"

namespace PracownicyFirmy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o EdytujPracownikaForm
	/// </summary>
	public ref class EdytujPracownikaForm : public System::Windows::Forms::Form
	{
	private: 
		int idPracownika = 0;
		String^ idStanowiska;
		String^ idLokalizacji;
		String^ imie;
		String^ nazwisko;
		String^ pensja;
		String^ stanowisko;
		String^ miasto;
		String^ connectionString;


	public:
		EdytujPracownikaForm(int idPracownika, String^ connectionString)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			this->idPracownika = idPracownika;
			this->connectionString = connectionString;

			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			SqlCommand^ sqlCommand;
			SqlDataReader^ sqlDataReader;
			sqlConnection->Open();
			
			
			
		//https://www.functionx.com/vccli/controls/combobox.htm

			
			if (idPracownika!=0) //jesli edytujemy dane to trzeba wyswietlic dane w odpowiednich polach
			{
				try {

					sqlCommand = gcnew SqlCommand("select * from dbo.Pracownicy where id = " + idPracownika, sqlConnection);
					SqlDataReader^ sqlDataReader = sqlCommand->ExecuteReader();
					sqlDataReader->Read();
					//sqlDataReader->GetValue(0);
					//imie = sqlDataReader->GetValue(1)->ToString();
					//sqlDataReader->GetValue(2);
					//sqlDataReader->GetValue(3);
					imie = sqlDataReader["imie"]->ToString();
					this->ImieTextBox->Text = imie;
					nazwisko = sqlDataReader["nazwisko"]->ToString();
					this->NazwiskoTextBox->Text = nazwisko;
					pensja = sqlDataReader["pensja"]->ToString();
					this->PensjaTextBox->Text = pensja;
					idStanowiska = sqlDataReader["idStanowiska"]->ToString();
					idLokalizacji = sqlDataReader["idStanowiska"]->ToString();

					sqlDataReader->Close();
				}catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
				
			}

			//uzupe³nianie comboboxów

			sqlCommand = gcnew SqlCommand("select * from dbo.Stanowiska", sqlConnection);

			ComboBoxItem^ tempComboBoxItem;
			String^ tempId;
			String^ tempValue;

			sqlDataReader = sqlCommand->ExecuteReader();
			while (sqlDataReader->Read()) {
				tempId = sqlDataReader["id"]->ToString();
				tempValue = sqlDataReader["stanowisko"]->ToString();
				tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
				this->StanowiskoCBox->Items->Add(tempComboBoxItem);
				if ((idPracownika != 0)&&(idStanowiska== tempId)) this->StanowiskoCBox->SelectedItem = tempComboBoxItem;
			}
			sqlDataReader->Close();

			sqlCommand = gcnew SqlCommand("select * from dbo.Lokalizacje", sqlConnection);

			sqlDataReader = sqlCommand->ExecuteReader();
			while (sqlDataReader->Read()) {
				tempId = sqlDataReader["id"]->ToString();
				tempValue = sqlDataReader["miasto"]->ToString();
				tempComboBoxItem = gcnew ComboBoxItem(tempId, tempValue);
				this->LokalizacjaCBox->Items->Add(tempComboBoxItem);
				if ((idPracownika != 0) && (idLokalizacji == tempId)) this->LokalizacjaCBox->SelectedItem = tempComboBoxItem;
			}
			//MessageBox::Show(this->LokalizacjaCBox->SelectedValue->ToString());


			sqlDataReader->Close();
			sqlConnection->Close();

		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~EdytujPracownikaForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ ImieTextBox;
	protected:

	private: System::Windows::Forms::Label^ ImieLbl;
	protected:


	private: System::Windows::Forms::Button^ OkBtn;
	private: System::Windows::Forms::ComboBox^ StanowiskoCBox;

	protected:



	private: System::Windows::Forms::Label^ NazwiskoLbl;
	private: System::Windows::Forms::Label^ PensjaLbl;
	private: System::Windows::Forms::Label^ StanowiskoLbl;
	private: System::Windows::Forms::Label^ LokalizacjaLbl;
	private: System::Windows::Forms::TextBox^ NazwiskoTextBox;
	private: System::Windows::Forms::TextBox^ PensjaTextBox;


	private: System::Windows::Forms::ComboBox^ LokalizacjaCBox;

	private: System::Windows::Forms::Button^ AnulujBtn;





	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ImieTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ImieLbl = (gcnew System::Windows::Forms::Label());
			this->OkBtn = (gcnew System::Windows::Forms::Button());
			this->StanowiskoCBox = (gcnew System::Windows::Forms::ComboBox());
			this->NazwiskoLbl = (gcnew System::Windows::Forms::Label());
			this->PensjaLbl = (gcnew System::Windows::Forms::Label());
			this->StanowiskoLbl = (gcnew System::Windows::Forms::Label());
			this->LokalizacjaLbl = (gcnew System::Windows::Forms::Label());
			this->NazwiskoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PensjaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LokalizacjaCBox = (gcnew System::Windows::Forms::ComboBox());
			this->AnulujBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ImieTextBox
			// 
			this->ImieTextBox->Location = System::Drawing::Point(206, 115);
			this->ImieTextBox->Name = L"ImieTextBox";
			this->ImieTextBox->Size = System::Drawing::Size(278, 26);
			this->ImieTextBox->TabIndex = 0;
			// 
			// ImieLbl
			// 
			this->ImieLbl->AutoSize = true;
			this->ImieLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ImieLbl->Location = System::Drawing::Point(77, 115);
			this->ImieLbl->Name = L"ImieLbl";
			this->ImieLbl->Size = System::Drawing::Size(53, 25);
			this->ImieLbl->TabIndex = 1;
			this->ImieLbl->Text = L" Imiê";
			// 
			// OkBtn
			// 
			this->OkBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->OkBtn->Location = System::Drawing::Point(206, 559);
			this->OkBtn->Name = L"OkBtn";
			this->OkBtn->Size = System::Drawing::Size(125, 40);
			this->OkBtn->TabIndex = 2;
			this->OkBtn->Text = L"Ok";
			this->OkBtn->UseVisualStyleBackColor = true;
			this->OkBtn->Click += gcnew System::EventHandler(this, &EdytujPracownikaForm::OkBtn_Click);
			// 
			// StanowiskoCBox
			// 
			this->StanowiskoCBox->FormattingEnabled = true;
			this->StanowiskoCBox->Location = System::Drawing::Point(206, 355);
			this->StanowiskoCBox->Name = L"StanowiskoCBox";
			this->StanowiskoCBox->Size = System::Drawing::Size(278, 28);
			this->StanowiskoCBox->TabIndex = 3;

			this->StanowiskoCBox->DisplayMember = L"Text";
			this->StanowiskoCBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->StanowiskoCBox->ValueMember = L"Value";
			// 
			// NazwiskoLbl
			// 
			this->NazwiskoLbl->AutoSize = true;
			this->NazwiskoLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->NazwiskoLbl->Location = System::Drawing::Point(77, 195);
			this->NazwiskoLbl->Name = L"NazwiskoLbl";
			this->NazwiskoLbl->Size = System::Drawing::Size(96, 25);
			this->NazwiskoLbl->TabIndex = 4;
			this->NazwiskoLbl->Text = L"Nazwisko";
			// 
			// PensjaLbl
			// 
			this->PensjaLbl->AutoSize = true;
			this->PensjaLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->PensjaLbl->Location = System::Drawing::Point(77, 275);
			this->PensjaLbl->Name = L"PensjaLbl";
			this->PensjaLbl->Size = System::Drawing::Size(72, 25);
			this->PensjaLbl->TabIndex = 5;
			this->PensjaLbl->Text = L"Pensja";
			// 
			// StanowiskoLbl
			// 
			this->StanowiskoLbl->AutoSize = true;
			this->StanowiskoLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->StanowiskoLbl->Location = System::Drawing::Point(77, 355);
			this->StanowiskoLbl->Name = L"StanowiskoLbl";
			this->StanowiskoLbl->Size = System::Drawing::Size(113, 25);
			this->StanowiskoLbl->TabIndex = 6;
			this->StanowiskoLbl->Text = L"Stanowisko";
			// 
			// LokalizacjaLbl
			// 
			this->LokalizacjaLbl->AutoSize = true;
			this->LokalizacjaLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LokalizacjaLbl->Location = System::Drawing::Point(77, 435);
			this->LokalizacjaLbl->Name = L"LokalizacjaLbl";
			this->LokalizacjaLbl->Size = System::Drawing::Size(109, 25);
			this->LokalizacjaLbl->TabIndex = 7;
			this->LokalizacjaLbl->Text = L"Lokalizacja";
			// 
			// NazwiskoTextBox
			// 
			this->NazwiskoTextBox->Location = System::Drawing::Point(206, 195);
			this->NazwiskoTextBox->Name = L"NazwiskoTextBox";
			this->NazwiskoTextBox->Size = System::Drawing::Size(278, 26);
			this->NazwiskoTextBox->TabIndex = 8;
			// 
			// PensjaTextBox
			// 
			this->PensjaTextBox->Location = System::Drawing::Point(206, 275);
			this->PensjaTextBox->Name = L"PensjaTextBox";
			this->PensjaTextBox->Size = System::Drawing::Size(278, 26);
			this->PensjaTextBox->TabIndex = 9;
			// 
			// LokalizacjaCBox
			// 
			this->LokalizacjaCBox->FormattingEnabled = true;
			this->LokalizacjaCBox->Location = System::Drawing::Point(206, 435);
			this->LokalizacjaCBox->Name = L"LokalizacjaCBox";
			this->LokalizacjaCBox->Size = System::Drawing::Size(278, 28);
			this->LokalizacjaCBox->TabIndex = 10;

			this->LokalizacjaCBox->DisplayMember = L"Text";
			this->LokalizacjaCBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->LokalizacjaCBox->ValueMember = L"Value";
			// 
			// AnulujBtn
			// 
			this->AnulujBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->AnulujBtn->Location = System::Drawing::Point(359, 559);
			this->AnulujBtn->Name = L"AnulujBtn";
			this->AnulujBtn->Size = System::Drawing::Size(125, 40);
			this->AnulujBtn->TabIndex = 11;
			this->AnulujBtn->Text = L"Anuluj";
			this->AnulujBtn->UseVisualStyleBackColor = true;
			this->AnulujBtn->Click += gcnew System::EventHandler(this, &EdytujPracownikaForm::AnulujBtn_Click);
			// 
			// EdytujPracownikaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(685, 660);
			this->Controls->Add(this->AnulujBtn);
			this->Controls->Add(this->LokalizacjaCBox);
			this->Controls->Add(this->PensjaTextBox);
			this->Controls->Add(this->NazwiskoTextBox);
			this->Controls->Add(this->LokalizacjaLbl);
			this->Controls->Add(this->StanowiskoLbl);
			this->Controls->Add(this->PensjaLbl);
			this->Controls->Add(this->NazwiskoLbl);
			this->Controls->Add(this->StanowiskoCBox);
			this->Controls->Add(this->OkBtn);
			this->Controls->Add(this->ImieLbl);
			this->Controls->Add(this->ImieTextBox);
			this->Name = L"EdytujPracownikaForm";
			this->Text = L"EdytujPracownikaForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OkBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		ComboBoxItem^ selectedLokalizacja = (ComboBoxItem^)this->LokalizacjaCBox->SelectedItem;
		//MessageBox::Show(selectedLokalizacja->getId());

		ComboBoxItem^ selectedStanowisko = (ComboBoxItem^)this->StanowiskoCBox->SelectedItem;


		imie = this->ImieTextBox->Text;
		nazwisko = this->NazwiskoTextBox->Text;
		pensja = this->PensjaTextBox->Text;
		idLokalizacji = selectedLokalizacja->getId();
		idStanowiska = selectedStanowisko->getId();

		float dlPensja;
		int intIdStanowiska, intIdLokalizacji;
		String^ sqlString;
		
		if ((imie=="")||(nazwisko=="")||(pensja=="")||(idLokalizacji=="")||(idStanowiska==""))
		{
			MessageBox::Show("Wype³nij wszystkie pola");
		}
		else if (dlPensja = Convert::ToDouble(pensja)) {
			intIdStanowiska = Convert::ToInt32(idStanowiska);
			intIdLokalizacji = Convert::ToInt32(idLokalizacji);

			if (idPracownika==0) //dodanie nowego rekordu do tabeli Pracownicy
			{
				sqlString = "insert into dbo.Pracownicy(imie,nazwisko,pensja,idStanowiska,idLokalizacji) values (@imie,@nazwisko,@pensja,@idStanowiska,@idLokalizacji);";
			}
			else { //edycja rekordu tabeli Pracownicy
				sqlString = "update dbo.Pracownicy set imie = @imie, nazwisko = @nazwisko, pensja = @pensja, idStanowiska = @idstanowiska, idLokalizacji = @idLokalizacji " +
					"where ID = @ipPracownika ;";
			}

			try {
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand(sqlString, sqlConnection);
				sqlCommand->Parameters->Add("@imie", imie);
				sqlCommand->Parameters->Add("@nazwisko", nazwisko);
				sqlCommand->Parameters->Add("@pensja", pensja);
				sqlCommand->Parameters->Add("@idStanowiska", intIdStanowiska);
				sqlCommand->Parameters->Add("@idLokalizacji", intIdLokalizacji);
				if (idPracownika != 0) sqlCommand->Parameters->Add("@idPracownika", idPracownika);

				sqlCommand->ExecuteNonQuery();

				sqlConnection->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}
			
			EdytujPracownikaForm::Close();


		}
	}
private: System::Void AnulujBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	EdytujPracownikaForm::Close();
}
};
}
