#include "graph.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	int choice;
	Graph g;
	cin >> choice;
	switch (choice)
	{
	case 1:   //TEST_CASE( "[Path] Empty graph", "[path_exists]" )
		cout << "false\t" << g.path_exists(0, 1);
		break;
	case 2: //TEST_CASE( "[Path] Singleton graph", "[path_exists]" )
	{
		g.add_vertex(0);
		cout << "true\t" << g.path_exists(0, 0) << endl;
		break;
	}
	case 3: //TEST_CASE( "[Path] Singleton graph with a loop", "[path_exists]" ) 
		g.add_vertex(0);
		g.add_arc(0, 0);
		cout << "true\t" << g.path_exists(0, 0) << endl;
		break;
	case 4: //TEST_CASE( "[Path] Path for two vertices without an arc", "[path_exists]" ) {
		g.add_vertex(0);
		g.add_vertex(1);
		cout << "false\t" << g.path_exists(0, 1) << endl;
		break;
	case 5: //TEST_CASE( "[Path] Path for two vertices with an arc", "[path_exists]" ) {
		g.add_arc(0, 1);
		cout << "true\t" << g.path_exists(0, 1) << endl;
		cout << "false\t" << g.path_exists(1, 0) << endl;
		break;
	case 6: //TEST_CASE( "[Path] Path for several vertices", "[path_exists]" ) {
		g.add_arc(0, 1);
		g.add_arc(1, 2);
		g.add_arc(2, 3);
		g.add_arc(0, 3);
		cout << "true\t" << g.path_exists(0, 3) << endl;
		cout << "true\t" << g.path_exists(1, 1) << endl;
		cout << "true\t" << g.path_exists(1, 3) << endl;
		cout << "false\t" << g.path_exists(3, 0) << endl;
		cout << "false\t" << g.path_exists(3, 1) << endl;
		break;
	case 7: //TEST_CASE( "[Path] Path in a disconnected graph", "[path_exists]" ) {
		g.add_arc(0, 1);
		g.add_arc(1, 2);
		g.add_arc(2, 3);
		g.add_arc(0, 3);
		g.add_arc(4, 5);
		g.add_arc(5, 6);
		g.add_vertex(7);
		cout << "true\t" << g.path_exists(1, 3) << endl;
		cout << "false\t" << g.path_exists(0, 5) << endl;
		cout << "false\t" << g.path_exists(1, 7) << endl;
		cout << "false\t" << g.path_exists(5, 7) << endl;
		break;
	case 8: //TEST_CASE( "[Path] Path with non-existing vertices", "[path_exists]" ) {
		g.add_arc(0, 1);
		g.add_arc(1, 2);
		g.add_arc(2, 3);
		g.add_arc(2, 4);
		g.add_arc(3, 5);
		cout << "false\t" << g.path_exists(0, 7) << endl;
		cout << "false\t" << g.path_exists(6, 2) << endl;
		cout << "false\t" << g.path_exists(6, 8) << endl;
		break;
	case 9: //TEST_CASE( "[Path] Path in a graph with loops", "[path_exists]" ) {
		g.add_arc(0, 1);
		g.add_arc(1, 2);
		g.add_arc(2, 3);
		g.add_arc(3, 1);
		g.add_arc(3, 5);
		g.add_arc(5, 3);
		g.add_arc(5, 6);
		g.add_arc(6, 5);
		g.add_arc(0, 7);
		cout << "true\t" << g.path_exists(0, 5) << endl;
		cout << "true\t" << g.path_exists(0, 6) << endl;
		cout << "true\t" << g.path_exists(1, 3) << endl;
		cout << "true\t" << g.path_exists(2, 1) << endl;
		cout << "true\t" << g.path_exists(6, 1) << endl;
		cout << "true\t" << g.path_exists(6, 2) << endl;
		cout << "false\t" << g.path_exists(5, 0) << endl;
		cout << "false\t" << g.path_exists(6, 7) << endl;
		break;
	case 10: //TEST_CASE( "[Path] Graph with negative vertices", "[path_exists]" ) {
		g.add_arc(-1, -999);
		g.add_arc(-1, -2);
		g.add_arc(-2, 0);
		g.add_arc(0, 999);
		cout << "true\t" << g.path_exists(-1, -999) << endl;
		cout << "true\t" << g.path_exists(-1, 999) << endl;
		cout << "false\t" << g.path_exists(-999, 999) << endl;
		break;
	case 11: //TEST_CASE( "[Path] Graph with many loops", "[path_exists]" ) 
		g.add_arc(0, 1);
		g.add_arc(1, 2);
		g.add_arc(1, 3);
		g.add_arc(1, 4);
		g.add_arc(2, 0);
		g.add_arc(3, 0);
		g.add_arc(2, 5);
		g.add_arc(3, 5);
		g.add_arc(4, 5);
		g.add_arc(5, 6);
		g.add_arc(6, 0);
		cout << "true\t" << g.path_exists(0, 0)<<endl;
		cout << "true\t" << g.path_exists(0, 6)<<endl;
		cout << "true\t" << g.path_exists(1, 0)<<endl;
		cout << "true\t" << g.path_exists(2, 0)<<endl;
		cout << "true\t" << g.path_exists(5, 0)<<endl;
		cout << "true\t" << g.path_exists(4, 1)<<endl;
		cout << "true\t" << g.path_exists(2, 4)<<endl;
		break;
	}




	/*g.add_vertex(0);
	g.add_arc(0, 1);
	g.add_arc(1, 2);
	g.add_arc(2, 0);
	
	g.add_vertex(6);
	g.add_vertex(3);
	g.add_arc(6, 2);
	g.add_arc(-2, -1);
	cout << " из 2 в 0\t"<<g.path_exists(g, 2,0) << endl;
	cout << " из 0 в 3\t" << g.path_exists(g, 2, 3) << endl;
	cout << "из 6 в 0\t" << g.path_exists(g, 6, 0) << endl;
	cout << "из -2 в -1" << g.path_exists(g, -2, -1) << endl;
	*/

}