#include "stdafx.h"
#include "SceneNode.h"
#include "Scene.h"
#include "SceneManager.h"

using namespace ENG;

class SceneManager_Impl : public SceneManager
{
public: 
	SceneManager_Impl();
	~SceneManager_Impl();

	Scene& CreateScene(const std::string& name) override;
	Scene& GetScene(const std::string& name) override;
	void RemoveScene(const std::string& name) override;

	int Update() override;

private: 
	std::vector<Scene*> m_scenes;
};

SceneManager& ENG::SceneManager::Create()
{
	SceneManager* sceneManager = new SceneManager_Impl();
	return *sceneManager;
}

SceneManager_Impl::SceneManager_Impl()
{
}

SceneManager_Impl::~SceneManager_Impl()
{
}

Scene& SceneManager_Impl::CreateScene(const std::string& name)
{
	for (auto it : m_scenes)
	{
		if (it->GetName() == name)
		{
			return *it;
		}
	}

	Scene* scene = &Scene::Create(name);
	m_scenes.push_back(scene);
	return *scene;
}

Scene & SceneManager_Impl::GetScene(const std::string & name)
{
	Scene* scene = nullptr;
	for (auto it : m_scenes)
	{
		if (it->GetName() == name)
		{
			return *it;
		}
	}

	return *scene;
}

void SceneManager_Impl::RemoveScene(const std::string&/* name*/)
{
}

int SceneManager_Impl::Update()
{
	for (auto it : m_scenes)
	{
		it->Update();
	}

	return 0;
}
