#pragma once
class Entity
{
	float damage;
	float health;
public:
	Entity();
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
};

