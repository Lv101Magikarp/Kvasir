#ifndef VORCONSTANTS_H
#define VORCONSTANTS_H

typedef enum {NO_COMMAND = -1, NORMAL_PLAY = 0, ALLY_KICKOFF, ENEMY_KICKOFF, FREEKICK, PENALTY} Command;
#define COMMAND_MEMBER_NAMES {"Normal Play", "Ally Kick Off", "Enemy Kick Off", "Free Kick", "Penalty"}
#define N_COMMANDS 5

typedef enum {NO_ROLE = -1, GOALKEEPER = 0, DEFENDER, ATTACKER, SUPPORT} Role;
#define ROLE_MEMBER_NAMES {"Goalkeeper", "Defender", "Attacker", "Support"}
#define N_ROLES 4

typedef enum {LEFT, RIGHT} Side;
#define SIDE LEFT

#define ATTACKER_BALL_OFFSET 0 //60
#define ATTACKER_OFFSET_RANGE 140

#define ADJUST_ANGLE false

#define SPIN_WHEN_CLOSE false

#define FRAMES_TO_SPIN 7

#define SPIN_RANGE 80

#define ANGLE_COMPARE_EPSILON 0.15

#endif //VORCONSTANTS_H
