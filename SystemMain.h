#pragma once

class SystemMain
{
public:
	SystemMain() = default;
	~SystemMain() = default;
	bool Initialize() const;
	void Finalize() const;
	void Main() const;
};