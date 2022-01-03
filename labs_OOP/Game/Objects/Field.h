#pragma once
#include "Cell.h"
#include "../Entity/Entity.h"
#include "../Entity/Character/Character.h"
#include "../Entity/Items/Item.h"
#include "../Entity/Enemies/Mutant.h"
#include "../Entity/Enemies/Ghost.h"
#include "../Entity/Enemies/Troll.h"
#include "../Command/ControlsCommand.h"
#include <vector>

class Field {
private:
	int width;
	int height;
	Cell* enter = nullptr;
	Cell* exit = nullptr;
	Cell* hero = nullptr;
	Cell** board;
	int enemy_count;
	int countEnemiesDied;

public:
	std::vector <Cell*> enemies;
	Field();
	Cell* getEnter() const;
	Cell* getExit() const;
	Cell* getHero() const;
	Cell& getboard(int i, int j) const;
	Cell* getenemi(int i) const;
	std::vector<Cell*> getenemies() const;
	int get_index_change_enemy() const;
	int getStartEnemyCount();
	int getWidth() const;
	int getHeight() const;
	int getEnemyIndex(Cell* obj) const;
	int getCountEnemiesDied() const;
	bool HeroWin() const;
	void setEnter(Cell* obj);
	void setExit(Cell* obj);
	void setHero(Cell* obj);
	void setWidth(int value);
	void setHeight(int value);
	void start_finish_generate();
	void spawn_hero();
	void spawn_walls();
	void generate_enemies();
	void generate_items();
	void moveEntity(Cell cell, COMMANDS command, int enemy_Number = 0);
	Field(int user_width, int user_height);
	//конструктор копирования
	Field(const Field& obj);
	Field& operator=(const Field& obj);
	//конструктор перемещения
	Field(Field&& obj);
	Field& operator=(Field&& obj);
	~Field();
};