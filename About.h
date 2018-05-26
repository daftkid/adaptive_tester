#pragma once

namespace adaptive_tester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for About
	/// </summary>
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~About()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  l_name;
	protected:
	private: System::Windows::Forms::RichTextBox^  rtb_about;
	private: System::Windows::Forms::RichTextBox^  rtb_about_me;
	private: System::Windows::Forms::Label^  l_dev;
	private: System::Windows::Forms::Label^  l_c;
	private: System::Windows::Forms::Button^  btn_close;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(About::typeid));
			this->l_name = (gcnew System::Windows::Forms::Label());
			this->rtb_about = (gcnew System::Windows::Forms::RichTextBox());
			this->rtb_about_me = (gcnew System::Windows::Forms::RichTextBox());
			this->l_dev = (gcnew System::Windows::Forms::Label());
			this->l_c = (gcnew System::Windows::Forms::Label());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// l_name
			// 
			this->l_name->AutoSize = true;
			this->l_name->Location = System::Drawing::Point(12, 9);
			this->l_name->Name = L"l_name";
			this->l_name->Size = System::Drawing::Size(78, 13);
			this->l_name->TabIndex = 0;
			this->l_name->Text = L"О программе:";
			// 
			// rtb_about
			// 
			this->rtb_about->Location = System::Drawing::Point(12, 26);
			this->rtb_about->Name = L"rtb_about";
			this->rtb_about->ReadOnly = true;
			this->rtb_about->Size = System::Drawing::Size(426, 96);
			this->rtb_about->TabIndex = 3;
			this->rtb_about->Text = resources->GetString(L"rtb_about.Text");
			// 
			// rtb_about_me
			// 
			this->rtb_about_me->Location = System::Drawing::Point(15, 164);
			this->rtb_about_me->Name = L"rtb_about_me";
			this->rtb_about_me->ReadOnly = true;
			this->rtb_about_me->Size = System::Drawing::Size(423, 36);
			this->rtb_about_me->TabIndex = 5;
			this->rtb_about_me->Text = L"Дизайн и проектирование: Пивовар Александра Олеговна, гр. 156амп\nКодирование и те"
				L"стирование: Пивовар Александра Олеговна, гр. 156амп";
			// 
			// l_dev
			// 
			this->l_dev->AutoSize = true;
			this->l_dev->Location = System::Drawing::Point(12, 142);
			this->l_dev->Name = L"l_dev";
			this->l_dev->Size = System::Drawing::Size(91, 13);
			this->l_dev->TabIndex = 4;
			this->l_dev->Text = L"О разработчике:";
			// 
			// l_c
			// 
			this->l_c->AutoSize = true;
			this->l_c->Location = System::Drawing::Point(142, 217);
			this->l_c->Name = L"l_c";
			this->l_c->Size = System::Drawing::Size(147, 13);
			this->l_c->TabIndex = 6;
			this->l_c->Text = L"НАУ \"ХАИ\", 2018 - Харьков";
			// 
			// btn_close
			// 
			this->btn_close->Location = System::Drawing::Point(179, 236);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(75, 23);
			this->btn_close->TabIndex = 7;
			this->btn_close->Text = L"ОК";
			this->btn_close->UseVisualStyleBackColor = true;
			this->btn_close->Click += gcnew System::EventHandler(this, &About::btn_close_Click);
			// 
			// About
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(446, 271);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->l_c);
			this->Controls->Add(this->rtb_about_me);
			this->Controls->Add(this->l_dev);
			this->Controls->Add(this->rtb_about);
			this->Controls->Add(this->l_name);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"About";
			this->Text = L"О программе";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_close_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
