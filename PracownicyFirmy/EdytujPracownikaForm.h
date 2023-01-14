#pragma once

namespace PracownicyFirmy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o EdytujPracownikaForm
	/// </summary>
	public ref class EdytujPracownikaForm : public System::Windows::Forms::Form
	{
	public:
		EdytujPracownikaForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ NameLbl;
	private: System::Windows::Forms::Button^ OkBtn;
	private: System::Windows::Forms::ComboBox^ StanowiskoCBox;

	protected:



	private: System::Windows::Forms::Label^ NazwiskoLbl;
	private: System::Windows::Forms::Label^ PensjaLbl;
	private: System::Windows::Forms::Label^ StanowiskoLbl;
	private: System::Windows::Forms::Label^ LokalizacjaLbl;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->NameLbl = (gcnew System::Windows::Forms::Label());
			this->OkBtn = (gcnew System::Windows::Forms::Button());
			this->StanowiskoCBox = (gcnew System::Windows::Forms::ComboBox());
			this->NazwiskoLbl = (gcnew System::Windows::Forms::Label());
			this->PensjaLbl = (gcnew System::Windows::Forms::Label());
			this->StanowiskoLbl = (gcnew System::Windows::Forms::Label());
			this->LokalizacjaLbl = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->LokalizacjaCBox = (gcnew System::Windows::Forms::ComboBox());
			this->AnulujBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(206, 115);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(278, 26);
			this->textBox1->TabIndex = 0;
			// 
			// NameLbl
			// 
			this->NameLbl->AutoSize = true;
			this->NameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->NameLbl->Location = System::Drawing::Point(77, 115);
			this->NameLbl->Name = L"NameLbl";
			this->NameLbl->Size = System::Drawing::Size(53, 25);
			this->NameLbl->TabIndex = 1;
			this->NameLbl->Text = L" Imiê";
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
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(206, 195);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(278, 26);
			this->textBox2->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(206, 275);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(278, 26);
			this->textBox3->TabIndex = 9;
			// 
			// LokalizacjaCBox
			// 
			this->LokalizacjaCBox->FormattingEnabled = true;
			this->LokalizacjaCBox->Location = System::Drawing::Point(206, 435);
			this->LokalizacjaCBox->Name = L"LokalizacjaCBox";
			this->LokalizacjaCBox->Size = System::Drawing::Size(278, 28);
			this->LokalizacjaCBox->TabIndex = 10;
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
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->LokalizacjaLbl);
			this->Controls->Add(this->StanowiskoLbl);
			this->Controls->Add(this->PensjaLbl);
			this->Controls->Add(this->NazwiskoLbl);
			this->Controls->Add(this->StanowiskoCBox);
			this->Controls->Add(this->OkBtn);
			this->Controls->Add(this->NameLbl);
			this->Controls->Add(this->textBox1);
			this->Name = L"EdytujPracownikaForm";
			this->Text = L"EdytujPracownikaForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OkBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void AnulujBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	EdytujPracownikaForm::Close();
}
};
}
