#include "findrel.h"
#include "ui_findrel.h"

FindRel::FindRel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FindRel)
{
    ui->setupUi(this);
}

FindRel::~FindRel()
{
    delete ui;
}

void FindRel::on_findRel_clicked()
{
    QVector<QString> relation;
    int max=0;
    QStringList r = ui->getRelation->text().split(" ");
    foreach (QString value, r) {
        relation.push_back(value);
        QStringList list = value.split(",");
        if(list[0].toInt() > max){
            max = list[0].toInt();
        }
        if(list[1].toInt() > max){
            max = list[1].toInt();
        }
    }
    this->n=max;
    QString Output = this->Find(relation);
    ui->textEdit->append("Relation Matrix: ");
    QString text = "";
    for(int i=0 ; i<this->n ; i++){
        for(int j=0 ; j<this->n ; j++){
            text += QString::number(this->matrix[i][j]) + "   ";
        }
        text += "\n";
    }
    ui->textEdit->append(text);
    if(Output.length()!=0){
        ui->textEdit->append(Output);
    }
    else{
        ui->textEdit->append("Nothing");
    }
}

