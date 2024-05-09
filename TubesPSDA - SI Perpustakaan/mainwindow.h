#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTGui>
#include <QStackedWidget>
#include <QStandardItemModel>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

//Membuat struktur buku
struct Buku {
    QString judul;
    QString penulis;
    QString penerbit;
    QDate tanggalTerbit;

    //Mengecek jika variabel-variabel judul lebih besar atau kecil untuk di sort nanti
    bool operator<(const Buku &a) const{
        return judul.compare(a.judul) > 0;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdmin_clicked();
    void on_btnGuest_clicked();
    void on_btnTambah_clicked();
    void on_btnHapus_clicked();
    void on_btnEdit_clicked();
    void on_btnSearch_clicked();
    void on_btnBack_clicked();
    void on_btnSearchGuest_clicked();

//Variabel dan method apa saja yang akan digunakan pada mainwindow.cpp
private:
    QDate date = QDate::currentDate();
    Ui::MainWindow *ui;
    Buku dataBuku[999]; //Array untuk menyimpan struct buku
    int jumlahBuku = 0; //Integer untuk digunakan saat binary search
    QStandardItemModel *model;
    void update();
    void modeGuest();
    void modeAdmin();
    int binarySearch(const QString& dicari);
};
#endif // MAINWINDOW_H
