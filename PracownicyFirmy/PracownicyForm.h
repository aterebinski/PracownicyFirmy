#pragma once
#include "EdytujPracownikaForm.h"
#include "DictionaryForm.h"
namespace PracownicyFirmy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o PracownicyForm
	/// </summary>
	public ref class PracownicyForm : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString = L"Server=(localdb)\\MSSQLLocalDB;Database=PracownicyDB;Trusted_Connection=True;";
		//String^ connectionString = L"Data Source=(localdb)\MSSQLLocalDB;Initial Catalog=PracownicyDB;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False";
		//String^ connectionString = L"Server=(localdb)\\MSSQLLocalDB;Database=PracownicyDB;Trusted_Connection=True;";
		//String^ connectionString = L"Server=localhost\\SQLEXPRESS;Database=PracownicyDB;Trusted_Connection=True;";

	public:
		PracownicyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			this->generateView();
		}

	protected:
		/// <summary>
		/// Wyczy�� wszystkie u�ywane zasoby.
		/// </summary>
		~PracownicyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ PracownicyDataGridView;
	protected:

	private: System::Windows::Forms::Button^ DodajPracownikaBtn;
	private: System::Windows::Forms::Button^ EdytujPracownikaBtn;
	private: System::Windows::Forms::Button^ UsunPracownikaBtn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ StanowiskaBtn;
	private: System::Windows::Forms::Button^ LokalizacjeBtn;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs�ugi projektanta � nie nale�y modyfikowa�
		/// jej zawarto�ci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PracownicyDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->DodajPracownikaBtn = (gcnew System::Windows::Forms::Button());
			this->EdytujPracownikaBtn = (gcnew System::Windows::Forms::Button());
			this->UsunPracownikaBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->StanowiskaBtn = (gcnew System::Windows::Forms::Button());
			this->LokalizacjeBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PracownicyDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// PracownicyDataGridView
			// 
			this->PracownicyDataGridView->AllowUserToAddRows = false;
			this->PracownicyDataGridView->AllowUserToDeleteRows = false;
			this->PracownicyDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PracownicyDataGridView->Location = System::Drawing::Point(31, 67);
			this->PracownicyDataGridView->Name = L"PracownicyDataGridView";
			this->PracownicyDataGridView->ReadOnly = true;
			this->PracownicyDataGridView->RowHeadersVisible = false;
			this->PracownicyDataGridView->RowHeadersWidth = 62;
			this->PracownicyDataGridView->Size = System::Drawing::Size(519, 393);
			this->PracownicyDataGridView->TabIndex = 0;
			this->PracownicyDataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PracownicyForm::dataGridView1_CellContentClick);
			// 
			// DodajPracownikaBtn
			// 
			this->DodajPracownikaBtn->Location = System::Drawing::Point(31, 486);
			this->DodajPracownikaBtn->Margin = System::Windows::Forms::Padding(2);
			this->DodajPracownikaBtn->Name = L"DodajPracownikaBtn";
			this->DodajPracownikaBtn->Size = System::Drawing::Size(133, 32);
			this->DodajPracownikaBtn->TabIndex = 1;
			this->DodajPracownikaBtn->Text = L"Dodaj pracownika";
			this->DodajPracownikaBtn->UseVisualStyleBackColor = true;
			this->DodajPracownikaBtn->Click += gcnew System::EventHandler(this, &PracownicyForm::DodajPracownikaBtn_Click);
			// 
			// EdytujPracownikaBtn
			// 
			this->EdytujPracownikaBtn->Location = System::Drawing::Point(226, 486);
			this->EdytujPracownikaBtn->Margin = System::Windows::Forms::Padding(2);
			this->EdytujPracownikaBtn->Name = L"EdytujPracownikaBtn";
			this->EdytujPracownikaBtn->Size = System::Drawing::Size(133, 32);
			this->EdytujPracownikaBtn->TabIndex = 2;
			this->EdytujPracownikaBtn->Text = L"Edytuj pracownika";
			this->EdytujPracownikaBtn->UseVisualStyleBackColor = true;
			this->EdytujPracownikaBtn->Click += gcnew System::EventHandler(this, &PracownicyForm::EdytujPracownikaBtn_Click);
			// 
			// UsunPracownikaBtn
			// 
			this->UsunPracownikaBtn->Location = System::Drawing::Point(416, 486);
			this->UsunPracownikaBtn->Margin = System::Windows::Forms::Padding(2);
			this->UsunPracownikaBtn->Name = L"UsunPracownikaBtn";
			this->UsunPracownikaBtn->Size = System::Drawing::Size(133, 32);
			this->UsunPracownikaBtn->TabIndex = 3;
			this->UsunPracownikaBtn->Text = L"Usu� pracownika";
			this->UsunPracownikaBtn->UseVisualStyleBackColor = true;
			this->UsunPracownikaBtn->Click += gcnew System::EventHandler(this, &PracownicyForm::UsunPracownikaBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(28, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Pracownicy:";
			// 
			// StanowiskaBtn
			// 
			this->StanowiskaBtn->Location = System::Drawing::Point(32, 533);
			this->StanowiskaBtn->Name = L"StanowiskaBtn";
			this->StanowiskaBtn->Size = System::Drawing::Size(241, 32);
			this->StanowiskaBtn->TabIndex = 5;
			this->StanowiskaBtn->Text = L"Poka� stanowiska";
			this->StanowiskaBtn->UseVisualStyleBackColor = true;
			this->StanowiskaBtn->Click += gcnew System::EventHandler(this, &PracownicyForm::StanowiskaBtn_Click);
			// 
			// LokalizacjeBtn
			// 
			this->LokalizacjeBtn->Location = System::Drawing::Point(308, 533);
			this->LokalizacjeBtn->Name = L"LokalizacjeBtn";
			this->LokalizacjeBtn->Size = System::Drawing::Size(241, 32);
			this->LokalizacjeBtn->TabIndex = 5;
			this->LokalizacjeBtn->Text = L"Poka� lokalizacje";
			this->LokalizacjeBtn->UseVisualStyleBackColor = true;
			this->LokalizacjeBtn->Click += gcnew System::EventHandler(this, &PracownicyForm::LokalizacjeBtn_Click);
			// 
			// PracownicyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(585, 579);
			this->Controls->Add(this->LokalizacjeBtn);
			this->Controls->Add(this->StanowiskaBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->UsunPracownikaBtn);
			this->Controls->Add(this->EdytujPracownikaBtn);
			this->Controls->Add(this->DodajPracownikaBtn);
			this->Controls->Add(this->PracownicyDataGridView);
			this->Name = L"PracownicyForm";
			this->Text = L"PracownicyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PracownicyDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			}

		   System::Void generateView() {

			   
			   
			   //SqlDataReader^ sqlDataReader;
			   try
			   {
				   SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				   SqlCommand^ sqlCommand = gcnew SqlCommand("select p.id, p.Imie, p.Nazwisko, s.Stanowisko, l.Miasto, p.Pensja from dbo.Pracownicy p, dbo.Stanowiska s, dbo.Lokalizacje l where p.IdStanowiska = s.id and p.IdLokalizacji = l.ID; ", sqlConnection);

				   SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
				   sqlDataAdapter->SelectCommand = sqlCommand;
				   DataTable^ dataTable = gcnew DataTable();
				   sqlDataAdapter->Fill(dataTable);
				   BindingSource^ bindingSource = gcnew BindingSource();

				   //bindingSource->DataSource = dataTable;
				   //PracownicyDataGridView->DataSource = bindingSource;


				   PracownicyDataGridView->DataSource = dataTable;
				   sqlDataAdapter->Update(dataTable);

				   //chowa kolumn� ID w dataGridView
				   this->PracownicyDataGridView->Columns["ID"]->Visible = false;
			   }
			   catch (Exception^ ex)
			   {
				   MessageBox::Show(ex->Message);
			   }



				//https://www.youtube.com/watch?v=r_cj1uhs9-c
		   };
	private: System::Void DodajPracownikaBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		EdytujPracownikaForm^ AddForm = gcnew EdytujPracownikaForm(0, connectionString);
		AddForm->ShowDialog();
		this->generateView();
		//Application::Restart();
	}



	private: System::Void EdytujPracownikaBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		int idPracownika = 0;
		idPracownika = (int)PracownicyDataGridView->CurrentRow->Cells[0]->Value;
		//MessageBox::Show(idPracownika.ToString());
		EdytujPracownikaForm^ EditForm = gcnew EdytujPracownikaForm(idPracownika, connectionString);
		EditForm->ShowDialog();
		this->generateView();
		//this->Refresh();
		//Application::Restart();
	}

private: System::Void StanowiskaBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	DictionaryForm^ dictionaryForm = gcnew DictionaryForm("stanowiska",connectionString);
	dictionaryForm->ShowDialog();
}
private: System::Void LokalizacjeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	DictionaryForm^ dictionaryForm = gcnew DictionaryForm("lokalizacje",connectionString);
	dictionaryForm->ShowDialog();
}
private: System::Void UsunPracownikaBtn_Click(System::Object^ sender, System::EventArgs^ e) {

	if (MessageBox::Show("Usun�� pracownika?", "Usuwanie pracownika", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
		int idPracownika = (int)PracownicyDataGridView->CurrentRow->Cells[0]->Value;
		if (idPracownika) {
			try {
				SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
				sqlConnection->Open();
				SqlCommand^ sqlCommand = gcnew SqlCommand("delete from dbo.Pracownicy where id = @id", sqlConnection);
				sqlCommand->Parameters->Add("@id", idPracownika);
				sqlCommand->ExecuteNonQuery();
				sqlConnection->Close();
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}

			this->generateView();
		}

		
		
	}

}
};

	
}
