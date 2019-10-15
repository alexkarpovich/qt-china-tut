QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Dao/GroupDao.cpp \
    Dao/WordDao.cpp \
    Entities/Group.cpp \
    Entities/Word.cpp \
    Models/TranslationModel.cpp \
    Views/GroupManagement/GroupEditView.cpp \
    Views/GroupManagement/GroupListItemDelegate.cpp \
    Views/GroupManagement/GroupNotSelectedView.cpp \
    Views/GroupManagement/GroupView.cpp \
    Views/MainWindow.cpp \
    Views/ManagementView.cpp \
    Views/TranslationManagement/TranslationItemDelegate.cpp \
    dbmanager.cpp \
    main.cpp \
    Models/GroupListModel.cpp

HEADERS += \
    Dao/GroupDao.h \
    Dao/WordDao.h \
    Entities/Group.h \
    Entities/Word.h \
    Models/TranslationModel.h \
    Views/GroupManagement/GroupEditView.h \
    Views/GroupManagement/GroupListItemDelegate.h \
    Views/GroupManagement/GroupNotSelectedView.h \
    Views/GroupManagement/GroupView.h \
    Views/MainWindow.h \
    Views/ManagementView.h \
    Views/TranslationManagement/TranslationItemDelegate.h \
    dbmanager.h \
    Models/GroupListModel.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Static.qrc
