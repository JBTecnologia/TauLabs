TEMPLATE = lib
TARGET = TauLabs
include(../../taulabsgcsplugin.pri)
include(../../plugins/uavobjects/uavobjects.pri)
include(../../plugins/uavobjectutil/uavobjectutil.pri)
include(../../plugins/uavobjectwidgetutils/uavobjectwidgetutils.pri)

OTHER_FILES += TauLabs.json
SLIM_GCS {
INCLUDEPATH+=../slimcoreplugin
}
!SLIM_GCS {
INCLUDEPATH+=../coreplugin
}
HEADERS += \
    taulabsplugin.h \
    freedom.h \
    sparky.h \
    sparkybgc.h \
    sparkybgcconfiguration.h \
    taulink.h

SOURCES += \
    taulabsplugin.cpp \
    freedom.cpp \
    sparky.cpp \
    sparkybgc.cpp \
    sparkybgcconfiguration.cpp \
    taulink.cpp

RESOURCES += \
    taulabs.qrc

FORMS += \
    sparkybgcconfiguration.ui
