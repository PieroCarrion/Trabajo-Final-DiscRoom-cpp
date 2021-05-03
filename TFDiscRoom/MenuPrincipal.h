#pragma once
#include "frmJuego.h"
namespace TFDiscRoom {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace System::IO;
	/// <summary>
	/// Summary for MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form {
	private:
		SoundPlayer^ music;
		Graphics^ g;
		System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 25, FontStyle::Bold);;
		int nvidas = 3;
		String^ fileName = "Running in the 90 s.wav";
	private: System::Windows::Forms::Button^  btnAgregarMusica;
	private: System::Windows::Forms::Button^  btnAceptar;
	private: System::Windows::Forms::TextBox^  textBox1;
	public:
	public:
		MenuPrincipal(void) {
			InitializeComponent();
		}
	protected:
		~MenuPrincipal() {
			if (components)
				delete components;
		}
	private: System::Windows::Forms::Button^  btnStart;
	protected:
	private: System::Windows::Forms::Button^  btnConfigurar;
	private: System::Windows::Forms::Button^  btnInstrucciones;
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
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnConfigurar = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnAgregarMusica = (gcnew System::Windows::Forms::Button());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::Transparent;
			this->btnStart->Location = System::Drawing::Point(73, 214);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(97, 53);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnStart_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::Transparent;
			this->btnInstrucciones->Location = System::Drawing::Point(268, 214);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(97, 53);
			this->btnInstrucciones->TabIndex = 1;
			this->btnInstrucciones->Text = L"Instructions";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnInstrucciones_Click);
			// 
			// btnConfigurar
			// 
			this->btnConfigurar->BackColor = System::Drawing::Color::Transparent;
			this->btnConfigurar->Location = System::Drawing::Point(173, 326);
			this->btnConfigurar->Name = L"btnConfigurar";
			this->btnConfigurar->Size = System::Drawing::Size(97, 53);
			this->btnConfigurar->TabIndex = 2;
			this->btnConfigurar->Text = L"Settings";
			this->btnConfigurar->UseVisualStyleBackColor = false;
			this->btnConfigurar->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnConfigurar_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(212, 135);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(97, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Visible = false;
			// 
			// btnAgregarMusica
			// 
			this->btnAgregarMusica->BackColor = System::Drawing::Color::Transparent;
			this->btnAgregarMusica->Location = System::Drawing::Point(245, 214);
			this->btnAgregarMusica->Name = L"btnAgregarMusica";
			this->btnAgregarMusica->Size = System::Drawing::Size(120, 31);
			this->btnAgregarMusica->TabIndex = 4;
			this->btnAgregarMusica->Text = L"Choose File (.wav)";
			this->btnAgregarMusica->UseVisualStyleBackColor = false;
			this->btnAgregarMusica->Visible = false;
			this->btnAgregarMusica->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnAgregarMusica_Click);
			// 
			// btnAceptar
			// 
			this->btnAceptar->BackColor = System::Drawing::Color::Transparent;
			this->btnAceptar->Location = System::Drawing::Point(182, 341);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(75, 23);
			this->btnAceptar->TabIndex = 5;
			this->btnAceptar->Text = L"Accept";
			this->btnAceptar->UseVisualStyleBackColor = false;
			this->btnAceptar->Visible = false;
			this->btnAceptar->Click += gcnew System::EventHandler(this, &MenuPrincipal::btnAceptar_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(434, 431);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->btnAceptar);
			this->Controls->Add(this->btnAgregarMusica);
			this->Controls->Add(this->btnConfigurar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Location = System::Drawing::Point(50, 50);
			this->MaximumSize = System::Drawing::Size(450, 470);
			this->Name = L"MenuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Disc Room";
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void MenuPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
		g = this->CreateGraphics();
		Bitmap^ bmpFondo = gcnew Bitmap("menuBackGround.jpg");
		g->DrawImage(bmpFondo, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);
	}
	private: System::Void btnConfigurar_Click(System::Object^  sender, System::EventArgs^  e) {
		btnStart->Visible = false;
		btnInstrucciones->Visible = false;
		btnConfigurar->Visible = false;
		btnAgregarMusica->Visible = true;
		btnAceptar->Visible = true;
		textBox1->Visible = true;
		g->DrawString("Settings", f, Brushes::Black, 110, 30);
		g->DrawString("Player HP :", f, Brushes::Black, 26, 120);
		g->DrawString("Soundtrack :", f, Brushes::Black, 26, 200);
	}
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
		music = gcnew SoundPlayer(fileName);
		music->PlayLooping();
		frmJuego^ Juego = gcnew frmJuego(nvidas);
		Juego->ShowDialog();
		Juego->Close();
		music->Stop();
	}
	private: System::Void btnAgregarMusica_Click(System::Object^  sender, System::EventArgs^  e) {
		Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "wav files (*.wav)|*.wav|All files (*.*)|*.*";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((myStream = openFileDialog1->OpenFile()) != nullptr) {
				fileName = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				myStream->Close();
			}
		}
	}
	private: System::Void btnAceptar_Click(System::Object^  sender, System::EventArgs^  e) {
		g->Clear(this->BackColor);
		if (textBox1->Text != "") {
			nvidas = Convert::ToInt32(textBox1->Text);
		}
		Bitmap^ bmpFondo = gcnew Bitmap("menuBackGround.jpg");
		g->DrawImage(bmpFondo, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);
		btnStart->Visible = true;
		btnInstrucciones->Visible = true;
		btnConfigurar->Visible = true;
		btnAgregarMusica->Visible = false;
		btnAceptar->Visible = false;
		textBox1->Visible = false;
	}
	private: System::Void btnInstrucciones_Click(System::Object^  sender, System::EventArgs^  e) {
		g->DrawString("How to Play?", f, Brushes::Black, 100, 30);
		btnStart->Visible = false;
		btnInstrucciones->Visible = false;
		btnConfigurar->Visible = false;
		btnAceptar->Visible = true;
		g->DrawString("*Movement ", gcnew System::Drawing::Font("Arial", 13, FontStyle::Bold), Brushes::Black, 26, 100);
		g->DrawString("Arrow Up, Down, Right, Left", gcnew System::Drawing::Font("Arial", 13, FontStyle::Bold), Brushes::Black, 30, 115);
		g->DrawString("*'C' SlowMode", gcnew System::Drawing::Font("Arial", 13, FontStyle::Bold), Brushes::Black, 26, 150);
		g->DrawString("If you still live during X seconds", gcnew System::Drawing::Font("Arial", 13, FontStyle::Bold), Brushes::Black, 6, 185);
		g->DrawString("in the map is going to appear a portal,", gcnew System::Drawing::Font("Arial", 13, FontStyle::Bold), Brushes::Black, 6, 200);
		g->DrawString("that teleports you to the next level.", gcnew System::Drawing::Font("Arial", 13, FontStyle::Bold), Brushes::Black, 6, 215);
	}
	};
}

