#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Security::Cryptography;

#include <tchar.h>

#include <locale.h>
#include "ChooseTest.h"
#include "QuestStruct.h"

namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginAdmin
	/// </summary>
	public ref class LoginAdmin : public System::Windows::Forms::Form
	{

	public:
		LoginAdmin(Form^ main_form, GlobalVars^ gv)
		{
			InitializeComponent();
			this->main = main_form;
			this->tb_password->Focus();
			this->gv = gv;
			this->password = this->gv->password;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginAdmin()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Form ^ main;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tb_password;
	private: System::Windows::Forms::RadioButton^  rb_enter_password;
	private: System::Windows::Forms::RadioButton^  rb_change_password;
	private: System::Windows::Forms::TextBox^  tb_old_password;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tb_new_password;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  back_to_start;
	private: System::Windows::Forms::Button^  btn_go;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		String^ password;
		GlobalVars^ gv;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_password = (gcnew System::Windows::Forms::TextBox());
			this->rb_enter_password = (gcnew System::Windows::Forms::RadioButton());
			this->rb_change_password = (gcnew System::Windows::Forms::RadioButton());
			this->tb_old_password = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_new_password = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->back_to_start = (gcnew System::Windows::Forms::Button());
			this->btn_go = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Пароль:";
			this->label1->Click += gcnew System::EventHandler(this, &LoginAdmin::label1_Click);
			// 
			// tb_password
			// 
			this->tb_password->Location = System::Drawing::Point(75, 41);
			this->tb_password->Name = L"tb_password";
			this->tb_password->PasswordChar = '*';
			this->tb_password->Size = System::Drawing::Size(203, 20);
			this->tb_password->TabIndex = 1;
			this->tb_password->TextChanged += gcnew System::EventHandler(this, &LoginAdmin::tb_password_TextChanged);
			// 
			// rb_enter_password
			// 
			this->rb_enter_password->AutoSize = true;
			this->rb_enter_password->Checked = true;
			this->rb_enter_password->Location = System::Drawing::Point(15, 13);
			this->rb_enter_password->Name = L"rb_enter_password";
			this->rb_enter_password->Size = System::Drawing::Size(100, 17);
			this->rb_enter_password->TabIndex = 0;
			this->rb_enter_password->TabStop = true;
			this->rb_enter_password->Text = L"Ввести пароль";
			this->rb_enter_password->UseVisualStyleBackColor = true;
			this->rb_enter_password->CheckedChanged += gcnew System::EventHandler(this, &LoginAdmin::rb_enter_password_CheckedChanged);
			// 
			// rb_change_password
			// 
			this->rb_change_password->AutoSize = true;
			this->rb_change_password->Location = System::Drawing::Point(15, 79);
			this->rb_change_password->Name = L"rb_change_password";
			this->rb_change_password->Size = System::Drawing::Size(115, 17);
			this->rb_change_password->TabIndex = 2;
			this->rb_change_password->TabStop = true;
			this->rb_change_password->Text = L"Изменить пароль";
			this->rb_change_password->UseVisualStyleBackColor = true;
			this->rb_change_password->CheckedChanged += gcnew System::EventHandler(this, &LoginAdmin::rb_change_password_CheckedChanged);
			// 
			// tb_old_password
			// 
			this->tb_old_password->Enabled = false;
			this->tb_old_password->Location = System::Drawing::Point(114, 102);
			this->tb_old_password->Name = L"tb_old_password";
			this->tb_old_password->PasswordChar = '*';
			this->tb_old_password->Size = System::Drawing::Size(164, 20);
			this->tb_old_password->TabIndex = 3;
			this->tb_old_password->TextChanged += gcnew System::EventHandler(this, &LoginAdmin::tb_old_password_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Старый пароль:";
			// 
			// tb_new_password
			// 
			this->tb_new_password->Enabled = false;
			this->tb_new_password->Location = System::Drawing::Point(114, 128);
			this->tb_new_password->Name = L"tb_new_password";
			this->tb_new_password->PasswordChar = '*';
			this->tb_new_password->Size = System::Drawing::Size(164, 20);
			this->tb_new_password->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Новый пароль:";
			// 
			// back_to_start
			// 
			this->back_to_start->Location = System::Drawing::Point(22, 219);
			this->back_to_start->Name = L"back_to_start";
			this->back_to_start->Size = System::Drawing::Size(256, 31);
			this->back_to_start->TabIndex = 6;
			this->back_to_start->Text = L"Вернуться";
			this->back_to_start->UseVisualStyleBackColor = true;
			this->back_to_start->Click += gcnew System::EventHandler(this, &LoginAdmin::back_to_start_Click);
			// 
			// btn_go
			// 
			this->btn_go->Enabled = false;
			this->btn_go->Location = System::Drawing::Point(22, 163);
			this->btn_go->Name = L"btn_go";
			this->btn_go->Size = System::Drawing::Size(256, 47);
			this->btn_go->TabIndex = 5;
			this->btn_go->Text = L"Продолжить";
			this->btn_go->UseVisualStyleBackColor = true;
			this->btn_go->Click += gcnew System::EventHandler(this, &LoginAdmin::btn_go_Click);
			// 
			// LoginAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(290, 258);
			this->Controls->Add(this->back_to_start);
			this->Controls->Add(this->btn_go);
			this->Controls->Add(this->tb_new_password);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tb_old_password);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->rb_change_password);
			this->Controls->Add(this->rb_enter_password);
			this->Controls->Add(this->tb_password);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"LoginAdmin";
			this->Text = L"Пароль для перподавателя";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LoginAdmin::LoginAdmin_FormClosing);
			this->Load += gcnew System::EventHandler(this, &LoginAdmin::LoginAdmin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void rb_enter_password_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->tb_password->Enabled = true;
		this->btn_go->Text = "Продолжить";
		
		this->tb_new_password->Enabled = false;
		this->tb_old_password->Enabled = false;

		this->tb_new_password->Clear();
		this->tb_old_password->Clear();
	}
	private: System::Void rb_change_password_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		this->tb_new_password->Enabled = true;
		this->tb_old_password->Enabled = true;

		this->btn_go->Text = "Изменить пароль";

		this->tb_password->Enabled = false;
		this->tb_password->Clear();
	}

	private: System::Void LoginAdmin_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		this->Visible = false;
		this->main->Show();
	}
	private: System::Void back_to_start_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	private: System::Void tb_password_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->tb_password->Text == "")
		{
			this->btn_go->Enabled = false;
		}
		else
		{
			this->btn_go->Enabled = true;
		}
	}
	private: System::Void btn_go_Click(System::Object^  sender, System::EventArgs^  e) {

		if (this->rb_enter_password->Checked)
		{
			if (!checkPassword(this->tb_password->Text)) return;
		}
		else
		{
			if (this->tb_new_password->Text == "" || this->tb_old_password->Text == "")
			{
				MessageBox::Show("Введите старый и новый пароли!");
				return;
			}
			else
			{
				if (!checkPassword(this->tb_old_password->Text)) return;
				this->password = tb_new_password->Text;
				gv->password = tb_new_password->Text;
			}
		}

		Form^ chooseTest = gcnew ChooseTest(gv);
		this->Hide();
		chooseTest->ShowDialog();
		this->Show();

	}
	private: System::Void LoginAdmin_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Boolean checkPassword(String^ in_password)
	{
		if (in_password != this->password)
		{
			MessageBox::Show("Пароль неверный! Повторите ввод пароля");
			this->tb_password->Clear();
			this->tb_password->Focus();
			return false;
		}
		else
		{
			return true;
		}
	}

	private: System::Void tb_old_password_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->tb_old_password->Text == "")
		{
			this->btn_go->Enabled = false;
		}
		else
		{
			this->btn_go->Enabled = true;
		}
	}
};
}
