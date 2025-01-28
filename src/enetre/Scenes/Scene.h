#pragma once
#include "../includes.h"

class Scene
{
	std::vector<Entity*> m_entities;
public:
	template<class T>
	T* GetEntity();
	template<class T>
	void AddEntity();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
};

