TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

SOURCES += main.cpp \
    Game.cpp \
    MyGame.cpp \
    Resources.cpp \
    utils.cpp \
    Pelota.cpp

HEADERS += \
    Game.hpp \
    MyGame.hpp \
    Resources.hpp \
    utils.hpp \
    Pelota.hpp

