/**
 ******************************************************************************
 * @file       tbssplashscreen.h
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

#ifndef TBSSPLASHSCREEN_H
#define TBSSPLASHSCREEN_H

#include <QWidget>
#include <QMovie>
#include <QTimer>
#include <QPushButton>
#include "../core_global.h"

namespace Ui {
class TBSSplashScreen;
}

class CORE_EXPORT TBSSplashDialog : public QWidget
{
    Q_OBJECT

public:
    enum Buttons {
        BUTTONS_NO_BUTTONS = 0,
        BUTTONS_OK =        0b00000001,
        BUTTONS_CANCEL =    0b00000010,
        BUTTONS_NEXT =      0b00000100,
        BUTTONS_CUSTOM0 =   0b00001000,
        BUTTONS_CUSTOM1 =   0b00010000
    };
    enum DialogType {
        TYPE_WAIT,
        TYPE_QUESTION,
        TYPE_WARNING,
        TYPE_ERROR
    };

    explicit TBSSplashDialog(QWidget *parent = 0);
    ~TBSSplashDialog();
    void setSplashMovie(QMovie *movie);
    void setImage(QPixmap *image);
    void setText(QString text, bool waiting);
    void setup(DialogType type, int button, QString text, bool waitingText, Buttons autoCountDown, int buttonStartTime = 0);
    void setup(QMovie *movie, int button, QString text, bool waitingText,Buttons autoCountDown, int buttonStartTime = 0);
    void setup(QPixmap *image, int button, QString text, bool waitingText, Buttons autoCountDown, int buttonStartTime = 0);
    void setCustomButton0Text(QString text);
    void setCustomButton1Text(QString text);
private:
    Ui::TBSSplashScreen *ui;
    QString tempText;
    QString tempButtonText;
    int waitTextCount;
    QTimer waitTextTimer;
    QTimer buttonTimer;
    void setButtons(int button, Buttons buttonAutoClick, int buttonCountDown);
    int m_buttonCountDown;
    QPushButton *currentTimedButton;
    int currentButtons;
private slots:
    void onWaitTextTimerTimeout();
    void onButtonClicked();
    void onButtonTimerTimeout();
signals:
    void okClicked();
    void cancelClicked();
    void nextClicked();
    void custom0Clicked();
    void custom1Clicked();
};

#endif // TBSSPLASHSCREEN_H