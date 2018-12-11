TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH+=$$PWD/include
INCLUDEPATH+=$$PWD/include/cameras
INCLUDEPATH+=$$PWD/include/engines
INCLUDEPATH+=$$PWD/include/scientific
INCLUDEPATH+=$$PWD/include/surfaces
INCLUDEPATH+=$$PWD/include/rayTracing
INCLUDEPATH+=$$PWD/include/utils
INCLUDEPATH+=$$PWD/include/testing


HEADERS += \
    include/cameras/Camera.h \
    include/engines/Controller.h \
    include/engines/RayTracingHandler.h \
    include/rayTracing/RayTracer.h \
    include/scientific/BRDF.h \
    include/surfaces/GenericSurface.h \
    include/surfaces/Triangle.h \
    include/surfaces/World.h \
    include/testing/Testing.h \
    include/utils/Helper.h \
    include/utils/Settings.h \
    include/stdafx.h \
    include/scientific/Vec3d.h \
    include/scientific/VecXd.h

SOURCES += \
    src/engines/Controller.cpp \
    src/engines/RayTracingHandler.cpp \
    src/rayTracing/RayTracer.cpp \
    src/surfaces/Triangle.cpp \
    src/surfaces/World.cpp \
    src/testing/Testing.cpp \
    src/utils/Helper.cpp \
    src/utils/Settings.cpp \
    main.cpp \
    src/cameras/Camera.cpp \
    src/scientific/Vec3d.cpp \
    src/scientific/VecXd.cpp
