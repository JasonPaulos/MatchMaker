/* Copyright (c) 2015 Jason Paulos
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef DBVALIDATEWIDGET_H
#define DBVALIDATEWIDGET_H

#include <QScopedPointer>
#include "StepWidget.h"

namespace Ui{
    class DbValidateWidget;
}

/* This widget is the 3rd step in selecting a database. Here, a connection is
 * made to the database that the user filled in information for in the previous
 * step and the user is prompted to select a table from the database.
 */
class DbValidateWidget : public StepWidget{
    Q_OBJECT

public:
    explicit DbValidateWidget(DatabaseDialog *parent);
    ~DbValidateWidget();

    virtual void saveData();
    void finishedQuery(bool success);

public slots:
    void slotShowError(QString error);
    void slotFillTables(QStringList tables);

signals:
    void signalShowError(QString error);
    void signalFillTables(QStringList tables);

private:
    QScopedPointer<Ui::DbValidateWidget> ui;
};

#endif // DBVALIDATEWIDGET_H
