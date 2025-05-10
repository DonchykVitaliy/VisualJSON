#pragma once
#include "include/json/json.h"

namespace VisualJSON {
	using namespace System::Windows::Forms;
	using namespace System;


	public ref class JsonTree
	{
	private:
		int nodeCount;
		TreeView^ treeRef;

	public:
		JsonTree(TreeView^ tree);
		~JsonTree();

		void PopulateTree(const Json::Value& jsonData, TreeNode^ parentNode);
		void Clear();
		void Close(String^ fileName, String^ filePath, ToolStripStatusLabel^ status, Panel^ map, ToolStripProgressBar^ bar, TextBox^ textBox);
		int GetNodeCount();
	};
}