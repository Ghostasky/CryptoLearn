# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'ui.ui'
#
# Created: Tue Mar 29 21:37:19 2011
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(800, 600)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(MainWindow.sizePolicy().hasHeightForWidth())
        MainWindow.setSizePolicy(sizePolicy)
        MainWindow.setBaseSize(QtCore.QSize(530, 630))
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.label_title_e = QtGui.QLabel(self.centralwidget)
        self.label_title_e.setGeometry(QtCore.QRect(290, 6, 67, 31))
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setWeight(75)
        font.setItalic(False)
        font.setUnderline(False)
        font.setBold(True)
        self.label_title_e.setFont(font)
        self.label_title_e.setObjectName(_fromUtf8("label_title_e"))
        self.button_e = QtGui.QPushButton(self.centralwidget)
        self.button_e.setGeometry(QtCore.QRect(370, 80, 171, 141))
        self.button_e.setObjectName(_fromUtf8("button_e"))
        self.line = QtGui.QFrame(self.centralwidget)
        self.line.setGeometry(QtCore.QRect(-10, 230, 811, 20))
        self.line.setFrameShape(QtGui.QFrame.HLine)
        self.line.setFrameShadow(QtGui.QFrame.Sunken)
        self.line.setObjectName(_fromUtf8("line"))
        self.label_title_d = QtGui.QLabel(self.centralwidget)
        self.label_title_d.setGeometry(QtCore.QRect(290, 260, 67, 21))
        font = QtGui.QFont()
        font.setPointSize(16)
        font.setWeight(75)
        font.setBold(True)
        self.label_title_d.setFont(font)
        self.label_title_d.setObjectName(_fromUtf8("label_title_d"))
        self.button_d = QtGui.QPushButton(self.centralwidget)
        self.button_d.setGeometry(QtCore.QRect(370, 340, 171, 141))
        self.button_d.setObjectName(_fromUtf8("button_d"))
        self.layoutWidget = QtGui.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(70, 110, 261, 117))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.verticalLayout_2 = QtGui.QVBoxLayout(self.layoutWidget)
        self.verticalLayout_2.setMargin(0)
        self.verticalLayout_2.setObjectName(_fromUtf8("verticalLayout_2"))
        self.label_e_c = QtGui.QLabel(self.layoutWidget)
        self.label_e_c.setObjectName(_fromUtf8("label_e_c"))
        self.verticalLayout_2.addWidget(self.label_e_c)
        self.text_e_c = QtGui.QTextBrowser(self.layoutWidget)
        self.text_e_c.setObjectName(_fromUtf8("text_e_c"))
        self.verticalLayout_2.addWidget(self.text_e_c)
        self.layoutWidget1 = QtGui.QWidget(self.centralwidget)
        self.layoutWidget1.setGeometry(QtCore.QRect(70, 50, 261, 52))
        self.layoutWidget1.setObjectName(_fromUtf8("layoutWidget1"))
        self.verticalLayout = QtGui.QVBoxLayout(self.layoutWidget1)
        self.verticalLayout.setMargin(0)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.label_e_m = QtGui.QLabel(self.layoutWidget1)
        self.label_e_m.setObjectName(_fromUtf8("label_e_m"))
        self.verticalLayout.addWidget(self.label_e_m)
        self.line_e_m = QtGui.QLineEdit(self.layoutWidget1)
        self.line_e_m.setObjectName(_fromUtf8("line_e_m"))
        self.verticalLayout.addWidget(self.line_e_m)
        self.layoutWidget2 = QtGui.QWidget(self.centralwidget)
        self.layoutWidget2.setGeometry(QtCore.QRect(70, 300, 261, 131))
        self.layoutWidget2.setObjectName(_fromUtf8("layoutWidget2"))
        self.verticalLayout_3 = QtGui.QVBoxLayout(self.layoutWidget2)
        self.verticalLayout_3.setMargin(0)
        self.verticalLayout_3.setObjectName(_fromUtf8("verticalLayout_3"))
        self.label_d_c = QtGui.QLabel(self.layoutWidget2)
        self.label_d_c.setObjectName(_fromUtf8("label_d_c"))
        self.verticalLayout_3.addWidget(self.label_d_c)
        self.text_d_c = QtGui.QTextBrowser(self.layoutWidget2)
        self.text_d_c.setReadOnly(False)
        self.text_d_c.setObjectName(_fromUtf8("text_d_c"))
        self.verticalLayout_3.addWidget(self.text_d_c)
        self.label_d_m = QtGui.QLabel(self.centralwidget)
        self.label_d_m.setGeometry(QtCore.QRect(71, 441, 30, 17))
        self.label_d_m.setObjectName(_fromUtf8("label_d_m"))
        self.line_d_m = QtGui.QLineEdit(self.centralwidget)
        self.line_d_m.setGeometry(QtCore.QRect(71, 464, 261, 31))
        self.line_d_m.setObjectName(_fromUtf8("line_d_m"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 25))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QtGui.QApplication.translate("MainWindow", "RSA??????", None, QtGui.QApplication.UnicodeUTF8))
        self.label_title_e.setText(QtGui.QApplication.translate("MainWindow", "??????", None, QtGui.QApplication.UnicodeUTF8))
        self.button_e.setText(QtGui.QApplication.translate("MainWindow", "??????", None, QtGui.QApplication.UnicodeUTF8))
        self.label_title_d.setText(QtGui.QApplication.translate("MainWindow", "??????", None, QtGui.QApplication.UnicodeUTF8))
        self.button_d.setText(QtGui.QApplication.translate("MainWindow", "??????", None, QtGui.QApplication.UnicodeUTF8))
        self.label_e_c.setText(QtGui.QApplication.translate("MainWindow", "??????", None, QtGui.QApplication.UnicodeUTF8))
        self.label_e_m.setText(QtGui.QApplication.translate("MainWindow", "??????", None, QtGui.QApplication.UnicodeUTF8))
        self.label_d_c.setText(QtGui.QApplication.translate("MainWindow", "??????", None, QtGui.QApplication.UnicodeUTF8))
        self.label_d_m.setText(QtGui.QApplication.translate("MainWindow", "??????", None, QtGui.QApplication.UnicodeUTF8))

