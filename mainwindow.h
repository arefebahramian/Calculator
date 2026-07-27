#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>   // برای ذخیره تاریخچه
#include <QString>   // برای المان‌های تاریخچه
#include <QMessageBox> // برای نمایش تاریخچه در یک پیام

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT // ماکرو لازم برای استفاده از سیگنال‌ها و اسلات‌ها

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // اسلات‌ها برای دکمه‌های عملگر
    void on_S_clicked();       // دکمه جمع
    void on_M_clicked();       // دکمه ضرب
    void on_T_clicked();       // دکمه تفریق (T برای "تفریق")
    void on_D_clicked();       // دکمه تقسیم

    void on_E_clicked();       // دکمه مساوی/نتیجه
    void on_History_clicked(); // دکمه نمایش تاریخچه

private:
    Ui::MainWindow *ui;
    QVector<QString> history;     // ذخیره تاریخچه عملیات
    char currentOperator;         // عملگر انتخاب شده را ذخیره می‌کند: '+', '-', '*', '/'
};
#endif // MAINWINDOW_H
