/**
 ******************************************************************************
 *
 * @file       generalsettings.h
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2014
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 *             Parts by Nokia Corporation (qt-info@nokia.com) Copyright (C) 2009.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup CorePlugin Core Plugin
 * @{
 * @brief The Core GCS plugin
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

#ifndef GENERALSETTINGS_H
#define GENERALSETTINGS_H

#include <coreplugin/core_global.h>
#include <QObject>

namespace Core {
namespace Internal {

namespace Ui {
    class GeneralSettings;
}

class CORE_EXPORT GeneralSettings : public QObject
{
    Q_OBJECT

public:
    GeneralSettings();
    bool useUDPMirror(){return false;}
    bool useSessionManaging(){return true;}
    bool useExpertMode(){return true;}

};
} // namespace Internal
} // namespace Core

#endif // GENERALSETTINGS_H
