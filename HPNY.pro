QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc16/lib/ -lopencv_world4100
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc16/lib/ -lopencv_world4100d
else:unix: LIBS += -L$$PWD/../../../../../opencv/build/x64/vc16/lib/ -lopencv_world4100

INCLUDEPATH += $$PWD/../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../opencv/build/include


DEFINES -= UNICODE


win32: LIBS += -L$$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64/' -lEasyXa

INCLUDEPATH += $$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64'
DEPENDPATH += $$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64'

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/release/' -lEasyXw
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/debug/' -lEasyXw

INCLUDEPATH += $$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64'
DEPENDPATH += $$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64'

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/release/' -lVSCustomNativeHeapEtwProvider
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/debug/' -lVSCustomNativeHeapEtwProvider

INCLUDEPATH += $$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64'
DEPENDPATH += $$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64'

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/release/' -lVsGraphicsHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/debug/' -lVsGraphicsHelper

INCLUDEPATH += $$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64'
DEPENDPATH += $$PWD/'../../../../../Program Files/Microsoft Visual Studio/2022/Community/VC/Auxiliary/VS/lib/x64'

win32{
    INCLUDEPATH += $$PWD/sdk/include
    LIBS += -L$$PWD/sdk/lib -llibvlc -llibvlccore
}else{
    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib -lvlc -lvlccore
}
RC_ICONS = LOGO.ico
