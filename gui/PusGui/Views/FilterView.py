# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

from PySide import QtGui, QtCore

from .Ui.Ui_FilterView import Ui_FilterView


class FilterView(object):
    """
    This class represents a window. It references the class
    Ui_CreateTCView, that class is where the graphical interface
    is created
    """
    resizeFlag = False

    def __init__(self):
        """
        This is the constructor of the class
        """
        self.view = QtGui.QDialog()
        self.window = Ui_FilterView()
        self.window.setupUi(self.view)
        self.fixedWidth = 0
        self.fixedHeight = 0
        self.extra_customization()
        self.view.resizeEvent = self.resize_elements

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
        fixed_width = self.view.frameGeometry().width()
        fixed_height = self.view.frameGeometry().height()

        self.view.setMinimumSize(fixed_width, fixed_height)
        self.view.setMaximumSize(fixed_width, fixed_height)

        self.window.typeComboBox.setItemData(0, "")
        self.window.typeComboBox.setItemData(1, "TC")
        self.window.typeComboBox.setItemData(2, "TM")

    def resize_elements(self, event):
        """
        This method defines all the instructions needed to make
        our CreateTCView window responsive

        :param event: The event that triggers this method
        """
        pass

    def show(self):
        """
        This method calls to the .exec_() method of the view referenced
        by this class. Exec method blocks the execution of the program until
        an answer is given.
        """
        return self.view.exec_()

    def destroy(self):
        self.view.destroy()
