#include "stdafx.h"
#include "SceneNode.h"
#include "Scene.h"

using namespace ENG;

class Scene_Impl : public Scene
{
public:
	Scene_Impl(const std::string& name);
	~Scene_Impl();

	SceneNode& AddSceneNode(const std::string& name) override;
	SceneNode& GetSceneNode(const std::string& name) override;
	void RemoveSceneNode(const std::string& name) override;

	std::string GetName() const override;

	int Update() override;

private: 
	std::string m_name;

	std::vector<SceneNode*> m_sceneNodes;
};

Scene& ENG::Scene::Create(const std::string& name)
{
	Scene* scene = new Scene_Impl(name);
	return *scene;
}

Scene_Impl::Scene_Impl(const std::string& name)
	: m_name(name)
{
}

Scene_Impl::~Scene_Impl()
{
}

SceneNode& Scene_Impl::AddSceneNode(const std::string& name)
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

SceneNode& Scene_Impl::GetSceneNode(const std::string & name)
{
	SceneNode* sceneNode = nullptr;
	for (auto it : m_sceneNodes)
	{
		if (it->GetName() == name)
		{
			return *it;
		}
	}

	return *sceneNode;
}

void Scene_Impl::RemoveSceneNode(const std::string&/* name*/)
{
}

std::string Scene_Impl::GetName() const
{
	return m_name;
}

int Scene_Impl::Update()
{
	std::cout << "Update " << m_name << std::endl;

	for (auto it : m_sceneNodes)
	{
		it->Update();
	}

	return 0;
}
