from PySide import QtGui, QtCore
from .Ui.Ui_CodeView import Ui_CodeView


class CodeView:
    """
    This class represents a window. It references the class
    Ui_CodeView, that class is where the graphics
    are created
    """
    resizeFlag = False

    def __init__(self):
        """
        This is the constructor of the class
        """
        self.view = QtGui.QDialog()
        self.window = Ui_CodeView()
        self.window.setupUi(self.view)
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
        self.view.setStyleSheet("background-color: white")

    def resize_elements(self, event):
        """
        This method defines all the instructions needed to make
        our DetailsView window responsive

        :param event: The event that triggers this method
        """
        padding = 20
        if self.resizeFlag:
            pass
        else:
            self.resizeFlag = True

    def set_code(self, data):
        self.window.obcpCodeTextEdit.setPlainText(data)

    def get_code(self):
        return self.window.obcpCodeTextEdit.toPlainText()

    def get_id(self):
        return self.window.obcpIdValue.text()

    def show(self):
        """
        This method calls to the .show() method of the view referenced
        by this class
        """
        return self.view.exec_()

    def set_close_event(self, fun):
        self.view.closeEvent = fun

    def destroy(self):
        self.view.destroy()
