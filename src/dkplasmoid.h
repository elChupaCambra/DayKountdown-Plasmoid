/*
* SPDX-FileCopyrightText: (C) 2021 Claudio Cambra <claudio.cambra@gmail.com>
* 
* SPDX-LicenseRef: GPL-3.0-or-later
*/

#ifndef DKPLASMOID_H
#define DKPLASMOID_H

#include <Plasma/Applet>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDir>
// Remember to have .h files in here! Otherwise the linker will panic!
#include "kountdownmodel.h"

class DKPlasmoid : public Plasma::Applet
{
    Q_OBJECT
    Q_PROPERTY(KountdownModel* KountdownModel READ readKountdownModel WRITE setKountdownModel NOTIFY kountdownModelChanged CONSTANT)
	Q_PROPERTY(bool dbError READ readDbError CONSTANT)

public:
    DKPlasmoid(QObject *parent, const QVariantList &args);
    ~DKPlasmoid();

	Q_INVOKABLE void updateKountdownModel();
	Q_INVOKABLE void launchFullDK();
	
    KountdownModel* readKountdownModel() const;
	void setKountdownModel(KountdownModel* inKountdownModel);
	bool readDbError();
	
signals:
	void kountdownModelChanged(KountdownModel*);

private:
    KountdownModel* m_KountdownModel;
	bool m_dbError;
};

#endif
