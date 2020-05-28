/*************************************************************************
 * Project: ImdbGraph implementation
 * File Name: ImdbGraph.cpp
 */
#include <cctype>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include "ImdbGraph.h"
#include "SLelement.h"
#include "data_src/ActorMovieIMDB.h"

using namespace bridges;

// Constructor
ImdbGraph::ImdbGraph() {}

// Destructor
ImdbGraph::~ImdbGraph() {}

// Function: Adds a vertex to the graph.
// Pre:  Graph has been initialized.
// Post: The actor or movie will be added as a vertex.
//          No duplicate vertics will be created.
void ImdbGraph::AddVertex(string actorOrMovie) {
  // TODO Add code here.
  auto vertices = graph.getVertices();

  if (vertices->find(actorOrMovie) == vertices->end()) {
    graph.addVertex(actorOrMovie);
    graph.getVisualizer(actorOrMovie)->setColor(Color("black"));
    graph.getVisualizer(actorOrMovie)->setSize(10);
    graph.getVisualizer(actorOrMovie)->setOpacity(.5);
  }
}

// Function: Adds a edge to the graph.
// Pre:  Graph has been initialized.
//          Vertics have been already added to the graph.
// Post: The actor movie edge will be added to the graph.
//          No duplicate edges will be created.
void ImdbGraph::AddEdge(string actorOrMovie, string movieOrActor) {
  // TODO Add code here.
  graph.addEdge(actorOrMovie, movieOrActor, "1");
  graph.addEdge(movieOrActor, actorOrMovie, "1");
  graph.getLinkVisualizer(actorOrMovie, movieOrActor)
      ->setColor(Color("lightskyblue"));
  graph.getLinkVisualizer(movieOrActor, actorOrMovie)
      ->setColor(Color("lightskyblue"));
  graph.getLinkVisualizer(actorOrMovie, movieOrActor)->setThickness(1.);
  graph.getLinkVisualizer(movieOrActor, actorOrMovie)->setThickness(1.);
}

// Function: Updates the visualization for to vertex.
// Pre:  Graph has been initialized.
//          Vertex is in the graph.
// Post: The vertex will display the new color.
void ImdbGraph::VisualizeVertex(string actorOrMovie, string color) {
  // TODO Add code here.

  graph.getVisualizer(actorOrMovie)->setColor(Color(color));
  graph.getVisualizer(actorOrMovie)->setSize(50);
  graph.getVisualizer(actorOrMovie)->setOpacity(1.);
}

// Function: Updates the visualization for to edge.
// Pre:  Graph has been initialized.
//          Edge is in the graph.
// Post: The edge will display the new color.
void ImdbGraph::VisualizeEdge(string actorOrMovie, string movieOrActor2,
                              string color) {
  // TODO Add code here.
  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setColor(Color(color));
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setColor(Color(color));
  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setThickness(10.);
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setThickness(10.);
}

// Function: Resets all visualizations to the default.
// Pre:  Graph has been initialized.
// Post: The vertics and edges will display the default color.
void ImdbGraph::ResetVisualizer() {
  // TODO Add code here.
  for (auto &vertex : *graph.getVertices()) {
    graph.getVisualizer(vertex.first)->setColor(Color("black"));
    graph.getVisualizer(vertex.first)->setSize(10);
    graph.getVisualizer(vertex.first)->setOpacity(0.5);

    auto sl_list = graph.getAdjacencyList(vertex.first);
    for (auto sle = sl_list; sle != NULL; sle = sle->getNext()) {
      auto destination = ((Edge<string>)sle->getValue()).to();
      graph.getLinkVisualizer(vertex.first, destination)
          ->setColor(Color("lightskyblue"));
      graph.getLinkVisualizer(vertex.first, destination)->setThickness(1.);
    }
  }
}

// Function: Calculates the Bacon Number for two actors.
//           In addition to returning the number, the graph is update to
//           highlight the path.
//           https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon
// Pre:  Graph has been initialized.
//          Vertices are in the graph.
//          Edges connect the actors in the graph.
// Post: The number returned will be lowest number of actor connections used to
// connect them.
//          The graph will visually show the path to connect the actors.
int ImdbGraph::GetBaconNumber(string sourceActor, string destinationActor) {
  int bacon_number = 0;
  queue<string> frontierQueue;
  set<string> discoveredSet;
  map<string, string> paths;

  string currentVertex = sourceActor;

  frontierQueue.push(currentVertex);
  discoveredSet.emplace(currentVertex);

  while (!frontierQueue.empty()) {
    currentVertex = frontierQueue.front();
    
    if (currentVertex == sourceActor) {
      VisualizeVertex(currentVertex, "purple");
    }
    if (currentVertex == destinationActor) {
      VisualizeVertex(currentVertex, "purple");
      break;
    }

    auto adjList = graph.getAdjacencyList(currentVertex);
    frontierQueue.pop();

    for (auto sle = adjList; sle != NULL; sle = sle->getNext()) {
      auto destination = ((Edge<string>)sle->getValue()).to();

      if (discoveredSet.count(destination) != 1) {
        frontierQueue.push(destination);
        discoveredSet.emplace(destination);
        paths.emplace(destination, currentVertex);
      }
    }
  }

  while (currentVertex != sourceActor) {
    VisualizeEdge(currentVertex, paths.at(currentVertex), "orange");
    currentVertex = paths.at(currentVertex);
    bacon_number++;
  }

  return bacon_number;
}
