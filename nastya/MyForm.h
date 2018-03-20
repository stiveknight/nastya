#pragma once
#include "json.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <msclr/marshal_cppstd.h>
#include "md5.h"
//#include <mpirxx.h>

namespace nastya {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using json = nlohmann::json;


	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^ loginUser = "null";
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  listBoxInbox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBoxLogin;
	private: System::Windows::Forms::TextBox^  textBoxPass;
	private: System::Windows::Forms::Button^  buttonLogin;
	private: System::Windows::Forms::Button^  buttonSent;
	private: System::Windows::Forms::TextBox^  textBoxTo;
	private: System::Windows::Forms::TextBox^  textBoxHeader;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  buttonSend;

	private: System::Windows::Forms::Button^  buttonReadMes;
	private: System::Windows::Forms::Button^  buttonDelMes;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  buttonRegistrsation;
	private: System::Windows::Forms::Label^  labelReg;
	private: System::Windows::Forms::Label^  labelDel;






	private: System::Windows::Forms::Label^  label5;
	private:
		const std::string currentDateTime() {
			time_t     now = time(0);
			struct tm  tstruct;
			char       buf[80];
			tstruct = *localtime(&now);
			strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

			return buf;
		}


		std::string toStringFromSysString(String^ s) {
			return msclr::interop::marshal_as<std::string>(s);
		}

