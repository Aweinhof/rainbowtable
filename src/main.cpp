#include <iostream>
#include <filesystem>

#include "AttackPhase/Attack.h"
#include "BuildPhase/BuildTable.h"


enum class ActionType { NONE, UNKNOWN, BUILD, ATTACK, ATTACK_NO_FILE, ATTACK_BAD_FILE };

ActionType checkArguments(int argc, char* argv[]) {
    if (argc < 2) return ActionType::NONE;

    std::string action = argv[1];

    if (action == "build") {
        return ActionType::BUILD;

    } else if (action == "attack") {
        if (argc < 3) return ActionType::ATTACK_NO_FILE;

        if (!std::filesystem::is_regular_file(argv[2])) {
            return ActionType::ATTACK_BAD_FILE;
        }
        return ActionType::ATTACK;

    } else {
        std::cerr << "Unknown action: " << action << std::endl;
        return ActionType::UNKNOWN;
    }
}

int main(int argc, char* argv[]) {
    BuildTable buildTable;
    Attack attack;


    ActionType actionType = checkArguments(argc, argv);

    switch (actionType) {

        case ActionType::NONE:
            std::cerr << "Usage: " << argv[0] << " <action> [filename]" << std::endl;
            return 1;

        case ActionType::UNKNOWN:
            std::cerr << "Unknown action specified" << std::endl;
            return 1;

        case ActionType::BUILD:
            std::cout << "Executing build rainbow table" << std::endl;
            buildTable.Start();
            break;

        case ActionType::ATTACK:
            std::cout << "Executing attack on file : " << argv[2] << std::endl;
            attack.Start();
            break;

        case ActionType::ATTACK_NO_FILE:
            std::cerr << "Error: No filename specified for attack" << std::endl;
            return 1;

        case ActionType::ATTACK_BAD_FILE:
            std::cerr << "Error: File not valid : " << argv[2] << std::endl;
            return 1;
    }

    return 0;
}