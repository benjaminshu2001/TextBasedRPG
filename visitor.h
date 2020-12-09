#ifndef __VISITOR_H__
#define __VISITOR_H__

class Visitor {
    private:
        int equips = 0;
        int armors = 0;
        int weapons = 0;

    public:
        Visitor() { };
        void visit_equip() {
            equips++;
        }
        int equip_count() {
            return equips;
        }
        void visit_armor() {
            armors++;
        }
        int armor_count() {
            return armors;
        }
        void visit_weapon() {
            weapons++;
        }
        int weapon_count() {
            return weapons;
        }
        void reset_equip() {
            equips = 0;
        }
        void reset_weapon() {
            weapons = 0;
        }
        void reset_armor() {
            armors = 0;
        }
};
#endif
