TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    src/surfaces/Triangle.cpp \
    src/engines/SimpleRayTracer.cpp \
    src/engines/Controller.cpp \
    src/utils/Settings.cpp \
    src/scientific/SpectralIntensity.cpp \
    src/surfaces/World.cpp \
    src/utils/Helper.cpp

HEADERS += \
    include/surfaces/GenericSurface.h \
    include/surfaces/Triangle.h \
    include/surfaces/stdafx.h \
    include/stdafx.h \
    include/cameras/Camera.h \
    include/engines/SimpleRayTracer.h \
    include/surfaces/World.h \
    include/utils/Settings.h \
    include/engines/Controller.h \
    include/scientific/SpectralIntensity.h \
    include/utils/Helper.h \
    include/scientific/BDF.h

INCLUDEPATH+= /usr/include/eigen3


INCLUDEPATH+=$$PWD/include
INCLUDEPATH+=$$PWD/include/cameras
INCLUDEPATH+=$$PWD/include/engines
INCLUDEPATH+=$$PWD/include/scientific
INCLUDEPATH+=$$PWD/include/surfaces
INCLUDEPATH+=$$PWD/include/utils




