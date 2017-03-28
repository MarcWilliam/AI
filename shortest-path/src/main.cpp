#include "includes.h"

using namespace std;

int main(int argc, char** argv) {
	std::vector<Link> links;
	std::map<char,float> huristicMap;
	char startCity, endCity;
	int algori;
	acquireLinks(links);

	cout << "Start -> Goal city: ";
	cin >> startCity >> endCity;
	cout << "1->BFS \t| 2->A* \t| 3->UCS \t| 4->Huristic "<< endl;
	cout << " pick an algorithm: ";
	cin >> algori;

	if (algori == HURISTIC || algori == ASTAR) {
		acquireHuristics(huristicMap);
	}

	Node* currentNode = new Node(startCity);
	List* frontier = new List(currentNode);

	for (int i = 0; i < links.size(); i++) {
		cout << links[i] << endl;
	}

	while ( (currentNode != NULL) && (!currentNode->isGoal(endCity)) ) {
		currentNode->expand(links, huristicMap, frontier);
		currentNode = frontier->getNextNode(algori);
		cout << *frontier << endl;
	}

	if (currentNode == NULL) {
		cout << endl << "================= NO SOLUTION =================" << endl;
		return 2; // no solution
	} else {
		frontier->printResult();
		return 0;
	}
}