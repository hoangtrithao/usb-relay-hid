#pragma once

namespace GUIapp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    const int MaxRelaysNum = 8;

    /// <summary>
    /// Main form for the demo app
    ///
    /// WARNING: If you change the name of this class, you will need to change the
    ///          'Resource File Name' property for the managed resource compiler tool
    ///          associated with all .resx files this class depends on.  Otherwise,
    ///          the designers will not be able to interact properly with localized
    ///          resources associated with this form.
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();

            //
            // >>> Added constructor code 
            //
            txtMsg->Visible = false;

			arrayFill(aIndicators,   IndOn1, IndOn2, IndOn3, IndOn4, IndOn5, IndOn6, IndOn7, IndOn8);
            arrayFill(aRNames,       Rname1, Rname2, Rname3, Rname4, Rname5, Rname6, Rname7, Rname8);
            arrayFill(aButtonsOpen,  Ropen1, Ropen2, Ropen3, Ropen4, Ropen5, Ropen6, Ropen7, Ropen8);
            arrayFill(aButtonsClose, Rclose1, Rclose2, Rclose3, Rclose4, Rclose5, Rclose6, Rclose7, Rclose8);

            for ( int i = 0; i <  MaxRelaysNum; i++ ) {
                System::Windows::Forms::Button^ b;
                b = static_cast<System::Windows::Forms::Button^>(aButtonsOpen->GetValue(i));
                b->Text = L"ON";
                b->Click += gcnew System::EventHandler(this, &Form1::Ropen1_Click);
                b = static_cast<System::Windows::Forms::Button^>(aButtonsClose->GetValue(i));
                b->Text = L"OFF";
                b->Click += gcnew System::EventHandler(this, &Form1::Rclose1_Click);
                System::Windows::Forms::TextBox^ t;
                t = static_cast<System::Windows::Forms::TextBox^>(aRNames->GetValue(i));
                t->Text = L"PLC " + (i).ToString();
                t = static_cast<System::Windows::Forms::TextBox^>(aIndicators->GetValue(i));
            }
        }

    private:
        Array^ aButtonsOpen;
        Array^ aButtonsClose;
        Array^ aRNames;
        Array^ aIndicators;

		System::Windows::Forms::Label^  txtMsg;

        template<typename Ty> void arrayFill( Array^% aa, Ty t0, Ty t1, Ty t2, Ty t3, Ty t4, Ty t5, Ty t6, Ty t7)
        {
          aa = Array::CreateInstance(Ty::typeid, MaxRelaysNum);
          aa->SetValue(t0, 0);
          aa->SetValue(t1, 1);
          aa->SetValue(t2, 2);
          aa->SetValue(t3, 3);
          aa->SetValue(t4, 4);
          aa->SetValue(t5, 5);
          aa->SetValue(t6, 6);
          aa->SetValue(t7, 7);

          t0->Tag = gcnew System::Int16(0);
          t1->Tag = gcnew System::Int16(1);
          t2->Tag = gcnew System::Int16(2);
          t3->Tag = gcnew System::Int16(3);
          t4->Tag = gcnew System::Int16(4);
          t5->Tag = gcnew System::Int16(5);
          t6->Tag = gcnew System::Int16(6);
          t7->Tag = gcnew System::Int16(7);
        }

        //---------- End of added construction code --------------

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^  buttonFind;
    private: System::Windows::Forms::ComboBox^  comboDevices;
    private: System::Windows::Forms::Button^  buttonOpen;
    private: System::Windows::Forms::TextBox^  IndOpen;
    private: System::Windows::Forms::Button^  buttonClose;
    private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;

    private: System::Windows::Forms::TextBox^  Rname1;
    private: System::Windows::Forms::TextBox^  Rname2;
    private: System::Windows::Forms::TextBox^  Rname3;
    private: System::Windows::Forms::TextBox^  Rname4;
    private: System::Windows::Forms::TextBox^  Rname5;
    private: System::Windows::Forms::TextBox^  Rname6;
    private: System::Windows::Forms::TextBox^  Rname7;
    private: System::Windows::Forms::TextBox^  Rname8;

    private: System::Windows::Forms::TextBox^  IndOn1;
    private: System::Windows::Forms::TextBox^  IndOn2;
    private: System::Windows::Forms::TextBox^  IndOn3;
    private: System::Windows::Forms::TextBox^  IndOn4;
    private: System::Windows::Forms::TextBox^  IndOn5;
    private: System::Windows::Forms::TextBox^  IndOn6;
    private: System::Windows::Forms::TextBox^  IndOn7;
    private: System::Windows::Forms::TextBox^  IndOn8;

    private: System::Windows::Forms::Button^  Rclose8;
    private: System::Windows::Forms::Button^  Rclose7;
    private: System::Windows::Forms::Button^  Rclose6;
    private: System::Windows::Forms::Button^  Rclose5;
    private: System::Windows::Forms::Button^  Rclose4;
    private: System::Windows::Forms::Button^  Rclose3;
    private: System::Windows::Forms::Button^  Rclose2;
    private: System::Windows::Forms::Button^  Rclose1;

    private: System::Windows::Forms::Button^  Ropen1;
    private: System::Windows::Forms::Button^  Ropen2;
    private: System::Windows::Forms::Button^  Ropen3;
    private: System::Windows::Forms::Button^  Ropen4;
    private: System::Windows::Forms::Button^  Ropen5;
    private: System::Windows::Forms::Button^  Ropen6;
    private: System::Windows::Forms::Button^  Ropen7;
    private: System::Windows::Forms::Button^  Ropen8;

    private: System::Windows::Forms::Button^  RopenAll;
    private: System::Windows::Forms::Button^  RcloseAll;


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
            this->buttonFind = (gcnew System::Windows::Forms::Button());
            this->comboDevices = (gcnew System::Windows::Forms::ComboBox());
            this->buttonOpen = (gcnew System::Windows::Forms::Button());
            this->IndOpen = (gcnew System::Windows::Forms::TextBox());
            this->buttonClose = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->Rclose8 = (gcnew System::Windows::Forms::Button());
            this->Rclose7 = (gcnew System::Windows::Forms::Button());
            this->Rclose6 = (gcnew System::Windows::Forms::Button());
            this->Rclose5 = (gcnew System::Windows::Forms::Button());
            this->Rclose4 = (gcnew System::Windows::Forms::Button());
            this->Rclose3 = (gcnew System::Windows::Forms::Button());
            this->Rclose2 = (gcnew System::Windows::Forms::Button());
            this->Rname1 = (gcnew System::Windows::Forms::TextBox());
            this->Rname2 = (gcnew System::Windows::Forms::TextBox());
            this->Rname3 = (gcnew System::Windows::Forms::TextBox());
            this->Rname4 = (gcnew System::Windows::Forms::TextBox());
            this->Rname5 = (gcnew System::Windows::Forms::TextBox());
            this->Rname6 = (gcnew System::Windows::Forms::TextBox());
            this->Rname7 = (gcnew System::Windows::Forms::TextBox());
            this->Rname8 = (gcnew System::Windows::Forms::TextBox());
            this->IndOn2 = (gcnew System::Windows::Forms::TextBox());
            this->IndOn3 = (gcnew System::Windows::Forms::TextBox());
            this->IndOn4 = (gcnew System::Windows::Forms::TextBox());
            this->IndOn5 = (gcnew System::Windows::Forms::TextBox());
            this->IndOn6 = (gcnew System::Windows::Forms::TextBox());
            this->IndOn7 = (gcnew System::Windows::Forms::TextBox());
            this->IndOn8 = (gcnew System::Windows::Forms::TextBox());
            this->Ropen1 = (gcnew System::Windows::Forms::Button());
            this->Ropen2 = (gcnew System::Windows::Forms::Button());
            this->Ropen3 = (gcnew System::Windows::Forms::Button());
            this->Ropen4 = (gcnew System::Windows::Forms::Button());
            this->Ropen5 = (gcnew System::Windows::Forms::Button());
            this->Ropen6 = (gcnew System::Windows::Forms::Button());
            this->Ropen7 = (gcnew System::Windows::Forms::Button());
            this->Ropen8 = (gcnew System::Windows::Forms::Button());
            this->IndOn1 = (gcnew System::Windows::Forms::TextBox());
            this->Rclose1 = (gcnew System::Windows::Forms::Button());
            this->RopenAll = (gcnew System::Windows::Forms::Button());
            this->RcloseAll = (gcnew System::Windows::Forms::Button());
            this->txtMsg = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1->SuspendLayout();
            this->SuspendLayout();
            // 
            // buttonFind
            // 
            this->buttonFind->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonFind->Location = System::Drawing::Point(12, 9);
            this->buttonFind->Name = L"buttonFind";
            this->buttonFind->Size = System::Drawing::Size(125, 39);
            this->buttonFind->TabIndex = 0;
            this->buttonFind->Tag = L"99";
            this->buttonFind->Text = L"Search Device";
            this->buttonFind->UseVisualStyleBackColor = true;
            this->buttonFind->Click += gcnew System::EventHandler(this, &Form1::buttonFind_Click);
            // 
            // comboDevices
            // 
            this->comboDevices->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->comboDevices->FormattingEnabled = true;
            this->comboDevices->ItemHeight = 29;
            this->comboDevices->Location = System::Drawing::Point(143, 10);
            this->comboDevices->Name = L"comboDevices";
            this->comboDevices->Size = System::Drawing::Size(224, 37);
            this->comboDevices->TabIndex = 1;
            // 
            // buttonOpen
            // 
            this->buttonOpen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonOpen->Location = System::Drawing::Point(12, 53);
            this->buttonOpen->Name = L"buttonOpen";
            this->buttonOpen->Size = System::Drawing::Size(125, 48);
            this->buttonOpen->TabIndex = 2;
            this->buttonOpen->Text = L"Connect";
            this->buttonOpen->UseVisualStyleBackColor = true;
            this->buttonOpen->Click += gcnew System::EventHandler(this, &Form1::buttonOpen_Click);
            // 
            // IndOpen
            // 
            this->IndOpen->BackColor = System::Drawing::Color::Red;
            this->IndOpen->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->IndOpen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->IndOpen->Location = System::Drawing::Point(143, 54);
            this->IndOpen->Multiline = true;
            this->IndOpen->Name = L"IndOpen";
            this->IndOpen->Size = System::Drawing::Size(133, 47);
            this->IndOpen->TabIndex = 3;
            this->IndOpen->TabStop = false;
            // 
            // buttonClose
            // 
            this->buttonClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonClose->Location = System::Drawing::Point(282, 53);
            this->buttonClose->Name = L"buttonClose";
            this->buttonClose->Size = System::Drawing::Size(85, 48);
            this->buttonClose->TabIndex = 4;
            this->buttonClose->Text = L"Exit";
            this->buttonClose->UseVisualStyleBackColor = true;
            this->buttonClose->Click += gcnew System::EventHandler(this, &Form1::buttonClose_Click);
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->ColumnCount = 4;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                30)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                25)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                20)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                25)));
            this->tableLayoutPanel1->Controls->Add(this->Rclose8, 3, 7);
            this->tableLayoutPanel1->Controls->Add(this->Rclose7, 3, 6);
            this->tableLayoutPanel1->Controls->Add(this->Rclose6, 3, 5);
            this->tableLayoutPanel1->Controls->Add(this->Rclose5, 3, 4);
            this->tableLayoutPanel1->Controls->Add(this->Rclose4, 3, 3);
            this->tableLayoutPanel1->Controls->Add(this->Rclose3, 3, 2);
            this->tableLayoutPanel1->Controls->Add(this->Rclose2, 3, 1);
            this->tableLayoutPanel1->Controls->Add(this->Rname1, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->Rname2, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->Rname3, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->Rname4, 0, 3);
            this->tableLayoutPanel1->Controls->Add(this->Rname5, 0, 4);
            this->tableLayoutPanel1->Controls->Add(this->Rname6, 0, 5);
            this->tableLayoutPanel1->Controls->Add(this->Rname7, 0, 6);
            this->tableLayoutPanel1->Controls->Add(this->Rname8, 0, 7);
            this->tableLayoutPanel1->Controls->Add(this->IndOn2, 2, 1);
            this->tableLayoutPanel1->Controls->Add(this->IndOn3, 2, 2);
            this->tableLayoutPanel1->Controls->Add(this->IndOn4, 2, 3);
            this->tableLayoutPanel1->Controls->Add(this->IndOn5, 2, 4);
            this->tableLayoutPanel1->Controls->Add(this->IndOn6, 2, 5);
            this->tableLayoutPanel1->Controls->Add(this->IndOn7, 2, 6);
            this->tableLayoutPanel1->Controls->Add(this->IndOn8, 2, 7);
            this->tableLayoutPanel1->Controls->Add(this->Ropen1, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->Ropen2, 1, 1);
            this->tableLayoutPanel1->Controls->Add(this->Ropen3, 1, 2);
            this->tableLayoutPanel1->Controls->Add(this->Ropen4, 1, 3);
            this->tableLayoutPanel1->Controls->Add(this->Ropen5, 1, 4);
            this->tableLayoutPanel1->Controls->Add(this->Ropen6, 1, 5);
            this->tableLayoutPanel1->Controls->Add(this->Ropen7, 1, 6);
            this->tableLayoutPanel1->Controls->Add(this->Ropen8, 1, 7);
            this->tableLayoutPanel1->Controls->Add(this->IndOn1, 2, 0);
            this->tableLayoutPanel1->Controls->Add(this->Rclose1, 3, 0);
            this->tableLayoutPanel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->tableLayoutPanel1->Location = System::Drawing::Point(9, 107);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 4;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 0)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 0)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 0)));
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 0)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(361, 233);
            this->tableLayoutPanel1->TabIndex = 5;
            // 
            // Rclose8
            // 
            this->Rclose8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rclose8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rclose8->Location = System::Drawing::Point(273, 235);
            this->Rclose8->Name = L"Rclose8";
            this->Rclose8->Size = System::Drawing::Size(85, 1);
            this->Rclose8->TabIndex = 30;
            this->Rclose8->Text = L"OFF";
            this->Rclose8->UseVisualStyleBackColor = true;
            this->Rclose8->Visible = false;
            // 
            // Rclose7
            // 
            this->Rclose7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rclose7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rclose7->Location = System::Drawing::Point(273, 235);
            this->Rclose7->Name = L"Rclose7";
            this->Rclose7->Size = System::Drawing::Size(85, 1);
            this->Rclose7->TabIndex = 29;
            this->Rclose7->Text = L"OFF";
            this->Rclose7->UseVisualStyleBackColor = true;
            this->Rclose7->Visible = false;
            // 
            // Rclose6
            // 
            this->Rclose6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rclose6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rclose6->Location = System::Drawing::Point(273, 235);
            this->Rclose6->Name = L"Rclose6";
            this->Rclose6->Size = System::Drawing::Size(85, 1);
            this->Rclose6->TabIndex = 28;
            this->Rclose6->Text = L"OFF";
            this->Rclose6->UseVisualStyleBackColor = true;
            this->Rclose6->Visible = false;
            // 
            // Rclose5
            // 
            this->Rclose5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rclose5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rclose5->Location = System::Drawing::Point(273, 235);
            this->Rclose5->Name = L"Rclose5";
            this->Rclose5->Size = System::Drawing::Size(85, 1);
            this->Rclose5->TabIndex = 27;
            this->Rclose5->Text = L"OFF";
            this->Rclose5->UseVisualStyleBackColor = true;
            this->Rclose5->Visible = false;
            // 
            // Rclose4
            // 
            this->Rclose4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rclose4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rclose4->Location = System::Drawing::Point(273, 177);
            this->Rclose4->Name = L"Rclose4";
            this->Rclose4->Size = System::Drawing::Size(85, 52);
            this->Rclose4->TabIndex = 26;
            this->Rclose4->Text = L"OFF";
            this->Rclose4->UseVisualStyleBackColor = true;
            // 
            // Rclose3
            // 
            this->Rclose3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rclose3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rclose3->Location = System::Drawing::Point(273, 119);
            this->Rclose3->Name = L"Rclose3";
            this->Rclose3->Size = System::Drawing::Size(85, 52);
            this->Rclose3->TabIndex = 25;
            this->Rclose3->Text = L"OFF";
            this->Rclose3->UseVisualStyleBackColor = true;
            // 
            // Rclose2
            // 
            this->Rclose2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rclose2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rclose2->Location = System::Drawing::Point(273, 61);
            this->Rclose2->Name = L"Rclose2";
            this->Rclose2->Size = System::Drawing::Size(85, 52);
            this->Rclose2->TabIndex = 24;
            this->Rclose2->Text = L"OFF";
            this->Rclose2->UseVisualStyleBackColor = true;
            // 
            // Rname1
            // 
            this->Rname1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->Rname1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rname1->Location = System::Drawing::Point(3, 3);
            this->Rname1->MaxLength = 64;
            this->Rname1->Multiline = true;
            this->Rname1->Name = L"Rname1";
            this->Rname1->ReadOnly = true;
            this->Rname1->Size = System::Drawing::Size(102, 52);
            this->Rname1->TabIndex = 0;
            this->Rname1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // Rname2
            // 
            this->Rname2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->Rname2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rname2->Location = System::Drawing::Point(3, 61);
            this->Rname2->MaxLength = 64;
            this->Rname2->Multiline = true;
            this->Rname2->Name = L"Rname2";
            this->Rname2->ReadOnly = true;
            this->Rname2->Size = System::Drawing::Size(102, 52);
            this->Rname2->TabIndex = 1;
            this->Rname2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // Rname3
            // 
            this->Rname3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->Rname3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rname3->Location = System::Drawing::Point(3, 119);
            this->Rname3->MaxLength = 64;
            this->Rname3->Multiline = true;
            this->Rname3->Name = L"Rname3";
            this->Rname3->ReadOnly = true;
            this->Rname3->Size = System::Drawing::Size(102, 52);
            this->Rname3->TabIndex = 2;
            this->Rname3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // Rname4
            // 
            this->Rname4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->Rname4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rname4->Location = System::Drawing::Point(3, 177);
            this->Rname4->MaxLength = 64;
            this->Rname4->Multiline = true;
            this->Rname4->Name = L"Rname4";
            this->Rname4->ReadOnly = true;
            this->Rname4->Size = System::Drawing::Size(102, 52);
            this->Rname4->TabIndex = 3;
            this->Rname4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // Rname5
            // 
            this->Rname5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rname5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rname5->Location = System::Drawing::Point(3, 235);
            this->Rname5->MaxLength = 64;
            this->Rname5->Name = L"Rname5";
            this->Rname5->Size = System::Drawing::Size(102, 35);
            this->Rname5->TabIndex = 4;
            this->Rname5->Visible = false;
            // 
            // Rname6
            // 
            this->Rname6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rname6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rname6->Location = System::Drawing::Point(3, 235);
            this->Rname6->MaxLength = 64;
            this->Rname6->Name = L"Rname6";
            this->Rname6->Size = System::Drawing::Size(102, 35);
            this->Rname6->TabIndex = 5;
            this->Rname6->Visible = false;
            // 
            // Rname7
            // 
            this->Rname7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rname7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rname7->Location = System::Drawing::Point(3, 235);
            this->Rname7->MaxLength = 64;
            this->Rname7->Name = L"Rname7";
            this->Rname7->Size = System::Drawing::Size(102, 35);
            this->Rname7->TabIndex = 6;
            this->Rname7->Visible = false;
            // 
            // Rname8
            // 
            this->Rname8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rname8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rname8->Location = System::Drawing::Point(3, 235);
            this->Rname8->MaxLength = 64;
            this->Rname8->Name = L"Rname8";
            this->Rname8->Size = System::Drawing::Size(102, 35);
            this->Rname8->TabIndex = 7;
            this->Rname8->Visible = false;
            // 
            // IndOn2
            // 
            this->IndOn2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->IndOn2->BackColor = System::Drawing::Color::Red;
            this->IndOn2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->IndOn2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->IndOn2->Location = System::Drawing::Point(201, 61);
            this->IndOn2->Multiline = true;
            this->IndOn2->Name = L"IndOn2";
            this->IndOn2->ReadOnly = true;
            this->IndOn2->Size = System::Drawing::Size(66, 52);
            this->IndOn2->TabIndex = 8;
            this->IndOn2->TabStop = false;
            // 
            // IndOn3
            // 
            this->IndOn3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->IndOn3->BackColor = System::Drawing::Color::Red;
            this->IndOn3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->IndOn3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->IndOn3->Location = System::Drawing::Point(201, 119);
            this->IndOn3->Multiline = true;
            this->IndOn3->Name = L"IndOn3";
            this->IndOn3->ReadOnly = true;
            this->IndOn3->Size = System::Drawing::Size(66, 52);
            this->IndOn3->TabIndex = 9;
            this->IndOn3->TabStop = false;
            // 
            // IndOn4
            // 
            this->IndOn4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->IndOn4->BackColor = System::Drawing::Color::Red;
            this->IndOn4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->IndOn4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->IndOn4->Location = System::Drawing::Point(201, 177);
            this->IndOn4->Multiline = true;
            this->IndOn4->Name = L"IndOn4";
            this->IndOn4->ReadOnly = true;
            this->IndOn4->Size = System::Drawing::Size(66, 52);
            this->IndOn4->TabIndex = 10;
            this->IndOn4->TabStop = false;
            // 
            // IndOn5
            // 
            this->IndOn5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->IndOn5->BackColor = System::Drawing::Color::Red;
            this->IndOn5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->IndOn5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->IndOn5->Location = System::Drawing::Point(201, 235);
            this->IndOn5->Name = L"IndOn5";
            this->IndOn5->ReadOnly = true;
            this->IndOn5->Size = System::Drawing::Size(66, 35);
            this->IndOn5->TabIndex = 11;
            this->IndOn5->TabStop = false;
            this->IndOn5->Visible = false;
            // 
            // IndOn6
            // 
            this->IndOn6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->IndOn6->BackColor = System::Drawing::Color::Red;
            this->IndOn6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->IndOn6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->IndOn6->Location = System::Drawing::Point(201, 235);
            this->IndOn6->Name = L"IndOn6";
            this->IndOn6->ReadOnly = true;
            this->IndOn6->Size = System::Drawing::Size(66, 35);
            this->IndOn6->TabIndex = 12;
            this->IndOn6->TabStop = false;
            this->IndOn6->Visible = false;
            // 
            // IndOn7
            // 
            this->IndOn7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->IndOn7->BackColor = System::Drawing::Color::Red;
            this->IndOn7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->IndOn7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->IndOn7->Location = System::Drawing::Point(201, 235);
            this->IndOn7->Name = L"IndOn7";
            this->IndOn7->ReadOnly = true;
            this->IndOn7->Size = System::Drawing::Size(66, 35);
            this->IndOn7->TabIndex = 13;
            this->IndOn7->TabStop = false;
            this->IndOn7->Visible = false;
            // 
            // IndOn8
            // 
            this->IndOn8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->IndOn8->BackColor = System::Drawing::Color::Red;
            this->IndOn8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->IndOn8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->IndOn8->Location = System::Drawing::Point(201, 235);
            this->IndOn8->Name = L"IndOn8";
            this->IndOn8->ReadOnly = true;
            this->IndOn8->Size = System::Drawing::Size(66, 35);
            this->IndOn8->TabIndex = 14;
            this->IndOn8->TabStop = false;
            this->IndOn8->Visible = false;
            // 
            // Ropen1
            // 
            this->Ropen1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Ropen1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Ropen1->Location = System::Drawing::Point(111, 3);
            this->Ropen1->Name = L"Ropen1";
            this->Ropen1->Size = System::Drawing::Size(84, 52);
            this->Ropen1->TabIndex = 15;
            this->Ropen1->Text = L"ON";
            this->Ropen1->UseVisualStyleBackColor = true;
            // 
            // Ropen2
            // 
            this->Ropen2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Ropen2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Ropen2->Location = System::Drawing::Point(111, 61);
            this->Ropen2->Name = L"Ropen2";
            this->Ropen2->Size = System::Drawing::Size(84, 52);
            this->Ropen2->TabIndex = 16;
            this->Ropen2->Text = L"ON";
            this->Ropen2->UseVisualStyleBackColor = true;
            // 
            // Ropen3
            // 
            this->Ropen3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Ropen3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Ropen3->Location = System::Drawing::Point(111, 119);
            this->Ropen3->Name = L"Ropen3";
            this->Ropen3->Size = System::Drawing::Size(84, 52);
            this->Ropen3->TabIndex = 17;
            this->Ropen3->Text = L"ON";
            this->Ropen3->UseVisualStyleBackColor = true;
            // 
            // Ropen4
            // 
            this->Ropen4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Ropen4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Ropen4->Location = System::Drawing::Point(111, 177);
            this->Ropen4->Name = L"Ropen4";
            this->Ropen4->Size = System::Drawing::Size(84, 52);
            this->Ropen4->TabIndex = 18;
            this->Ropen4->Text = L"ON";
            this->Ropen4->UseVisualStyleBackColor = true;
            // 
            // Ropen5
            // 
            this->Ropen5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Ropen5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Ropen5->Location = System::Drawing::Point(111, 235);
            this->Ropen5->Name = L"Ropen5";
            this->Ropen5->Size = System::Drawing::Size(84, 1);
            this->Ropen5->TabIndex = 19;
            this->Ropen5->Text = L"ON";
            this->Ropen5->UseVisualStyleBackColor = true;
            this->Ropen5->Visible = false;
            // 
            // Ropen6
            // 
            this->Ropen6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Ropen6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Ropen6->Location = System::Drawing::Point(111, 235);
            this->Ropen6->Name = L"Ropen6";
            this->Ropen6->Size = System::Drawing::Size(84, 1);
            this->Ropen6->TabIndex = 20;
            this->Ropen6->Text = L"ON";
            this->Ropen6->UseVisualStyleBackColor = true;
            this->Ropen6->Visible = false;
            // 
            // Ropen7
            // 
            this->Ropen7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Ropen7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Ropen7->Location = System::Drawing::Point(111, 235);
            this->Ropen7->Name = L"Ropen7";
            this->Ropen7->Size = System::Drawing::Size(84, 1);
            this->Ropen7->TabIndex = 21;
            this->Ropen7->Text = L"ON";
            this->Ropen7->UseVisualStyleBackColor = true;
            this->Ropen7->Visible = false;
            // 
            // Ropen8
            // 
            this->Ropen8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Ropen8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Ropen8->Location = System::Drawing::Point(111, 235);
            this->Ropen8->Name = L"Ropen8";
            this->Ropen8->Size = System::Drawing::Size(84, 1);
            this->Ropen8->TabIndex = 22;
            this->Ropen8->Text = L"ON";
            this->Ropen8->UseVisualStyleBackColor = true;
            this->Ropen8->Visible = false;
            // 
            // IndOn1
            // 
            this->IndOn1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->IndOn1->BackColor = System::Drawing::Color::Red;
            this->IndOn1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->IndOn1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->IndOn1->Location = System::Drawing::Point(201, 3);
            this->IndOn1->Multiline = true;
            this->IndOn1->Name = L"IndOn1";
            this->IndOn1->ReadOnly = true;
            this->IndOn1->Size = System::Drawing::Size(66, 52);
            this->IndOn1->TabIndex = 6;
            this->IndOn1->TabStop = false;
            // 
            // Rclose1
            // 
            this->Rclose1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->Rclose1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Rclose1->Location = System::Drawing::Point(273, 3);
            this->Rclose1->Name = L"Rclose1";
            this->Rclose1->Size = System::Drawing::Size(85, 52);
            this->Rclose1->TabIndex = 23;
            this->Rclose1->Text = L"OFF";
            this->Rclose1->UseVisualStyleBackColor = true;
            // 
            // RopenAll
            // 
            this->RopenAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->RopenAll->Location = System::Drawing::Point(12, 350);
            this->RopenAll->Name = L"RopenAll";
            this->RopenAll->Size = System::Drawing::Size(161, 43);
            this->RopenAll->TabIndex = 6;
            this->RopenAll->Text = L"ALL ON";
            this->RopenAll->UseVisualStyleBackColor = true;
            this->RopenAll->Click += gcnew System::EventHandler(this, &Form1::RopenAll_Click);
            // 
            // RcloseAll
            // 
            this->RcloseAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->RcloseAll->Location = System::Drawing::Point(206, 350);
            this->RcloseAll->Name = L"RcloseAll";
            this->RcloseAll->Size = System::Drawing::Size(161, 43);
            this->RcloseAll->TabIndex = 7;
            this->RcloseAll->Text = L"ALL OFF";
            this->RcloseAll->UseVisualStyleBackColor = true;
            this->RcloseAll->Click += gcnew System::EventHandler(this, &Form1::RcloseAll_Click);
            // 
            // txtMsg
            // 
            this->txtMsg->AutoSize = true;
            this->txtMsg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtMsg->ForeColor = System::Drawing::Color::Black;
            this->txtMsg->Location = System::Drawing::Point(12, 400);
            this->txtMsg->Name = L"txtMsg";
            this->txtMsg->Size = System::Drawing::Size(31, 29);
            this->txtMsg->TabIndex = 8;
            this->txtMsg->Text = L"...";
            this->txtMsg->Visible = false;
            this->txtMsg->Click += gcnew System::EventHandler(this, &Form1::txtMsg_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(379, 442);
            this->Controls->Add(this->comboDevices);
            this->Controls->Add(this->buttonOpen);
            this->Controls->Add(this->RcloseAll);
            this->Controls->Add(this->RopenAll);
            this->Controls->Add(this->txtMsg);
            this->Controls->Add(this->tableLayoutPanel1);
            this->Controls->Add(this->buttonClose);
            this->Controls->Add(this->IndOpen);
            this->Controls->Add(this->buttonFind);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"Form1";
            this->Text = L"USB HID";
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
             
private: System::Void buttonFind_Click(System::Object^  sender, System::EventArgs^  e);
         
private: System::Void buttonOpen_Click(System::Object^  sender, System::EventArgs^  e);
         
private: System::Void buttonClose_Click(System::Object^  sender, System::EventArgs^  e);
         
private: System::Void RopenAll_Click(System::Object^  sender, System::EventArgs^  e);
         
private: System::Void RcloseAll_Click(System::Object^  sender, System::EventArgs^  e);
         
private: System::Void Ropen1_Click(System::Object^  sender, System::EventArgs^  e);
         
private: System::Void Rclose1_Click(System::Object^  sender, System::EventArgs^  e);
         
private: System::Void txtMsg_Click(System::Object^  sender, System::EventArgs^  e) {
             txtMsg->Visible = false;
         }

public:
    // Show a message in txtMsg field
    // The message is green or green, depending on param err
    // Hide txtMsg field if msg is null
    System::Void setMsg(System::String^ msg, bool err)
    {
        if (!msg) {
          txtMsg->Visible = false;
        } else {
          System::Drawing::Color color = err ? System::Drawing::Color::Red : System::Drawing::Color::Green; 
          txtMsg->Text = msg;
          txtMsg->BackColor = color;
          txtMsg->Visible = true;
       }
    }
};

}
