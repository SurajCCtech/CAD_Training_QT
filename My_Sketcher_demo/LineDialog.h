#pragma once

#include <QtWidgets>

class LineDialog : public QDialog {
    Q_OBJECT
public:
    LineDialog(QWidget* parent = nullptr) : QDialog(parent) {
        setWindowTitle("Line Dialog");

        // Create line edits for X and Y coordinates
        start_x_edit = new QLineEdit(this);
        start_y_edit = new QLineEdit(this);
        end_x_edit = new QLineEdit(this);
        end_y_edit = new QLineEdit(this);

        // Create OK and Cancel buttons
        QPushButton* ok_button = new QPushButton("OK", this);
        QPushButton* cancel_button = new QPushButton("Cancel", this);

        // Create layout for the dialog
        QFormLayout* layout = new QFormLayout(this);
        layout->addRow("Start X:", start_x_edit);
        layout->addRow("Start Y:", start_y_edit);
        layout->addRow("End X:", end_x_edit);
        layout->addRow("End Y:", end_y_edit);
        layout->addRow(ok_button, cancel_button);

        // Connect slots to handle button events
        connect(ok_button, &QPushButton::clicked, this, &LineDialog::accept);
        connect(cancel_button, &QPushButton::clicked, this, &LineDialog::reject);
    }

    QLineEdit* start_x_edit;
    QLineEdit* start_y_edit;
    QLineEdit* end_x_edit;
    QLineEdit* end_y_edit;
};

