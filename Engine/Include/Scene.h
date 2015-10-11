#pragma once

namespace ENG
{
	class SceneNode;
	class Scene
	{
	public:
		static Scene& Create(const std::string& name);

		virtual SceneNode& AddSceneNode(const std::string& name) = 0;
		virtual SceneNode& GetSceneNode(const std::string& name) = 0;
		virtual void RemoveSceneNode(const std::string& name) = 0;

		virtual std::string GetName() const = 0;

		virtual int Update() = 0;
	private:
	};
}