TEMPLATE = app
CONFIG -= console
CONFIG -= app_bundle
CONFIG -= qt

DEFINES -= UNICODE

INCLUDEPATH += "C:/Projects/Gx/Gx" \
               "C:/Projects/pcx" \
               "C:/lib/Bullet/src"

LIBS += "C:/Projects/Gx/build-Gx/release/libgx.a" \
        "C:/Projects/pcx/build-pcx/release/libpcx.a"

QMAKE_CXXFLAGS += -std=gnu++11 \
                  -include "GxCore/GxDebug.h"

QMAKE_LFLAGS += -Wl,--exclude-all-symbols

QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas -Wno-comment -Wno-maybe-uninitialized -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-attributes

PRE_TARGETDEPS += "C:/Projects/Gx/build-Gx/release/libgx.a" \
                  "C:/Projects/pcx/build-pcx/release/libpcx.a"

LIBS += "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3d9.lib" \
        "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3dx9.lib" \
        "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/dxerr.lib" \
        "C:/mingw64/x86_64-w64-mingw32.shared/lib/libuser32.a" \
        "C:/mingw64/x86_64-w64-mingw32.shared/lib/libgdi32.a" \
        "C:/mingw64/x86_64-w64-mingw32.shared/lib/libpsapi.a" \
        "C:/lib/Bullet/build-Bullet/release/libBullet.a"

SOURCES += \
        application/Application.cpp \
        debug/DebugText.cpp \
        debug/FpsCounter.cpp \
        debug/MemUsage.cpp \
        graphics/Graphics.cpp \
        main.cpp \
        modes/GameMode.cpp \
        modes/Mode.cpp

HEADERS += \
    application/Application.h \
    debug/DebugText.h \
    debug/FpsCounter.h \
    debug/MemUsage.h \
    graphics/Graphics.h \
    modes/GameMode.h \
    modes/Mode.h
