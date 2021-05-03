#pragma once
#include "CJuego.h"
#include "CApp.h"
namespace TFDiscRoom {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for frmJuego
	/// </summary>
	public ref class frmJuego : public System::Windows::Forms::Form {
	private:
		CApp* Controller;
		BufferedGraphics^ buffer;
		Graphics^ g;
		Bitmap^ bmpPersonaje;
		Bitmap^ bmpFondo;
		Bitmap^ bmpMarco;
		Bitmap^ bmpBigDisc;
		Bitmap^ bmpSmallDisc;
		Bitmap^ bmpLateralDisc;
		Bitmap^ bmpPersecutorDisc;
		Bitmap^ bmpPortal;
		//Bitmap^ bmpBloodDisc;
		bool slowMode = false;
		int nvidas;
	private: System::Windows::Forms::Timer^  timer1;
	public:
		frmJuego(int nvidas) {
			this->nvidas = nvidas;
			InitializeComponent();
		}
	protected:
		~frmJuego() {
			if (components)
				delete components;
		}
	private: System::ComponentModel::IContainer^  components;
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &frmJuego::timer1_Tick);
			// 
			// frmJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(728, 601);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"frmJuego";
			this->Text = L"DiscRoom";
			this->Load += gcnew System::EventHandler(this, &frmJuego::frmJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmJuego::frmJuego_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &frmJuego::frmJuego_KeyUp);
			this->Leave += gcnew System::EventHandler(this, &frmJuego::frmJuego_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmJuego_Load(System::Object^  sender, System::EventArgs^  e) {
		g = this->CreateGraphics();
		BufferedGraphicsContext^Context = BufferedGraphicsManager::Current;
		bmpPersonaje = gcnew Bitmap("SpritePersonaje.png");
		bmpBigDisc = gcnew Bitmap("BigDisc.png");
		bmpSmallDisc = gcnew Bitmap("SmallDisc.png");
		bmpLateralDisc = gcnew Bitmap("LateralDisc.png");
		bmpPersecutorDisc = gcnew Bitmap("PersecutorDisc.png");
		bmpPortal = gcnew Bitmap("Portal.jpg");
		//bmpBloodDisc = gcnew Bitmap("BloodDisc.png");
		buffer = Context->Allocate(g, this->ClientRectangle);
		Controller = new CApp(nvidas, bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpPortal, this->ClientRectangle.Width, this->ClientRectangle.Height);
	}
	private: System::Void frmJuego_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::C) slowMode = true;
		Controller->MoverPersonaje(e->KeyData, slowMode);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		buffer->Graphics->Clear(this->BackColor);
		Controller->Dibujar(buffer->Graphics, bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpFondo, bmpMarco, bmpPortal);
		Controller->ComprobarPortal(bmpPersonaje, bmpSmallDisc, bmpLateralDisc, bmpPersecutorDisc, bmpBigDisc, bmpFondo, bmpMarco, bmpPortal);
		Controller->MoverDisco(0, 0, slowMode);
		if (Controller->getGameover() == true) {
			Bitmap^ bmpGameOver = gcnew Bitmap("GameOver.jpg");
			g->DrawImage(bmpGameOver, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);
			_sleep(1000);
			this->Close();
		}
		if (Controller->getNivel()==6) {
			Bitmap^ bmpGameOver = gcnew Bitmap("bmpWin.jpg");
			g->DrawImage(bmpGameOver, 0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);
			_sleep(1000);
			this->Close();
		}
		buffer->Render(g);
	}
	private: System::Void frmJuego_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyData == Keys::C) {
			slowMode = false;
			int aux = Controller->getContadorUsos();
			Controller->setContadorUsos(++aux);
		}
	}
	};
}
