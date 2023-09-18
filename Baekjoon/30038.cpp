#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef struct {
    int attackPower;
    int attackRange;
    int moveSpeed;
    int demandExp;
    int currentExp;
    int level;
} Player;

typedef struct {
    int health;
    int defense;
    int exp;
} Monster;

enum MOVE {
    r,
    l,
    d,
    u,
};

bool isClear = false;

int N, M, K, S;
int eatPillCnt = 0;
bool isOVERDOSE = false;

int actionCnt = 0;
int actionCntAfterOVERDOSE = 0;

char map[52][52];
int monsterMap[52][52];
typedef std::pair<int, int> pos;

pos playerPos, goalPos;
std::vector<pos> monsterPosList;
std::vector<Monster> monsterInfoList;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

Player player = {5, 1, 1, 10, 0, 1};

void levelUp() {
    player.attackPower += player.level;
    player.attackRange += 1;
    player.demandExp += 10;
    player.level += 1;
}

void checkPlayerExp() {
    while (player.currentExp >= player.demandExp) {
        player.currentExp -= player.demandExp;
        levelUp();
    }
}

void printMap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}

void printMonsterInfo(int monsterIdx) {
    Monster monster = monsterInfoList[monsterIdx];
    std::cout << monster.health << std::endl;
}

void printGameResult() {
    std::cout << player.level << " " << player.currentExp << std::endl;
    std::cout << actionCnt << std::endl;

    printMap();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'm') {
                printMonsterInfo(monsterMap[i][j]);
            }
        }
    }
}

void updateMap(pos pos, char info) {
    map[pos.first][pos.second] = info;
}

void updateActionCnt(int point) {
    actionCnt += point;
    if (isOVERDOSE) {
        if (actionCnt - actionCntAfterOVERDOSE >= 10) {
            isOVERDOSE = false;
        }
    } else {
        if (eatPillCnt == 5) {
            isOVERDOSE = true;
            eatPillCnt = 0;
            actionCntAfterOVERDOSE = actionCnt;
        }
    }
}

void updatePlayerPos(pos newPos) {
    if (newPos.first < 0 || newPos.first >= N || newPos.second < 0 || newPos.second >= M)
        return;
    if (map[newPos.first][newPos.second] == 'm' ||
        map[newPos.first][newPos.second] == '*')
        return;

    updateMap(playerPos, '.');
    playerPos = newPos;
    updateMap(playerPos, 'p');
    updateActionCnt(1);
}

bool isPlayer(pos pos) {
    return (map[pos.first][pos.second] == 'p');
}

bool isMonster(pos pos) {
    return (map[pos.first][pos.second] == 'm');
}

bool isObstacle(pos pos) {
    return (map[pos.first][pos.second] == '*');
}

bool isGoal(pos pos) {
    return (map[pos.first][pos.second] == 'g');
}

void playerAttack(MOVE move) {
    pos actionPos = playerPos;
    int playerAttackRange = player.attackRange;
    
    while (playerAttackRange--) {
        actionPos.first += dx[move];
        actionPos.second += dy[move];
        if (isObstacle(actionPos))
            break;
        if (isMonster(actionPos)) {
            int monsterIdx = monsterMap[actionPos.first][actionPos.second];
            Monster &monster = monsterInfoList[monsterIdx];

            int damage = player.attackPower - monster.defense;
            if (damage >= 0) {
                monster.health -= damage;
                if (monster.health <= 0) {
                    updateMap(actionPos, '.');
                    player.currentExp += monster.exp;
                }
            }
        }
    }
    updateActionCnt(3);
}

void eatPill(int speed) {
    eatPillCnt++;
    player.moveSpeed += speed;
    player.moveSpeed = std::max(0, player.moveSpeed);
    updateActionCnt(2);
}

int main() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 'g')
                goalPos = std::make_pair(i, j);
            if (map[i][j] == 'p')
                playerPos = std::make_pair(i, j);
            if (map[i][j] == 'm') {
                monsterPosList.push_back(std::make_pair(i, j));
                monsterMap[i][j] = monsterPosList.size() - 1;
            }
        }
    }

    std::cin >> K;
    Monster monster;
    for (int i = 0; i < K; i++) {
        monsterInfoList.push_back(monster);
    }

    for (int i = 0; i < K; i++) {
        std::cin >> monsterInfoList[i].health;
    }
    for (int i = 0; i < K; i++) {
        std::cin >> monsterInfoList[i].defense;
    }
    for (int i = 0; i < K; i++) {
        std::cin >> monsterInfoList[i].exp;
    }

    std::cin >> S;
    std::string action;
    bool isClear = false;
    for (int i = 0; i < S; i++) {
        std::cin >> action;
        // std::cout << "action : " << action << std::endl;
        if (isClear)
            continue;
        if (action.length() == 1) {
            if (action[0] == 'w') {
                updateActionCnt(1);
            }
            else if (action[0] == 'c' && !isOVERDOSE) {
                if (playerPos.first == goalPos.first && 
                    playerPos.second == goalPos.second) {
                    updateMap(goalPos, 'p');
                    isClear = true;
                    continue;
                }
            }
            else { // move
                if (action[0] == 'u') {
                    int newX = playerPos.first + dx[MOVE::u] * player.moveSpeed;
                    int newY = playerPos.second + dy[MOVE::u] * player.moveSpeed;
                    updatePlayerPos(std::make_pair(newX, newY));
                }
                if (action[0] == 'd') {
                    int newX = playerPos.first + dx[MOVE::d] * player.moveSpeed;
                    int newY = playerPos.second + dy[MOVE::d] * player.moveSpeed;
                    updatePlayerPos(std::make_pair(newX, newY));
                }
                if (action[0] == 'l') {
                    int newX = playerPos.first + dx[MOVE::l] * player.moveSpeed;
                    int newY = playerPos.second + dy[MOVE::l] * player.moveSpeed;
                    updatePlayerPos(std::make_pair(newX, newY));
                }
                if (action[0] == 'r') {
                    int newX = playerPos.first + dx[MOVE::r] * player.moveSpeed;
                    int newY = playerPos.second + dy[MOVE::r] * player.moveSpeed;
                    updatePlayerPos(std::make_pair(newX, newY));
                }
            }
        }
        else {
            if (action.compare("au") == 0 && !isOVERDOSE) {
                playerAttack(MOVE::u);
            }
            if (action.compare("ad") == 0 && !isOVERDOSE) {
                playerAttack(MOVE::d);
            }
            if (action.compare("ar") == 0 && !isOVERDOSE) {
                playerAttack(MOVE::r);
            }
            if (action.compare("al") == 0 && !isOVERDOSE) {
                playerAttack(MOVE::l);
            }
            if (action.compare("dd") == 0 && !isOVERDOSE) {
                eatPill(-1);
            }
            if (action.compare("du") == 0 && !isOVERDOSE) {
                eatPill(1);
            }
        }
        checkPlayerExp(); //"한 가지 행동이 끝난 후 경험치를 얻어 요구 경험치 이상시 레벨업
        if (!isPlayer(goalPos) && !isGoal(goalPos)) {
            updateMap(goalPos, 'g');
        }
    }
    printGameResult();
    return 0;
}