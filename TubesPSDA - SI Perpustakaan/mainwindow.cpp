#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Membuat model untuk tabel
    model = new QStandardItemModel(this);
    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(QStringList() << "Judul" << "Penulis" << "Penerbit" << "Tanggal Terbit");

    //Memasang model yang telah dibuat ke tabel
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Mengubah tanggal menjadi tanggal sekarang
    ui->editTanggalTerbit->setDate(date);
}

MainWindow::~MainWindow()
{
    delete ui;

}

//==========Tombol-tombol==========
void MainWindow::on_btnBack_clicked()
{
    //Mengubah laman yang sedang aktif
    ui->stackedWidget->setCurrentWidget(ui->page);
}

void MainWindow::on_btnAdmin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);

    //Menentukan tombol-tombol yang bisa dilihat admin
    modeAdmin();
}

void MainWindow::on_btnGuest_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);

    //Menentukan tombol-tombol yang bisa dilihat guest
    modeGuest();
}

void MainWindow::on_btnTambah_clicked()
{
        //Mengambil data dari inputan user
        Buku idbuku;
        idbuku.judul = ui->lineJudul->text();
        idbuku.penulis = ui->linePenulis->text();
        idbuku.penerbit = ui->linePenerbit->text();
        idbuku.tanggalTerbit = ui->editTanggalTerbit->date();

        //Menyimpan data struct ke dalam array
        dataBuku[jumlahBuku] = idbuku;

        //Mensortir array of struct data buku
        std::sort(std::begin(dataBuku), std::end(dataBuku));

        //Menambahkan jumlah buku
        jumlahBuku++;

        //Mengupdate tabel dengan informasi yang baru
        update();
}

void MainWindow::on_btnHapus_clicked()
{
    //Menentukan barisan yang dipilih
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (!selectedIndexes.isEmpty()) {

        //Menghapus data yang dipilih
        int index = selectedIndexes.at(0).row();
        if (index >= 0 && index < jumlahBuku) {

            //Menghapus data dari array
            for (int i = index; i < jumlahBuku - 1; ++i) {
                dataBuku[i] = dataBuku[i + 1];
            }

            std::sort(std::begin(dataBuku), std::end(dataBuku));

            //Mengurangi jumlah buku
            jumlahBuku--;

            update();
        }
    }
}

void MainWindow::on_btnEdit_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (!selectedIndexes.isEmpty()) {
        int index = selectedIndexes.at(0).row();

        //Mengambil data dari input user
        QString judul = ui->lineJudul->text();
        QString penulis = ui->linePenulis->text();
        QString penerbit = ui->linePenerbit->text();
        QDate tanggalTerbit = ui->editTanggalTerbit->date();

        //Mengubah data dalam tabel menjadi data yang diinput user
        if (index >= 0 && index < jumlahBuku) {
            Buku idbuku;
            idbuku.judul = judul;
            idbuku.penulis =penulis;
            idbuku.penerbit = penerbit;
            idbuku.tanggalTerbit = tanggalTerbit;
            dataBuku[index] = idbuku;

            std::sort(std::begin(dataBuku), std::end(dataBuku));

            update();
        }
    }
}

void MainWindow::on_btnSearch_clicked()
{
    //Mengambil nama judul yang dicari dari input user
    QString dicari = ui->lineSearchAdmin->text();

    //Meenggunakan binary search untuk menentukan letak index judul yang dicari
    int index = binarySearch(dicari);

    //Memeriksa hasil binary search
    if (index != -1) {
        //Memilih row dengan index yang didapat binary search
        ui->tableView->selectRow(index);
    } else {
        //Tampilan error jika buku yang dicari tidak ditemukan
        QMessageBox::warning(this, "Error", QString("Buku tidak ditemukan."));
    }

    //Mengosongkan line search
    ui->lineSearchAdmin->setText("");
}

void MainWindow::on_btnSearchGuest_clicked()
{
    //Mengambil nama judul yang dicari dari input user
    QString dicari = ui->lineSearchGuest->text();

    //Meenggunakan binary search untuk menentukan letak index judul yang dicari
    int index = binarySearch(dicari);

    //Memeriksa hasil binary search
    if (index != -1) {
        //Memilih row dengan index yang didapat binary search
        ui->tableView->selectRow(index);
    } else {
        //Tampilan error jika buku yang dicari tidak ditemukan
        QMessageBox::warning(this, "Error", QString("Buku tidak ditemukan."));
    }

    //Mengosongkan line search
    ui->lineSearchGuest->setText("");
}

//==========Method-method==========
void MainWindow::modeAdmin(){
    //Menentukan tombol bisa dilihat atau tidak
    ui->btnTambah->setVisible(true);
    ui->btnHapus->setVisible(true);
    ui->btnEdit->setVisible(true);
    ui->btnSearch->setVisible(true);
    ui->btnSearchGuest->setVisible(false);
    ui->editTanggalTerbit->setVisible(true);

    ui->lineJudul->setVisible(true);
    ui->lineSearchGuest->setVisible(false);
    ui->lineSearchAdmin->setVisible(true);
    ui->linePenulis->setVisible(true);
    ui->linePenerbit->setVisible(true);

    ui->labelJudul->setVisible(true);
    ui->labelPenulis->setVisible(true);
    ui->labelPenerbit->setVisible(true);
    ui->labelTanggalTerbit->setVisible(true);
}

void MainWindow::modeGuest(){
    ui->btnTambah->setVisible(false);
    ui->btnHapus->setVisible(false);
    ui->btnEdit->setVisible(false);
    ui->btnSearch->setVisible(false);
    ui->btnSearchGuest->setVisible(true);
    ui->editTanggalTerbit->setVisible(false);

    ui->lineJudul->setVisible(false);
    ui->lineSearchGuest->setVisible(true);
    ui->lineSearchAdmin->setVisible(false);
    ui->linePenulis->setVisible(false);
    ui->linePenerbit->setVisible(false);

    ui->labelJudul->setVisible(false);
    ui->labelPenulis->setVisible(false);
    ui->labelPenerbit->setVisible(false);
    ui->labelTanggalTerbit->setVisible(false);
}

void MainWindow::update()
{
    //Mereset input user agar menjadi kosong
    ui->lineJudul->setText("");
    ui->linePenulis->setText("");
    ui->linePenerbit->setText("");
    ui->editTanggalTerbit->setDate(date);

    //Menghapus isi tabel
    model->clear();

    //Membuat atau mengupdate isi tabel yang terbaru
    model->setHorizontalHeaderLabels(QStringList() << "Judul" << "Penulis" << "Penerbit" << "Tanggal Terbit");
    for (int i = 0; i < jumlahBuku; ++i) {
        QList<QStandardItem *> rowItems;
        rowItems << new QStandardItem(dataBuku[i].judul)
                 << new QStandardItem(dataBuku[i].penulis)
                 << new QStandardItem(dataBuku[i].penerbit)
                 << new QStandardItem(dataBuku[i].tanggalTerbit.toString("MM-dd-yyyy"));
        model->appendRow(rowItems);
    }
}

int MainWindow::binarySearch(const QString& dicari)
{
    //Algoritma binary search
    int awal = 0;
    int akhir = jumlahBuku - 1;
    int tengah;
    bool ketemu = false;
    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (dataBuku[tengah].judul == dicari) {
            ketemu = true;
            break;
        } else if (dataBuku[tengah].judul > dicari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (ketemu) {
        return tengah;
    } else {
        return -1;
    }
}
