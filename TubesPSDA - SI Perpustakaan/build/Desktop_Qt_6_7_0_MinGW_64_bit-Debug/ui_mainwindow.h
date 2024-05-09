/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *btnAdmin;
    QPushButton *btnGuest;
    QLabel *label;
    QLabel *label_2;
    QWidget *page_2;
    QLineEdit *lineJudul;
    QPushButton *btnTambah;
    QTableView *tableView;
    QLabel *labelJudul;
    QLineEdit *linePenulis;
    QLabel *labelPenulis;
    QLabel *labelPenerbit;
    QLineEdit *linePenerbit;
    QDateEdit *editTanggalTerbit;
    QLabel *labelTanggalTerbit;
    QPushButton *btnHapus;
    QPushButton *btnEdit;
    QPushButton *btnSearch;
    QPushButton *btnBack;
    QLineEdit *lineSearchAdmin;
    QPushButton *btnSearchGuest;
    QLineEdit *lineSearchGuest;
    QWidget *page_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1024, 768);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1024, 768));
        page = new QWidget();
        page->setObjectName("page");
        btnAdmin = new QPushButton(page);
        btnAdmin->setObjectName("btnAdmin");
        btnAdmin->setGeometry(QRect(430, 400, 171, 29));
        btnGuest = new QPushButton(page);
        btnGuest->setObjectName("btnGuest");
        btnGuest->setGeometry(QRect(430, 450, 171, 29));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(430, 240, 209, 40));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(480, 360, 96, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        lineJudul = new QLineEdit(page_2);
        lineJudul->setObjectName("lineJudul");
        lineJudul->setGeometry(QRect(180, 110, 231, 28));
        btnTambah = new QPushButton(page_2);
        btnTambah->setObjectName("btnTambah");
        btnTambah->setGeometry(QRect(80, 280, 83, 29));
        tableView = new QTableView(page_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(430, 110, 421, 571));
        labelJudul = new QLabel(page_2);
        labelJudul->setObjectName("labelJudul");
        labelJudul->setGeometry(QRect(110, 110, 50, 27));
        linePenulis = new QLineEdit(page_2);
        linePenulis->setObjectName("linePenulis");
        linePenulis->setGeometry(QRect(180, 150, 231, 28));
        labelPenulis = new QLabel(page_2);
        labelPenulis->setObjectName("labelPenulis");
        labelPenulis->setGeometry(QRect(100, 150, 64, 27));
        labelPenerbit = new QLabel(page_2);
        labelPenerbit->setObjectName("labelPenerbit");
        labelPenerbit->setGeometry(QRect(90, 190, 81, 27));
        linePenerbit = new QLineEdit(page_2);
        linePenerbit->setObjectName("linePenerbit");
        linePenerbit->setGeometry(QRect(180, 190, 231, 28));
        editTanggalTerbit = new QDateEdit(page_2);
        editTanggalTerbit->setObjectName("editTanggalTerbit");
        editTanggalTerbit->setGeometry(QRect(180, 230, 231, 29));
        labelTanggalTerbit = new QLabel(page_2);
        labelTanggalTerbit->setObjectName("labelTanggalTerbit");
        labelTanggalTerbit->setGeometry(QRect(50, 230, 126, 27));
        btnHapus = new QPushButton(page_2);
        btnHapus->setObjectName("btnHapus");
        btnHapus->setGeometry(QRect(200, 280, 83, 29));
        btnEdit = new QPushButton(page_2);
        btnEdit->setObjectName("btnEdit");
        btnEdit->setGeometry(QRect(320, 280, 83, 29));
        btnSearch = new QPushButton(page_2);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(80, 370, 83, 29));
        btnBack = new QPushButton(page_2);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(10, 10, 101, 29));
        lineSearchAdmin = new QLineEdit(page_2);
        lineSearchAdmin->setObjectName("lineSearchAdmin");
        lineSearchAdmin->setGeometry(QRect(180, 370, 231, 28));
        btnSearchGuest = new QPushButton(page_2);
        btnSearchGuest->setObjectName("btnSearchGuest");
        btnSearchGuest->setGeometry(QRect(80, 110, 83, 29));
        lineSearchGuest = new QLineEdit(page_2);
        lineSearchGuest->setObjectName("lineSearchGuest");
        lineSearchGuest->setGeometry(QRect(180, 110, 231, 28));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnAdmin->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        btnGuest->setText(QCoreApplication::translate("MainWindow", "Guest", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt;\">SI Perpustakaan</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Login sebagai:", nullptr));
        btnTambah->setText(QCoreApplication::translate("MainWindow", "Tambah", nullptr));
        labelJudul->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Judul:</span></p></body></html>", nullptr));
        labelPenulis->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Penulis:</span></p></body></html>", nullptr));
        labelPenerbit->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Penerbit:</span></p></body></html>", nullptr));
        labelTanggalTerbit->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Tanggal Terbit:</span></p></body></html>", nullptr));
        btnHapus->setText(QCoreApplication::translate("MainWindow", "Hapus", nullptr));
        btnEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        btnSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        btnBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        btnSearchGuest->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
