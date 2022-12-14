#ifndef LAB_4_MAINWINDOW_H
#define LAB_4_MAINWINDOW_H

#include <QApplication>
#include <QTextEdit>
#include <QPainter>
#include <QAction>
#include <QMainWindow>

#include <QList>
#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include "Landscape.h"

class DrawArea;


class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(int n, int m, QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void slotTimerAlarm();
    void about();

protected:
    void keyPressEvent(QKeyEvent * event) override;

private:
    Landscape landscape;
    DrawArea *drawArea;
    QTimer *timer;
    QLabel *statusLabel;

    QMenu *helpMenu;
    QAction *aboutAct;
};

#endif //LAB_4_MAINWINDOW_H
