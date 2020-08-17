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
        window.cpp

HEADERS += \
    component.h \
    entity.h \
    entitymanager.h \
    game.h \
    utils.h \
    window.h
