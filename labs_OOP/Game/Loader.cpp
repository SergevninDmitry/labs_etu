#include "Loader.h"



bool Loader::try_load(Snapshot saver, std::string filename) {
	std::ifstream filetest(filename);
	if (filetest.fail() == true) {
		std::cout << "The file does not exist or is broken, cannot be loaded\n";
		return 0;
	}
	std::ifstream file;
	file.open("hash" + filename);
	if (file.fail() == true) {
		std::cout << "The file does not exist or is broken, cannot be loaded\n";
		return 0;
	}
	int hash2;
	file >> hash2;
	file.close();
	int hash1 = saver.hash_func_ret(filename);
	if (hash1 == hash2) {
		return 1;
	}
	else {
		std::cout << "The file does not exist or is broken, cannot be loaded\n";
		return 0;
	}
}


Field* Loader::load_from_file(std::string filename) {
	std::ifstream file;
	file.open(filename);
	int width, height, enemyCount, y, x, tmp;
	STATE dir;
	std::string skip;
	file >> skip;
	file >> width;
	file >> skip;
	file >> height;
	Field* saveModel = new Field(width, height);
	file >> skip;
	file >> enemyCount;
	(*saveModel).enemies.clear();
	for (int i = 0; i < (*saveModel).getWidth(); i++) {
		for (int j = 0; j < (*saveModel).getHeight(); j++) {
			file >> skip;
			file >> skip;
			if (skip == "0") { dir = EMPTY; }
			if (skip == "1") { dir = WALL; }
			if (skip == "2") { dir = START; }
			if (skip == "3") { dir = FINISH; }
			(*saveModel).getboard(i, j) = Cell(i, j, dir);
			file >> skip;
			file >> skip;
			if (skip == "Heal") {
				Heal* potion = new Heal;
				(*saveModel).getboard(i, j).setEntity(potion);
			}
			if (skip == "Protect") {
				Protect* potion = new Protect;
				(*saveModel).getboard(i, j).setEntity(potion);
			}
			if (skip == "Damage") {
				Damage* potion = new Damage;
				(*saveModel).getboard(i, j).setEntity(potion);
			}
		}
	}
	file >> skip;
	file >> y;
	file >> skip;
	file >> x;
	Character* Hero = new Character;
	(*saveModel).getboard(x, y).setEntity(Hero);
	(*saveModel).setHero(&(*saveModel).getboard(x, y));
	file >> skip;
	file >> tmp;
	dynamic_cast<Character*>((*saveModel).getHero()->getEntity())->setHealth(tmp);
	file >> skip;
	file >> tmp;
	dynamic_cast<Character*>((*saveModel).getHero()->getEntity())->setAttack(tmp);
	file >> skip;
	file >> tmp;
	dynamic_cast<Character*>((*saveModel).getHero()->getEntity())->setArmor(tmp);
	for (int i = 0; i < enemyCount; i++) {
		std::string type;
		COMMANDS dir;
		int hp;
		file >> skip;
		file >> type;
		file >> skip;
		file >> y;
		file >> skip;
		file >> x;
		file >> skip;
		file >> hp;
		file >> skip;
		file >> skip;
		if (skip == "0") { dir = UP; }
		if (skip == "1") { dir = DOWN; }
		if (skip == "2") { dir = RIGHT; }
		if (skip == "3") { dir = LEFT; }
		if (type == "Ghost") {
			Ghost* temp = new Ghost();
			temp->setHealth(hp);
			temp->setDirection(dir);
			(*saveModel).getboard(x, y).setEntity(temp);
			(*saveModel).enemies.push_back(&(*saveModel).getboard(x, y));
		}
		if (type == "Mutant") {
			Mutant* temp = new Mutant();
			temp->setHealth(hp);
			temp->setDirection(dir);
			(*saveModel).getboard(x, y).setEntity(temp);
			(*saveModel).enemies.push_back(&(*saveModel).getboard(x, y));
		}
		if (type == "Troll") {
			Troll* temp = new Troll();
			temp->setHealth(hp);
			temp->setDirection(dir);
			(*saveModel).getboard(x, y).setEntity(temp);
			(*saveModel).enemies.push_back(&(*saveModel).getboard(x, y));
		}
	}
	file.close();
	return saveModel;
}