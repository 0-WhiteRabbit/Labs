#include "DrowArea.h"
#include "fields/Road.h"
#include "fields/Land.h"
#include "other/Castle.h"
#include "other/Lair.h"
#include "tower/SimpleTower.h"
#include "tower/MagicTower.h"
#include "tower/MagicTrap.h"
#include "other/Enemy.h"

#include <QMouseEvent>
#include <QPainter>
#include <QInputDialog>
#include <QMessageBox>


DrawArea::DrawArea(Landscape *_landscape, QWidget *parent)
        : QWidget(parent), n(_landscape->n), m(_landscape->m), landscape(_landscape) {
    setAttribute(Qt::WA_StaticContents);
}

void DrawArea::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        choose_x = (event->x() + dx)/da;
        choose_y = (event->y() + dy)/da;

        if (choose_x < 0 || choose_x >= n || choose_y < 0 || choose_y >= m) {
            choose_y = -1;
            choose_x = -1;
        } else
            update();
    }
}

void DrawArea::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            switch (landscape->fields[i][j]->type()) {
                case 1:
                    draw_Road(i, j, painter);
                    break;
                case 2:
                    draw_Land(i, j, painter);
                    break;
                case 3:
                    draw_Forest(i, j, painter);
                    break;
                default:
                    break;
            }
        }
    }

    for (int i=0; i<landscape->objects.size(); ++i) {
        switch (landscape->objects[i]->type()) {
            case 1:
                draw_Castle(landscape->objects[i]->x, landscape->objects[i]->y, painter);
                break;
            case 2:
                draw_Enemy(landscape->objects[i]->x, landscape->objects[i]->y, painter, landscape->objects[i]->get_hill());
                break;
            case 3:
                draw_Lair(landscape->objects[i]->x, landscape->objects[i]->y, painter);
                break;
            case 11:
                draw_SimpleTower(landscape->objects[i]->x, landscape->objects[i]->y, painter);
                break;
            case 12:
                draw_MagicTrap(landscape->objects[i]->x, landscape->objects[i]->y, painter);
                break;
            case 13:
                draw_MagicTower(landscape->objects[i]->x, landscape->objects[i]->y, painter);
                break;
            default:
                break;
        }
    }

    draw_help_message(painter);

    if (choose_x != -1 && choose_y != -1) {
        painter.setPen(QPen(Qt::green, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(dx + choose_x*da, dy + choose_y*da, da, da);
    }
}

void DrawArea::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
}

void DrawArea::PressEvent(QKeyEvent *event) {
    Field *tmp = nullptr;
    Tower *tmp1 = nullptr;
    Enemy *tmp2 = nullptr;
    Object *tmp3 = nullptr;
    try {
        if (event->key() == Qt::Key_Up && choose_y != -1 && choose_y != 0) {
            --choose_y;
        } else if (event->key() == Qt::Key_Down && choose_y != -1 && choose_y != m - 1) {
            ++choose_y;
        } else if (event->key() == Qt::Key_Right && choose_x != -1 && choose_x != n - 1) {
            ++choose_x;
        } else if (event->key() == Qt::Key_Left && choose_x != -1 && choose_x != 0) {
            --choose_x;
        } else if (event->key() == Qt::Key_1) {
            if (phase == 0) {
                tmp = new Road();
                landscape->set_field(choose_x, choose_y, tmp);
            } else if (phase != 0) {
                tmp1 = new SimpleTower();
                if (landscape->gold < tmp1->get_specification().cost) {
                    throw std::invalid_argument("You should have more gold!");
                }
                landscape->gold -= tmp1->get_specification().cost;
                tmp1->x = choose_x;
                tmp1->y = choose_y;
                landscape->build(tmp1);
            }
        } else if (event->key() == Qt::Key_2) {
            if (phase == 0) {
                tmp = new Land();
                landscape->set_field(choose_x, choose_y, tmp);
            }  else if (phase != 0) {
                bool ok, ok1, ok2;
                int slowdown = QInputDialog::getInt(this, "Input", "Slowdown", 0, 0, 100, 1, &ok);
                int poisoning = QInputDialog::getInt(this, "Input", "Poisoning:", 0, 0, 100, 1, &ok1);
                int weakening = QInputDialog::getInt(this, "Input", "Weakening:", 0, 0, 100, 1, &ok2);
                if (ok && ok1 && ok2) {
                    tmp1 = new MagicTower({slowdown, poisoning, weakening});
                    if (landscape->gold < tmp1->get_specification().cost) {
                        throw std::invalid_argument("You should have more gold!");
                    }
                    landscape->gold -= tmp1->get_specification().cost;
                    tmp1->x = choose_x;
                    tmp1->y = choose_y;
                    landscape->build(tmp1);
                }
            }
        } else if (event->key() == Qt::Key_3) {
            if (phase == 0) {
                tmp = new Forest();
                landscape->set_field(choose_x, choose_y, tmp);
            }  else if (phase != 0) {
                bool ok, ok1, ok2;
                int slowdown = QInputDialog::getInt(this, "Input", "Slowdown", 0, 0, 100, 1, &ok);
                int poisoning = QInputDialog::getInt(this, "Input", "Poisoning:", 0, 0, 100, 1, &ok1);
                int weakening = QInputDialog::getInt(this, "Input", "Weakening:", 0, 0, 100, 1, &ok2);
                if (ok && ok1 && ok2) {
                    tmp1 = new MagicTrap({slowdown, poisoning, weakening});
                    if (landscape->gold < tmp1->get_specification().cost) {
                        throw std::invalid_argument("You should have more gold!");
                    }
                    landscape->gold -= tmp1->get_specification().cost;
                    tmp1->x = choose_x;
                    tmp1->y = choose_y;
                    landscape->build(tmp1);
                }
            }
        } else if (event->key() == Qt::Key_5 && phase == 0) {
            bool ok2;
            int stab = QInputDialog::getInt(this, "Input", "Max stability:", 10, 1, 100, 1, &ok2);
            if (ok2) {
                tmp3 = new Castle(stab);
                tmp3->x = choose_x;
                tmp3->y = choose_y;
                landscape->build(tmp3);
            }
        } else if (event->key() == Qt::Key_6 && phase == 0) {
            tmp3 = new Lair();
            tmp3->x = choose_x;
            tmp3->y = choose_y;
            landscape->build(tmp3);
        } else if ((event->key() == Qt::Key_Enter) || (event->key() == Qt::Key_Return)) {
            int k=-1;
            for (int i=0; i<landscape->objects.size(); ++i) {
                if (landscape->objects[i]->type() == 3 && landscape->objects[i]->x == choose_x && landscape->objects[i]->y == choose_y) {
                    k = i;
                    break;
                }
            }
            if (k == -1) {
                throw std::invalid_argument("Wrong place!");
            }
            bool ok, ok1, ok2;
            int gold = QInputDialog::getInt(this, "Input", "Max gold:", 10, 1, 100, 1, &ok);
            int time = QInputDialog::getInt(this, "Input", "Spawn time:", 10, 1, 100, 1, &ok1);
            int hill = QInputDialog::getInt(this, "Input", "Hill:", 10, 1, 100, 1, &ok2);
            if (ok && ok1 && ok2) {
                tmp2 = new Enemy(gold, time, hill);
                landscape->objects[k]->add_enemy(tmp2);
            }
        }
    }
    catch (const std::invalid_argument &e) {
        QMessageBox msgBox(this);
        msgBox.setText(e.what());
        msgBox.exec();
        delete tmp1;
        delete tmp;
        delete tmp2;
        delete tmp3;
    }
    update();
    QWidget::keyPressEvent(event);
}

