#include "huffman.h"
#include <vector>
#include <exception>
#include <map>
#include <queue>

using HuffmanTable = std::map<char, std::string>;

namespace {

	struct TreeNodeWeightCompare {
		bool operator()(const TreeNode* t1, const TreeNode* t2) const {
			return t1->weight > t2->weight;
		}
	};

	void addToTable(const TreeNode* tree, HuffmanTable& table, const std::string& code) {
		if (!tree) {
			return;
		}
		if (tree->isLeaf()) {
			table[tree->symbol] = code;
			return;
		}
		addToTable(tree->left, table, code + '0');
		addToTable(tree->right, table, code + '1');
	}

	HuffmanTable buildHuffmanTable(const TreeNode* tree) {
		HuffmanTable table;
		addToTable(tree, table, "");
		return table;
	}

}

TreeNode* buildTree() {
	std::priority_queue<TreeNode*, std::vector<TreeNode*>, TreeNodeWeightCompare> nodes;
	for (char c = 'a'; c <= 'z'; c++) {
		nodes.push(new TreeNode(c, 5));
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		nodes.push(new TreeNode(c, 2));
	}
	for (char c : std::string(" \"'0123456789!?@#$%^&*()-+,.~<>`\t\n\r")) {
		nodes.push(new TreeNode(c, 1));
	}
	while (nodes.size() > 1) {
		auto* n1 = nodes.top();
		nodes.pop();
		auto* n2 = nodes.top();
		nodes.pop();
		nodes.push(new TreeNode(0, n1->weight + n2->weight, n1, n2));
	}
	return nodes.top();
}

void deleteTree(const TreeNode* root) {
	if (!root) {
		return;
	}
	if (root->left) {
		deleteTree(root->left);
	}
	if (root->right) {
		deleteTree(root->right);
	}
	delete root;
}

std::string encode(const TreeNode* tree, const std::string& str) {
	const auto table = buildHuffmanTable(tree);
	std::string result = "";
	for (auto c : str) {
		try {
			result += table.at(c);
		}
		catch (const std::exception&) {
			// throw std::logi(std::string("Cannot encode character ") + c);
		}
	}
	return result;
}

std::string decode(const TreeNode* tree, const std::string& code_str) {
	const TreeNode* cursor = tree;
	int cursor_ch = 0;
	std::string result;
	while (true)
	{
		if (cursor_ch < code_str.size())
		{
			if (code_str[cursor_ch] == '0')
			{
				if (cursor->left != nullptr)
				{
					cursor = cursor->left;
					cursor_ch++;
				}
				else
				{
					result += cursor->symbol;
					cursor = tree;
				}
			}
			else if (code_str[cursor_ch] == '1')
			{
				if (cursor->right != nullptr)
				{
					cursor = cursor->right;
					cursor_ch++;
				}
				else
				{
					result += cursor->symbol;
					cursor = tree;
				}
			}
		}
		else
		{
			result += cursor->symbol;
			break;
		}
	}
	return result;
}