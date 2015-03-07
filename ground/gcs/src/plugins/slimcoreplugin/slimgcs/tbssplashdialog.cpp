/**
 ******************************************************************************
 * @file       tbssplashscreen.cpp
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2014
 * @addtogroup [Group]
 * @{
 * @addtogroup TBSSplashScreen
 * @{
 * @brief [Brief]
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "tbssplashdialog.h"
#include "ui_tbssplashdialog.h"
#include <QDesktopWidget>

TBSSplashDialog::TBSSplashDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TBSSplashScreen)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(QApplication::desktop()->availableGeometry().center() - this->rect().center());
    connect(&waitTextTimer, SIGNAL(timeout()), this, SLOT(onWaitTextTimerTimeout()));
    connect(&buttonTimer, SIGNAL(timeout()), this, SLOT(onButtonTimerTimeout()));
    connect(ui->button0, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->button1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->button2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
}

TBSSplashDialog::~TBSSplashDialog()
{
    delete ui;
}

void TBSSplashDialog::setSplashMovie(QMovie *movie)
{
    movie->setScaledSize(QSize(80, 80));
    ui->image->setMovie(movie);
    movie->start();
}

void TBSSplashDialog::setImage(QPixmap *image)
{
    ui->image->setPixmap(*image);
}

void TBSSplashDialog::setText(QString text, bool waiting)
{
    waitTextCount = 0;
    waitTextTimer.stop();
    tempText = text;
    ui->text->setText(text);
    if(waiting)
    {
        waitTextTimer.start(500);
    }
}

void TBSSplashDialog::setup(TBSSplashDialog::DialogType type, int button, QString text, bool waitingText, TBSSplashDialog::Buttons autoCountDown, int buttonStartTime)
{
    QMovie *movie;
    switch (type) {
    case TYPE_ERROR:
        movie = new QMovie(":/dialog/resources/warning.gif");
        break;
    case TYPE_QUESTION:
        movie = new QMovie(":/dialog/resources/question1.gif");
        break;
    case TYPE_WAIT:
        movie = new QMovie(":/dialog/resources/477.GIF");
        break;
    case TYPE_WARNING:
        movie = new QMovie(":/dialog/resources/triangle-spin.gif");

        break;
    default:
        break;
    }
    setup(movie, button, text, waitingText, autoCountDown, buttonStartTime);
}

void TBSSplashDialog::setup(QMovie *movie, int button, QString text, bool waitingText, TBSSplashDialog::Buttons autoCountDown, int buttonStartTime)
{
    setSplashMovie(movie);
    setButtons(button, autoCountDown, buttonStartTime);
    setText(text, waitingText);
}

void TBSSplashDialog::setup(QPixmap *image, int button, QString text, bool waitingText, TBSSplashDialog::Buttons autoCountDown, int buttonStartTime)
{
    setImage(image);
    setButtons(button, autoCountDown, buttonStartTime);
    setText(text, waitingText);
}

void TBSSplashDialog::setCustomButton0Text(QString text)
{
    ui->button0->setText(text);
}

void TBSSplashDialog::setCustomButton1Text(QString text)
{
    ui->button1->setText(text);
}

void TBSSplashDialog::setButtons(int button, Buttons buttonAutoClick, int buttonCountDown)
{
    currentButtons = button;
    ui->button0->setVisible(false);
    ui->button1->setVisible(false);
    ui->button2->setVisible(false);
    if(button & BUTTONS_NO_BUTTONS)
    {}
    if(button & BUTTONS_OK) {
        ui->button0->setVisible(true);
        ui->button0->setText("Ok");
    }
    if(button & BUTTONS_CANCEL) {
        ui->button1->setVisible(true);
        ui->button1->setText("Cancel");
    }
    if(button & BUTTONS_NEXT) {
        ui->button2->setVisible(true);
        ui->button2->setText("Next");
    }
    if(button & BUTTONS_CUSTOM0) {
        ui->button0->setVisible(true);
        ui->button0->setText("");
    }
    if(button & BUTTONS_CUSTOM1) {
        ui->button1->setVisible(true);
        ui->button1->setText("");
    }
    buttonTimer.stop();
    if(button & BUTTONS_NO_BUTTONS)
    {}
    buttonTimer.stop();
    if(buttonAutoClick & BUTTONS_OK) {
        currentTimedButton = ui->button0;
        m_buttonCountDown = buttonCountDown;
        tempButtonText = currentTimedButton->text();
        onButtonTimerTimeout();
        buttonTimer.start(1000);
    }
    if(buttonAutoClick & BUTTONS_CANCEL) {
        currentTimedButton = ui->button1;
        m_buttonCountDown = buttonCountDown;
        tempButtonText = currentTimedButton->text();
        onButtonTimerTimeout();
        buttonTimer.start(1000);
    }
    if(buttonAutoClick & BUTTONS_NEXT) {
        currentTimedButton = ui->button2;
        m_buttonCountDown = buttonCountDown;
        tempButtonText = currentTimedButton->text();
        onButtonTimerTimeout();
        buttonTimer.start(1000);
    }
    if(buttonAutoClick & BUTTONS_CUSTOM0) {
        currentTimedButton = ui->button0;
        m_buttonCountDown = buttonCountDown;
        tempButtonText = currentTimedButton->text();
        onButtonTimerTimeout();
        buttonTimer.start(1000);
    }
    if(buttonAutoClick & BUTTONS_CUSTOM1) {
        currentTimedButton = ui->button1;
        m_buttonCountDown = buttonCountDown;
        tempButtonText = currentTimedButton->text();
        onButtonTimerTimeout();
        buttonTimer.start(1000);
    }
}

void TBSSplashDialog::onWaitTextTimerTimeout()
{
    if(waitTextCount == 4)
    {
        waitTextCount = 0;
        ui->text->setText(QString("%0%1").arg(tempText).arg("    "));
    }
    if(waitTextCount == 3)
    {
        waitTextCount = 4;
        ui->text->setText(QString("%0%1").arg(tempText).arg("   ."));
    }
    if(waitTextCount == 2)
    {
        waitTextCount = 3;
        ui->text->setText(QString("%0%1").arg(tempText).arg("  . "));
    }
    if(waitTextCount == 1)
    {
        waitTextCount = 2;
        ui->text->setText(QString("%0%1").arg(tempText).arg(" .  "));
    }
    if(waitTextCount == 0)
    {
        waitTextCount = 1;
        ui->text->setText(QString("%0%1").arg(tempText).arg(".   "));
    }
    waitTextTimer.start(500);
}

void TBSSplashDialog::onButtonClicked()
{
    waitTextTimer.stop();
    buttonTimer.stop();

    QPushButton *button = dynamic_cast<QPushButton*> (sender());
    if(!button)
        return;
    if(button == ui->button0) {
        if(currentButtons & BUTTONS_CUSTOM0)
            emit custom0Clicked();
        else
            emit okClicked();
    }
    else if(button == ui->button1) {
        if(currentButtons & BUTTONS_CUSTOM1)
            emit custom1Clicked();
        else
            emit cancelClicked();
    }
    else if(button == ui->button2) {
             emit nextClicked();
    }
}

void TBSSplashDialog::onButtonTimerTimeout()
{
    currentTimedButton->setText(QString("%0 (%1)").arg(tempButtonText).arg(QString::number(m_buttonCountDown)));
    --m_buttonCountDown;
    if(m_buttonCountDown == -1)
    {
        buttonTimer.stop();
        currentTimedButton->click();
    }
}
