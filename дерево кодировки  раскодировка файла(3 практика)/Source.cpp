#include <iostream>
#include <fstream>
#include "huffman.h"

int main()
{
	std::ifstream fout;
	fout.open("data.txt");
	const auto* tree = buildTree();
	while (!fout.eof())
	{
		std::string input;
		fout >> input;
		std::cout << decode(tree, input) << std::endl;
	}
	fout.close();
	deleteTree(tree);
	return 0;
}