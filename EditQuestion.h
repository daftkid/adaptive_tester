#pragma once

#include "QuestStruct.h"

namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditQuestion
	/// </summary>
	public ref class EditQuestion : public System::Windows::Forms::Form
	{

	public: QuestStruct question;
	public:
		EditQuestion(QuestStruct q)
		{
			InitializeComponent();
			this->question = q;

			this->rtb_quest->Text = question.question;
			this->tb_answer_1->Text = question.first_answer;
			this->tb_answer_2->Text = question.second_answer;
			this->tb_answer_3->Text = question.third_answer;
			this->tb_answer_4->Text = question.fourth_answer;

			if (question.coefficient == 0)
			{
				this->nud_koef->Value = 1;
			}
			else
			{
				this->nud_koef->Value = question.coefficient;
			}			

			switch (this->question.correct_answer)
			{
				case 0:
					rb_answer_1->Checked = true;
					break;
				case 1:
					rb_answer_2->Checked = true;
					break;
				case 2:
					rb_answer_3->Checked = true;
					break;
				case 3:
					rb_answer_4->Checked = true;
					break;
				default:
					break;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditQuestion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  quest_gb;
	protected:
	private: System::Windows::Forms::RichTextBox^  rtb_quest;
	private: System::Windows::Forms::GroupBox^  answers_gb;
	private: System::Windows::Forms::Label^  l_warn;
	private: System::Windows::Forms::RadioButton^  rb_answer_4;
	private: System::Windows::Forms::TextBox^  tb_answer_4;
	private: System::Windows::Forms::RadioButton^  rb_answer_3;
	private: System::Windows::Forms::TextBox^  tb_answer_3;
	private: System::Windows::Forms::RadioButton^  rb_answer_2;
	private: System::Windows::Forms::TextBox^  tb_answer_2;
	private: System::Windows::Forms::RadioButton^  rb_answer_1;
	private: System::Windows::Forms::TextBox^  tb_answer_1;
	private: System::Windows::Forms::Label^  l_coef;
	private: System::Windows::Forms::NumericUpDown^  nud_koef;
	private: System::Windows::Forms::Button^  btn_clean;
	private: System::Windows::Forms::Button^  btn_ok;
	private: System::Windows::Forms::Button^  btn_back;

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
			this->quest_gb = (gcnew System::Windows::Forms::GroupBox());
			this->rtb_quest = (gcnew System::Windows::Forms::RichTextBox());
			this->answers_gb = (gcnew System::Windows::Forms::GroupBox());
			this->l_warn = (gcnew System::Windows::Forms::Label());
			this->rb_answer_4 = (gcnew System::Windows::Forms::RadioButton());
			this->tb_answer_4 = (gcnew System::Windows::Forms::TextBox());
			this->rb_answer_3 = (gcnew System::Windows::Forms::RadioButton());
			this->tb_answer_3 = (gcnew System::Windows::Forms::TextBox());
			this->rb_answer_2 = (gcnew System::Windows::Forms::RadioButton());
			this->tb_answer_2 = (gcnew System::Windows::Forms::TextBox());
			this->rb_answer_1 = (gcnew System::Windows::Forms::RadioButton());
			this->tb_answer_1 = (gcnew System::Windows::Forms::TextBox());
			this->l_coef = (gcnew System::Windows::Forms::Label());
			this->nud_koef = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_clean = (gcnew System::Windows::Forms::Button());
			this->btn_ok = (gcnew System::Windows::Forms::Button());
			this->btn_back = (gcnew System::Windows::Forms::Button());
			this->quest_gb->SuspendLayout();
			this->answers_gb->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_koef))->BeginInit();
			this->SuspendLayout();
			// 
			// quest_gb
			// 
			this->quest_gb->Controls->Add(this->rtb_quest);
			this->quest_gb->Location = System::Drawing::Point(12, 12);
			this->quest_gb->Name = L"quest_gb";
			this->quest_gb->Size = System::Drawing::Size(632, 141);
			this->quest_gb->TabIndex = 0;
			this->quest_gb->TabStop = false;
			this->quest_gb->Text = L"Введите текст вопроса:   ";
			// 
			// rtb_quest
			// 
			this->rtb_quest->Location = System::Drawing::Point(7, 19);
			this->rtb_quest->Name = L"rtb_quest";
			this->rtb_quest->Size = System::Drawing::Size(619, 115);
			this->rtb_quest->TabIndex = 0;
			this->rtb_quest->Text = L"";
			// 
			// answers_gb
			// 
			this->answers_gb->Controls->Add(this->l_warn);
			this->answers_gb->Controls->Add(this->rb_answer_4);
			this->answers_gb->Controls->Add(this->tb_answer_4);
			this->answers_gb->Controls->Add(this->rb_answer_3);
			this->answers_gb->Controls->Add(this->tb_answer_3);
			this->answers_gb->Controls->Add(this->rb_answer_2);
			this->answers_gb->Controls->Add(this->tb_answer_2);
			this->answers_gb->Controls->Add(this->rb_answer_1);
			this->answers_gb->Controls->Add(this->tb_answer_1);
			this->answers_gb->Location = System::Drawing::Point(12, 185);
			this->answers_gb->Name = L"answers_gb";
			this->answers_gb->Size = System::Drawing::Size(632, 169);
			this->answers_gb->TabIndex = 1;
			this->answers_gb->TabStop = false;
			this->answers_gb->Text = L"Введите варианты ответов:   ";
			// 
			// l_warn
			// 
			this->l_warn->AutoSize = true;
			this->l_warn->Location = System::Drawing::Point(7, 147);
			this->l_warn->Name = L"l_warn";
			this->l_warn->Size = System::Drawing::Size(266, 13);
			this->l_warn->TabIndex = 8;
			this->l_warn->Text = L"ВАЖНО! Не забудьте отметить правильный ответ!";
			// 
			// rb_answer_4
			// 
			this->rb_answer_4->AutoSize = true;
			this->rb_answer_4->Location = System::Drawing::Point(7, 113);
			this->rb_answer_4->Name = L"rb_answer_4";
			this->rb_answer_4->Size = System::Drawing::Size(75, 17);
			this->rb_answer_4->TabIndex = 7;
			this->rb_answer_4->TabStop = true;
			this->rb_answer_4->Text = L"Ответ №4";
			this->rb_answer_4->UseVisualStyleBackColor = true;
			// 
			// tb_answer_4
			// 
			this->tb_answer_4->Location = System::Drawing::Point(88, 112);
			this->tb_answer_4->Name = L"tb_answer_4";
			this->tb_answer_4->Size = System::Drawing::Size(538, 20);
			this->tb_answer_4->TabIndex = 8;
			// 
			// rb_answer_3
			// 
			this->rb_answer_3->AutoSize = true;
			this->rb_answer_3->Location = System::Drawing::Point(7, 87);
			this->rb_answer_3->Name = L"rb_answer_3";
			this->rb_answer_3->Size = System::Drawing::Size(75, 17);
			this->rb_answer_3->TabIndex = 5;
			this->rb_answer_3->TabStop = true;
			this->rb_answer_3->Text = L"Ответ №3";
			this->rb_answer_3->UseVisualStyleBackColor = true;
			// 
			// tb_answer_3
			// 
			this->tb_answer_3->Location = System::Drawing::Point(88, 86);
			this->tb_answer_3->Name = L"tb_answer_3";
			this->tb_answer_3->Size = System::Drawing::Size(538, 20);
			this->tb_answer_3->TabIndex = 6;
			// 
			// rb_answer_2
			// 
			this->rb_answer_2->AutoSize = true;
			this->rb_answer_2->Location = System::Drawing::Point(7, 61);
			this->rb_answer_2->Name = L"rb_answer_2";
			this->rb_answer_2->Size = System::Drawing::Size(75, 17);
			this->rb_answer_2->TabIndex = 4;
			this->rb_answer_2->TabStop = true;
			this->rb_answer_2->Text = L"Ответ №2";
			this->rb_answer_2->UseVisualStyleBackColor = true;
			// 
			// tb_answer_2
			// 
			this->tb_answer_2->Location = System::Drawing::Point(88, 60);
			this->tb_answer_2->Name = L"tb_answer_2";
			this->tb_answer_2->Size = System::Drawing::Size(538, 20);
			this->tb_answer_2->TabIndex = 4;
			// 
			// rb_answer_1
			// 
			this->rb_answer_1->AutoSize = true;
			this->rb_answer_1->Location = System::Drawing::Point(7, 35);
			this->rb_answer_1->Name = L"rb_answer_1";
			this->rb_answer_1->Size = System::Drawing::Size(75, 17);
			this->rb_answer_1->TabIndex = 2;
			this->rb_answer_1->TabStop = true;
			this->rb_answer_1->Text = L"Ответ №1";
			this->rb_answer_1->UseVisualStyleBackColor = true;
			// 
			// tb_answer_1
			// 
			this->tb_answer_1->Location = System::Drawing::Point(88, 34);
			this->tb_answer_1->Name = L"tb_answer_1";
			this->tb_answer_1->Size = System::Drawing::Size(538, 20);
			this->tb_answer_1->TabIndex = 3;
			// 
			// l_coef
			// 
			this->l_coef->AutoSize = true;
			this->l_coef->Location = System::Drawing::Point(19, 161);
			this->l_coef->Name = L"l_coef";
			this->l_coef->Size = System::Drawing::Size(236, 13);
			this->l_coef->TabIndex = 2;
			this->l_coef->Text = L"Коффициент сложности вопроса (от 1 до 10):";
			// 
			// nud_koef
			// 
			this->nud_koef->Location = System::Drawing::Point(261, 159);
			this->nud_koef->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nud_koef->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nud_koef->Name = L"nud_koef";
			this->nud_koef->Size = System::Drawing::Size(70, 20);
			this->nud_koef->TabIndex = 1;
			this->nud_koef->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// btn_clean
			// 
			this->btn_clean->Location = System::Drawing::Point(153, 360);
			this->btn_clean->Name = L"btn_clean";
			this->btn_clean->Size = System::Drawing::Size(75, 23);
			this->btn_clean->TabIndex = 9;
			this->btn_clean->Text = L"Очистить";
			this->btn_clean->UseVisualStyleBackColor = true;
			this->btn_clean->Click += gcnew System::EventHandler(this, &EditQuestion::btn_clean_Click);
			// 
			// btn_ok
			// 
			this->btn_ok->Location = System::Drawing::Point(296, 360);
			this->btn_ok->Name = L"btn_ok";
			this->btn_ok->Size = System::Drawing::Size(75, 23);
			this->btn_ok->TabIndex = 10;
			this->btn_ok->Text = L"ОК";
			this->btn_ok->UseVisualStyleBackColor = true;
			this->btn_ok->Click += gcnew System::EventHandler(this, &EditQuestion::btn_ok_Click);
			// 
			// btn_back
			// 
			this->btn_back->Location = System::Drawing::Point(449, 360);
			this->btn_back->Name = L"btn_back";
			this->btn_back->Size = System::Drawing::Size(75, 23);
			this->btn_back->TabIndex = 11;
			this->btn_back->Text = L"Назад";
			this->btn_back->UseVisualStyleBackColor = true;
			this->btn_back->Click += gcnew System::EventHandler(this, &EditQuestion::btn_back_Click);
			// 
			// EditQuestion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(656, 395);
			this->Controls->Add(this->btn_back);
			this->Controls->Add(this->btn_ok);
			this->Controls->Add(this->btn_clean);
			this->Controls->Add(this->nud_koef);
			this->Controls->Add(this->l_coef);
			this->Controls->Add(this->answers_gb);
			this->Controls->Add(this->quest_gb);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"EditQuestion";
			this->Text = L"Редактирование вопроса";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &EditQuestion::EditQuestion_FormClosing);
			this->quest_gb->ResumeLayout(false);
			this->answers_gb->ResumeLayout(false);
			this->answers_gb->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_koef))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_clean_Click(System::Object^  sender, System::EventArgs^  e) {
		this->rtb_quest->Clear();
		this->tb_answer_1->Clear();
		this->tb_answer_2->Clear();
		this->tb_answer_3->Clear();
		this->tb_answer_4->Clear();
		this->nud_koef->Value = 1;
		this->rb_answer_1->Checked = false;
		this->rb_answer_2->Checked = false;
		this->rb_answer_3->Checked = false;
		this->rb_answer_4->Checked = false;
	}
	private: System::Void btn_back_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void btn_ok_Click(System::Object^  sender, System::EventArgs^  e) {
		if (rtb_quest->Text == "")
		{
			MessageBox::Show("Вы не ввели текст вопроса!", "Не могу сохранить вопрос");
			this->rtb_quest->Focus();
			return;
		}

		if (tb_answer_1->Text == "")
		{
			MessageBox::Show("Вы не ввели вариант ответа №1!", "Не могу сохранить вопрос");
			this->tb_answer_1->Focus();
			return;
		}

		if (tb_answer_2->Text == "")
		{
			MessageBox::Show("Вы не ввели вариант ответа №2!", "Не могу сохранить вопрос");
			this->tb_answer_2->Focus();
			return;
		}

		if (tb_answer_3->Text == "")
		{
			MessageBox::Show("Вы не ввели вариант ответа №3!", "Не могу сохранить вопрос");
			this->tb_answer_3->Focus();
			return;
		}

		if (tb_answer_4->Text == "")
		{
			MessageBox::Show("Вы не ввели вариант ответа №4!", "Не могу сохранить вопрос");
			this->tb_answer_4->Focus();
			return;
		}

		if (!(rb_answer_1->Checked || rb_answer_2->Checked || rb_answer_3->Checked || rb_answer_4->Checked))
		{
			MessageBox::Show("Вы не отметили правильный вариант ответа!", "Не могу сохранить вопрос");
			return;
		}

		String ^ str = "";

		for each (String^ str_in in rtb_quest->Lines)
		{
			str = str + " " + str_in;
		}

		question.question = str;
		question.first_answer = tb_answer_1->Text;
		question.second_answer = tb_answer_2->Text;
		question.third_answer = tb_answer_3->Text;
		question.fourth_answer = tb_answer_4->Text;

		question.coefficient = Convert::ToInt32(nud_koef->Text);
		
		if (rb_answer_1->Checked)
		{
			question.correct_answer = 0;
		}
		if (rb_answer_2->Checked)
		{
			question.correct_answer = 1;
		}
		if (rb_answer_3->Checked)
		{
			question.correct_answer = 2;
		}
		if (rb_answer_4->Checked)
		{
			question.correct_answer = 3;
		}

		this->Close();
	}
	private: System::Void EditQuestion_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	}
};
}
