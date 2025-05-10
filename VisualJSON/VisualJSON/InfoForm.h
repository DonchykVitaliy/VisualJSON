#pragma once

namespace VisualJSON {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InfoForm
	/// </summary>
	public ref class InfoForm : public System::Windows::Forms::Form
	{
	public:
		InfoForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->lblVersion->Text = "Версія: " + Application::ProductVersion;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnClose;
	protected:
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::Label^ lblVersion;
	private: System::Windows::Forms::Label^ lblAuthor;
	private: System::Windows::Forms::Label^ lblRights;
	private: System::Windows::Forms::PictureBox^ pbIcon;
	private: System::Windows::Forms::GroupBox^ gbInfo;
	private: System::Windows::Forms::Label^ lblInfo;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InfoForm::typeid));
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->lblVersion = (gcnew System::Windows::Forms::Label());
			this->lblAuthor = (gcnew System::Windows::Forms::Label());
			this->lblRights = (gcnew System::Windows::Forms::Label());
			this->pbIcon = (gcnew System::Windows::Forms::PictureBox());
			this->gbInfo = (gcnew System::Windows::Forms::GroupBox());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbIcon))->BeginInit();
			this->gbInfo->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnClose->Location = System::Drawing::Point(190, 422);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(91, 30);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"Закрити";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &InfoForm::btnClose_Click);
			// 
			// lblName
			// 
			this->lblName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblName->Location = System::Drawing::Point(201, 30);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(90, 16);
			this->lblName->TabIndex = 1;
			this->lblName->Text = L"VisualJSON";
			// 
			// lblVersion
			// 
			this->lblVersion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblVersion->AutoSize = true;
			this->lblVersion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblVersion->Location = System::Drawing::Point(201, 57);
			this->lblVersion->Name = L"lblVersion";
			this->lblVersion->Size = System::Drawing::Size(82, 16);
			this->lblVersion->TabIndex = 2;
			this->lblVersion->Text = L"Версія: 1.0.1";
			// 
			// lblAuthor
			// 
			this->lblAuthor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblAuthor->AutoSize = true;
			this->lblAuthor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblAuthor->Location = System::Drawing::Point(201, 84);
			this->lblAuthor->Name = L"lblAuthor";
			this->lblAuthor->Size = System::Drawing::Size(163, 16);
			this->lblAuthor->TabIndex = 3;
			this->lblAuthor->Text = L"Розробник: Дончик В. В.";
			// 
			// lblRights
			// 
			this->lblRights->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblRights->AutoSize = true;
			this->lblRights->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblRights->Location = System::Drawing::Point(201, 111);
			this->lblRights->Name = L"lblRights";
			this->lblRights->Size = System::Drawing::Size(130, 16);
			this->lblRights->TabIndex = 4;
			this->lblRights->Text = L"Всі права захищені";
			// 
			// pbIcon
			// 
			this->pbIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbIcon.Image")));
			this->pbIcon->Location = System::Drawing::Point(13, 30);
			this->pbIcon->Margin = System::Windows::Forms::Padding(4);
			this->pbIcon->Name = L"pbIcon";
			this->pbIcon->Size = System::Drawing::Size(181, 174);
			this->pbIcon->TabIndex = 5;
			this->pbIcon->TabStop = false;
			// 
			// gbInfo
			// 
			this->gbInfo->Controls->Add(this->lblInfo);
			this->gbInfo->Location = System::Drawing::Point(13, 212);
			this->gbInfo->Margin = System::Windows::Forms::Padding(4);
			this->gbInfo->Name = L"gbInfo";
			this->gbInfo->Padding = System::Windows::Forms::Padding(4);
			this->gbInfo->Size = System::Drawing::Size(463, 192);
			this->gbInfo->TabIndex = 8;
			this->gbInfo->TabStop = false;
			// 
			// lblInfo
			// 
			this->lblInfo->Location = System::Drawing::Point(15, 19);
			this->lblInfo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(431, 168);
			this->lblInfo->TabIndex = 7;
			this->lblInfo->Text = L"Застосунок дозволяє:\r\n1. Відкривати JSON файли.\r\n2. Редагувати JSON файли.\r\n3. Ст"
				L"ворювати JSON файли.\r\n4. Добавляти та видаляти гілки.\r\n5. Працювати з великими о"
				L"б\'ємами даних.";
			// 
			// InfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 466);
			this->Controls->Add(this->gbInfo);
			this->Controls->Add(this->pbIcon);
			this->Controls->Add(this->lblRights);
			this->Controls->Add(this->lblAuthor);
			this->Controls->Add(this->lblVersion);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->btnClose);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(514, 500);
			this->Name = L"InfoForm";
			this->Text = L"Про застосунок";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbIcon))->EndInit();
			this->gbInfo->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
