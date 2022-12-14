#include "mainwindow.h"
#include "DrowArea.h"

#include <QColorDialog>
#include <QImageWriter>
#include <QInputDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QTimer>
#include <QStatusBar>

MainWindow::MainWindow(int n, int m, QWidget *parent)
        : QMainWindow(parent), landscape(n, m), drawArea(new DrawArea(&landscape, this)) {
    setCentralWidget(drawArea);

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);

    menuBar()->addMenu(helpMenu);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->setInterval(500);

    statusLabel = new QLabel();

    statusBar()->addPermanentWidget(statusLabel);
    statusLabel->setText("Build phase");


    setWindowTitle(tr("Mega game"));
    resize(100*n + 50, 100*m + 50);
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About game"),
                       tr("<p></p>"));
}

void MainWindow::slotTimerAlarm() {
    if (!landscape.refresh()) {
        QMessageBox msgBox(this);
        msgBox.setText("Game over!");
        msgBox.exec();
        QApplication::closeAllWindows();
    }
    drawArea->update();
}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    if (event->key() == Qt::Key_Space && drawArea->phase != 0) {
        if (timer->isActive()) {
            timer->stop();
            drawArea->phase = 2;
            statusLabel->setText("Stop");
        }
        else {
            timer->start();
            drawArea->phase = 1;
            statusLabel->setText("Start");
        }
    } else if (event->key() == Qt::Key_Space && drawArea->phase == 0) {
        if (!landscape.check_correct()) {
            QMessageBox msgBox(this);
            msgBox.setText("Wrong map!");
            msgBox.exec();
        } else {
            drawArea->phase = 1;
            statusLabel->setText("Start");
            timer->start();
        }
    } else {
        drawArea->PressEvent(event);
    }

    QWidget::keyPressEvent(event);
}

MainWindow::~MainWindow() {
        delete drawArea;
        delete timer;
        delete helpMenu;
        delete aboutAct;
}
