#include <iostream>
#include "AStarSearcher.h"
#include "BestFirstSearcher.h"
#include "BreadthSearcher.h"
#include "GeneralServer.h"
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "SearchAdapter.h"
#include "Searcher.h"
#include "DepthSearcher.h"
#include "SearchCacheManager.h"
#include "SearchClientHandler.h"
#include "MatrixReader.h"
#include "Matrix.h"

using namespace std;

int main() {
    CacheManager<Searchable<string>, string> *f = new SearchCacheManager<string>();

    Searcher<string> *src = new DepthSearcher<string>();

    Solver<Searchable<string>, string> *sol = new SearchAdapter<Searchable<string>, string, string>(src);

    ClientHandler *c = new SearchClientHandler<string>(sol, f);

    Server *server  = new MyParallelServer();
    server->open(5402, c);
    server->close();


    delete server;
    delete c;
    delete f;
    delete sol;
    delete src;
    return 0;
//    string input;
//    while (true) {
//        bool running = true;
//        MatrixReader matrixReader;
//        while (running) {
//            getline(cin, input);
//            if (input == "end") {
//                running = false;
//            } else {
//                matrixReader.receiveInput(input);
//            }
//        }

//        Searchable<string> *searchable = matrixReader.createMatrix();


//        string path;


//        if (f->isSolutionExist(searchable)) {
//            path = f->getSolution(searchable);
//        } else {
//
//            path = sol->solve(searchable);
//
//            f->saveSolution(searchable, path);
//        }
//            cout << path << endl;
//    }


}