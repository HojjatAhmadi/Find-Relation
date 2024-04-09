#ifndef FINDREL_H
#define FINDREL_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class FindRel;
}
QT_END_NAMESPACE

class FindRel : public QMainWindow
{
    Q_OBJECT

    public:
        FindRel(QWidget *parent = nullptr);
        ~FindRel();
        int n=0;
        int matrix[100][100];

    public slots:
        QString Find(QVector<QString> relation){
            QString real = "";
            this->creatMatrix(relation);
            if(this->isReflection()){
                if(real.length()!=0){
                    real += " ";
                }
                real += "Reflection";
            }
            if(this->isSymmetric()){
                if(real.length()!=0){
                    real += " ";
                }
                real += "Symmetric";
            }
            if(this->isASymmetric()){
                if(real.length()!=0){
                    real += " ";
                }
                real += "ASymmetric";
            }
            if(this->isTransitive()){
                if(real.length()!=0){
                    real += " ";
                }
                real += "Transitive";
            }
            return real;
        }

        void on_findRel_clicked();

    private:
        void creatMatrix(QVector<QString> relation){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    matrix[i][j] = 0;
                }
            }
            foreach(QString value , relation){
                QStringList list = value.split(",");
                this->matrix[list[0].toInt()-1][list[1].toInt()-1] = 1;
            }
        }
        bool isReflection(){
            for(int i=0 ; i<this->n ; i++){
                for(int j=0 ; j<this->n ; j++){
                    if(i==j && this->matrix[i][j]!=1){
                        return false;
                    }
                }
            }
            return true;
        }
        bool isSymmetric(){
            for(int i=0 ; i<this->n ; i++){
                for(int j=0 ; j<this->n ; j++){
                    if(matrix[i][j]==1){
                        if(matrix[j][i]!=1){
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        bool isASymmetric(){
            for(int i=0 ; i<this->n ; i++){
                for(int j=0 ; j<this->n ; j++){
                    if(matrix[i][j]==1){
                        if(matrix[j][i]==1){
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        bool isTransitive() {
            for (int i = 0; i < this->n; i++) {
                for (int j = 0; j < this->n; j++) {
                    if (matrix[i][j] == 1) {
                        for (int k = 0; k < this->n; k++) {
                            if (matrix[j][k] == 1 && matrix[i][k] != 1) {
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }

        Ui::FindRel *ui;
};
#endif // FINDREL_H
