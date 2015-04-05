TEMPLATE = lib
TARGET = Core
DEFINES += CORE_LIBRARY

QT += widgets
QT += xml \
    network \
    script \
    svg \
    sql
include(../../taulabsgcsplugin.pri)
include(../../libs/utils/utils.pri)
include(../../shared/scriptwrapper/scriptwrapper.pri)
include(coreplugin_dependencies.pri)
INCLUDEPATH *= dialogs \
    uavgadgetmanager \
    actionmanager
DEPENDPATH += dialogs \
    uavgadgetmanager \
    actionmanager
SOURCES += mainwindow.cpp \
    tabpositionindicator.cpp \
    uniqueidmanager.cpp \
    messagemanager.cpp \
    messageoutputwindow.cpp \
    versiondialog.cpp \
    iuavgadget.cpp \
    basemode.cpp \
    baseview.cpp \
    coreplugin.cpp \
    variablemanager.cpp \
    threadmanager.cpp \
    coreimpl.cpp \
    plugindialog.cpp \
    manhattanstyle.cpp \
    minisplitter.cpp \
    styleanimator.cpp \
    mimedatabase.cpp \
    icore.cpp \
    settingsdatabase.cpp \
    eventfilteringmainwindow.cpp \
    iconnection.cpp \
    iuavgadgetconfiguration.cpp \
    uavgadgetdecorator.cpp \
    uavconfiginfo.cpp \
    authorsdialog.cpp \
    telemetrymonitorwidget.cpp \
    boardmanager.cpp \
    iboardtype.cpp \
    idevice.cpp \
    globalmessaging.cpp \
    alarmsmonitorwidget.cpp \
    connectionmanager.cpp
HEADERS += mainwindow.h \
    tabpositionindicator.h \
    uniqueidmanager.h \
    messagemanager.h \
    messageoutputwindow.h \
    iuavgadget.h \
    iuavgadgetfactory.h \
    icontext.h \
    icore.h \
    imode.h \
    ioutputpane.h \
    coreconstants.h \
    iversioncontrol.h \
    iview.h \
    icorelistener.h \
    versiondialog.h \
    core_global.h \
    basemode.h \
    baseview.h \
    coreplugin.h \
    variablemanager.h \
    threadmanager.h \
    coreimpl.h \
    plugindialog.h \
    manhattanstyle.h \
    minisplitter.h \
    styleanimator.h \
    mimedatabase.h \
    settingsdatabase.h \
    eventfilteringmainwindow.h \
    iconnection.h \
    iuavgadgetconfiguration.h \
    uavgadgetdecorator.h \
    uavconfiginfo.h \
    authorsdialog.h \
    iconfigurableplugin.h \
    telemetrymonitorwidget.h \
    boardmanager.h \
    iboardtype.h \
    idevice.h \
    globalmessaging.h \
    alarmsmonitorwidget.h \
    connectionmanager.h \
    generalsettings.h
FORMS += generalsettings.ui \
    uavgadgetoptionspage.ui \
    workspacesettings.ui
RESOURCES += core.qrc
unix:!macx { 
    images.files = images/taulabs_logo_*.png
    images.files = images/qtcreator_logo_*.png
    images.path = /share/pixmaps
    INSTALLS += images
}
OTHER_FILES += Core.pluginspec \
    coreplugin.json

HEADERS += slimgcs/windowbutton.h \
    slimgcs/windowtitlebar.h \
    slimgcs/mainwidget.h \
    slimgcs/tbssplashdialog.h
SOURCES += slimgcs/windowbutton.cpp \
    slimgcs/windowtitlebar.cpp \
    slimgcs/mainwidget.cpp \
    slimgcs/tbssplashdialog.cpp
FORMS += \
    slimgcs/mainwidget.ui \
    slimgcs/tbssplashdialog.ui
RESOURCES += \
    slimgcs/resource.qrc

include(gcsversioninfo.pri)
