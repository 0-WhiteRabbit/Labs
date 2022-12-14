#include <QApplication>
#include <QInputDialog>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    bool ok1=true, ok2=true;
    int n = 4;/*QInputDialog::getInt(nullptr, "Input", "N:", 5, 3, 20, 1, &ok1);*/
    int m = 5;/*QInputDialog::getInt(nullptr, "Input", "M:", 5, 3, 20, 1, &ok2);*/

    if (!(ok1 && ok2)) {
        return 0;
    }
    MainWindow window(n, m);
    window.show();
    return app.exec();
}