#pragma once


namespace PracownicyFirmy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o StanowiskaForm
	/// </summary>
	public ref class DictionaryForm : public System::Windows::Forms::Form
	{
	public:
		String^ dictionaryType;

		DictionaryForm(String^ dictionaryType, String^ connectionString)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//

			this->dictionaryType = dictionaryType;


			SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			SqlCommand^ sqlCommand = gcnew SqlCommand("select * from dbo."+dictionaryType, sqlConnection);
			//SqlDataReader^ sqlDataReader;
			try
			{
				SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
				sqlDataAdapter->SelectCommand = sqlCommand;
				DataTable^ dataTable = gcnew DataTable();
				sqlDataAdapter->Fill(dataTable);
				//BindingSource^ bindingSource = gcnew BindingSource();

				//bindingSource->DataSource = dataTable;
				//PracownicyDataGridView->DataSource = bindingSource;


				DictionaryDataGridView->DataSource = dataTable;
				sqlDataAdapter->Update(dataTable);

				//chowa kolumnê ID w dataGridView
				this->DictionaryDataGridView->Columns["ID"]->Visible = false;
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}




		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~DictionaryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ DictionaryDataGridView;
	private: System::Windows::Forms::Label^ dictionaryLabel;
	private: System::Windows::Forms::Button^ okButton;
	protected:

	protected:


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
			this->DictionaryDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->dictionaryLabel = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DictionaryDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// DictionaryDataGridView
			// 
			this->DictionaryDataGridView->AllowUserToAddRows = false;
			this->DictionaryDataGridView->AllowUserToDeleteRows = false;
			this->DictionaryDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DictionaryDataGridView->Location = System::Drawing::Point(33, 50);
			this->DictionaryDataGridView->Name = L"DictionaryDataGridView";
			this->DictionaryDataGridView->ReadOnly = true;
			this->DictionaryDataGridView->RowHeadersVisible = false;
			this->DictionaryDataGridView->Size = System::Drawing::Size(165, 150);
			this->DictionaryDataGridView->TabIndex = 0;
			// 
			// dictionaryLabel
			// 
			this->dictionaryLabel->AutoSize = true;
			this->dictionaryLabel->Location = System::Drawing::Point(33, 13);
			this->dictionaryLabel->Name = L"dictionaryLabel";
			this->dictionaryLabel->Size = System::Drawing::Size(112, 13);
			this->dictionaryLabel->TabIndex = 1;
			this->dictionaryLabel->Text = L"Dostêpne stanowiska:";
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(70, 332);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 2;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &DictionaryForm::okButton_Click);
			// 
			// DictionaryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(226, 392);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->dictionaryLabel);
			this->Controls->Add(this->DictionaryDataGridView);
			this->Name = L"DictionaryForm";
			this->Text = L"DictionaryForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DictionaryDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
