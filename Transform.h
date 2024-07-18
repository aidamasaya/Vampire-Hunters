#pragma once
#include "GameMath.h"

/// <summary>
/// �I�u�W�F�N�g�̏�ԕϐ��N���X��2D��
/// </summary>
struct Transform2D
{
	Vector2 Position;
	Vector2 Rotation;
	Vector2 Size;

	bool Reverse = false;

	Transform2D()
		:Position(0, 0)
		, Rotation(0, 0)
		, Size(0, 0)
	{}
	virtual ~Transform2D()
	{};

	void SetPosition(Vector2 pos) { Position = pos; }
	void SetRotation(Vector2 rot) { Rotation = rot; }
};