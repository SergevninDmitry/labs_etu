#pragma once
#include "Objects/Field.h"
#include "../Logs/LoggerPull.h"
#include "../UI/FieldView.h"
#include "../Rules/Rule_enemies_died.h"
#include "../Rules/Rule_step.h"
#include "GameStats.h"
#include "Command/ControlsCommand.h"
#include "Snapshot.h"
#include "Loader.h"


template<class... WinChecker>
class Game {
private:
	bool quit = false;  // флаг для выхода из игры
	int countEnemiesDied = 0;
	bool isWinner = false;
	bool isLive = true;
	GameStats gameStats;
protected:
	void EndGame();
	void is_Game_End(WinChecker... winChecker);
public:
	Field* modelField;
	FieldView* field;
	LoggerPull* logger;
	void StartGame();
};

template<class... WinChecker>
void Game<WinChecker...>::is_Game_End(WinChecker... winChecker) {
	if ((winChecker.Check(gameStats) && ...) && isWinner && isLive) {  // Если умерли все враги, то игра завершается winChecker.EnemiesDiedChecker() isWinner????
		EndGame();
	}
}

template<class... WinChecker>
void Game<WinChecker...>::EndGame() {// необходимо изменить
	this->quit = true;
}


template<class... WinChecker>
void Game<WinChecker...>::StartGame() {
	char dir;
	int user_height, user_width, iter, mode, flag = 0, enemy_check = -1;
	std::cout << "Enter the dimensions for the field.\nWidth = ";
	std::cin >> user_height;
	std::cout << "\nHeight = ";
	std::cin >> user_width;
	std::cout << '\n';
	std::cout << "Where should the logs be output? 0 - console, 1 - file, 2 - file and console, do not output - any other number:";
	std::cin >> mode;
	std::cout << '\n';
	Snapshot saver;
	Loader loader;
	Field* modelField = new Field(user_width, user_height);
	FieldView* field = new FieldView(*modelField);
	Commander commander;
	/*std::cout << "Want to customize a key control? No - enter 0, yes - enter 1:";
	std::cin >> flag;
	if (flag == 1) {
		std::cout << "\nEnter direction up:";
		std::cin >> dir;
		(*commander.get_controls()).set_up(dir);
		std::cout << "\nEnter direction down:";
		std::cin >> dir;
		(*commander.get_controls()).set_down(dir);
		std::cout << "\nEnter direction left:";
		std::cin >> dir;
		(*commander.get_controls()).set_left(dir);
		std::cout << "\nEnter direction right:";
		std::cin >> dir;
		(*commander.get_controls()).set_right(dir);
	}*/
	iter = 0;
	(*field).print();
	LoggerPull* logger = new LoggerPull(mode, (*modelField).getHero()->getEntity(), (*modelField).enemies);
	while (!this->quit){ //проверка на конец игры в rules
		COMMANDS cur_com = commander.determinate_the_command();
		if (cur_com != NONE) {
			(*modelField).moveEntity(*(*modelField).getHero(), cur_com);
			gameStats.setStepsMade();
			if (cur_com == SAVE) {
				std::cout << "Where to save? Enter the file name in the format <filename>.txt\n";
				std::string filename;
				std::cin >> filename;
				saver.save_to_file(&(*modelField), filename, mode);
			}
			if (cur_com == LOAD) {
				std::cout << "Where to download? Enter the file name in the format <filename>.txt\n";
				std::string filename;
				std::cin >> filename;
				if (loader.try_load(saver, filename)) {
					delete modelField;
					modelField = loader.load_from_file(filename);
					field = new FieldView(*modelField);
					logger = new LoggerPull(mode, (*modelField).getHero()->getEntity(), (*modelField).enemies);
				}
			}
			//движение врагов
			for (int i = 0; i < (*modelField).getenemies().size(); i++) {
				if (typeid(*((*(*modelField).getenemi(i)).getEntity())).name() == typeid(Mutant).name()) {
					(dynamic_cast<Mutant&>(*(*modelField).getenemi(i)->getEntity())).change_dir(iter);
				}
				if (typeid(*((*(*modelField).getenemi(i)).getEntity())).name() == typeid(Ghost).name()) {
					(dynamic_cast<Ghost&>(*(*modelField).getenemi(i)->getEntity())).change_dir(iter);
				}
				if (typeid(*((*(*modelField).getenemi(i)).getEntity())).name() == typeid(Troll).name()) {
					(dynamic_cast<Troll&>(*(*modelField).getenemi(i)->getEntity())).change_dir(iter);
				}
				(*modelField).moveEntity(*(*modelField).getenemi(i), (dynamic_cast<Enemy&>(*(*modelField).getenemi(i)->getEntity())).getDirection(), i);
			}

			// для логгера
			if (dynamic_cast<Character&>(*(*modelField).getHero()->getEntity()).getHealth() != (*(*logger).mainLogger).hero_stats[0] || dynamic_cast<Character&>(*(*modelField).getHero()->getEntity()).getAttack() != (*(*logger).mainLogger).hero_stats[1] || dynamic_cast<Character&>(*(*modelField).getHero()->getEntity()).getArmor() != (*(*logger).mainLogger).hero_stats[2]) {
				(*logger).writeHero();//логгер вызывается при изменении характеристик героя
				(*(*logger).mainLogger).clone_Character();
			}

			// попытка изменить логгер
			// if (enemy_check != modelField.get_index_change_enemy()) {
			//	logger.writeEnemy(modelField.getenemi(modelField.get_index_change_enemy())->getEntity());//логгер вызывается при изменении характеристик врагов
			//	(*logger.mainLogger).clone_Enemy(modelField.getenemi(modelField.get_index_change_enemy())->getEntity());
			//	enemy_check = modelField.get_index_change_enemy();
			//	if (modelField.del_enemy == 1) {
			//		logger.writeEnemy(modelField.tmp->getEntity());//логгер вызывается при изменении характеристик врагов
			//		(*logger.mainLogger).clone_Enemy(modelField.tmp->getEntity());
			//	}
			//	 в мувэнтити/ оповещать логгер об изменении какого-либо врага
			//}

			for (int i = 0; i < (*modelField).getenemies().size(); i++) {
				if (dynamic_cast<Enemy&>(*(*modelField).getenemi(i)->getEntity()).getHealth() != (*(*logger).mainLogger).enemy_stats[(*modelField).getenemi(i)->getEntity()][0]) {
					(*logger).writeEnemy((*modelField).getenemi(i)->getEntity());//логгер вызывается при изменении характеристик врагов
					(*(*logger).mainLogger).clone_Enemy((*modelField).getenemi(i)->getEntity());
					// в мувэнтити/ оповещать логгер об изменении какого-либо врага
				}
			}
		}
		//std::cout << "steps: " << gameStats.getStepsMade() << "\n";
		countEnemiesDied = (*modelField).getCountEnemiesDied();
		gameStats.setEnemyKilled(countEnemiesDied);
		isWinner = (*modelField).HeroWin();
		Rule_enemies_died<1> rule_enemies_died;
		Rule_step<1> rule_step;
		is_Game_End(rule_enemies_died, rule_step);
		iter++;
		field->print();
		if (dynamic_cast<Character&>(*(*modelField).getHero()->getEntity()).getHealth() <= 0){
			isLive = false;
			std::cout << "Your hero died :(\n";
			quit = true;
		}
	}
}