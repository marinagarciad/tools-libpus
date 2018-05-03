from PySide import QtGui, QtCore

from .Ui.Ui_MainView import Ui_MainView
from PusGui.Utilities import DigitalClock


class MainView:
    """
    This class represents a window. It references the class
    Ui_MainView, that class is where the graphical interface
    is created
    """

    def __init__(self):
        """
        This is the constructor of the class
        """
        self.view = QtGui.QMainWindow()
        self.window = Ui_MainView()
        self.window.setupUi(self.view)
        self.spacecraftTimeValue = DigitalClock(0, self.window.statusTab)
        self.system_params = dict()
        self.extra_customization()
        self.window.centralwidget.resizeEvent = self.resize_elements

    def get_window(self):
        """
        This method returns the view that this class references

        :return: A view. It could be a QWidget, QMainWindow, etc.
        """
        return self.view

    def extra_customization(self):
        """
        This method allow us to define an extra configuration for the
        view without having to touch the code generated by the QtDesigner
        giving us a extra level of abstraction
        """
        header = self.window.packagesTable.horizontalHeader()
        header.setResizeMode(0, QtGui.QHeaderView.ResizeToContents)
        header.setResizeMode(1, QtGui.QHeaderView.ResizeToContents)
        header.setResizeMode(2, QtGui.QHeaderView.ResizeToContents)
        header.setResizeMode(3, QtGui.QHeaderView.ResizeToContents)
        header.setResizeMode(4, QtGui.QHeaderView.ResizeToContents)
        header.setResizeMode(5, QtGui.QHeaderView.ResizeToContents)
        header.setResizeMode(6, QtGui.QHeaderView.ResizeToContents)
        header.setResizeMode(7, QtGui.QHeaderView.ResizeToContents)
        header.setResizeMode(8, QtGui.QHeaderView.ResizeToContents)
        header.setResizeMode(9, QtGui.QHeaderView.ResizeToContents)
        self.window.packagesTable.setSelectionBehavior(QtGui.QAbstractItemView.SelectRows)
        self.view.setStyleSheet("background-color: white")
        self.window.menubar.setStyleSheet("background: 3c3b37")
        # self.window.label.setText(
        #     QtGui.QApplication.translate("MainView", "<html><head/><body><p>"
        #                                              "<img src=\"Views/Views_Ui/images/logo_gmv.svg\""
        #                                              "width=\"60\" height=\"35\"/></p></body></html>",
        #                                  None, QtGui.QApplication.UnicodeUTF8))
        header.sortIndicatorOrder()
        self.window.packagesTable.verticalHeader().setVisible(False)
        self.window.packagesTable.sortByColumn(0, QtCore.Qt.AscendingOrder)
        sctv_h = self.window.spacecraftTimeLbl.frameGeometry().height()
        sctv_w = self.window.spacecraftTimeLbl.frameGeometry().width()
        sctv_x = self.window.spacecraftTimeLbl.pos().x() + sctv_w + 10
        sctv_y = self.window.spacecraftTimeLbl.pos().y()
        self.spacecraftTimeValue.setGeometry(QtCore.QRect(sctv_x, sctv_y, sctv_w, sctv_h))
        self.spacecraftTimeValue.setText("")
        self.spacecraftTimeValue.setObjectName("spacecraftTimeValue")

    def resize_elements(self, event):
        """
        This method defines all the instructions needed to make
        our CreateTCView window responsive

        :param event: The event that triggers this method
        """
        padding = 10
        tw_w = self.window.packagesTable.frameGeometry().width()
        tw_h = self.window.packagesTable.frameGeometry().height()
        tw_x = self.window.packagesTable.pos().x()
        tw_y = self.window.packagesTable.pos().y()

        img_w = self.window.label.frameGeometry().width()
        img_h = self.window.label.frameGeometry().height()
        img_x = self.window.label.pos().x()
        img_y = self.window.label.pos().y()

        self.window.tabWidget.resize(self.window.centralwidget.frameGeometry().width() - 2*padding,
                                     self.window.centralwidget.frameGeometry().height() - 2*padding)
        self.window.label.move(self.window.centralwidget.frameGeometry().width() - img_w - 3*padding, img_y)

    def __add_system_params__(self, name: str):
        if name not in self.system_params:
            obj = QtGui.QListWidgetItem()
            obj.setHidden(True)
            self.window.hkParamList.addItem(obj)
            self.system_params[name] = obj

    def update_space_time(self, val):
        if val is not None:
            self.spacecraftTimeValue.setVisible(True)
            self.spacecraftTimeValue.setText(val)

    def update_system_params(self, idx: str, val):
        self.__add_system_params__(idx)  # The param is added if it is not already
        if val is not None:
            self.system_params[idx].setHidden(False)
            self.system_params[idx].setText("{}: {}".format(idx, val))

    def set_close_event(self, func):
        self.view.closeEvent = func

    def show(self):
        """
        This method calls to the .show_() method of the view referenced
        by this class.
        """
        return self.view.show()
