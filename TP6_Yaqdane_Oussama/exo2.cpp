#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Graph
{
private:
    unordered_map<string, vector<string>*>* adjacency_list= new unordered_map<string, vector<string>*>{};

    

public:

    void add_edge(string vertex, string neighbor){
        if ((*adjacency_list).count(vertex)){
            (*adjacency_list)[vertex]->push_back(neighbor); 
        } else {
            (*adjacency_list)[vertex] = new vector<string>{neighbor};
        }
    }

    void DFS(const string& starting_vertex){
        unordered_set<string> visited{starting_vertex};
        stack<string> stack;
        stack.push(starting_vertex);

        while (!stack.empty()){
            string vertex = stack.top();
            stack.pop();
            
            cout << vertex << "==>";

            if (adjacency_list->count(vertex) == 0) continue;

            for (auto it = adjacency_list->at(vertex)->begin(); it != adjacency_list->at(vertex)->end(); it++){
                if (!visited.count(*it)){
                    stack.push(*it);
                    visited.insert(*it);
                }
                    
            }
        }
        cout << "end" << endl;
        
    }

    // Not asked to be done but not freeing memory feels wrong :/
    ~Graph(){
        for (auto it = adjacency_list->begin(); it != adjacency_list->end(); it++){
            delete (*it).second;
        }
        delete adjacency_list;

    }
};


int main(){
    Graph g;
    g.add_edge("A", "B");
    g.add_edge("A", "C");
    g.add_edge("D", "B");
    g.add_edge("E", "B");
    g.add_edge("C", "F");
    g.add_edge("E", "F");
    g.add_edge("F", "G");

    cout << "The oriented edges entered: (A, B), (A, C), (D, B), (E, B), (C, F), (E, F), (F, G)"<< endl;

    cout << "DFS: " << endl;
    g.DFS("A");

    cout << "Not every edge is reached because the graph is oriented" << endl;
}