#include <iostream>

#include "graph_node.h"
#include "edge.h"
#include "graph.h"

using std::cout;
using std::endl;

int main()
{
    Graph g;

    // create nodes
    GraphNode A{"Corvallis"}; // GraphNode object 'A' is initialized with the value "Corvallis"
    GraphNode B{"Salem"};
    GraphNode C{"Eugene"};
    GraphNode D{"Portland"};
    GraphNode E{"Mt Hood"};
    GraphNode F{"Bend"};

    cout << "A.name: " << A.name << endl;
    cout << "F.name: " << F.name << endl;

    g.add_node(&A);
    g.add_node(&B);
    g.add_node(&C);
    g.add_node(&D);
    g.add_node(&E);
    g.add_node(&F);

    g.print_nodes();

    // create edges
    Edge AB{36, &A, &B};
    Edge BA{36, &B, &A};
    Edge AC{47, &A, &C};
    Edge CA{47, &C, &A};
    Edge AF{128, &A, &F};
    Edge FA{128, &F, &A};

    Edge BC{66, &B, &C};
    Edge CB{66, &C, &B};
    Edge BD{46, &B, &D};
    Edge DB{46, &D, &B};

    Edge CF{129, &C, &F};
    Edge FC{129, &F, &C};

    Edge DE{77, &D, &E};
    Edge ED{77, &E, &D};

    Edge EF{129, &E, &F};
    Edge FE{129, &F, &E};

    cout << "\nAF(weight, src->name, dst->name): (" << AF.weight << ", " << AF.source->name << ", " << AF.destination->name << ")" << endl;
    cout << "FA(weight, src->name, dst->name): (" << FA.weight << ", " << FA.source->name << ", " << FA.destination->name << ")" << endl;

    // hook up the edges into the nodes
    g.add_edge(&AB);
    g.add_edge(&BA);
    g.add_edge(&AC);
    g.add_edge(&CA);
    g.add_edge(&AF);
    g.add_edge(&FA);

    g.add_edge(&BC);
    g.add_edge(&CB);
    g.add_edge(&BD);
    g.add_edge(&DB);

    g.add_edge(&CF);
    g.add_edge(&FC);

    g.add_edge(&DE);
    g.add_edge(&ED);

    g.add_edge(&EF);
    g.add_edge(&FE);

    // source, destination complication might come up here!
    cout << "A.neighbors[2]->destination->name: " << A.neighbors[2]->destination->name << endl;
    cout << "A.neighbors[1]->destination->name: " << A.neighbors[1]->destination->name << endl;
    cout << "A.neighbors[0]->destination->name: " << A.neighbors[0]->destination->name << endl;

    // Test Dijkstra's algorithm from Corvallis
    cout << "\nDijkstra's shortest paths from Corvallis:\n";
    vector<pair<GraphNode *, int>> distances = g.dijkstra(&A);
    for (auto &[node, distance] : distances)
    {
        cout << node->name << ": " << distance << endl;
    }

    // Test Dijkstra's algorithm from Eugene
    cout << "\nDijkstra's shortest paths from Eugene:\n";
    distances = g.dijkstra(&C);
    for (auto &[node, distance] : distances)
    {
        cout << node->name << ": " << distance << endl;
    }

    // Test Prim's algorithm for MST
    cout << "\nPrim's minimum spanning tree:\n";
    vector<Edge *> mst = g.prim();
    for (Edge *edge : mst)
    {
        cout << "(" << edge->source->name << " - " << edge->destination->name << ", " << edge->weight << ")\n";
    }

    // Create a second graph
    Graph g2;
    GraphNode G{"Brookings"};
    GraphNode H{"Coos Bay"};
    GraphNode I{"Roseburg"};
    GraphNode J{"Medford"};

    g2.add_node(&G);
    g2.add_node(&H);
    g2.add_node(&I);
    g2.add_node(&J);

    Edge GH{107, &G, &H};
    Edge HG{107, &H, &G};
    Edge GI{162, &G, &I};
    Edge IG{161, &I, &G};
    Edge HJ{165, &H, &J};
    Edge JH{165, &J, &H};
    Edge IJ{97, &I, &J};
    Edge JI{97, &J, &I};

    g2.add_edge(&GH);
    g2.add_edge(&HG);
    g2.add_edge(&GI);
    g2.add_edge(&IG);
    g2.add_edge(&HJ);
    g2.add_edge(&JH);
    g2.add_edge(&IJ);
    g2.add_edge(&JI);

    cout << "\nPrim's minimum spanning tree (second graph):\n";
    mst = g2.prim();
    for (Edge *edge : mst)
    {
        cout << "(" << edge->source->name << " - " << edge->destination->name << ", " << edge->weight << ")\n";
    }

    return 0;
}
