/**************************************************************************
 *  This file is part of QXmlEdit                                         *
 *  Copyright (C) 2011-2018 by Luca Bellonda and individual contributors  *
 *    as indicated in the AUTHORS file                                    *
 *  lbellonda _at_ gmail.com                                              *
 *                                                                        *
 * This library is free software; you can redistribute it and/or          *
 * modify it under the terms of the GNU Library General Public            *
 * License as published by the Free Software Foundation; either           *
 * version 2 of the License, or (at your option) any later version.       *
 *                                                                        *
 * This library is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 * Library General Public License for more details.                       *
 *                                                                        *
 * You should have received a copy of the GNU Library General Public      *
 * License along with this library; if not, write to the                  *
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,       *
 * Boston, MA  02110-1301  USA                                            *
 **************************************************************************/
#include "xsdchoiceeditor.h"
#include "ui_xsdchoiceeditor.h"

XsdChoiceEditor::XsdChoiceEditor(QWidget *parent) :
    QWidget(parent),
    _target(NULL),
    ui(new Ui::XsdChoiceEditor)
{
    ui->setupUi(this);
}

XsdChoiceEditor::~XsdChoiceEditor()
{
    delete ui;
}

void XsdChoiceEditor::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch(e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void XsdChoiceEditor::setTarget(XSchemaObject *newGenericTarget)
{
    XSchemaChoice *newTarget = qobject_cast<XSchemaChoice *>(newGenericTarget);
    if(newTarget != _target) {
        if(_target != NULL) {
            //disconnect( _target, SIGNAL(propertyChanged(const QString &)), this, SLOT(onTargetPropertyChanged(const QString &)) );
        }
        _target = newTarget ;
        if(_target != NULL) {
            //connect( _target, SIGNAL(propertyChanged(const QString &)), this, SLOT(onTargetPropertyChanged(const QString &)) );
            //applyPropertyChanged( "", true );
        }
    }
}

XSchemaObject *XsdChoiceEditor::target()
{
    return _target ;
}
