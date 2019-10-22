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
    Application.cpp \
    Dao/GroupDao.cpp \
    Dao/LanguageDao.cpp \
    Dao/ProfileDao.cpp \
    Dao/TrainingDao.cpp \
    Dao/WordDao.cpp \
    Entities/Group.cpp \
    Entities/Language.cpp \
    Entities/Profile.cpp \
    Entities/Training.cpp \
    Entities/Word.cpp \
    Models/CardModel.cpp \
    Models/GroupModel.cpp \
    Models/TranslationModel.cpp \
    Models/WordModel.cpp \
    Views/Cards/Card.cpp \
    Views/Cards/CardAskView.cpp \
    Views/Cards/CardDetailView.cpp \
    Views/GroupManagement/GroupEditView.cpp \
    Views/GroupManagement/GroupListItemDelegate.cpp \
    Views/GroupManagement/GroupNotSelectedView.cpp \
    Views/GroupManagement/GroupPage.cpp \
    Views/GroupManagement/GroupTrainingView.cpp \
    Views/GroupManagement/GroupView.cpp \
    Views/LearningView.cpp \
    Views/MainWindow.cpp \
    Views/ManagementView.cpp \
    Views/PageSwitch.cpp \
    Views/WordManagement/TranslationEditor.cpp \
    Views/WordManagement/TranslationItemDelegate.cpp \
    Views/WordManagement/WordItemDelegate.cpp \
    main.cpp

HEADERS += \
    Application.h \
    Dao/GroupDao.h \
    Dao/LanguageDao.h \
    Dao/ProfileDao.h \
    Dao/TrainingDao.h \
    Dao/WordDao.h \
    Entities/Group.h \
    Entities/Language.h \
    Entities/Profile.h \
    Entities/Training.h \
    Entities/Word.h \
    Models/CardModel.h \
    Models/GroupModel.h \
    Models/TranslationModel.h \
    Models/WordModel.h \
    Views/Cards/Card.h \
    Views/Cards/CardAskView.h \
    Views/Cards/CardDetailView.h \
    Views/GroupManagement/GroupEditView.h \
    Views/GroupManagement/GroupListItemDelegate.h \
    Views/GroupManagement/GroupNotSelectedView.h \
    Views/GroupManagement/GroupPage.h \
    Views/GroupManagement/GroupTrainingView.h \
    Views/GroupManagement/GroupView.h \
    Views/LearningView.h \
    Views/MainWindow.h \
    Views/ManagementView.h \
    Views/PageSwitch.h \
    Views/WordManagement/TranslationEditor.h \
    Views/WordManagement/TranslationItemDelegate.h \
    Views/WordManagement/WordItemDelegate.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Static.qrc
