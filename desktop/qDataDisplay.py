from PySide2.QtWidgets import QLabel
from PySide2.QtWidgets import QLineEdit
from PySide2.QtWidgets import QVBoxLayout
from PySide2.QtWidgets import QWidget

import constants

class QDataDisplay(QWidget):
  def __init__(self, parent):
    QWidget.__init__(self, parent)