void DrawArea::draw_help_message(QPainter &painter) {
    QString all = "Press to cell fo choose.\n"
                  "Use Arrow for move choose.\n";
    QString phase_0 = "Press Space for go to new phase.\n"
                      "Select cell and press 1 for set road.\n"
                      "Select cell and press 2 for set land.\n"
                      "Select cell and press 3 for set forest.\n"
                      "Select cell and press 5 for build castle.\n"
                      "Select cell and press 6 for build lair.\n"
                      "Press A for add enemy to selected lair.\n";
    QString phase_1 = "Space for pause.\n"
                      "Select cell and press 1 for set simple tower.\n"
                      "Select cell and press 2 for set magic tower.\n"
                      "Select cell and press 3 for set magic trap.\n"
                      "You have " + QString::number(landscape->gold) + " gold!";
    QRectF react(dx, dy + da * m + 30, 500, 500);
    if (phase == 0) {
        painter.drawText(react, 1,all + phase_0);
    } else if (phase != 0) {
        painter.drawText(react, 1,all + phase_1);
    }
}

void DrawArea::draw_Castle(int x, int y, QPainter &painter) {
    QImage castle;
    castle.load("../img/castle.png");
    painter.drawImage(dx + x*da+5, dy + y*da+10, castle.scaled(da-10, da-20));
}

void DrawArea::draw_Lair(int x, int y, QPainter &painter) {
    QImage lair;
    lair.load("../img/lair.png");
    painter.drawImage(dx + x*da, dy + y*da, lair.scaled(da, da));
}

void DrawArea::draw_Enemy(int x, int y, QPainter &painter, int hill) {
    QImage lair;
    lair.load("../img/enemy.png");
    painter.drawImage(dx + x*da+5, dy + y*da+5, lair.scaled(da-10, da-10));
    painter.drawText(dx + x*da+5, dy+y*da+15, QString::number(hill));
}

void DrawArea::draw_Forest(int x, int y, QPainter &painter) {
    painter.setBrush(QColor(34, 139, 34));
    painter.drawRect(dx + x*da, dy + y*da, da, da);
}

void DrawArea::draw_Land(int x, int y, QPainter &painter) {
    painter.setBrush(QColor(255, 215, 0));
    painter.drawRect(dx + x*da, dy + y*da, da, da);
}

void DrawArea::draw_Road(int x, int y, QPainter &painter) {
    painter.setBrush(QColor(255, 222, 173));
    painter.drawRect(dx + x*da, dy + y*da, da, da);
}

void DrawArea::draw_SimpleTower(int x, int y, QPainter &painter) {
    painter.setBrush(QColor(128, 0, 0));
    painter.drawEllipse(dx + x*da+10, dy + y*da+10, da-20, da-20);
}

void DrawArea::draw_MagicTrap(int x, int y, QPainter &painter) {
    painter.setBrush(QColor(0, 128, 128));
    painter.drawEllipse(dx + x*da+10, dy + y*da+10, da-20, da-20);
}

void DrawArea::draw_MagicTower(int x, int y, QPainter &painter) {
    painter.setBrush(QColor(75, 0, 130));
    painter.drawEllipse(dx + x*da+10, dy + y*da+10, da-20, da-20);
}