		bool validLogin(System::String^ logn, System::String^ pass) {
			ifstream i("users.json");
			json j_in;
			i >> j_in;
			MD5 md5;
			//md5.digestString(&toStringFromSysString(pass)[0u]);
			for (auto& js : j_in["users"]) {
				if (js["login"] == toStringFromSysString(logn) && js["pass"] == md5.digestString(&toStringFromSysString(pass)[0u])) {
					i.close();
					return true;
				}
			}
			i.close();
			return false;
		}


	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBoxInbox = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPass = (gcnew System::Windows::Forms::TextBox());
			this->buttonLogin = (gcnew System::Windows::Forms::Button());
			this->buttonSent = (gcnew System::Windows::Forms::Button());
			this->textBoxTo = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHeader = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonSend = (gcnew System::Windows::Forms::Button());
			this->buttonReadMes = (gcnew System::Windows::Forms::Button());
			this->buttonDelMes = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonRegistrsation = (gcnew System::Windows::Forms::Button());
			this->labelReg = (gcnew System::Windows::Forms::Label());
			this->labelDel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(68, 145);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Get inbox";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBoxInbox
			// 
			this->listBoxInbox->FormattingEnabled = true;
			this->listBoxInbox->Location = System::Drawing::Point(45, 187);
			this->listBoxInbox->Name = L"listBoxInbox";
			this->listBoxInbox->Size = System::Drawing::Size(225, 303);
			this->listBoxInbox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(42, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Password";
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Location = System::Drawing::Point(97, 17);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(100, 20);
			this->textBoxLogin->TabIndex = 3;
			// 
			// textBoxPass
			// 
			this->textBoxPass->Location = System::Drawing::Point(97, 38);
			this->textBoxPass->Name = L"textBoxPass";
			this->textBoxPass->Size = System::Drawing::Size(100, 20);
			this->textBoxPass->TabIndex = 3;
			// 
			// buttonLogin
			// 
			this->buttonLogin->Location = System::Drawing::Point(159, 64);
			this->buttonLogin->Name = L"buttonLogin";
			this->buttonLogin->Size = System::Drawing::Size(75, 23);
			this->buttonLogin->TabIndex = 4;
			this->buttonLogin->Text = L"Log in";
			this->buttonLogin->UseVisualStyleBackColor = true;
			this->buttonLogin->Click += gcnew System::EventHandler(this, &MyForm::buttonLogin_Click);
			// 
			// buttonSent
			// 
			this->buttonSent->Location = System::Drawing::Point(159, 145);
			this->buttonSent->Name = L"buttonSent";
			this->buttonSent->Size = System::Drawing::Size(75, 23);
			this->buttonSent->TabIndex = 5;
			this->buttonSent->Text = L"Get sent";
			this->buttonSent->UseVisualStyleBackColor = true;
			this->buttonSent->Click += gcnew System::EventHandler(this, &MyForm::buttonSent_Click);
			// 
			// textBoxTo
			// 
			this->textBoxTo->Location = System::Drawing::Point(394, 18);
			this->textBoxTo->Name = L"textBoxTo";
			this->textBoxTo->Size = System::Drawing::Size(179, 20);
			this->textBoxTo->TabIndex = 6;
			// 
			// textBoxHeader
			// 
			this->textBoxHeader->Location = System::Drawing::Point(394, 41);
			this->textBoxHeader->Name = L"textBoxHeader";
			this->textBoxHeader->Size = System::Drawing::Size(179, 20);
			this->textBoxHeader->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(368, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(20, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"To";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(346, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Header";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(394, 67);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(179, 136);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			// 
			// buttonSend
			// 
			this->buttonSend->Location = System::Drawing::Point(394, 209);
			this->buttonSend->Name = L"buttonSend";
			this->buttonSend->Size = System::Drawing::Size(75, 23);
			this->buttonSend->TabIndex = 9;
			this->buttonSend->Text = L"Send";
			this->buttonSend->UseVisualStyleBackColor = true;
			this->buttonSend->Click += gcnew System::EventHandler(this, &MyForm::buttonSend_Click);
			// 
			// buttonReadMes
			// 
			this->buttonReadMes->Location = System::Drawing::Point(45, 496);
			this->buttonReadMes->Name = L"buttonReadMes";
			this->buttonReadMes->Size = System::Drawing::Size(90, 23);
			this->buttonReadMes->TabIndex = 11;
			this->buttonReadMes->Text = L"Read message";
			this->buttonReadMes->UseVisualStyleBackColor = true;
			this->buttonReadMes->Click += gcnew System::EventHandler(this, &MyForm::buttonReadMes_Click);
			// 
			// buttonDelMes
			// 
			this->buttonDelMes->Location = System::Drawing::Point(159, 496);
			this->buttonDelMes->Name = L"buttonDelMes";
			this->buttonDelMes->Size = System::Drawing::Size(95, 23);
			this->buttonDelMes->TabIndex = 12;
			this->buttonDelMes->Text = L"Del message";
			this->buttonDelMes->UseVisualStyleBackColor = true;
			this->buttonDelMes->Click += gcnew System::EventHandler(this, &MyForm::buttonDelMes_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(394, 257);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(162, 218);
			this->richTextBox2->TabIndex = 13;
			this->richTextBox2->Text = L"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(394, 238);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Selected message";
			// 
			// buttonRegistrsation
			// 
			this->buttonRegistrsation->Location = System::Drawing::Point(68, 64);
			this->buttonRegistrsation->Name = L"buttonRegistrsation";
			this->buttonRegistrsation->Size = System::Drawing::Size(75, 23);
			this->buttonRegistrsation->TabIndex = 15;
			this->buttonRegistrsation->Text = L"Registration";
			this->buttonRegistrsation->UseVisualStyleBackColor = true;
			this->buttonRegistrsation->Click += gcnew System::EventHandler(this, &MyForm::buttonRegistrsation_Click);
			// 
			// labelReg
			// 
			this->labelReg->AutoSize = true;
			this->labelReg->Location = System::Drawing::Point(135, 106);
			this->labelReg->Name = L"labelReg";
			this->labelReg->Size = System::Drawing::Size(0, 13);
			this->labelReg->TabIndex = 16;
			// 
			// labelDel
			// 
			this->labelDel->AutoSize = true;
			this->labelDel->Location = System::Drawing::Point(451, 496);
			this->labelDel->Name = L"labelDel";
			this->labelDel->Size = System::Drawing::Size(0, 13);
			this->labelDel->TabIndex = 17;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(725, 527);
			this->Controls->Add(this->labelDel);
			this->Controls->Add(this->labelReg);
			this->Controls->Add(this->buttonRegistrsation);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->buttonDelMes);
			this->Controls->Add(this->buttonReadMes);
			this->Controls->Add(this->buttonSend);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxHeader);
			this->Controls->Add(this->textBoxTo);
			this->Controls->Add(this->buttonSent);
			this->Controls->Add(this->buttonLogin);
			this->Controls->Add(this->textBoxPass);
			this->Controls->Add(this->textBoxLogin);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBoxInbox);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		/*INBOX*/
		this->richTextBox2->Clear();
		std::ifstream i("mails.json");
		json j_in;
		i >> j_in;
		this->listBoxInbox->Items->Clear();
		for (auto& js : j_in["mails"]) {
			String^ tmp = this->loginUser;
			if (js["to"] == toStringFromSysString(tmp)) {
				std::string ss = js["time"];
				std::string ss1 = js["from"];
				ss += " from: ";
				ss += ss1;
				String^ s = gcnew System::String(ss.c_str());
				this->listBoxInbox->Items->Add(s);

				//String^ c = gcnew System::String(js[""].c_str());
				//this->richTextBox2->AppendText()
			}
		}
		i.close();
	}
	private: System::Void buttonLogin_Click(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox2->Clear();
		this->listBoxInbox->Items->Clear();
		this->labelReg->Text = "";
		String^ logn = this->textBoxLogin->Text;
		String^ pass = this->textBoxPass->Text;
		if (validLogin(logn, pass)) {
			this->buttonDelMes->Enabled = true;
			this->buttonReadMes->Enabled = true;
			this->buttonSend->Enabled = true;
			this->buttonSent->Enabled = true;
			this->button1->Enabled = true;
			this->Text = logn;
			this->labelReg->Text = "WELCOME";
			this->textBoxLogin->Clear();
			this->textBoxPass->Clear();
		}
		else {
			this->buttonDelMes->Enabled = false;
			this->buttonReadMes->Enabled = false;
			this->buttonSend->Enabled = false;
			this->buttonSent->Enabled = false;
			this->button1->Enabled = false;
			this->Text = "-";
			this->listBoxInbox->Items->Clear();
			this->richTextBox2->Clear();
			this->labelReg->Text = "Incorrect login or password";
		}
		//this->richTextBox2->AppendText(logn);
		//this->richTextBox2->AppendText(pass);
		//this->Text = logn;
		this->loginUser = logn;

	}
	private: System::Void buttonSend_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ to = this->textBoxTo->Text;
		String^ header = this->textBoxHeader->Text;
		String^ textMes = this->richTextBox1->Text;

		json j;
		System::String^ managed = this->loginUser;
		j["from"] = this->toStringFromSysString(managed);
		j["to"] = this->toStringFromSysString(to);
		j["header"] = this->toStringFromSysString(header);
		j["text"] = this->toStringFromSysString(textMes);
		j["time"] = this->currentDateTime();

		std::string txt = j.dump();

		std::ifstream i("mails.json");
		json j_out;
		i >> j_out;
		j_out["mails"].push_back(j);
		i.close();
		std::ofstream o("mails.json");
		o << j_out.dump();
		o.close();
		this->richTextBox1->Clear();
		this->textBoxHeader->Clear();
		this->textBoxTo->Clear();
		//String ^ c = gcnew System::String(txt.c_str());
		//MarshalString(c, txt);
		//this->richTextBox2->AppendText(c);
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->buttonDelMes->Enabled = false;
		this->buttonReadMes->Enabled = false;
		this->buttonSend->Enabled = false;
		this->buttonSent->Enabled = false;
		this->button1->Enabled = false;
		this->Text = "-";
	}
	private: System::Void buttonReadMes_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ s = this->listBoxInbox->SelectedItem->ToString();
		string ss = toStringFromSysString(s);
		string ss1 = ss.substr(0, 18);
		ss = ss.substr(0, 19);

