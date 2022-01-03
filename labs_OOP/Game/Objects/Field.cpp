#include "Field.h"

Field::Field() {
	width = 0;
	height = 0;
	board = nullptr;
	enter = nullptr;
	exit = nullptr;
	enemy_count = 0;
	countEnemiesDied = 0;
}


int Field::getStartEnemyCount() { return enemy_count; }
Cell* Field::getEnter() const { return enter; }
Cell* Field::getExit() const { return exit; }
Cell* Field::getHero() const { return hero; }
int Field::getWidth() const { return width; }
int Field::getHeight() const { return height; }
int Field::getCountEnemiesDied() const {
	return countEnemiesDied;
}

bool Field::HeroWin() const {
	if (board[hero->getposX()][hero->getposY()].getType() == FINISH) {
		return true;
	}
	else {
		return false;
	}
}
Cell* Field::getenemi(int i) const { return enemies[i]; }
Cell& Field::getboard(int i, int j) const { return this->board[i][j]; }
std::vector<Cell*> Field::getenemies() const {
	return enemies;
}
int Field::getEnemyIndex(Cell* obj) const {
	for (int i = 0; i < enemies.size(); i++) {
		if (obj == enemies[i]) {
			return i;
		}
	}
	return -1;
}
//int Field::get_index_change_enemy() const {
//	return this->index_change_enemy;
//}
void Field::setEnter(Cell* obj) { enter = obj; }
void Field::setExit(Cell* obj) { exit = obj; }
void Field::setHero(Cell* obj) { hero = obj; }
void Field::setWidth(int value) { width = value; }
void Field::setHeight(int value) { height = value; }
void Field::start_finish_generate() {
	int enter_coords[2] = { 0, 0 };
	int exit_coords[2] = { 0, 0 };
	enter_coords[0] = std::rand() % this->width;
	enter_coords[1] = std::rand() % this->height;
	int check = 1, x_cord, y_cord;
	while (check == 1) {
		x_cord = std::rand() % width;
		y_cord = std::rand() % height;
		if (x_cord == enter_coords[0] && ((y_cord != enter_coords[1]) && (y_cord != enter_coords[1] - 1) && (y_cord != enter_coords[1] + 1))) {
			check = 0;
		}
		else {
			if (y_cord == enter_coords[1] && ((x_cord != enter_coords[0]) && (x_cord != enter_coords[0] - 1) && (x_cord != enter_coords[0] + 1))) {
				check = 0;
			}
			else {
				if (y_cord != enter_coords[1] && x_cord != enter_coords[0]) {
					check = 0;
				}
			}
		}
	}
	exit_coords[0] = x_cord;
	exit_coords[1] = y_cord;
	this->board[enter_coords[0]][enter_coords[1]].setType(START);
	this->board[exit_coords[0]][exit_coords[1]].setType(FINISH);
	this->enter = &board[enter_coords[0]][enter_coords[1]];
	this->exit = &board[exit_coords[0]][exit_coords[1]];
}
void Field::spawn_hero() {
	Character* Hero = new Character;
	this->board[enter->getposX()][enter->getposY()].setEntity(Hero);
	this->hero = &board[enter->getposX()][enter->getposY()];
}
void Field::spawn_walls() {
	int status;
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			status = std::rand() % 2;
			if (status == 1) {
				this->board[i][j] = Cell(i, j, EMPTY);
			}
			else {
				this->board[i][j] = Cell(i, j, EMPTY); //временное решение без стен, изменить на WALL, для рандомной генерации
			}
		}
	}
}
void Field::generate_enemies() {
	int totalCells = this->height * this->width;
	for (int i = 0; i < ((totalCells / 20) + 1); i++) {
		//временное решение, пока нет норм генерации стен
		bool check = 1;
		int x_cord, y_cord;
		while (check == 1) {
			x_cord = std::rand() % width;
			y_cord = std::rand() % height;
			if (this->board[x_cord][y_cord].getType() == EMPTY && this->board[x_cord][y_cord].getEntity() == nullptr) {
				if ((i % 3) == 0) {
					Mutant* enemy = new Mutant;
					this->board[x_cord][y_cord].setEntity(enemy);
				}
				if ((i % 3) == 1) {
					Ghost* enemy = new Ghost;
					this->board[x_cord][y_cord].setEntity(enemy);
				}
				if ((i % 3) == 2) {
					Troll* enemy = new Troll;
					this->board[x_cord][y_cord].setEntity(enemy);
				}
				this->enemies.push_back(&this->board[x_cord][y_cord]);
				check = 0;
			}
		}
	}
	enemy_count = enemies.size();
}
void Field::generate_items() {
	int totalCells = this->height * this->width;
	for (int i = 0; i < ((totalCells / 15) + 1); i++) {
		//временное решение, пока нет норм генерации стен
		bool check = 1;
		int x_cord, y_cord;
		while (check == 1) {
			x_cord = std::rand() % width;
			y_cord = std::rand() % height;
			if (this->board[x_cord][y_cord].getType() == EMPTY && this->board[x_cord][y_cord].getEntity() == nullptr) {
				if ((i % 3) == 0) {
					Heal* potion = new Heal;
					this->board[x_cord][y_cord].setEntity(potion);
				}
				if ((i % 3) == 1) {
					Protect* potion = new Protect;
					this->board[x_cord][y_cord].setEntity(potion);
				}
				if ((i % 3) == 2) {
					Damage* potion = new Damage;
					this->board[x_cord][y_cord].setEntity(potion);
				}
				check = 0;
			}
		}
	}
}
void Field::moveEntity(Cell cell, COMMANDS direction, int enemy_Number) {
	int x = 0;
	int y = 0;
	bool flag = false;
	if (direction == UP && cell.getposX() != 0) {
		x = cell.getposX() - 1;
		y = cell.getposY();
		flag = true;
	}
	if (direction == DOWN && cell.getposX() != width - 1) {
		x = cell.getposX() + 1;
		y = cell.getposY();
		flag = true;
	}
	if (direction == LEFT && cell.getposY() != 0) {
		x = cell.getposX();
		y = cell.getposY() - 1;
		flag = true;
	}
	if (direction == RIGHT && cell.getposY() != height - 1) {
		x = cell.getposX();
		y = cell.getposY() + 1;
		flag = true;
	}
	if (flag) {
		if (cell.getEntity() != nullptr) {
			if ((typeid((*cell.getEntity())).name() == typeid(Character).name())) {
				if (board[x][y].getEntity() != nullptr) {
					if (typeid(*board[x][y].getEntity()).name() != typeid(Mutant).name() && typeid(*board[x][y].getEntity()).name() != typeid(Ghost).name() && typeid(*board[x][y].getEntity()).name() != typeid(Troll).name()) { // попробовать изменить на enemy
						if (typeid(*board[x][y].getEntity()).name() == typeid(Heal).name() || typeid(*board[x][y].getEntity()).name() == typeid(Protect).name() || typeid(*board[x][y].getEntity()).name() == typeid(Damage).name()) {
							(dynamic_cast<Character&>(*hero->getEntity())).takeItem(board[x][y].getEntity());
							delete board[x][y].getEntity();
						}
						board[x][y].setEntity(cell.getEntity());
						board[cell.getposX()][cell.getposY()].setEntity(nullptr);
						hero = &board[x][y];
					}
					else {
						(dynamic_cast<Character&>(*hero->getEntity())).fight(board[x][y].getEntity());
						(dynamic_cast<Enemy&>(*board[x][y].getEntity())).fight(hero->getEntity());
						//index_change_enemy = getEnemyIndex(&board[x][y]); // индекс измененного врага для логгера
						if ((dynamic_cast<Enemy&>(*board[x][y].getEntity())).getHealth() <= 0) {
							int iter = getEnemyIndex(&board[x][y]);
							enemies.erase(enemies.cbegin() + iter);
							countEnemiesDied++;
							delete (board[x][y].getEntity());
							board[x][y].setEntity(cell.getEntity());
							board[cell.getposX()][cell.getposY()].setEntity(nullptr);
							hero = &board[x][y];
						}
					}
				}
				else {
					board[x][y].setEntity(cell.getEntity());
					board[cell.getposX()][cell.getposY()].setEntity(nullptr);
					hero = &board[x][y];
				}
			}
			else {
				if (board[x][y].getEntity() != nullptr) {
					if (typeid(*board[x][y].getEntity()).name() != typeid(Character).name() && typeid(*board[x][y].getEntity()).name() != typeid(Mutant).name() && typeid(*board[x][y].getEntity()).name() != typeid(Ghost).name() && typeid(*board[x][y].getEntity()).name() != typeid(Troll).name()) {
						if (typeid(*board[x][y].getEntity()).name() == typeid(Heal).name() || typeid(*board[x][y].getEntity()).name() == typeid(Damage).name() || typeid(*board[x][y].getEntity()).name() == typeid(Protect).name()) {
							delete board[x][y].getEntity();
						}
						board[x][y].setEntity(cell.getEntity());
						board[cell.getposX()][cell.getposY()].setEntity(nullptr);
						enemies[enemy_Number] = &board[x][y];
					}
				}
				else {
					board[x][y].setEntity(cell.getEntity());
					board[cell.getposX()][cell.getposY()].setEntity(nullptr);
					enemies[enemy_Number] = &board[x][y];
				}
			}
		}
	}
}
Field::Field(int user_width, int user_height) {
	this->width = std::min(30, std::max(2, user_width));
	this->height = std::min(30, std::max(2, user_height));
	board = new Cell * [width];
	for (int i = 0; i < width; i++) {
		board[i] = new Cell[height];
	}
	spawn_walls();
	start_finish_generate();
	spawn_hero();
	generate_enemies();
	generate_items();
}
//конструктор копирования
Field::Field(const Field& obj) {
	this->width = obj.width;
	this->height = obj.height;
	this->enter = obj.enter;
	this->exit = obj.exit;
	this->hero = obj.hero;
	this->enemy_count = obj.enemy_count;
	this->countEnemiesDied = obj.countEnemiesDied;
	for (int i = 0; i < obj.enemies.size(); i++) {
		this->enemies.push_back(obj.enemies[i]);
	}
	board = new Cell * [width];
	for (int i = 0; i < width; i++) {
		board[i] = new Cell[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			board[i][j] = Cell(i, j, obj.board[i][j].getType());
			board[i][j].setEntity(obj.board[i][j].getEntity());
		}
	}
}
Field& Field::operator=(const Field& obj) {
	if (this != &obj) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				if (board[i][j].getEntity() != nullptr) {
					delete (board[i][j].getEntity());
				}
			}
		}
		for (int i = 0; i < width; i++) {
			delete[] board[i];
		}
		delete[] board;
		this->width = obj.width;
		this->height = obj.height;
		this->enter = obj.enter;
		this->exit = obj.exit;
		this->hero = obj.hero;
		this->enemy_count = obj.enemy_count;
		this->countEnemiesDied = obj.countEnemiesDied;
		for (int i = 0; i < obj.enemies.size(); i++) {
			this->enemies.push_back(obj.enemies[i]);
		}
		board = new Cell * [width];
		for (int i = 0; i < width; i++) {
			board[i] = new Cell[height];
		}
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				board[i][j] = Cell(i, j, obj.board[i][j].getType());
				board[i][j].setEntity(obj.board[i][j].getEntity());
			}
		}
	}
	return *this;
}
Field::Field(Field&& obj) {
	std::swap(board, obj.board);
	std::swap(width, obj.width);
	std::swap(height, obj.height);
	std::swap(enter, obj.enter);
	std::swap(exit, obj.exit);
	std::swap(hero, obj.hero);
	std::swap(enemy_count, obj.enemy_count);
	std::swap(countEnemiesDied, obj.countEnemiesDied);
	std::swap(enemies, obj.enemies);
}
Field& Field::operator=(Field&& obj) {
	if (this != &obj) {
		std::swap(board, obj.board);
		std::swap(width, obj.width);
		std::swap(height, obj.height);
		std::swap(enter, obj.enter);
		std::swap(exit, obj.exit);
		std::swap(hero, obj.hero);
		std::swap(enemy_count, obj.enemy_count);
		std::swap(countEnemiesDied, obj.countEnemiesDied);
		std::swap(enemies, obj.enemies);
	}
	return *this;
}
Field::~Field() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (board[i][j].getEntity() != nullptr) {
				delete (board[i][j].getEntity());
			}
		}
	}
	for (int i = 0; i < width; i++) {
		delete[] board[i];
	}
	delete[] board;
	//delete tmp;
}
