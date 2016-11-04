#include "converter.h"
#include "ui_converter.h"

Converter::Converter(QWidget *parent) : QDialog(parent), ui(new Ui::Converter) {
  Hexits << "mör"
         << "ań"
         << "phaŕń"
         << "ńwën"
         << "ňai"
         << "chai"
         << "zoi"
         << "ńoi"
         << "štëp"
         << "rou`ań "
         << "rouphaŕń"
         << "rouńwën"
         << "rouňai"
         << "rouchai"
         << "rouzoi"
         << "rouńoi";

  Opers << "ap" << "äp"
        << "ïp" << "ip"
        << "kwot" << "kwöt"
        << "ëit" << "eit";

  ui->setupUi(this);

  connect(ui->spinBox, SIGNAL(valueChanged(int)), SLOT(reconvert(int)));
}

Converter::~Converter() { delete ui; }

void Converter::reconvert(int input) {
  // we first shift none
  int shift = 0;
  QString out;
  quint8 hexit = input % 16;

  QString hx = Hexits[hexit];
  bool alt = hx.endsWith("ä") || hx.endsWith("ö") || hx.endsWith("ü") || hx.endsWith("e") || hx.endsWith("i");

  if(input < 0) {
      input = -input;
      out = alt?"nil":"nïl";
  }
  if(input == 0) {
      out = Hexits[0];
  }
  while (input > 0) {
    hexit = input % 16;

    hx = Hexits[hexit];
    alt = hx.endsWith("ä") || hx.endsWith("ö") || hx.endsWith("ü") || hx.endsWith("e") || hx.endsWith("i");

      if (shift % 16 == 8) {
        out = out.prepend( Opers[8+alt]);
      }
      if (shift % 8 == 4) {
        out = out.prepend(Opers[4+alt]);
      }
      if (shift % 4 == 2) {
        out = out.prepend(Opers[2+alt]);
      }
      if (shift % 2 == 1) {
        out = out.prepend(Opers[0+alt]);
      }

      if (hexit != 0) {
      out.prepend(" "+hx);
    }

    input >>= 4;
    shift++;
  }


  ui->label->setText(out);
}
