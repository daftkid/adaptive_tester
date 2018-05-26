#pragma once

#include "EditTest.h"
#include "QuestStruct.h"

using namespace System;
using namespace System::IO;

namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChooseTest
	/// </summary>
	public ref class ChooseTest : public System::Windows::Forms::Form
	{
	public: ChooseTest(GlobalVars^ gv_i)
	{
		InitializeComponent();

		this->gv = gv_i;

		for (int i = 0; i < gv->test_list->Count; i++)
		{
			this->dgv_test_list->Rows->Add(gv->test_list[i].test_name, gv->test_list[i].test_path);
		}			
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChooseTest()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgv_test_list;
	private: GlobalVars^ gv;
	protected:

	protected:


	private: System::Windows::Forms::Label^  l_text_list;
	private: System::Windows::Forms::GroupBox^  gb_add_test;
	private: System::Windows::Forms::Button^  btn_add_test;
	private: System::Windows::Forms::Button^  btn_clear_test;
	private: System::Windows::Forms::Button^  btn_browse_test;
	private: System::Windows::Forms::Label^  l_test_path;
	private: System::Windows::Forms::Label^  l_test_name;
	private: System::Windows::Forms::TextBox^  tb_path;

	private: System::Windows::Forms::TextBox^  tb_title;

	private: System::Windows::Forms::GroupBox^  gb_delete_test;
	private: System::Windows::Forms::Button^  btn_edit_test;
	private: System::Windows::Forms::Button^  btn_delete_test;
	private: System::Windows::Forms::OpenFileDialog^  openTestDlg;
	private: System::Windows::Forms::Button^  back_to_start;
	private: System::Windows::Forms::Button^  btn_new_test;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TestName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TestPath;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChooseTest::typeid));
			this->dgv_test_list = (gcnew System::Windows::Forms::DataGridView());
			this->TestName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TestPath = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->l_text_list = (gcnew System::Windows::Forms::Label());
			this->gb_add_test = (gcnew System::Windows::Forms::GroupBox());
			this->btn_new_test = (gcnew System::Windows::Forms::Button());
			this->btn_add_test = (gcnew System::Windows::Forms::Button());
			this->btn_clear_test = (gcnew System::Windows::Forms::Button());
			this->btn_browse_test = (gcnew System::Windows::Forms::Button());
			this->l_test_path = (gcnew System::Windows::Forms::Label());
			this->l_test_name = (gcnew System::Windows::Forms::Label());
			this->tb_path = (gcnew System::Windows::Forms::TextBox());
			this->tb_title = (gcnew System::Windows::Forms::TextBox());
			this->gb_delete_test = (gcnew System::Windows::Forms::GroupBox());
			this->btn_edit_test = (gcnew System::Windows::Forms::Button());
			this->btn_delete_test = (gcnew System::Windows::Forms::Button());
			this->openTestDlg = (gcnew System::Windows::Forms::OpenFileDialog());
			this->back_to_start = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_test_list))->BeginInit();
			this->gb_add_test->SuspendLayout();
			this->gb_delete_test->SuspendLayout();
			this->SuspendLayout();
			// 
			// dgv_test_list
			// 
			this->dgv_test_list->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_test_list->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->TestName,
					this->TestPath
			});
			this->dgv_test_list->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dgv_test_list->EnableHeadersVisualStyles = false;
			this->dgv_test_list->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->dgv_test_list->Location = System::Drawing::Point(12, 29);
			this->dgv_test_list->MultiSelect = false;
			this->dgv_test_list->Name = L"dgv_test_list";
			this->dgv_test_list->ReadOnly = true;
			this->dgv_test_list->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_test_list->Size = System::Drawing::Size(606, 150);
			this->dgv_test_list->TabIndex = 0;
			this->dgv_test_list->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ChooseTest::dataGridView1_RowEnter);
			// 
			// TestName
			// 
			this->TestName->HeaderText = L"Название теста";
			this->TestName->Name = L"TestName";
			this->TestName->ReadOnly = true;
			this->TestName->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->TestName->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->TestName->Width = 200;
			// 
			// TestPath
			// 
			this->TestPath->HeaderText = L"Путь к файлу теста";
			this->TestPath->Name = L"TestPath";
			this->TestPath->ReadOnly = true;
			this->TestPath->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->TestPath->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->TestPath->Width = 350;
			// 
			// l_text_list
			// 
			this->l_text_list->AutoSize = true;
			this->l_text_list->Location = System::Drawing::Point(13, 13);
			this->l_text_list->Name = L"l_text_list";
			this->l_text_list->Size = System::Drawing::Size(84, 13);
			this->l_text_list->TabIndex = 1;
			this->l_text_list->Text = L"Список тестов:";
			// 
			// gb_add_test
			// 
			this->gb_add_test->Controls->Add(this->btn_new_test);
			this->gb_add_test->Controls->Add(this->btn_add_test);
			this->gb_add_test->Controls->Add(this->btn_clear_test);
			this->gb_add_test->Controls->Add(this->btn_browse_test);
			this->gb_add_test->Controls->Add(this->l_test_path);
			this->gb_add_test->Controls->Add(this->l_test_name);
			this->gb_add_test->Controls->Add(this->tb_path);
			this->gb_add_test->Controls->Add(this->tb_title);
			this->gb_add_test->Location = System::Drawing::Point(12, 186);
			this->gb_add_test->Name = L"gb_add_test";
			this->gb_add_test->Size = System::Drawing::Size(606, 109);
			this->gb_add_test->TabIndex = 2;
			this->gb_add_test->TabStop = false;
			this->gb_add_test->Text = L"Добавить тест:   ";
			// 
			// btn_new_test
			// 
			this->btn_new_test->Location = System::Drawing::Point(166, 78);
			this->btn_new_test->Name = L"btn_new_test";
			this->btn_new_test->Size = System::Drawing::Size(75, 23);
			this->btn_new_test->TabIndex = 6;
			this->btn_new_test->Text = L"Новый тест";
			this->btn_new_test->UseVisualStyleBackColor = true;
			this->btn_new_test->Click += gcnew System::EventHandler(this, &ChooseTest::btn_new_test_Click);
			// 
			// btn_add_test
			// 
			this->btn_add_test->Location = System::Drawing::Point(328, 78);
			this->btn_add_test->Name = L"btn_add_test";
			this->btn_add_test->Size = System::Drawing::Size(75, 23);
			this->btn_add_test->TabIndex = 4;
			this->btn_add_test->Text = L"Добавить";
			this->btn_add_test->UseVisualStyleBackColor = true;
			this->btn_add_test->Click += gcnew System::EventHandler(this, &ChooseTest::btn_add_test_Click);
			// 
			// btn_clear_test
			// 
			this->btn_clear_test->Location = System::Drawing::Point(247, 78);
			this->btn_clear_test->Name = L"btn_clear_test";
			this->btn_clear_test->Size = System::Drawing::Size(75, 23);
			this->btn_clear_test->TabIndex = 5;
			this->btn_clear_test->Text = L"Очистить";
			this->btn_clear_test->UseVisualStyleBackColor = true;
			this->btn_clear_test->Click += gcnew System::EventHandler(this, &ChooseTest::btn_clear_test_Click);
			// 
			// btn_browse_test
			// 
			this->btn_browse_test->Enabled = false;
			this->btn_browse_test->Location = System::Drawing::Point(525, 44);
			this->btn_browse_test->Name = L"btn_browse_test";
			this->btn_browse_test->Size = System::Drawing::Size(75, 23);
			this->btn_browse_test->TabIndex = 2;
			this->btn_browse_test->Text = L"Выбрать...";
			this->btn_browse_test->UseVisualStyleBackColor = true;
			this->btn_browse_test->Click += gcnew System::EventHandler(this, &ChooseTest::btn_browse_test_Click);
			// 
			// l_test_path
			// 
			this->l_test_path->AutoSize = true;
			this->l_test_path->Location = System::Drawing::Point(7, 49);
			this->l_test_path->Name = L"l_test_path";
			this->l_test_path->Size = System::Drawing::Size(108, 13);
			this->l_test_path->TabIndex = 3;
			this->l_test_path->Text = L"Путь к файлу теста:";
			// 
			// l_test_name
			// 
			this->l_test_name->AutoSize = true;
			this->l_test_name->Location = System::Drawing::Point(7, 23);
			this->l_test_name->Name = L"l_test_name";
			this->l_test_name->Size = System::Drawing::Size(91, 13);
			this->l_test_name->TabIndex = 2;
			this->l_test_name->Text = L"Название теста:";
			// 
			// tb_path
			// 
			this->tb_path->Location = System::Drawing::Point(118, 46);
			this->tb_path->Name = L"tb_path";
			this->tb_path->Size = System::Drawing::Size(401, 20);
			this->tb_path->TabIndex = 3;
			// 
			// tb_title
			// 
			this->tb_title->Location = System::Drawing::Point(118, 20);
			this->tb_title->Name = L"tb_title";
			this->tb_title->Size = System::Drawing::Size(482, 20);
			this->tb_title->TabIndex = 1;
			this->tb_title->TextChanged += gcnew System::EventHandler(this, &ChooseTest::tb_title_TextChanged);
			// 
			// gb_delete_test
			// 
			this->gb_delete_test->Controls->Add(this->btn_edit_test);
			this->gb_delete_test->Controls->Add(this->btn_delete_test);
			this->gb_delete_test->Location = System::Drawing::Point(16, 301);
			this->gb_delete_test->Name = L"gb_delete_test";
			this->gb_delete_test->Size = System::Drawing::Size(602, 58);
			this->gb_delete_test->TabIndex = 3;
			this->gb_delete_test->TabStop = false;
			this->gb_delete_test->Text = L"Операции над тестами:   ";
			// 
			// btn_edit_test
			// 
			this->btn_edit_test->Enabled = false;
			this->btn_edit_test->Location = System::Drawing::Point(324, 19);
			this->btn_edit_test->Name = L"btn_edit_test";
			this->btn_edit_test->Size = System::Drawing::Size(153, 23);
			this->btn_edit_test->TabIndex = 6;
			this->btn_edit_test->Text = L"Редактировать вопросы";
			this->btn_edit_test->UseVisualStyleBackColor = true;
			this->btn_edit_test->Click += gcnew System::EventHandler(this, &ChooseTest::btn_edit_test_Click);
			// 
			// btn_delete_test
			// 
			this->btn_delete_test->Enabled = false;
			this->btn_delete_test->Location = System::Drawing::Point(165, 19);
			this->btn_delete_test->Name = L"btn_delete_test";
			this->btn_delete_test->Size = System::Drawing::Size(153, 23);
			this->btn_delete_test->TabIndex = 7;
			this->btn_delete_test->Text = L"Удалить тест";
			this->btn_delete_test->UseVisualStyleBackColor = true;
			this->btn_delete_test->Click += gcnew System::EventHandler(this, &ChooseTest::btn_delete_test_Click);
			// 
			// openTestDlg
			// 
			this->openTestDlg->FileName = L"openFileDlg";
			this->openTestDlg->Filter = L"Adaptive Tets|*.adt";
			// 
			// back_to_start
			// 
			this->back_to_start->Location = System::Drawing::Point(201, 367);
			this->back_to_start->Name = L"back_to_start";
			this->back_to_start->Size = System::Drawing::Size(256, 31);
			this->back_to_start->TabIndex = 8;
			this->back_to_start->Text = L"Вернуться";
			this->back_to_start->UseVisualStyleBackColor = true;
			this->back_to_start->Click += gcnew System::EventHandler(this, &ChooseTest::back_to_start_Click);
			// 
			// ChooseTest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(630, 410);
			this->Controls->Add(this->back_to_start);
			this->Controls->Add(this->gb_delete_test);
			this->Controls->Add(this->gb_add_test);
			this->Controls->Add(this->l_text_list);
			this->Controls->Add(this->dgv_test_list);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ChooseTest";
			this->Text = L"Файлы тестов";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ChooseTest::ChooseTest_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_test_list))->EndInit();
			this->gb_add_test->ResumeLayout(false);
			this->gb_add_test->PerformLayout();
			this->gb_delete_test->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_RowEnter(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		this->btn_delete_test->Enabled = true;
		this->btn_edit_test->Enabled = true;
	}

	private: System::Void btn_clear_test_Click(System::Object^  sender, System::EventArgs^  e) {
		this->tb_path->Clear();
		this->tb_title->Clear();
	}
	private: System::Void tb_title_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->tb_title->Text != "")
		{
			this->btn_add_test->Enabled = true;
			this->btn_clear_test->Enabled = true;
			this->btn_browse_test->Enabled = true;
			this->btn_new_test->Enabled = true;
		}
		else
		{
			this->btn_add_test->Enabled = false;
			this->btn_clear_test->Enabled = false;
			this->btn_browse_test->Enabled = false;
			this->btn_new_test->Enabled = false;
		}
	}
	private: System::Void btn_browse_test_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->openTestDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->tb_path->Text = openTestDlg->FileName;
		}
	}
	private: System::Void btn_add_test_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->tb_title->Text == "")
		{
			MessageBox::Show("Введите название теста!");
			tb_title->Focus();
			return;
		}
		else
		{
			if (this->tb_path->Text == "")
			{
				MessageBox::Show("Выберите файл теста!");
				return;
			}
		}

		for (int row = 0; row < dgv_test_list->Rows->Count - 1; row++)
		{
			if (dgv_test_list->Rows->Count > 1)
			{
				try
				{
					if (dgv_test_list->Rows[row]->Cells["TestName"]->Value->ToString() == tb_title->Text->ToString())
					{
						MessageBox::Show("Тест с таким именем уже существует! Введите другое имя!");
						tb_title->Clear();
						tb_title->Focus();
						return;
					}
				}
				catch (Exception^ e)
				{
					//MessageBox::Show(e->Message);
				}
			}
		}

		try
		{
			this->dgv_test_list->Rows->Add(tb_title->Text, tb_path->Text);

			TestList temp;
			temp.test_name = tb_title->Text;
			temp.test_path = tb_path->Text;

			this->gv->test_list->Add(temp);

			this->tb_path->Clear();
			this->tb_title->Clear();
			this->dgv_test_list->CommitEdit(DataGridViewDataErrorContexts::Commit);


		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message);
		}
		this->dgv_test_list->CurrentCell = this->dgv_test_list->Rows[this->dgv_test_list->Rows->Count - 2]->Cells[0];
	}
	private: System::Void back_to_start_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void btn_edit_test_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dgv_test_list->RowCount > 1)
		{
			String^ test_name = this->dgv_test_list->CurrentRow->Cells["TestName"]->Value->ToString();
			String^ test_path = this->dgv_test_list->CurrentRow->Cells["TestPath"]->Value->ToString();

			Form^ editForm = gcnew EditTest(test_name, test_path, false);
		}
		else
		{
			MessageBox::Show("Нечего Редактировать! Ни один тест еще не был добавлен!");
		}
	}
	private: System::Void btn_new_test_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->tb_title->Text == "")
		{
			MessageBox::Show("Введите название теста!");
			tb_title->Focus();
			return;
		}
		else
		{
			Form^ editForm = gcnew EditTest(tb_title->Text, "", true);
			editForm->ShowDialog();
		}
	}
	private: System::Void ChooseTest_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		gv->test_list->Clear();

		for (int row = 0; row < dgv_test_list->Rows->Count - 1; row++)
		{
			TestList tl;

			tl.test_name = dgv_test_list->Rows[row]->Cells["TestName"]->Value->ToString();
			tl.test_path = dgv_test_list->Rows[row]->Cells["TestPath"]->Value->ToString();

			gv->test_list->Add(tl);
		}
	}
	private: System::Void btn_delete_test_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dgv_test_list->RowCount > 1)
		{
			gv->test_list->RemoveAt(dgv_test_list->CurrentRow->Index);
			this->dgv_test_list->CurrentCell = this->dgv_test_list->Rows[this->dgv_test_list->Rows->Count - 2]->Cells[0];

			this->dgv_test_list->Rows->Clear();

			for (int i = 0; i < gv->test_list->Count; i++)
			{
				this->dgv_test_list->Rows->Add(gv->test_list[i].test_name, gv->test_list[i].test_path);
			}

			this->dgv_test_list->CommitEdit(DataGridViewDataErrorContexts::Commit);

		}
		else
		{
			MessageBox::Show("Нечего удалять! Ни один тест еще не был добавлен!");
		}
	}
};
}
