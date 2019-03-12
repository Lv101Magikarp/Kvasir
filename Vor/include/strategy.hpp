#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "vorconstants.h"
#include "aifieldhandler.hpp"

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include <smmclib.hpp>

class Strategy
{
private:
    AIFieldHandler &ai_field_handler;

    Command command = NORMAL_PLAY;

    Entity ball;

    Player robot[N_ROBOTS];
    Role role[N_ROBOTS];
    int frames_close[N_ROBOTS];

    Entity enemy_robot[N_ROBOTS];

    Coord pf_ulc;
    Coord pf_lrc;

    Coord lg_ulc;
    Coord lg_lrc;
    Coord rg_ulc;
    Coord rg_lrc;

    Coord lga_ulc;
    Coord lga_lrc;
    Coord rga_ulc;
    Coord rga_lrc;

    int manual_robot;

    static Coord compared_object_coord;

    void assignRoles(void);

    void normalPlay(void);
    void allyKickOff(void);
    void enemyKickOff(void);
    void freeKick(void);
    void penalty(void);
    void manualControl(void);

    void moveGoalkeeper(int n);
    void moveDefender(int n);
    void moveAttacker(int n);
    void moveSupport(int n);

    void calculateMovementsFromDestinations(void);

    double normalizeAngle(double angle);
    bool angleCompare(double angle1, double angle2, double epsilon);
    void moveStraight(double angle);

public:
    Strategy(AIFieldHandler &afh);
    ~Strategy();

    void makeCommandList(void);
    void makeManualCommandList(void);
    void calculateMovements(void);

    static bool comparePlayerDistance(Player p1, Player p2);
};

#endif // STRATEGY_HPP
