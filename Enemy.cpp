#include "Enemy.h"
#include "Novice.h"
#include <cmath>

Enemy::Enemy()
{
}

Enemy::Enemy(Vector2 pos, float speed, float radius, bool isAlive)
{
	pos_ = pos;
	speed_ = speed;
	radius_ = radius;
	isAlive_ = isAlive;
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
	if (isAlive_) {
		pos_.x += speed_;
		if (pos_.x + radius_ > 1280 || pos_.x - radius_ < 0) {
			speed_ *= -1;
		}
	}
}

void Enemy::Draw()
{
	if (isAlive_) {
		Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, RED, kFillModeSolid);
	}
}

void Enemy::Collision(Vector2 pos, float radius)
{
	if (isAlive_) {
		float distance = float(std::sqrt(std::pow(pos.x - pos_.x, 2) + std::pow(pos.y - pos_.y, 2)));
		if (distance < (radius_ + radius)) {
			isAlive_ = false;
		}
	}
}