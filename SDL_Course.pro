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
        component.cpp \
        entity.cpp \
        entitymanager.cpp \
        game.cpp \
        main.cpp \
        texturemanager.cpp \
        window.cpp

HEADERS += \
    animation.h \
    Components/spritecomponent.h \
    Components/transrormcomponent.h \
    component.h \
    entity.h \
    entitymanager.h \
    game.h \
    texturemanager.h \
    utils.h \
    window.h
