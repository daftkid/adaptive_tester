#pragma once

#include "QuestStruct.h"
#include "EditQuestion.h"


using namespace System;
using namespace System::IO;
using namespace System::Text::RegularExpressions;

namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditTest
	/// </summary>
	public ref class EditTest : public System::Windows::Forms::Form
	{

	private: String ^ path;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Coefficient;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Question;


	public: Generic::List<QuestStruct>^ quest_list = gcnew  Generic::List<QuestStruct>();
	public:
		EditTest(String^ test_name, String^ test_path, bool is_new)
		{
			InitializeComponent();
			this->path = test_path;

			if (is_new)
			{
				btn_save_test->Enabled = false;
			}
			else
			{
				StreamReader^ din = File::OpenText(this->path);
				String^ delimiter_str = "|";
				array<Char>^ delimiter = delimiter_str->ToCharArray();
				array<String^>^ words;

				String^ str;
				int count = 0;
				while ((str = din->ReadLine()) != nullptr)
				{
					words = str->Split(delimiter);

					QuestStruct question;
					question.question = words[0];
					question.coefficient = Convert::ToInt16(words[1]);
					question.correct_answer = 0;

					String ^ what = "^[\+](.*)";
					String ^ result;

					for (int i = 2; i < 6; i++)
					{
						Regex ^ r = gcnew Regex(what, System::Text::RegularExpressions::RegexOptions::CultureInvariant);
						result = r->Match(words[i])->Value;
						if (result != "")
						{
							question.correct_answer = i - 2;
							words[i] = words[i]->Substring(1);
						}
					}

					question.first_answer = words[2];
					question.second_answer = words[3];
					question.third_answer = words[4];
					question.fourth_answer = words[5];

					quest_list->Add(question);
				}

				din->Close();

				for (int i = 0; i <= quest_list->Count - 1; i++)
				{
					QuestStruct quest = quest_list[i];

					this->dgv_list->Rows->Add(quest.coefficient, quest.question);
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditTest()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgv_list;
	protected:

	private: System::Windows::Forms::Label^  l_text_list;


	private: System::Windows::Forms::Button^  btn_edit;
	private: System::Windows::Forms::Button^  btn_delete;
	private: System::Windows::Forms::Button^  btn_new;
	private: System::Windows::Forms::Button^  btn_close;
	private: System::Windows::Forms::Button^  btn_save_test;
	private: System::Windows::Forms::Button^  btn_save_test_as;
	private: System::Windows::Forms::SaveFileDialog^  save_file_dlg;

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EditTest::typeid));
			this->dgv_list = (gcnew System::Windows::Forms::DataGridView());
			this->l_text_list = (gcnew System::Windows::Forms::Label());
			this->btn_edit = (gcnew System::Windows::Forms::Button());
			this->btn_delete = (gcnew System::Windows::Forms::Button());
			this->btn_new = (gcnew System::Windows::Forms::Button());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->btn_save_test = (gcnew System::Windows::Forms::Button());
			this->btn_save_test_as = (gcnew System::Windows::Forms::Button());
			this->save_file_dlg = (gcnew System::Windows::Forms::SaveFileDialog());
			this->Coefficient = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Question = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_list))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv_list
			// 
			this->dgv_list->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_list->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Coefficient,
					this->Question
			});
			this->dgv_list->Location = System::Drawing::Point(12, 40);
			this->dgv_list->Name = L"dgv_list";
			this->dgv_list->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_list->Size = System::Drawing::Size(741, 150);
			this->dgv_list->TabIndex = 0;
			// 
			// l_text_list
			// 
			this->l_text_list->AutoSize = true;
			this->l_text_list->Location = System::Drawing::Point(12, 9);
			this->l_text_list->Name = L"l_text_list";
			this->l_text_list->Size = System::Drawing::Size(98, 13);
			this->l_text_list->TabIndex = 2;
			this->l_text_list->Text = L"Список вопросов:";
			// 
			// btn_edit
			// 
			this->btn_edit->Location = System::Drawing::Point(290, 196);
			this->btn_edit->Name = L"btn_edit";
			this->btn_edit->Size = System::Drawing::Size(162, 23);
			this->btn_edit->TabIndex = 2;
			this->btn_edit->Text = L"Редактировать вопрос";
			this->btn_edit->UseVisualStyleBackColor = true;
			this->btn_edit->Click += gcnew System::EventHandler(this, &EditTest::btn_edit_Click);
			// 
			// btn_delete
			// 
			this->btn_delete->Location = System::Drawing::Point(122, 196);
			this->btn_delete->Name = L"btn_delete";
			this->btn_delete->Size = System::Drawing::Size(162, 23);
			this->btn_delete->TabIndex = 4;
			this->btn_delete->Text = L"Удалить вопрос";
			this->btn_delete->UseVisualStyleBackColor = true;
			this->btn_delete->Click += gcnew System::EventHandler(this, &EditTest::btn_delete_Click);
			// 
			// btn_new
			// 
			this->btn_new->Location = System::Drawing::Point(458, 196);
			this->btn_new->Name = L"btn_new";
			this->btn_new->Size = System::Drawing::Size(162, 23);
			this->btn_new->TabIndex = 3;
			this->btn_new->Text = L"Новый вопрос";
			this->btn_new->UseVisualStyleBackColor = true;
			this->btn_new->Click += gcnew System::EventHandler(this, &EditTest::btn_new_Click);
			// 
			// btn_close
			// 
			this->btn_close->Location = System::Drawing::Point(290, 230);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(162, 23);
			this->btn_close->TabIndex = 7;
			this->btn_close->Text = L"Назад";
			this->btn_close->UseVisualStyleBackColor = true;
			this->btn_close->Click += gcnew System::EventHandler(this, &EditTest::btn_close_Click);
			// 
			// btn_save_test
			// 
			this->btn_save_test->Location = System::Drawing::Point(122, 230);
			this->btn_save_test->Name = L"btn_save_test";
			this->btn_save_test->Size = System::Drawing::Size(162, 23);
			this->btn_save_test->TabIndex = 5;
			this->btn_save_test->Text = L"Сохранить тест";
			this->btn_save_test->UseVisualStyleBackColor = true;
			this->btn_save_test->Click += gcnew System::EventHandler(this, &EditTest::btn_save_test_Click);
			// 
			// btn_save_test_as
			// 
			this->btn_save_test_as->Location = System::Drawing::Point(458, 230);
			this->btn_save_test_as->Name = L"btn_save_test_as";
			this->btn_save_test_as->Size = System::Drawing::Size(162, 23);
			this->btn_save_test_as->TabIndex = 6;
			this->btn_save_test_as->Text = L"Сохранить тест как...";
			this->btn_save_test_as->UseVisualStyleBackColor = true;
			this->btn_save_test_as->Click += gcnew System::EventHandler(this, &EditTest::btn_save_test_as_Click);
			// 
			// save_file_dlg
			// 
			this->save_file_dlg->Filter = L"Adaptive Test|*.adt";
			// 
			// Coefficient
			// 
			this->Coefficient->HeaderText = L"Коэф";
			this->Coefficient->Name = L"Coefficient";
			this->Coefficient->ReadOnly = true;
			this->Coefficient->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Coefficient->Width = 50;
			// 
			// Question
			// 
			this->Question->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Question->HeaderText = L"Вопрос";
			this->Question->Name = L"Question";
			this->Question->ReadOnly = true;
			this->Question->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// EditTest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(764, 261);
			this->Controls->Add(this->btn_save_test_as);
			this->Controls->Add(this->btn_save_test);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->btn_new);
			this->Controls->Add(this->btn_delete);
			this->Controls->Add(this->btn_edit);
			this->Controls->Add(this->l_text_list);
			this->Controls->Add(this->dgv_list);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"EditTest";
			this->Text = L"EditTest";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_list))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_edit_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dgv_list->RowCount > 1)
		{
			EditQuestion^ editQuest = gcnew EditQuestion(quest_list[this->dgv_list->CurrentRow->Index]);
			editQuest->ShowDialog();

			quest_list[this->dgv_list->CurrentRow->Index] = editQuest->question;
			refresh_test();
		}
		else
		{
			MessageBox::Show("Any questions yet! Please add new!");
		}

	}
	private: System::Void btn_close_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

	public: System::Void refresh_test()
	{
		this->dgv_list->Rows->Clear();

		for (int i = 0; i <= quest_list->Count - 1; i++)
		{
			QuestStruct quest = quest_list[i];
			this->dgv_list->Rows->Add(quest.coefficient, quest.question);
		}

		this->dgv_list->CommitEdit(DataGridViewDataErrorContexts::Commit);
	}
	private: System::Void btn_delete_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dgv_list->RowCount > 1)
		{
			quest_list->RemoveAt(dgv_list->CurrentRow->Index);
			refresh_test();
			this->dgv_list->CurrentCell = this->dgv_list->Rows[this->dgv_list->Rows->Count - 2]->Cells[0];
		}
		else
		{
			MessageBox::Show("Ни один вопрос еще не был создан!");
		}

	}
	private: System::Void btn_new_Click(System::Object^  sender, System::EventArgs^  e) {
		QuestStruct new_quest;

		EditQuestion^ editQuest = gcnew EditQuestion(new_quest);
		editQuest->ShowDialog();

		quest_list->Add(editQuest->question);
		refresh_test();
		this->dgv_list->CurrentCell = this->dgv_list->Rows[this->dgv_list->Rows->Count - 2]->Cells[0];
	}
	private: System::Void btn_save_test_Click(System::Object^  sender, System::EventArgs^  e) {
		write_file(this->path);
	}
	private: System::Void write_file(String^ path)
	{
		try
		{
			StreamWriter^ sw = gcnew StreamWriter(path);
			for (int i = 0; i < this->quest_list->Count; i++)
			{
				QuestStruct q;
				q = quest_list[i];

				switch (quest_list[i].correct_answer)
				{
				case 0:
					q.first_answer = "+" + quest_list[i].first_answer;
					break;
				case 1:
					q.second_answer = "+" + quest_list[i].second_answer;
					break;
				case 2:
					q.third_answer = "+" + quest_list[i].third_answer;
					break;
				case 3:
					q.fourth_answer = "+" + quest_list[i].fourth_answer;
					break;
				}

				String ^ quest_text = q.question;

				sw->WriteLine(
					quest_text + "|" +
					q.coefficient.ToString() + "|" +
					q.first_answer + "|" +
					q.second_answer + "|" +
					q.third_answer + "|" +
					q.fourth_answer
				);
			}
			sw->Close();
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message);
		}
	}

	private: System::Void btn_save_test_as_Click(System::Object^  sender, System::EventArgs^  e) {
		this->save_file_dlg->ShowDialog();
		if (save_file_dlg->FileName != "")
		{
			write_file(save_file_dlg->FileName);
		}
	}
};
}
