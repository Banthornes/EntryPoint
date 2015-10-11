#pragma once

namespace ENG
{
	class Scene;
	class SceneManager
	{
	public:
		static SceneManager& Create();

		virtual Scene& CreateScene(const std::string& name) = 0;
		virtual Scene& GetScene(const std::string& name) = 0;
		virtual void RemoveScene(const std::string& name) = 0;

		virtual int Update() = 0;
	private:
	};
}