#pragma once
class Entity
{
	float damage;
	float health;
public:
	Entity();
	~Entity();
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
};

