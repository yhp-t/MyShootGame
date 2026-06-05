#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        setFixedSize(450, 800);

        QLabel *titleLabel = new QLabel("MY SHOOTING GAME", this);
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setFont(QFont("Arial", 24, QFont::Bold));
        titleLabel->setStyleSheet("color: white;");

        QPushButton *startButton = new QPushButton("Start Game", this);
        QPushButton *quitButton = new QPushButton("Quit", this);

        startButton->setFixedHeight(50);
        quitButton->setFixedHeight(50);

        startButton->setFont(QFont("Arial", 16, QFont::Bold));
        quitButton->setFont(QFont("Arial", 16, QFont::Bold));

        QString buttonStyle =
            "QPushButton {"
            "background-color: #f0c040;"
            "border-radius: 10px;"
            "color: #202020;"
            "}"
            "QPushButton:hover {"
            "background-color: #ffd966;"
            "}";

        startButton->setStyleSheet(buttonStyle);
        quitButton->setStyleSheet(buttonStyle);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addStretch();
        layout->addWidget(titleLabel);
        layout->addSpacing(60);
        layout->addWidget(startButton);
        layout->addSpacing(20);
        layout->addWidget(quitButton);
        layout->addStretch();

        layout->setContentsMargins(70, 0, 70, 0);

        setStyleSheet("background-color: #20232a;");

        connect(startButton, &QPushButton::clicked, this, &MenuWidget::startClicked);
        connect(quitButton, &QPushButton::clicked, this, &MenuWidget::quitClicked);
    }

signals:
    void startClicked();
    void quitClicked();
};
