#pragma once
#include "Vector2.h"
class Enemy
{public:
	Vector2 pos_;
	float speed_;
	float radius_;
	static bool isAlive_;

public:
	Enemy();//デフォルトコンストラクター
	Enemy(Vector2 pos, float speed, float radius, bool isAlive);
	~Enemy();
	void Move();
	void Draw();
	void Collision(Vector2 pos,float radius);
};

