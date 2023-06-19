#include<iostream>
#include<list>

using namespace std;

int get_id(char c) { return ((int)c - 65); }

char get_char(int id) { return (char)(id + 65); }

class Connection {

    public:

        int dst;
        int wgt;

        Connection() {

            dst = 0;
            wgt = 0;
        } // end of default constructor

        Connection(int dst, int wgt) {

            this->dst = dst;
            this->wgt = wgt;
        } // end of parameterised constructor
}; // end of class Connection

class Graph {

    public:

        int V; // store the number of vertices
        list<Connection> *adj; // to store childs with the weights of their connecting edge

        Graph(int V) {

            this->V = V;
            adj = new list<Connection>[V];
        } // end of constructor

        ~Graph() { delete adj; } // destructor

        void add_edge(int v1, int v2, int weight) {

            adj[v1].push_back(Connection(v2, weight));
            adj[v2].push_back(Connection(v1, weight));
        } // end of add_edge(int, int, int)

        void display_edges() {

            cout << "Srce    Dest    Wght" << endl;

            list<Connection>::iterator i;

            for (int src = 0; src < V; src++)
                for (i = adj[src].begin(); i != adj[src].end(); i++)
                    printf(" %d       %d       %d\n", src, i->dst, i->wgt);
        } // end of display_edges()

}; // end of Graph class

Connection *minSpanTree_init(int V) {

    Connection *arr = new Connection[V];

    for (int i = 0; i < V; i++) {

        arr[i].dst = -1;
        arr[i].wgt = -1; 
    }

    return arr;
} // end of minSpanTree_init(int)

void do_prim(Graph *gph, int src, int V, int *visited, int visit_count, Connection *mst) {

    visited[src] = 1; // mark current vertex as visited
    visit_count++;

    int dst, wgt;
    int v_min_wgt, min_wgt = -1;

    list<Connection>::iterator i;

    // check every children (iff unvisited) and set weight and parent if -1 or < current weight
    for (i = gph->adj[src].begin(); i != gph->adj[src].end(); i++) {

        dst = i->dst; // the current adjacent vertex
        wgt = i->wgt; // storing the associated weight

        // cout << src << " -> " << dst << endl; // debug statement

        if (!visited[dst]) { // checking if the current adjacent vertex is visited

            // checking the state of current adjacent vertex in mst
            if (mst[dst].wgt == -1 || mst[dst].wgt > wgt) { 

                mst[dst].wgt = wgt; // setting new weight
                mst[dst].dst = src; // setting current vertex as parent

                // checking state of variable min_wgt
                if (min_wgt == -1 || wgt < min_wgt) { 

                    min_wgt = wgt;
                    v_min_wgt = dst;
                }

            } // end of inner if block
        } // end of outer if block

    } // end of for loop

    if (visit_count == V - 1) return; // if all vertices except the last is visisted

    do_prim(gph, v_min_wgt, V, visited, visit_count, mst); // move to child with least weight
} // end of do_prim(Graph*, int, int, int*, int*, int, Connection*)

// ******************************************  debug functions
void display(int *arr, int len) { 
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    cout << endl;
}

void display(Connection *arr, int len) { 
    for (int i = 0; i < len; i++)
        printf("Current: %d, Parent: %d, Weight: %d\n", i, arr[i].dst, arr[i].wgt);
}
// ******************************************

Connection* get_minSpanTree(Graph *g, int V, int source) {

    int *visited = new int[V]{0}; // initialising visited

    Connection *mst = minSpanTree_init(V); // initialising minimum-spanning-tree

    do_prim(g, source, V, visited, 0, mst);

    //
    // display(visited, V);
    // display(mst, V);
    //

    return mst;
} // end of get_minSpanTree(Graph*, int, int)

void display_minSpanTree(Connection *mst, int V) {

    int sum = 0;

    printf("Edges of Minimum Spanning Tree :-\n\n");
    printf("Source    Destination    Weight\n");

    for (int i = 1; i < V; i++) {

        printf(" %c            %c            %d\n", get_char(mst[i].dst), get_char(i), mst[i].wgt);
        sum += mst[i].wgt;
    }

    printf("\nTotal weight of Minimum Spanning Tree: %d\n\n", sum);
} // end of display_minSpanTree(Connection*, int)

Graph* create_graph(int V, int E) {

    Graph *g = new Graph(V);

    printf("Enter edges (source, destination, weight, respectively) :-\n");
    char src, dst;
    int wgt;

    for (int i = 0; i < E; i++) {

        printf("%d Enter edge: ", (i + 1));
        cin >> src >> dst >> wgt;

        g->add_edge(get_id(src), get_id(dst), wgt);
    }

    // g->add_edge(0, 1, 4);
    // g->add_edge(0, 2, 8);
    // g->add_edge(1, 2, 2);
    // g->add_edge(1, 3, 6);
    // g->add_edge(2, 3, 3);
    // g->add_edge(2, 4, 9);
    // g->add_edge(3, 4, 5);

    return g;
} // end of create_graph(int)

int main() {

    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    Graph *graph = create_graph(V, E);

    display_minSpanTree(get_minSpanTree(graph, V, 0), V);

    return 0;
} // end of main()