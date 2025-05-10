#pragma once
#include <fstream>
#include <sstream>
#include "InfoForm.h"
#include "JsonTree.h"
#include "include/json/json.h"
#include <msclr/marshal_cppstd.h> // String^ <-> std::string

namespace VisualJSON {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::IO;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace System::Collections::Generic;

	public ref class MainForm : public Form {
	public:
		MainForm() {
			InitializeComponent();
		}

	protected:
		~MainForm() {
			if (components) {
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TreeView^ treeJson;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::String^ currentFilePath;
	private: String^ currentFileName;
	bool isModified = false;

	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ btnFile;
	private: System::Windows::Forms::ToolStripMenuItem^ btnOpen;
	private: System::Windows::Forms::ToolStripMenuItem^ btnSave;
	private: System::Windows::Forms::ToolStripMenuItem^ btnClose;

	private: System::Windows::Forms::ToolStripMenuItem^ btnWindow;
	private: System::Windows::Forms::ToolStripMenuItem^ btnClear;

	private: System::Windows::Forms::ToolStripMenuItem^ btnInfo;
	private: System::Windows::Forms::ToolStripMenuItem^ btnAbout;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ menuCreate;

	private: System::Windows::Forms::ToolStripButton^ menuSave;


	private: System::Windows::Forms::ToolStripMenuItem^ btnFastSave;
	private: System::Windows::Forms::ToolStripButton^ menuSaveAs;

	private: System::Windows::Forms::ToolStripButton^ menuTree;
	private: System::Windows::Forms::ToolStripButton^ menuFile;
	private: System::Windows::Forms::ToolStripButton^ menuDelete;


	private: System::Windows::Forms::ToolStripMenuItem^ btnCreate;

	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;

	private: System::Windows::Forms::Timer^ scrollSyncTimer;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblProgress;
	private: System::Windows::Forms::ToolStripProgressBar^ progressBarJson;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblStatus;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblStatusInf;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Panel^ panelMiniMap;
	private: System::Windows::Forms::Panel^ panelMenu;
	private: System::Windows::Forms::CheckBox^ checkMap;
	private: System::Windows::Forms::TextBox^ textBox;


	private: System::Windows::Forms::Label^ lblPath;
	private: System::Windows::Forms::Label^ lblSize;
	private: System::Windows::Forms::Label^ lblNameFile;
	private: VisualJSON::JsonTree^ treeHelper;
	private: System::Windows::Forms::ToolStripMenuItem^ btnExit;
	private: System::ComponentModel::IContainer^ components;

	private:

		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->treeJson = (gcnew System::Windows::Forms::TreeView());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->btnFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnCreate = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnFastSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->btnExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnClose = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnWindow = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnClear = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnInfo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->menuFile = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuCreate = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuSaveAs = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->menuTree = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuDelete = (gcnew System::Windows::Forms::ToolStripButton());
			this->scrollSyncTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->lblProgress = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->progressBarJson = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->lblStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->lblStatusInf = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panelMiniMap = (gcnew System::Windows::Forms::Panel());
			this->panelMenu = (gcnew System::Windows::Forms::Panel());
			this->checkMap = (gcnew System::Windows::Forms::CheckBox());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->lblPath = (gcnew System::Windows::Forms::Label());
			this->lblSize = (gcnew System::Windows::Forms::Label());
			this->lblNameFile = (gcnew System::Windows::Forms::Label());
			this->menuStrip->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->statusStrip->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->panelMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// treeJson
			// 
			this->treeJson->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeJson->LabelEdit = true;
			this->treeJson->Location = System::Drawing::Point(4, 4);
			this->treeJson->Margin = System::Windows::Forms::Padding(4);
			this->treeJson->Name = L"treeJson";
			this->treeJson->Size = System::Drawing::Size(667, 507);
			this->treeJson->TabIndex = 1;
			this->treeJson->AfterLabelEdit += gcnew System::Windows::Forms::NodeLabelEditEventHandler(this, &MainForm::treeJson_AfterLabelEdit_1);
			this->treeJson->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::treeJson_KeyDown);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			// 
			// menuStrip
			// 
			this->menuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->btnFile, this->btnWindow,
					this->btnInfo
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(900, 30);
			this->menuStrip->TabIndex = 8;
			this->menuStrip->Text = L"menuStrip";
			// 
			// btnFile
			// 
			this->btnFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->btnCreate, this->btnOpen,
					this->btnFastSave, this->btnSave, this->toolStripSeparator1, this->btnExit, this->btnClose
			});
			this->btnFile->Name = L"btnFile";
			this->btnFile->Size = System::Drawing::Size(57, 26);
			this->btnFile->Text = L"Файл";
			// 
			// btnCreate
			// 
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(225, 26);
			this->btnCreate->Text = L"Створити";
			this->btnCreate->Click += gcnew System::EventHandler(this, &MainForm::btnCreate_Click);
			// 
			// btnOpen
			// 
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(225, 26);
			this->btnOpen->Text = L"Відкрити";
			this->btnOpen->Click += gcnew System::EventHandler(this, &MainForm::btnOpen_Click);
			// 
			// btnFastSave
			// 
			this->btnFastSave->Name = L"btnFastSave";
			this->btnFastSave->Size = System::Drawing::Size(225, 26);
			this->btnFastSave->Text = L"Зберегти";
			this->btnFastSave->Click += gcnew System::EventHandler(this, &MainForm::btnFastSave_Click);
			// 
			// btnSave
			// 
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(225, 26);
			this->btnSave->Text = L"Зберегти як";
			this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(222, 6);
			// 
			// btnExit
			// 
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(225, 26);
			this->btnExit->Text = L"Закрити файл";
			this->btnExit->Click += gcnew System::EventHandler(this, &MainForm::btnExit_Click);
			// 
			// btnClose
			// 
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(225, 26);
			this->btnClose->Text = L"Закрити застосунок";
			this->btnClose->Click += gcnew System::EventHandler(this, &MainForm::CloseApplication);
			// 
			// btnWindow
			// 
			this->btnWindow->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->btnClear });
			this->btnWindow->Name = L"btnWindow";
			this->btnWindow->Size = System::Drawing::Size(58, 26);
			this->btnWindow->Text = L"Вікно";
			// 
			// btnClear
			// 
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(156, 26);
			this->btnClear->Text = L"Очистити";
			this->btnClear->Click += gcnew System::EventHandler(this, &MainForm::btnClear_Click_1);
			// 
			// btnInfo
			// 
			this->btnInfo->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->btnAbout });
			this->btnInfo->Name = L"btnInfo";
			this->btnInfo->Size = System::Drawing::Size(98, 26);
			this->btnInfo->Text = L"Інформація";
			// 
			// btnAbout
			// 
			this->btnAbout->Name = L"btnAbout";
			this->btnAbout->Size = System::Drawing::Size(196, 26);
			this->btnAbout->Text = L"Про застосунок";
			this->btnAbout->Click += gcnew System::EventHandler(this, &MainForm::btnAbout_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->menuFile, this->menuCreate,
					this->menuSave, this->menuSaveAs, this->toolStripSeparator2, this->menuTree, this->menuDelete
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 30);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(900, 31);
			this->toolStrip1->TabIndex = 9;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// menuFile
			// 
			this->menuFile->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->menuFile->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuFile.Image")));
			this->menuFile->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->menuFile->Name = L"menuFile";
			this->menuFile->Size = System::Drawing::Size(29, 28);
			this->menuFile->Text = L"toolStripButton1";
			this->menuFile->ToolTipText = L"Відкрити файл";
			this->menuFile->Click += gcnew System::EventHandler(this, &MainForm::menuFile_Click);
			// 
			// menuCreate
			// 
			this->menuCreate->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->menuCreate->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuCreate.Image")));
			this->menuCreate->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->menuCreate->Name = L"menuCreate";
			this->menuCreate->Size = System::Drawing::Size(29, 28);
			this->menuCreate->Text = L"toolStripButton1";
			this->menuCreate->ToolTipText = L"Новий файл";
			this->menuCreate->Click += gcnew System::EventHandler(this, &MainForm::menuCreate_Click);
			// 
			// menuSave
			// 
			this->menuSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->menuSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuSave.Image")));
			this->menuSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->menuSave->Name = L"menuSave";
			this->menuSave->Size = System::Drawing::Size(29, 28);
			this->menuSave->Text = L"toolStripButton2";
			this->menuSave->ToolTipText = L"Зберегти";
			this->menuSave->Click += gcnew System::EventHandler(this, &MainForm::menuSave_Click);
			// 
			// menuSaveAs
			// 
			this->menuSaveAs->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->menuSaveAs->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuSaveAs.Image")));
			this->menuSaveAs->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->menuSaveAs->Name = L"menuSaveAs";
			this->menuSaveAs->Size = System::Drawing::Size(29, 28);
			this->menuSaveAs->Text = L"toolStripButton3";
			this->menuSaveAs->ToolTipText = L"Зберегти як";
			this->menuSaveAs->Click += gcnew System::EventHandler(this, &MainForm::menuSaveAs_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 31);
			// 
			// menuTree
			// 
			this->menuTree->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->menuTree->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuTree.Image")));
			this->menuTree->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->menuTree->Name = L"menuTree";
			this->menuTree->Size = System::Drawing::Size(29, 28);
			this->menuTree->Text = L"toolStripButton4";
			this->menuTree->ToolTipText = L"Нова гілка";
			this->menuTree->Click += gcnew System::EventHandler(this, &MainForm::menuTree_Click);
			// 
			// menuDelete
			// 
			this->menuDelete->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->menuDelete->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menuDelete.Image")));
			this->menuDelete->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->menuDelete->Name = L"menuDelete";
			this->menuDelete->Size = System::Drawing::Size(29, 28);
			this->menuDelete->Text = L"toolStripButton2";
			this->menuDelete->ToolTipText = L"Видалити гілку";
			this->menuDelete->Click += gcnew System::EventHandler(this, &MainForm::menuDelete_Click);
			// 
			// statusStrip
			// 
			this->statusStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->lblProgress, this->progressBarJson,
					this->lblStatus, this->lblStatusInf
			});
			this->statusStrip->Location = System::Drawing::Point(0, 576);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(900, 24);
			this->statusStrip->TabIndex = 17;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// lblProgress
			// 
			this->lblProgress->Name = L"lblProgress";
			this->lblProgress->Size = System::Drawing::Size(67, 18);
			this->lblProgress->Text = L"Прогрес:";
			// 
			// progressBarJson
			// 
			this->progressBarJson->Name = L"progressBarJson";
			this->progressBarJson->Size = System::Drawing::Size(200, 16);
			this->progressBarJson->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			// 
			// lblStatus
			// 
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(80, 18);
			this->lblStatus->Text = L"     Статус:";
			// 
			// lblStatusInf
			// 
			this->lblStatusInf->Name = L"lblStatusInf";
			this->lblStatusInf->Size = System::Drawing::Size(80, 18);
			this->lblStatusInf->Text = L"очікується";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				75)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->treeJson, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 61);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(900, 515);
			this->tableLayoutPanel1->TabIndex = 19;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->panelMiniMap, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->panelMenu, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(678, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(219, 509);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// panelMiniMap
			// 
			this->panelMiniMap->AutoScroll = true;
			this->panelMiniMap->BackColor = System::Drawing::Color::Gainsboro;
			this->panelMiniMap->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelMiniMap->Location = System::Drawing::Point(4, 4);
			this->panelMiniMap->Margin = System::Windows::Forms::Padding(4);
			this->panelMiniMap->Name = L"panelMiniMap";
			this->panelMiniMap->Size = System::Drawing::Size(211, 399);
			this->panelMiniMap->TabIndex = 19;
			// 
			// panelMenu
			// 
			this->panelMenu->Controls->Add(this->checkMap);
			this->panelMenu->Controls->Add(this->textBox);
			this->panelMenu->Controls->Add(this->lblPath);
			this->panelMenu->Controls->Add(this->lblSize);
			this->panelMenu->Controls->Add(this->lblNameFile);
			this->panelMenu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelMenu->Location = System::Drawing::Point(3, 410);
			this->panelMenu->Name = L"panelMenu";
			this->panelMenu->Size = System::Drawing::Size(213, 96);
			this->panelMenu->TabIndex = 18;
			// 
			// checkMap
			// 
			this->checkMap->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->checkMap->AutoSize = true;
			this->checkMap->Checked = true;
			this->checkMap->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkMap->Location = System::Drawing::Point(0, 3);
			this->checkMap->Name = L"checkMap";
			this->checkMap->Size = System::Drawing::Size(203, 20);
			this->checkMap->TabIndex = 12;
			this->checkMap->Text = L"Відображення мапи файлу";
			this->checkMap->UseVisualStyleBackColor = true;
			this->checkMap->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkMap_CheckedChanged);
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(87, 29);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->ReadOnly = true;
			this->textBox->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox->Size = System::Drawing::Size(126, 69);
			this->textBox->TabIndex = 11;
			this->textBox->Text = L"Невідомо\r\nНевідомо\r\nНевідомо";
			this->textBox->WordWrap = false;
			// 
			// lblPath
			// 
			this->lblPath->AutoSize = true;
			this->lblPath->Location = System::Drawing::Point(3, 48);
			this->lblPath->Name = L"lblPath";
			this->lblPath->Size = System::Drawing::Size(107, 16);
			this->lblPath->TabIndex = 16;
			this->lblPath->Text = L"Шлях до файлу:";
			// 
			// lblSize
			// 
			this->lblSize->AutoSize = true;
			this->lblSize->Location = System::Drawing::Point(3, 64);
			this->lblSize->Name = L"lblSize";
			this->lblSize->Size = System::Drawing::Size(41, 16);
			this->lblSize->TabIndex = 14;
			this->lblSize->Text = L"Вага:";
			// 
			// lblNameFile
			// 
			this->lblNameFile->AutoSize = true;
			this->lblNameFile->Location = System::Drawing::Point(3, 32);
			this->lblNameFile->Name = L"lblNameFile";
			this->lblNameFile->Size = System::Drawing::Size(98, 16);
			this->lblNameFile->TabIndex = 13;
			this->lblNameFile->Text = L"Назва файлу:";
			// 
			// MainForm
			// 
			this->ClientSize = System::Drawing::Size(900, 600);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->MinimumSize = System::Drawing::Size(635, 647);
			this->Name = L"MainForm";
			this->Text = L"VisualJSON";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->panelMenu->ResumeLayout(false);
			this->panelMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		

		///////////////////////ФУНКЦІЇ/////////////////////////
		// FILE DATA 
		private: void textBoxData()
		{
			currentFilePath = openFileDialog->FileName; // Запам'ятовуємо шлях до файлу
			currentFileName = Path::GetFileName(currentFilePath); // імя файлу
			System::String^ directory = System::IO::Path::GetDirectoryName(currentFilePath);
			System::Int64 fileSize = (gcnew System::IO::FileInfo(currentFilePath))->Length;
			System::String^ sizeInKB = (fileSize / 1024.0).ToString("F2") + " КБ";

			// Заповнюємо TextBox — кожен рядок окремо
			textBox->Text = String::Format("{0}\r\n{1}\r\n{2}",
				currentFileName,
				directory,
				sizeInKB
			);
		}

		// click to TREE
	private: System::Void treeJson_NodeMouseDoubleClick(System::Object^ sender, TreeNodeMouseClickEventArgs^ e) {
		if (e->Node != nullptr) {
			e->Node->BeginEdit();
		}
	}

		   // TREE with JSON
	private: Json::Value ConvertTreeToJson(TreeNode^ node) {
		Json::Value jsonValue;

		if (node->Nodes->Count > 0) { // Якщо це об'єкт або масив
			for each (TreeNode ^ childNode in node->Nodes) {
				jsonValue[msclr::interop::marshal_as<std::string>(childNode->Text)] = ConvertTreeToJson(childNode);
			}
		}
		else { // Якщо це просто значення
			jsonValue = msclr::interop::marshal_as<std::string>(node->Text);
		}
		return jsonValue;
	}

		   // get json for MAP
	private: void GetAllTreeNodes(TreeNodeCollection^ nodes, List<TreeNode^>^ list) {
		for each (TreeNode ^ node in nodes) {
			list->Add(node);
			if (node->Nodes->Count > 0) {
				GetAllTreeNodes(node->Nodes, list);
			}
		}
	}

		   // MAP
	private: void BuildAccurateMinimap() {
		if (checkMap->Checked){
		panelMiniMap->Controls->Clear();

		List<TreeNode^>^ allNodes = gcnew List<TreeNode^>();
		GetAllTreeNodes(treeJson->Nodes, allNodes);
		int totalNodes = allNodes->Count;
		if (totalNodes == 0) return;
		int panelHeight = panelMiniMap->Height;
		int labelHeight = Math::Max(2, panelHeight / totalNodes);

		int y = 0;
		for each (TreeNode ^ node in allNodes) {
			Label^ lbl = gcnew Label();
			lbl->Click += gcnew System::EventHandler(this, &MainForm::MinimapLabel_Click);
			lbl->Text = node->Text;
			lbl->Font = gcnew System::Drawing::Font("Segoe UI", 6);
			lbl->AutoSize = false;
			lbl->Size = System::Drawing::Size(panelMiniMap->Width - 4, 14);
			lbl->Tag = node; // Прив'язуємо до TreeNode
			lbl->Padding = System::Windows::Forms::Padding(node->Level * 6, 0, 0, 0);
			lbl->Location = Point(0, y); // y — координата по вертикалі
			lbl->BringToFront(); // Важливо!

			// Додати до панелі
			panelMiniMap->Controls->Add(lbl);
			y += lbl->Height + 1;
		}
		}
	}

		  
		   ///////////////////////КНОПКИ/////////////////////////
				  // OPEN
	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog->Filter = "JSON файли (*.json)|*.json|Усі файли (*.*)|*.*";

		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				currentFilePath = openFileDialog->FileName; // шлях до файлу
				currentFileName = Path::GetFileName(currentFilePath); // імя файлу
				progressBarJson->Value = 0;  // 0%
				progressBarJson->Visible = true;
				this->lblStatusInf->Text = L"завантаження";

				std::string filePath = msclr::interop::marshal_as<std::string>(openFileDialog->FileName);
				std::ifstream file(filePath);
				if (!file.is_open()) throw std::runtime_error("Не вдалося відкрити файл!");

				progressBarJson->Value = 30;  // 30% - файл відкрито

				std::stringstream buffer;
				buffer << file.rdbuf();
				file.close();

				progressBarJson->Value = 60;  // 60% - файл прочитано

				Json::Value jsonData;
				Json::CharReaderBuilder builder;
				JSONCPP_STRING errs;
				std::istringstream ss(buffer.str());

				if (!parseFromStream(builder, ss, &jsonData, &errs)) {
					throw std::runtime_error("Помилка розбору JSON!");
				}
				progressBarJson->Value = 80;  // 80% - JSON оброблено

				treeJson->Nodes->Clear();
				TreeNode^ rootNode = gcnew TreeNode(currentFileName);
				treeHelper->PopulateTree(jsonData, rootNode);
				treeJson->Nodes->Add(rootNode);
				treeJson->ExpandAll();
				progressBarJson->Value = 100;  // 100%
				std::stringstream formattedJson;
				formattedJson << jsonData.toStyledString();
				textBoxData();
				BuildAccurateMinimap();
				treeHelper = gcnew VisualJSON::JsonTree(this->treeJson);
				this->lblStatusInf->Text = L"завантажено";
			}
			catch (const std::exception& ex) {
				this->lblStatusInf->Text = L"помилка";
				progressBarJson->Value = 0;
				MessageBox::Show("Помилка: " + gcnew String(ex.what()), "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

		   // CLEAR
	private: System::Void btnClear_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (treeJson->Nodes->Count != 0)
		treeHelper->Clear();
	}

		   // INFO
	private: System::Void btnAbout_Click(System::Object^ sender, System::EventArgs^ e) {
		InfoForm^ infoForm = gcnew InfoForm();
		infoForm->ShowDialog();
	}

		   // EXIT APP
	private: System::Void CloseApplication(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

		   // SAVE
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(currentFilePath)) {
			MessageBox::Show("Файл не відкритий!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		else {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "JSON файли (*.json)|*.json|Усі файли (*.*)|*.*";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				std::string filePath = msclr::interop::marshal_as<std::string>(saveDialog->FileName);
				Json::Value jsonData = ConvertTreeToJson(treeJson->Nodes[0]); // Конвертуємо TreeView у JSON
				std::ofstream file(filePath);
				file << jsonData.toStyledString();
				file.close();

				isModified = false;
				this->lblStatusInf->Text = L"збережено";
			}
		}
	}

		   // FAST SAVE
	private: System::Void btnFastSave_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(currentFilePath)) {
			MessageBox::Show("Файл не відкритий!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			msclr::interop::marshal_context context;
			std::string filePath = context.marshal_as<std::string>(currentFilePath);

			Json::Value jsonData = ConvertTreeToJson(treeJson->Nodes[0]); // Конвертуємо TreeView у JSON
			std::ofstream file(filePath);
			file << jsonData.toStyledString();
			file.close();

			isModified = false;
			this->lblStatusInf->Text = L"збережено";
		}
		catch (const std::exception& ex) {
			MessageBox::Show("Помилка збереження JSON: " + gcnew String(ex.what()), "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

		   // EDIT TEXT
	private: System::Void treeJson_AfterLabelEdit_1(System::Object^ sender, System::Windows::Forms::NodeLabelEditEventArgs^ e) {
		if (e->Label == nullptr || e->Label->Trim()->Length == 0) {
			e->CancelEdit = true;
			isModified = true;
			this->lblStatusInf->Text = L"модифіковано";
			MessageBox::Show("Назва вузла не може бути порожньою!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		isModified = true;
		this->lblStatusInf->Text = L"модифіковано";
	}
		   // CREATE
	private: System::Void btnCreate_Click(System::Object^ sender, System::EventArgs^ e) {
		menuCreate_Click(nullptr, gcnew System::EventArgs());
	}

		   // MENU SAVE
	private: System::Void menuSave_Click(System::Object^ sender, System::EventArgs^ e) {
		btnFastSave_Click(nullptr, gcnew System::EventArgs());
	}

		   // MENU SAVE AS
	private: System::Void menuSaveAs_Click(System::Object^ sender, System::EventArgs^ e) {
		btnSave_Click(nullptr, gcnew System::EventArgs());
	}

		   // MENU TREE
	private: System::Void menuTree_Click(System::Object^ sender, System::EventArgs^ e) {
		if (treeJson->SelectedNode == nullptr) {
			MessageBox::Show("Оберіть вузол, до якого додати новий елемент", "Увага!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		TreeNode^ newNode = gcnew TreeNode("New_Node");  // Створюємо новий вузол
		treeJson->SelectedNode->Nodes->Add(newNode);     // Додаємо його до вибраного вузла
		treeJson->SelectedNode->Expand();               // Розгортаємо батьківський вузол
		newNode->BeginEdit();                            // Запускаємо редагування нового вузла
		isModified = true;
		this->lblStatusInf->Text = L"модифіковано";
	}

		   // MENU DELETE
	private: System::Void menuDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		// Перевіряємо, чи вибраний вузол
		if (treeJson->SelectedNode == nullptr) {
			MessageBox::Show("Оберіть вузол для видалення!", "Увага", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Ви впевнені, що хочете видалити цей вузол?",
			"Підтвердження",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			treeJson->SelectedNode->Remove();
			isModified = true;
			this->lblStatusInf->Text = L"модифіковано";
		}
	}

		   // MENU OPEN FILE
	private: System::Void menuFile_Click(System::Object^ sender, System::EventArgs^ e) {
		btnOpen_Click(nullptr, gcnew System::EventArgs());
	}

		   // MENU CREATE
	private: System::Void menuCreate_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "JSON файли (*.json)|*.json|Усі файли (*.*)|*.*";
		saveFileDialog->Title = "Створити новий JSON файл";

		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Отримуємо шлях до нового файлу
			currentFilePath = saveFileDialog->FileName;

			// Створюємо новий порожній JSON-об'єкт
			Json::Value jsonData;
			jsonData["NewKey"] = "NewValue";

			// Записуємо JSON у файл
			std::string fileName = msclr::interop::marshal_as<std::string>(currentFilePath->ToString());
			std::ofstream file(fileName);
			if (file.is_open()) {
				file << jsonData.toStyledString();
				file.close();
			}

			// Очищаємо дерево і показуємо новий файл
			treeJson->Nodes->Clear();
			TreeNode^ rootNode = gcnew TreeNode(Path::GetFileName(currentFilePath));
			treeJson->Nodes->Add(rootNode);
		}
	}

		   // MINI MAP
	private: void MinimapLabel_Click(Object^ sender, EventArgs^ e) {
		Label^ lbl = safe_cast<Label^>(sender);
		TreeNode^ targetNode = dynamic_cast<TreeNode^>(lbl->Tag);

		if (targetNode != nullptr) {
			treeJson->SelectedNode = targetNode;
			targetNode->EnsureVisible();
		}
	}


		   // DELETE KEYBOARD BUTTON
	private: System::Void treeJson_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Delete) {
			menuDelete_Click(nullptr, gcnew EventArgs());
		}
	}

		   // CHECK BOX
private: System::Void checkMap_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!checkMap->Checked)
	{
		panelMiniMap->Controls->Clear();
	}
	else BuildAccurateMinimap();
}

	   // CLOSE WITHOUT SAVE
private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (isModified == true) {
		System::Windows::Forms::DialogResult result =
			MessageBox::Show(
				"Файл було змінено, але не збережено. Ви впевнені, що хочете вийти?",
				"Незбережені зміни",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning,
				MessageBoxDefaultButton::Button2
			);

		if (result == System::Windows::Forms::DialogResult::No) {
			e->Cancel = true; // скасувати закриття
		}
	}
}

	   // CLOSE FILE
private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
	if (progressBarJson->Value != 0)
	treeHelper->Close(currentFileName, currentFilePath, lblStatusInf, panelMiniMap, progressBarJson, textBox);
}
};
}