		std::ifstream i("mails.json");
		json j_in;
		i >> j_in;
		this->richTextBox2->Clear();
		for (auto& js : j_in["mails"]) {
			if (js["time"] == ss || js["time"] == ss1) {
				for (json::iterator it = js.begin(); it != js.end(); ++it) {
					string k = it.key();
					string v = it.value();
					string tmpp = k + ": " + v + "\n";
					String^ tmp = gcnew System::String(tmpp.c_str());
					this->richTextBox2->AppendText(tmp);
				}
			}

		}
		i.close();


		//String^ s = this->listBoxInbox->SelectedItem->ToString();
		//this->richTextBox2->AppendText(s);
	}
	private: System::Void buttonSent_Click(System::Object^ sender, System::EventArgs^ e) {
		std::ifstream i("mails.json");
		json j_in;
		i >> j_in;
		this->listBoxInbox->Items->Clear();
		for (auto& js : j_in["mails"]) {
			String^ tmp = this->loginUser;
			if (js["from"] == toStringFromSysString(tmp)) {
				std::string ss = js["time"];
				std::string ss1 = js["to"];
				ss += " to: ";
				ss += ss1;
				String^ s = gcnew System::String(ss.c_str());
				this->listBoxInbox->Items->Add(s);
			}
		}
		i.close();
	}
	private: System::Void buttonRegistrsation_Click(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox2->Clear();
		this->listBoxInbox->Items->Clear();
		this->labelReg->Text = "";
		String^ logn = this->textBoxLogin->Text;
		String^ pass = this->textBoxPass->Text;
		std::ifstream i("users.json");
		json j_in, j_out;
		i >> j_in;
		i.close();
		bool check = true;
		for (auto& js : j_in["users"]) {
			if (js["login"] == toStringFromSysString(logn)) {
				check = false;
				this->labelReg->Text = "This user already exists";
				return;
			}
		}
		if (check) {
			MD5 md5;
			json j;
			j["login"] = this->toStringFromSysString(logn);
			j["pass"] = md5.digestString(&toStringFromSysString(pass)[0u]);
			std::string txt = j.dump();
			std::ifstream ii("users.json");
			ii >> j_out;
			j_out["users"].push_back(j);
			ii.close();
			std::ofstream o("users.json");
			o << j_out.dump();
			o.close();
			this->labelReg->Text="Registration OK";
		}
	}


	private: System::Void buttonDelMes_Click(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox2->Clear();
		String^ s = this->listBoxInbox->SelectedItem->ToString();
		string ss = toStringFromSysString(s);
		ss = ss.substr(0, 19);
		std::ifstream i("mails.json");
		json j_in, j_out;
		i >> j_in;
		i.close();
		for (auto& js : j_in["mails"]) {
			if (js["time"] == ss && js["from"] == toStringFromSysString(loginUser)) {
				js.clear();
				std::ofstream o("mails.json");
				o << j_in.dump();
				o.close();
				this->labelDel->Text = "Message deleted";
				return;
			}
		}
		this->labelDel->Text = "Cannot delete";
	}


};
}
