#pragma once
#include "QuestStruct.h"
#include "Result.h"

namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for Test
	/// </summary>
	public ref class Test : public System::Windows::Forms::Form
	{
	private: String ^ path;
	private: String ^ name;
	private: int current_quest = 0;
	private: int cursor = 0;
	private: int quest_count = 0;
	private: int score = 0;
	private: Form ^ main_form;
	public: Generic::List<QuestStruct>^ quest_list = gcnew  Generic::List<QuestStruct>();
	public: Generic::List<int>^ done_indexes = gcnew  Generic::List<int>();

	public:
		Test(Form^ main, String^ test_name, String^ test_path)
		{
			InitializeComponent();
			this->main_form = main;
			this->name = test_name;
			this->path = test_path;

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

			this->quest_count = quest_list->Count;

			show_question(0);
			this->main_form->Hide();
			this->Show();
	
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Test()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  quest_gb;
	protected:
	private: System::Windows::Forms::RichTextBox^  rtb_quest;
	private: System::Windows::Forms::GroupBox^  gb_answers;
	private: System::Windows::Forms::RadioButton^  rb_a4;
	private: System::Windows::Forms::RadioButton^  rb_a3;
	private: System::Windows::Forms::RadioButton^  rb_a2;
	private: System::Windows::Forms::RadioButton^  rb_a1;
	private: System::Windows::Forms::Button^  btn_finish;
	private: System::Windows::Forms::Button^  btn_submit;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Test::typeid));
			this->quest_gb = (gcnew System::Windows::Forms::GroupBox());
			this->rtb_quest = (gcnew System::Windows::Forms::RichTextBox());
			this->gb_answers = (gcnew System::Windows::Forms::GroupBox());
			this->rb_a4 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_a3 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_a2 = (gcnew System::Windows::Forms::RadioButton());
			this->rb_a1 = (gcnew System::Windows::Forms::RadioButton());
			this->btn_finish = (gcnew System::Windows::Forms::Button());
			this->btn_submit = (gcnew System::Windows::Forms::Button());
			this->quest_gb->SuspendLayout();
			this->gb_answers->SuspendLayout();
			this->SuspendLayout();
			// 
			// quest_gb
			// 
			this->quest_gb->Controls->Add(this->rtb_quest);
			this->quest_gb->Location = System::Drawing::Point(12, 12);
			this->quest_gb->Name = L"quest_gb";
			this->quest_gb->Size = System::Drawing::Size(632, 141);
			this->quest_gb->TabIndex = 1;
			this->quest_gb->TabStop = false;
			this->quest_gb->Text = L"Вопрос (-/-):   ";
			// 
			// rtb_quest
			// 
			this->rtb_quest->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->rtb_quest->Location = System::Drawing::Point(7, 19);
			this->rtb_quest->Name = L"rtb_quest";
			this->rtb_quest->ReadOnly = true;
			this->rtb_quest->Size = System::Drawing::Size(619, 115);
			this->rtb_quest->TabIndex = 0;
			this->rtb_quest->Text = L"";
			// 
			// gb_answers
			// 
			this->gb_answers->Controls->Add(this->rb_a4);
			this->gb_answers->Controls->Add(this->rb_a3);
			this->gb_answers->Controls->Add(this->rb_a2);
			this->gb_answers->Controls->Add(this->rb_a1);
			this->gb_answers->Location = System::Drawing::Point(12, 159);
			this->gb_answers->Name = L"gb_answers";
			this->gb_answers->Size = System::Drawing::Size(632, 146);
			this->gb_answers->TabIndex = 2;
			this->gb_answers->TabStop = false;
			this->gb_answers->Text = L"Выберите ОДИН вариант ответа:   ";
			// 
			// rb_a4
			// 
			this->rb_a4->AutoSize = true;
			this->rb_a4->Location = System::Drawing::Point(6, 110);
			this->rb_a4->Name = L"rb_a4";
			this->rb_a4->Size = System::Drawing::Size(85, 17);
			this->rb_a4->TabIndex = 3;
			this->rb_a4->TabStop = true;
			this->rb_a4->Text = L"radioButton4";
			this->rb_a4->UseVisualStyleBackColor = true;
			// 
			// rb_a3
			// 
			this->rb_a3->AutoSize = true;
			this->rb_a3->Location = System::Drawing::Point(7, 80);
			this->rb_a3->Name = L"rb_a3";
			this->rb_a3->Size = System::Drawing::Size(85, 17);
			this->rb_a3->TabIndex = 2;
			this->rb_a3->TabStop = true;
			this->rb_a3->Text = L"radioButton3";
			this->rb_a3->UseVisualStyleBackColor = true;
			// 
			// rb_a2
			// 
			this->rb_a2->AutoSize = true;
			this->rb_a2->Location = System::Drawing::Point(6, 50);
			this->rb_a2->Name = L"rb_a2";
			this->rb_a2->Size = System::Drawing::Size(85, 17);
			this->rb_a2->TabIndex = 1;
			this->rb_a2->TabStop = true;
			this->rb_a2->Text = L"radioButton2";
			this->rb_a2->UseVisualStyleBackColor = true;
			// 
			// rb_a1
			// 
			this->rb_a1->AutoSize = true;
			this->rb_a1->Location = System::Drawing::Point(7, 20);
			this->rb_a1->Name = L"rb_a1";
			this->rb_a1->Size = System::Drawing::Size(85, 17);
			this->rb_a1->TabIndex = 0;
			this->rb_a1->TabStop = true;
			this->rb_a1->Text = L"radioButton1";
			this->rb_a1->UseVisualStyleBackColor = true;
			// 
			// btn_finish
			// 
			this->btn_finish->Location = System::Drawing::Point(196, 367);
			this->btn_finish->Name = L"btn_finish";
			this->btn_finish->Size = System::Drawing::Size(256, 31);
			this->btn_finish->TabIndex = 8;
			this->btn_finish->Text = L"Закончить тест";
			this->btn_finish->UseVisualStyleBackColor = true;
			this->btn_finish->Click += gcnew System::EventHandler(this, &Test::btn_finish_Click);
			// 
			// btn_submit
			// 
			this->btn_submit->Location = System::Drawing::Point(196, 311);
			this->btn_submit->Name = L"btn_submit";
			this->btn_submit->Size = System::Drawing::Size(256, 47);
			this->btn_submit->TabIndex = 7;
			this->btn_submit->Text = L"Ответить";
			this->btn_submit->UseVisualStyleBackColor = true;
			this->btn_submit->Click += gcnew System::EventHandler(this, &Test::btn_submit_Click);
			// 
			// Test
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(648, 405);
			this->Controls->Add(this->btn_finish);
			this->Controls->Add(this->btn_submit);
			this->Controls->Add(this->gb_answers);
			this->Controls->Add(this->quest_gb);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Test";
			this->Text = L"Test";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Test::Test_FormClosing);
			this->quest_gb->ResumeLayout(false);
			this->gb_answers->ResumeLayout(false);
			this->gb_answers->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Test_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		Form ^ result = gcnew Result(this->main_form, this->name, int(Math::Round((float(this->score) / float(this->quest_count))*100.0)));
		result->Show();
	}

	private: System::Void show_question(int index)
	{
		cursor++;

		MessageBox::Show("Сложность вопроса: " + quest_list[index].coefficient);
		this->quest_gb->Text = "Вопрос " + (cursor).ToString() + " из " + quest_count.ToString();

		rtb_quest->Text = quest_list[index].question;
		rb_a1->Text = quest_list[index].first_answer;
		rb_a2->Text = quest_list[index].second_answer;
		rb_a3->Text = quest_list[index].third_answer;
		rb_a4->Text = quest_list[index].fourth_answer;

		rb_a1->Checked = false;
		rb_a2->Checked = false;
		rb_a3->Checked = false;
		rb_a4->Checked = false;

		current_quest = index;

		add_item(current_quest);
	}
	private: System::Void btn_submit_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!(rb_a1->Checked || rb_a2->Checked || rb_a3->Checked || rb_a4->Checked))
		{
			MessageBox::Show("Выберите вариант ответа!");
			return;
		}

		bool correct = false;

		switch (quest_list[this->current_quest].correct_answer)
		{
		case 0:
			if (rb_a1->Checked)
			{
				score++;
				correct = true;
			}

			break;
		case 1:
			if (rb_a2->Checked) {
				score++;
				correct = true;
			}
			break;
		case 2:
			if (rb_a3->Checked) {
				score++;
				correct = true;
			}
			break;
		case 3:
			if (rb_a4->Checked) {
				score++;
				correct = true;
			}
			break;
		}

		if (done_indexes->Count < quest_list->Count)
		{
			int coef = quest_list[this->current_quest].coefficient;

			if (correct)
			{
				MessageBox::Show("Ответ правильный! Ищем вопрос посложнее");
				show_question(find_harder(coef));
			}
			else
			{
				MessageBox::Show("Ответ НЕПРАВИЛЬНЫЙ! Ищем вопрос полегче");
				show_question(find_easier(coef));
			}
		}
		else
		{
			this->Close();
		}		
	}
	private: System::Void btn_finish_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Вы уверены, что хотите закончить тест?", "Внимание!", MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
		{
			this->Close();
		}
		else
		{
			return;
		}
	}
	
	// check if the question has already been asked
	private: System::Boolean is_done(int index)
	{
		for (int j = 0; j < done_indexes->Count; j++)
		{
			if (index == done_indexes[j])
			{
				return true;
			}
		}
		return false;
	}

	// find the hardest question from the easier
	private: System::Int32 find_max_from_min_not_done(int t)
	{
		MessageBox::Show("Ищем наиболее сложный вопрос из всех, что легче предыдущего");

		int max = 1;
		int max_index = -1;

		for (int i = 0; i < quest_count; i++)
		{
			if (!is_done(i))
			{
				if (quest_list[i].coefficient < t)
				{
					if (max < quest_list[i].coefficient)
					{
						max = quest_list[i].coefficient;
						max_index = i;
					}
				}
			}
			else
			{
				continue;
			}
		}

		return max_index;
	}
    // find the easiest question from harder
	private: System::Int32 find_min_from_max_not_done(int t)
	{
		MessageBox::Show("Ищем наиболее легкий вопрос из всех, что сложнее предыдущего");

		int min = 15;
		int min_index = -1;

		for (int i = 0; i < quest_count; i++)
		{
			if (!is_done(i))
			{
				if (quest_list[i].coefficient > t)
				{
					if (min > quest_list[i].coefficient)
					{
						min = quest_list[i].coefficient;
						min_index = i;
					}
				}
			}
			else
			{
				continue;
			}
		}
		return min_index;
	}

	// find the hardest questions from all which have not been asked
	private: System::Int32 find_max_not_done()
	{
		MessageBox::Show("Ищем наиболее сложный вопрос из всех, что еще не были заданы, но легче предыдущего");
		int max = 1;
		int max_index = -1;

		for (int i = 0; i < quest_count; i++)
		{
			if ((max < quest_list[i].coefficient) && (!is_done(i)))
			{
				max = quest_list[i].coefficient;
				max_index = i;
			}
		}

		return max_index;
	}

	// find the easiest questions from all which have not been asked
	private: System::Int32 find_min_not_done()
	{
		MessageBox::Show("Ищем наиболее легкий вопрос из всех, что еще не были заданы, но сложнее предыдущего");

		int min = 15;
		int min_index = -1;

		for (int i = 0; i < quest_count; i++)
		{
			if ((min > quest_list[i].coefficient) && (!is_done(i)))
			{
				min = quest_list[i].coefficient;
				min_index = i;
			}
		}

		return min_index;
	}

	private: System::Int32 find_easier(int cur_coef)
	{
		int res = -1;

		for (int i = 0; i < quest_count; i++)
		{
			if (!is_done(i))
			{
				res = find_max_from_min_not_done(cur_coef);
				if (res > -1)
				{
					return res;
				}
				else
				{
					res = find_min_not_done();
					return res;
				}
			}
		}
	}

	private: System::Int32 find_harder(int cur_coef)
	{
		int res  = -1;

		for (int i = 0; i < quest_count; i++)
		{
			if (!is_done(i))
			{
				res = find_min_from_max_not_done(cur_coef);
				if (res > -1)
				{
					return res;
				}
				else
				{
					res = find_max_not_done();
					return res;
				}
			}
		}
	}

	private: System::Void add_item(int item)
	{
		for (int i = 0; i < done_indexes->Count; i++)
		{
			if (done_indexes[i] == item)
			{
				return;
			}
		}

		done_indexes->Add(item);
	}
};
}
