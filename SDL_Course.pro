TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "..\include"

win32{
    LIBS += -lmingw32
}

LIBS += -L"..\libs"
LIBS += -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf


SOURCES += \
        Components/collidercomponent.cpp \
        Components/keyboardcomponent.cpp \
        Components/labelcomponent.cpp \
        Components/projectileemmitercomponent.cpp \
        Components/spritecomponent.cpp \
        collisionmanager.cpp \
        component.cpp \
        entity.cpp \
        entitymanager.cpp \
        fontmanager.cpp \
        game.cpp \
        main.cpp \
        map.cpp \
        texturemanager.cpp \
        window.cpp

HEADERS += \
    Components/collidercomponent.h \
    Components/keyboardcomponent.h \
    Components/labelcomponent.h \
    Components/projectileemmitercomponent.h \
    Components/tilecomponent.h \
    Components/transformcomponent.h \
    animation.h \
    Components/spritecomponent.h \
    collisionmanager.h \
    component.h \
    entity.h \
    entitymanager.h \
    fontmanager.h \
    game.h \
    map.h \
    texturemanager.h \
    utils.h \
    window.h

DISTFILES += \
    assets/tilemap.map
