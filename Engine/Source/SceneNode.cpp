#include "stdafx.h"
#include "SceneNode.h"

using namespace ENG;

class SceneNode_Impl : public SceneNode
{
public:
	SceneNode_Impl(const std::string& name);
	~SceneNode_Impl();

	std::string GetName() const override;

	SceneNode& AddSceneNode(const std::string& name) override;

	int Update() override;

private:
	std::string m_name;

	std::vector<SceneNode*> m_sceneNodes;
};

SceneNode& ENG::SceneNode::Create(const std::string& name)
{
	SceneNode* sceneNode = new SceneNode_Impl(name);
	return *sceneNode;
}

SceneNode_Impl::SceneNode_Impl(const std::string& name)
	: m_name(name)
{
}

SceneNode_Impl::~SceneNode_Impl()
{
}

std::string SceneNode_Impl::GetName() const
{
	return m_name;
}

SceneNode& SceneNode_Impl::AddSceneNode(const std::string& name)
{
	for (auto it : m_sceneNodes)
	{
		if (it->GetName() == name)
		{
			return *it;
		}
	}

	SceneNode* sceneNode = &SceneNode::Create(name);
	m_sceneNodes.push_back(sceneNode);
	return *sceneNode;
}

int SceneNode_Impl::Update()
{
	std::cout << "Update " << m_name << std::endl;

	for (auto it : m_sceneNodes)
	{
		it->Update();
	}

	return 0;
}
