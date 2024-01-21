#pragma once
#include"jacinemaii.h"
#include "IdGenerator.h"


class ui {
	jacinemaii j;
	IdGenerator idgen;
public:
	ui();
	~ui() { j.write(); }
	void menu();
	void reservation();
	void killer();
	void finder();
	void registeration();
	void leaderboard();

};