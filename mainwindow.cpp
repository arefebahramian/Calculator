#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentOperator = '\0';
    ui->Result->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_S_clicked()
{
    // جمع
    currentOperator = '+';
}

void MainWindow::on_M_clicked()
{
    // تفریق
    currentOperator = '-';
}

void MainWindow::on_T_clicked()
{
    //ضرب
    currentOperator = '*';
}

void MainWindow::on_D_clicked()
{
    // تقسیم
    currentOperator = '/';
}

void MainWindow::on_E_clicked()
{
    bool isNum1Valid, isNum2Valid;
    double num1 = ui->Num1In->text().toDouble(&isNum1Valid);
    double num2 = ui->Num2In->text().toDouble(&isNum2Valid);


    if (!isNum1Valid || !isNum2Valid)
    {
        ui->Result->setText("مجدد تلاش کنید! ورودی نامعتبر است");
        history.append("خطای ورودی نامعتبر");
        return;
    }

    if (currentOperator == '\0')
    {
        ui->Result->setText("مجدد تلاش کنید! عملگر انتخاب نشده");
        history.append("خطای انتخاب نکردن عملگر");
        return;
    }

    if (currentOperator == '/' && num2 == 0.0)
    {
        ui->Result->setText("مجدد تلاش کنید! تقسیم بر 0 ممکن نیست");
        history.append(QString("خطای تقسیم بر صفر"));
        return;
    }

    double result = 0.0;

    switch (currentOperator)
    {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = num1 / num2; break;
    }

    ui->Result->setText(QString::number(result));

    QString operationString = QString("%1 %2 %3 = %4")
                                .arg(num1)
                                .arg(currentOperator)
                                .arg(num2)
                                .arg(result);

    history.append(operationString);
}

void MainWindow::on_History_clicked()
{
    if (history.isEmpty())
    {
        QMessageBox::information(this, "تاریخچه", "تاریخچه خالی است ");
        return;
    }

    QString historyText;
    for (const QString &item : qAsConst(history))
    {
        historyText.append(item + "\n");
    }

    QMessageBox::information(this, "تاریخچه عملیات", historyText);
}
