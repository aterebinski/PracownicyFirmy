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
	/// Podsumowanie informacji o PracownicyForm
	/// </summary>
	public ref class PracownicyForm : public System::Windows::Forms::Form
	{
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
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~PracownicyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(264, 83);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->Size = System::Drawing::Size(532, 761);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &PracownicyForm::dataGridView1_CellContentClick);
			// 
			// PracownicyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1134, 934);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"PracownicyForm";
			this->Text = L"PracownicyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
			private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			}

		   System::Void generateView() {
			   //String^ connectionString = L"Data Source=(localdb)\MSSQLLocalDB;Initial Catalog=PracownicyDB;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False";
			   String^ connectionString = L"Server=localhost\SQLEXPRESS;Database=PracownicyDB;Trusted_Connection=True;";
			   SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
			   SqlCommand^ sqlCommand = gcnew SqlCommand("select * from dbo.Pracownicy", sqlConnection);
			   SqlDataReader^ sqlDataReader;
			   try
			   {
				   SqlDataAdapter^ sqlDataAdapter = gcnew SqlDataAdapter();
				   sqlDataAdapter->SelectCommand = sqlCommand;
				   DataTable^ dataTable = gcnew DataTable();
				   sqlDataAdapter->Fill(dataTable);
				   BindingSource^ bindingSource = gcnew BindingSource();

				   bindingSource->DataSource = dataTable;
				   dataGridView1->DataSource = bindingSource;
				   sqlDataAdapter->Update(dataTable);
			   }
			   catch (Exception^ ex)
			   {
				   MessageBox::Show(ex->Message);
			   }



				//https://www.youtube.com/watch?v=r_cj1uhs9-c
		   };
	};

	
}
