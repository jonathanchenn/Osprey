from PySide2.QtWidgets import QGridLayout

from qGraph import QGraph

import constants

class QGraphLayout(QGridLayout):
  def __init__(self, graphs, parent=None):
    QGridLayout.__init__(self, parent)
    self.startTime = None
    self.graphs = []

    for index, graph in enumerate(graphs):
      graph = QGraph(graph, parent)

      self.graphs.append(graph)
      self.addWidget(graph, int(index / constants.GRAPHS_PER_ROW), index % constants.GRAPHS_PER_ROW)

  def updateDataset(self, dataset):
    for graph in self.graphs:
      graph.updateDataset(dataset)
