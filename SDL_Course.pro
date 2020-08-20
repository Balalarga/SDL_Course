TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "..\include"

win32{
    LIBS += -lmingw32
}

LIBS += -L"..\libs"
LIBS += -lSDL2main -lSDL2 -lSDL2_image


SOURCES += \
        Components/keyboardcomponent.cpp \
        Components/spritecomponent.cpp \
        component.cpp \
        entity.cpp \
        entitymanager.cpp \
        game.cpp \
        main.cpp \
        map.cpp \
        texturemanager.cpp \
        window.cpp

HEADERS += \
    Components/keyboardcomponent.h \
    Components/tilecomponent.h \
    Components/transformcomponent.h \
    animation.h \
    Components/spritecomponent.h \
    component.h \
    entity.h \
    entitymanager.h \
    game.h \
    map.h \
    texturemanager.h \
    utils.h \
    window.h

DISTFILES += \
    assets/tilemap.map
