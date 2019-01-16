# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

from PySide import QtGui, QtCore
from PySide.QtCore import QDateTime
import time
from .Ui.Ui_AddTCView import Ui_AddTCView
import json


class AddTCView(object):
    """
    This class represents a window. It references the class
    Ui_CreateTCView, that class is where the graphical interface
    is created
    """
    resizeFlag = False

    def __init__(self, show_time):
        """
        This is the constructor of the class
        """
        self.view = QtGui.QDialog()
        self.window = Ui_AddTCView()
        self.window.setupUi(self.view)
        self.is_19_svc = False
        if show_time:
            self.window.parentTCLbl.setText("st14 telecommand")
            now = QtCore.QDateTime.currentDateTime()

            self.window.dateTimeEdit.setDateTime(now)
            self.window.eventIdLbl.setHidden(True)
            self.window.eventIdLineEdit.setHidden(True)

        else:
            self.window.parentTCLbl.setText("st19 telecommand")
            self.window.scheduleLbl.setHidden(True)
            self.window.dateTimeEdit.setHidden(True)
            self.is_19_svc = True

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
        # self.view.setStyleSheet("background-color: white")
        pass

    def resize_elements(self, event):
        """
        This method defines all the instructions needed to make
        our CreateTCView window responsive

        :param event: The event that triggers this method
        """
        padding = 20
        pshte_w = self.window.pckSecHeaderTextEdit.frameGeometry().width()
        pshte_h = self.window.pckSecHeaderTextEdit.frameGeometry().height()
        pshte_x = self.window.pckSecHeaderTextEdit.pos().x()
        pshte_y = self.window.pckSecHeaderTextEdit.pos().y()

        sdte_w = self.window.srcDataTextEdit.frameGeometry().width()
        sdte_h = self.window.srcDataTextEdit.frameGeometry().height()
        sdte_x = self.window.srcDataTextEdit.pos().x()
        sdte_y = self.window.srcDataTextEdit.pos().y()

        if self.resizeFlag:
            self.window.pckSecHeaderTextEdit.resize(self.view.frameGeometry().width() - 2 * padding, pshte_h)

            self.window.srcDataTextEdit.resize(self.view.frameGeometry().width() - 2 * padding,
                                               self.view.frameGeometry().height() - 3 * padding + 4 - sdte_y)
        else:
            self.resizeFlag = True

    def add_item_svc_type_combo_box(self, item: str):
        """
        This method fills in the service id combobox with
        the ids every telecommand that can be embedded in a
        st11 or st19 packet.
        :param item: element to be added to the combobox
        """
        self.window.serviceComboBox.addItem(item, int(item))

    def add_item_msg_type_combo_box(self, item: str):
        """
        This method fills in the message id combobox, for each
        service in the service combobox, with the messages ids
        of that service that can be embedded in a st11 or st19
        packet.
        :param item: element to be added to the combobox
        """
        self.window.msgComboBox.addItem(item, int(item))

    def clear_msg_type_combo_box(self):
        """
        This method clears the message id combobox
        """
        self.window.msgComboBox.clear()

    def show(self):
        """
        This method calls to the .exec()_ method of the qDialog referenced
        by this class
        """
        return self.view.exec_()

    def set_tc_text(self, pck_sec_head="", source_data=""):
        """
        This method prints in the text box a json template
        making the creation of telecommands easier

        :param pck_sec_head: Data field of the packet secondary header
        :param source_data: Data field of the source_data
        """
        font = QtGui.QFont()
        font.setFamily("Courier")
        font.setStyleHint(QtGui.QFont.Monospace)
        font.setFixedPitch(True)
        font.setPointSize(10)
        metrics = QtGui.QFontMetrics(font)
        self.window.pckSecHeaderTextEdit.setTabStopWidth(metrics.width(' '))
        self.window.pckSecHeaderTextEdit.setPlainText(pck_sec_head)
        self.window.srcDataTextEdit.setTabStopWidth(metrics.width(' '))
        self.window.srcDataTextEdit.setPlainText(source_data)

    def get_tc_text(self):
        """
        This method returns the json that appears in
        the window textbox
        :return: json with the packet and the time when the packet has to be executed
        """
        return self.window.pckSecHeaderTextEdit.toPlainText(), self.window.srcDataTextEdit.toPlainText()

    def get_date_time(self):
        return int(self.window.dateTimeEdit.dateTime().toPython().timestamp())

    def get_event_id(self):
        return self.window.eventIdLineEdit.text()

    def is_svc_19(self):
        return self.is_19_svc

    def destroy(self):
        self.view.destroy()
