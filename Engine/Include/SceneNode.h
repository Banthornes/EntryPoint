#pragma once

namespace ENG
{
	class SceneNode
	{
	public:
		static SceneNode& Create(const std::string& name);

		virtual SceneNode& AddSceneNode(const std::string& name) = 0;
		virtual std::string GetName() const = 0;
		virtual int Update() = 0;

	private:
	};
}