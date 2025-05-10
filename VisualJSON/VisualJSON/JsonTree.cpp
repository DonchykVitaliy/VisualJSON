#include "JsonTree.h"

namespace VisualJSON
{

    JsonTree::JsonTree(TreeView^ tree)
    {
        this->treeRef = tree;
        this->nodeCount = 0;
    }
    JsonTree::~JsonTree() {}

    // функції
    void JsonTree::PopulateTree(const Json::Value& jsonData, TreeNode^ parentNode)
    {
        try
        {
            if (jsonData.isObject()) {
                for (const auto& key : jsonData.getMemberNames()) {
                    const Json::Value& value = jsonData[key];
                    TreeNode^ node = gcnew TreeNode(gcnew String(key.c_str()));

                    if (value.isObject() || value.isArray()) {
                        PopulateTree(value, node);
                    }
                    else {
                        node->Text = gcnew String(value.asString().c_str());
                    }

                    parentNode->Nodes->Add(node);
                }
            }
            else if (jsonData.isArray()) {
                for (Json::ArrayIndex i = 0; i < jsonData.size(); ++i) {
                    TreeNode^ node = gcnew TreeNode("Елемент " + i);
                    PopulateTree(jsonData[i], node);
                    parentNode->Nodes->Add(node);
                }
            }
            else {
                parentNode->Text = gcnew String(jsonData.asString().c_str());
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show(ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }


    void JsonTree::Clear()
    {
            treeRef->Nodes->Clear();
    }

    void JsonTree::Close(String^ fileName, String^ filePath, ToolStripStatusLabel^ status, Panel^ map, ToolStripProgressBar^ bar, TextBox^ textBox)
    {
        Clear();
        filePath = "";
        fileName = "";

        textBox->Text = L"Невідомо\r\nНевідомо\r\nНевідомо";
        map->Controls->Clear();
        bar->Value = 0;
        status->Text = L"очікування";
    }

    int JsonTree::GetNodeCount()
    {
        return nodeCount;
    }
}
