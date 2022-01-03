#include "CellView.h"
#include "../Game/Entity/Character/Character.h"
#include "../Game/Entity/Enemies/Mutant.h"
#include "../Game/Entity/Enemies/Ghost.h"
#include "../Game/Entity/Enemies/Troll.h"
#include "../Game/Entity/Items/Heal.h"
#include "../Game/Entity/Items/Damage.h"
#include "../Game/Entity/Items/Protect.h"

CellView::CellView(Cell& obj) : cell(obj) {}
std::ostream& operator<< (std::ostream& out, const CellView& obj) {
	if (obj.cell.getEntity() == nullptr) {
		if (obj.cell.getType() == WALL) { out << "[X]"; }
		if (obj.cell.getType() == START) { out << "[S]"; }
		if (obj.cell.getType() == FINISH) { out << "[F]"; }
		if (obj.cell.getType() == EMPTY) { out << "[_]"; }
	}
	else {
		if (typeid(*obj.cell.getEntity()).name() == typeid(Character).name()) {
			out << "[H]";
		}
		if (typeid(*obj.cell.getEntity()).name() == typeid(Ghost).name()) {
			out << "[G]";
		}
		if (typeid(*obj.cell.getEntity()).name() == typeid(Mutant).name()) {
			out << "[M]";
		}
		if (typeid(*obj.cell.getEntity()).name() == typeid(Troll).name()) {
			out << "[T]";
		}
		if (typeid(*obj.cell.getEntity()).name() == typeid(Heal).name() || typeid(*obj.cell.getEntity()).name() == typeid(Protect).name() || typeid(*obj.cell.getEntity()).name() == typeid(Damage).name()) {
			out << "[P]";
		}
	}
	return out;
}