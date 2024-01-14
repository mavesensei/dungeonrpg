#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
class HealthPotion {
public:
    HealthPotion() : healingAmount(20) {}

    void use(int& playerhp, int& healthPotions) {
        if (healthPotions > 0) {
            playerhp += healingAmount;
            healthPotions--;
            cout << "\n\n";
            cout << "You used a health potion. Remaining health potions: " << healthPotions << "\n\n";
        } else {
            cout << "You don't have any health potions left.\n";
        }
    }

private:
    int healingAmount;
};
void levelup(int& dexterity, int& magic, int& strength);
void stats(int& dexterity, int& magic, int& strength, string& job);
void gameplay(string& adv, string& chosengoblin, int& strength, int& dexterity, int& magic, int& playerhp, int& playerlevel, int& healthPotions, int& defeatedgoblin);
void entrence(string choice, string job, char door);
void saveGame(int saveSlot, int& playerhp, int& playerlevel, int& healthPotions, int& defeatedgoblin);
bool loadGame(int saveSlot, int& playerhp, int& playerlevel, int& healthPotions, int& defeatedgoblin);
void deleteSave(int saveSlot);
int main(){
    int playerhp, playerlevel, healthPotions, defeatedgoblin, strength, dexterity, magic, saveSlot;
    string choice, job, adv, chosengoblin;
    char door;
    do{
        cout << "---------------------------\n";
        cout << "|                         |\n";
        cout << "|   DUNGEON OF MYSTERY    |\n";
        cout << "|                         |\n";
        cout << "|  [Go in]  [Walk Away]   |\n";
        cout << "|                         |\n";
        cout << "|     [Info]   [Load]     |\n";
        cout << "---------------------------\n\n\n";
        getline(cin, choice);
        if(choice == "quit" || choice == "q"){
            return 1;
        }
        if(choice == "Load" || choice == "load" || choice == "LOAD"){
            cout << "\n\t\t\tEnter the save slot number: \n";
            cin >> saveSlot;
            ifstream loadFile("savegame" + to_string(saveSlot) + ".txt");
                if (loadFile.is_open()) {
                    loadGame(saveSlot, playerhp, playerlevel, healthPotions, defeatedgoblin);
                    loadFile.close();
                    cout << "Game loaded successfully!\n";
                    gameplay(adv, chosengoblin, strength, dexterity, magic, playerhp, playerlevel, healthPotions, defeatedgoblin);
                } else {
                    cout << "Unable to open the file: savegame" << to_string(saveSlot) << ".txt\n";
                }
        } else if(choice == "Info" || choice == "INFO" || choice == "info"){
            cout << "To save your game please type 'save' at any point!\n";
        } else{
            entrence(choice, job, door);
        }
    }while(choice != "walk away" || choice != "Walk Away");
    return 0;
}
void levelup(int& dexterity, int& magic, int& strength) {
    int choice;
    cout << "---------------------------\n";
    cout << "|     YOU LEVELED UP!     |\n";
    cout << "|                         |\n";
    cout << "| [1] DEXTERITY           |\n";
    cout << "| [2] MAGIC               |\n";
    cout << "| [3] STRENGTH            |\n";
    cout << "|                         |\n";
    cout << "---------------------------\n\n";
    cin >> choice;

    int increaseAmount = 1;

    switch (choice) {
        case 1:
            dexterity += increaseAmount;
            cout << "(Dexterity increased by " << increaseAmount << ")\n";
            break;
        case 2:
            magic += increaseAmount;
            cout << "(Magic increased by " << increaseAmount << ")\n";
            break;
        case 3:
            strength += increaseAmount;
            cout << "(Strength increased by " << increaseAmount << ")\n";
            break;
        default:
            cout << "Invalid choice.\n";
    }
}
void stats(int& dexterity, int& magic, int& strength, string& job){
    if(job == "WARRIOR" || job == "warrior" || job == "Warrior"){
        strength += 5;
        magic += 1;
        dexterity += 1;
    }
    else if(job == "MAGE" || job == "Mage" || job == "mage"){
        strength += 1;
        magic += 5;
        dexterity +=1;
    }
    else if(job == "ARCHER" || job == "Archer" || job == "archer"){
        strength += 1;
        magic += 1;
        dexterity += 5;
    }
}
void gameplay(string& adv, string& chosengoblin, int& strength, int& dexterity, int& magic, int& playerhp, int& playerlevel, int& healthPotions, int& defeatedgoblin){
    HealthPotion healthPotion;
    int saveSlot;
    playerhp = 100, playerlevel = 1, healthPotions = 1;
    string battle, job;
    srand(time(0));
    int attack = 0, flee, showxp = 0, goblinlevel;
    int goblinhp = 20, archergoblinhp = 15, shieldgoblinhp = 35, bossgoblinhp = 50;
    int goblinap = rand() % 10 + 1, archergoblinap = rand() % 20 + 1, bossgoblinap = rand() % 50 + 1;
    do {
        cout << "---------------------------\n";
        cout << "| You're walking into the |\n";
        cout << "| corridor which darkness |\n";
        cout << "|        is ruling        |\n";
        cout << "|                         |\n";
        cout << "| [Walk to it]    [Wait]  |\n";
        cout << "| [Show XP]      [Stats]  |\n";
        cout << "---------------------------\n\n";
        getline(cin, adv);
        if(adv == "Save" || adv == "save" || adv == "SAVE"){
            cout << "\n\n\t\t\tPlease select the saving slot\n";
            cout << "\n\n\t\t\tFor example: 1, 2, 3\n";
            cin >> saveSlot;
            saveGame(saveSlot, playerhp, playerlevel, healthPotions, defeatedgoblin);
        }
        if (adv == "Walk to it" || adv == "walk to it") {
            string goblin = "Normal Goblin";
            string archergoblin = "Archer Goblin";
            string shieldgoblin = "Shield Goblin";
            string bossgoblin = "FATASS Goblin";
            int randomnumber = rand() % 100 + 1;


            if (randomnumber == 1) {
                chosengoblin = bossgoblin;
                bossgoblinhp = 50;
                goblinlevel = rand() % 10 + 1;
            } else {
                int randomType = rand() % 3;
                if (randomType == 0) {
                    chosengoblin = goblin;
                    goblinhp = 20;
                    goblinlevel = rand() % 10 + 1;
                } else if (randomType == 1) {
                    chosengoblin = archergoblin;
                    archergoblinhp = 20;
                    goblinlevel = rand() % 10 + 1;
                } else {
                    chosengoblin = shieldgoblin;
                    shieldgoblinhp = 35;
                    goblinlevel = rand() % 10 + 1;
                }
            }

            do{
                if(chosengoblin == archergoblin){
                    cout << "Chosen Goblin Type: " << chosengoblin << endl;
                    cout << "---------------------------          ---------------------------\n";
                    cout << "|  " << chosengoblin << "          |          | Your Chart              | \n";
                    cout << "|                         |          |                         |\n";
                    cout << "| Goblins lv: " << goblinlevel << "          |          | Your lv: "<< playerlevel << "               |\n";
                    cout << "| Goblins hp: " << archergoblinhp << "          |" "          | Your hp: "<< playerhp << "            |\n";
                    cout << "| Goblins ap: " << goblinap << "           |          |                         |\n";
                    cout << "|                         |          |                         |\n";
                    cout << "|   [Attack]    [Flee]    |          |                         |\n";
                    cout << "|      [Use Potion]       |          |                         |\n";
                    cout << "---------------------------          ---------------------------\n\n";

                    
                    getline(cin, battle);
                    if(battle == "Use Potion" || battle == "Use potion" || battle == "use potion"){
                        healthPotion.use(playerhp, healthPotions);
                        if (playerhp > 100) {
                            playerhp = 100;
                        }
                    }
                    else if(battle == "Flee" || battle == "flee"){
                        srand(time(0));
                        int fleedice = rand() % 6 + 1;

                        if (dexterity >= 5 && dexterity < 10) {
                            fleedice += 1;
                        } else if (dexterity >= 10 && dexterity < 15) {
                            fleedice += 2;
                        } else if (dexterity >= 15 && dexterity < 20) {
                            fleedice += 3;
                        } else if (dexterity >= 20 && dexterity < 25) {
                            fleedice += 4;
                        } else if(dexterity < 5) {
                            fleedice += 0;
                        } else {
                            fleedice += 5;
                        }
                        if (fleedice >= 4) {
                            cout << "Dexterity: " << dexterity << ", Original Fleedice: " << fleedice << endl;
                            cout << "You successfully flee.\n";
                            break;
                        } else {
                            cout << "Dexterity: " << dexterity << ", Original Flee dice: " << fleedice << endl;
                            cout << "You didn't flee.\n";
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 4;
                            enemydice += goblinap;
                            playerhp -= enemydice;
                            cout << chosengoblin << " attacked you. Your health is " << playerhp << " now.\n";
                            
                        }
                    }

                    else if (battle == "Attack" || battle == "attack") {
                        attack = 0;
                        
                        if (job == "WARRIOR" || job == "Warrior" || job == "warrior") {
                            cout << "(Special ability applied)\n";
                            attack = strength + (playerlevel * 12) / 10;
                        } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                            cout << "(Special ability applied)\n";
                            attack = magic + (playerlevel * 12) / 10;
                        } else {
                            cout << "(Special ability applied)\n";
                            attack = dexterity + (playerlevel * 12) / 10;
                        }

                        goblinhp = max(0, goblinhp - attack);
                        archergoblinhp = max(0, archergoblinhp - attack);
                        shieldgoblinhp = max(0, shieldgoblinhp - attack);

                        cout << "You attacked the " << chosengoblin << ". " << chosengoblin << " HP is " << archergoblinhp << " now.\n";
                        if(archergoblinhp > 0){
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 2;
                            enemydice += archergoblinap;
                            playerhp -= enemydice;
                            cout << chosengoblin << " attacked you. Your health is " << playerhp << " now.\n";
                            
                        }
                        if (chosengoblin == archergoblin && archergoblinhp <= 0) {
                        cout << "You defeated the " << chosengoblin << "!\n\n";
                        defeatedgoblin++;
                        if (rand() % 10 == 0) {
                            healthPotions++;
                            cout << "You found a health potion! Remaining health potions: " << healthPotions << "\n";
                        }
                        break;
                    }
                    }
                }
                else if(chosengoblin == shieldgoblin){
                    cout << "Chosen Goblin Type: " << chosengoblin << endl;
                    cout << "---------------------------          ---------------------------\n";
                    cout << "|  " << chosengoblin << "          |          | Your Chart              | \n";
                    cout << "|                         |          |                         |\n";
                    cout << "| Goblins lv: " << goblinlevel << "          |          | Your lv: "<< playerlevel << "               |\n";
                    cout << "| Goblins hp: " << shieldgoblinhp << "          |" "          | Your hp: "<< playerhp << "            |\n";
                    cout << "| Goblins ap: " << goblinap << "           |          |                         |\n";
                    cout << "|                         |          |                         |\n";
                    cout << "|   [Attack]    [Flee]    |          |                         |\n";
                    cout << "|      [Use Potion]       |          |                         |\n";
                    cout << "---------------------------          ---------------------------\n\n";
                    getline(cin, battle);
                    if (battle == "Use Potion" || battle == "Use potion" || battle == "use potion") {
                        healthPotion.use(playerhp, healthPotions);
                        if (playerhp > 100) {
                            playerhp = 100;
                        }
                    }
                    else if(battle == "Flee" || battle == "flee"){
                        srand(time(0));
                        int fleedice = rand() % 6 + 1;
                        

                        if (dexterity >= 5 && dexterity < 10) {
                            fleedice += 1;
                        } else if (dexterity >= 10 && dexterity < 15) {
                            fleedice += 2;
                        } else if (dexterity >= 15 && dexterity < 20) {
                            fleedice += 3;
                        } else if (dexterity >= 20 && dexterity < 25) {
                            fleedice += 4;
                        } else if(dexterity < 5) {
                            fleedice += 0;
                        } else {
                            fleedice += 5;
                        }
                        if (fleedice >= 4) {
                            cout << "Dexterity: " << dexterity << ", Original Fleedice: " << fleedice << endl;
                            cout << "You successfully flee.\n";
                            break;
                        } else {
                            cout << "Dexterity: " << dexterity << ", Original Flee dice: " << fleedice << endl;
                            cout << "You didn't flee.\n";
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 4;
                            enemydice += goblinap;
                            playerhp -= enemydice;
                            cout << chosengoblin << " attacked you. Your health is " << playerhp << " now.\n";
                            
                        }
                    }
                    else if(battle == "Attack" || battle == "attack"){
                    attack = 0;
                    
                        if (job == "WARRIOR" || job == "Warrior" || job == "warrior") {
                            cout << "(Special ability applied)\n";
                            attack = strength + (playerlevel * 12) / 10;
                        } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                            cout << "(Special ability applied)\n";
                            attack = magic + (playerlevel * 12) / 10;
                        } else {
                            cout << "(Special ability applied)\n";
                            attack = dexterity + (playerlevel * 12) / 10;
                        }

                        goblinhp = max(0, goblinhp - attack);
                        archergoblinhp = max(0, archergoblinhp - attack);
                        shieldgoblinhp = max(0, shieldgoblinhp - attack);

                        cout << "You attacked the " << chosengoblin << ". " << chosengoblin << " HP is " << shieldgoblinhp << " now.\n";
                        if(shieldgoblinhp > 0){
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 2;
                            enemydice += goblinap;
                            playerhp -= enemydice;
                            cout << chosengoblin << " attacked you. Your health is " << playerhp << " now.\n";
                            
                        }

                        cout << chosengoblin << " HP is " << shieldgoblinhp << " now.\n";
                        if (chosengoblin == shieldgoblin && shieldgoblinhp <= 0) {
                        cout << "You defeated the " << chosengoblin << "!\n\n";
                        defeatedgoblin++;
                        if (rand() % 10 == 0) {
                            healthPotions++;
                            cout << "You found a health potion! Remaining health potions: " << healthPotions << "\n";
                        }
                        break;
                    }
                }
                }
                else if(chosengoblin == goblin){
                    cout << "Chosen Goblin Type: " << chosengoblin << endl;
                    cout << "---------------------------          ---------------------------\n";
                    cout << "|  " << chosengoblin << "          |          | Your Chart              | \n";
                    cout << "|                         |          |                         |\n";
                    cout << "| Goblins lv: " << goblinlevel << "          |          | Your lv: "<< playerlevel << "               |\n";
                    cout << "| Goblins hp: " << goblinhp << "          |" "          | Your hp: "<< playerhp << "            |\n";
                    cout << "| Goblins ap: " << goblinap << "           |          |                         |\n";
                    cout << "|                         |          |                         |\n";
                    cout << "|   [Attack]    [Flee]    |          |                         |\n";
                    cout << "|      [Use Potion]       |          |                         |\n";
                    cout << "---------------------------          ---------------------------\n\n";
                    getline(cin, battle);
                    if (battle == "Use Potion" || battle == "Use potion" || battle == "use potion") {
                        healthPotion.use(playerhp, healthPotions);
                        if (playerhp > 100) {
                            playerhp = 100;
                        }
                    }                    
                    else if(battle == "Flee" || battle == "flee"){
                        srand(time(0));
                        int fleedice = rand() % 6 + 1;
                        

                        if (dexterity >= 5 && dexterity < 10) {
                            fleedice += 1;
                        } else if (dexterity >= 10 && dexterity < 15) {
                            fleedice += 2;
                        } else if (dexterity >= 15 && dexterity < 20) {
                            fleedice += 3;
                        } else if (dexterity >= 20 && dexterity < 25) {
                            fleedice += 4;
                        } else if(dexterity < 5) {
                            fleedice += 0;
                        } else {
                            fleedice += 5;
                        }
                        if (fleedice >= 4) {
                            cout << "Dexterity: " << dexterity << ", Original Fleedice: " << fleedice << endl;
                            cout << "You successfully flee.\n";
                            break;
                        } else {
                            cout << "Dexterity: " << dexterity << ", Original Flee dice: " << fleedice << endl;
                            cout << "You didn't flee.\n";
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 4;
                            enemydice += goblinap;
                            playerhp -= enemydice;
                            cout << chosengoblin << " attacked you. Your health is " << playerhp << " now.\n";
                            
                        }
                    }
                    else if(battle == "Attack" || battle == "attack"){
                    attack = 0;
                    
                        if (job == "WARRIOR" || job == "Warrior" || job == "warrior") {
                            cout << "(Special ability applied)\n";
                            attack = strength + (playerlevel * 12) / 10;
                        } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                            cout << "(Special ability applied)\n";
                            attack = magic + (playerlevel * 12) / 10;
                        } else {
                            cout << "(Special ability applied)\n";
                            attack = dexterity + (playerlevel * 12) / 10;
                        }

                        goblinhp = max(0, goblinhp - attack);
                        archergoblinhp = max(0, archergoblinhp - attack);
                        shieldgoblinhp = max(0, shieldgoblinhp - attack);

                        cout << "You attacked the " << chosengoblin << ". " << chosengoblin << " HP is " << goblinhp << " now.\n";
                        if(goblinhp > 0){
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 2;
                            enemydice += goblinap;
                            playerhp -= enemydice;
                            cout << chosengoblin << " attacked you. Your health is " << playerhp << " now.\n";
                            
                        }

                        cout << chosengoblin << " HP is " << goblinhp << " now.\n";
                        if (chosengoblin == goblin && goblinhp <= 0) {
                        cout << "You defeated the " << chosengoblin << "!\n\n";
                        defeatedgoblin++;
                        if (rand() % 10 == 0) {
                            healthPotions++;
                            cout << "You found a health potion! Remaining health potions: " << healthPotions << "\n";
                        }
                        break;
                    }
                }    
                }       
                else if(chosengoblin == bossgoblin){
                    cout << "Chosen Goblin Type: " << chosengoblin << endl;
                    cout << "---------------------------          ---------------------------\n";
                    cout << "|  " << chosengoblin << "          |          | Your Chart              | \n";
                    cout << "|                         |          |                         |\n";
                    cout << "| Goblins lv: " << goblinlevel << "          |          | Your lv: "<< playerlevel << "               |\n";
                    cout << "| Goblins hp: " << bossgoblinhp << "          |" "          | Your hp: "<< playerhp << "            |\n";
                    cout << "| Goblins ap: " << bossgoblinap << "           |          |                         |\n";
                    cout << "|                         |          |                         |\n";
                    cout << "|   [Attack]    [Flee]    |          |                         |\n";
                    cout << "|      [Use Potion]       |          |                         |\n";
                    cout << "---------------------------          ---------------------------\n\n";
                    getline(cin, battle);
                    if (battle == "Use Potion" || battle == "Use potion" || battle == "use potion") {
                        healthPotion.use(playerhp, healthPotions);
                        if (playerhp > 100) {
                            playerhp = 100;
                        }
                    }                    
                    else if(battle == "Flee" || battle == "flee"){
                        srand(time(0));
                        int fleedice = rand() % 6 + 1;
                    

                        if (dexterity >= 5 && dexterity < 10) {
                            fleedice += 1;
                        } else if (dexterity >= 10 && dexterity < 15) {
                            fleedice += 2;
                        } else if (dexterity >= 15 && dexterity < 20) {
                            fleedice += 3;
                        } else if (dexterity >= 20 && dexterity < 25) {
                            fleedice += 4;
                        } else if(dexterity < 5) {
                            fleedice += 0;
                        } else {
                            fleedice += 5;
                        }
                        if (fleedice >= 4) {
                            cout << "Dexterity: " << dexterity << ", Original Fleedice: " << fleedice << endl;
                            cout << "You successfully flee.\n";
                            break;
                        } else {
                            cout << "Dexterity: " << dexterity << ", Original Flee dice: " << fleedice << endl;
                            cout << "You didn't flee.\n";
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 4;
                            enemydice += bossgoblinap;
                            playerhp -= enemydice;
                            cout << chosengoblin << " attacked you. Your health is " << playerhp << " now.\n";
                            
                        }
                    }

                    else if (battle == "Attack" || battle == "attack") {
                    attack = 0;
                    
                        if (job == "WARRIOR" || job == "Warrior" || job == "warrior") {
                            cout << "(Special ability applied)\n";
                            attack = strength + (playerlevel * 12) / 10;
                        } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                            cout << "(Special ability applied)\n";
                            attack = magic + (playerlevel * 12) / 10;
                        } else {
                            cout << "(Special ability applied)\n";
                            attack = dexterity + (playerlevel * 12) / 10;
                        }

                    goblinhp = max(0, goblinhp - attack);
                    archergoblinhp = max(0, archergoblinhp - attack);
                    shieldgoblinhp = max(0, shieldgoblinhp - attack);
                    cout << "You attacked the " << chosengoblin << ". " << chosengoblin << " HP is " << goblinhp << " now.\n";
                    if(bossgoblinhp > 0){
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 2;
                            enemydice += bossgoblinap;
                            playerhp -= enemydice;
                            cout << chosengoblin << " attacked you. Your health is " << playerhp << " now.\n";
                            
                        }
                    if (chosengoblin == bossgoblin && bossgoblinhp <= 0) {
                        cout << "You defeated the " << chosengoblin << "!\n\n";
                        defeatedgoblin++;
                        if (rand() % 10 == 0) {
                            healthPotions++;
                            cout << "You found a health potion! Remaining health potions: " << healthPotions << "\n";
                        }
                        break;
                    }
                }        

                    if (playerhp <= 0) {
                        playerhp = min(0, playerhp);
                        cout << "You were defeated by the " << chosengoblin << ". Game over!\n";
                        break;
                    }
                }
        }while(playerhp > 0);
        }
        if(defeatedgoblin == 5){
            playerlevel++;
            defeatedgoblin = 0;
            levelup(dexterity, magic, strength);
        }
        else if(adv == "Show XP" || adv == "show xp" || adv == "Show xp"){
            cout << "---------------------------------\n"; 
            cout << "|Your current xp is:    " << defeatedgoblin << " / 5   |\n";
            cout << "---------------------------------\n"; 
            cout << "(Press ENTER for back)\n";
            getline(cin, adv);
        }
        else if (adv == "Wait" || adv == "wait") {
            string goblin, archergoblin, shieldgoblin, bossgoblin;
            playerhp = min(100, playerhp + 30);
            cout << "You chose to take a break for catch your breath.\n";
            cout << "You sat down to the ground its a little bit uncomfortable.\n\n";
            cout << "⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⢱⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     So you decide to start a campfire.\n";
            cout << "⠀⠀⠀⠀⠀⠀⢸⣿⡄⠀⠀⡀⠀⠀⠀⢸⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀     In the light of this campfire you,\n";
            cout << "⠀⠀⠀⠀⠈⢿⠇⠀⠀⣷⣦⣤⣴⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     healed your hp.\n";
            cout << "⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀     You are now resting...\n";
            cout << "⠀⠀⠀⠀⢠⣾⣷⡀⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀     Player HP: " << playerhp << '\n';
            cout << "⠀⠀⠀⢰⣿⣿⣿⣿⣷⣿⣿⣿⡟⢿⠿⠋⣿⣿⠀⠀⠀⠀⠰⣄⠀⠀⠀\n";
            cout << "⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⣿⣿⣦⡀⠀⠀⢀⣿⣧⠀⠀\n";
            cout << "⠀⠀⠀⢹⣿⣿⣿⠙⠻⠟⠋⠁⠀⠀⠀⠀⢿⣿⣿⣿⣶⣶⣿⣿⣿⠀⠀\n";
            cout << "⠀⠀⠀⠈⣿⣿⣿⡆⠀⠀⢀⣠⡤⠀⠀⠀⠈⠻⣿⡿⣿⣿⣿⣿⡟⠀⠀\n";
            cout << "⠀⠀⠀⠀⠘⠟⠋⣁⣤⡾⢟⣩⣴⣶⣆⠀⠀⠀⠀⢠⣿⣿⣿⠟⠀⠀⠀\n";
            cout << "⠀⠀⠀⢀⣠⣴⣿⣿⣿⣿⠟⢉⣁⣀⣉⠀⢹⣶⣶⣤⣄⣈⡁⠀⠀⠀⠀\n";
            cout << "⠀⠀⢸⣿⣿⣿⣿⢿⣿⠇⢰⡟⣫⣦⠙⢷⡀⣿⣿⣯⣍⣛⠛⠋⠀⠀⠀\n";
            cout << "⠀⠀⠀⠛⢋⣡⡾⠟⠋⠀⠸⣧⣙⡟⢁⡾⠁⠿⢿⣿⣿⣭⡉⠁⠀⠀⠀\n";
            cout << "⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠈⠙⠛⠋⠀⠀⠀⠀⠀⠈⠉⠉⠀⠀⠀⠀\n";

            int ambush = rand() % 2 + 1;
            if(ambush == 1){
                cout << "\n\n\n\t\t\tSURPRISE ATTACK!\n\n\n";
                cout << "While you sitting down to the campfire a hard object hit your head!\n";
                string chosenskeleton, skeleton, archerskeleton, shieldskeleton;
                int skeletonhp = 10, archerskeletonhp = 15, shieldskeletonhp = 20;
                int skeletonap = 6;
                playerhp -= 15;
                int randomType = rand() % 3;
                if (randomType == 0) {
                    chosengoblin = skeleton;
                    goblinlevel = rand() % 10 + 1;
                } else if (randomType == 1) {
                    chosengoblin = archerskeleton;
                    goblinlevel = rand() % 10 + 1;
                } else {
                    chosengoblin = shieldskeleton;
                    goblinlevel = rand() % 10 + 1;
                }

                do {
                    if (chosengoblin == archerskeleton) {
                        cout << "Chosen Skeleton Type: Archer Skeleton\n";
                        cout << "---------------------------          ---------------------------\n";
                        cout << "|  Archer Skeleton        |          | Your Chart              | \n";
                        cout << "|                         |          |                         |\n";
                        cout << "| Skeletons lv: " << goblinlevel << "          |          | Your lv: "<< playerlevel << "               |\n";
                        cout << "| Skeletons hp: " << archerskeletonhp << "          |" "          | Your hp: "<< playerhp << "            |\n";
                        cout << "| Skeletons ap: " << skeletonap << "           |          |                         |\n";
                        cout << "|                         |          |                         |\n";
                        cout << "|  [Attack] [Use Potion]  |          |                         |\n";
                        cout << "|                         |          |                         |\n";
                        cout << "---------------------------          ---------------------------\n\n";

                        getline(cin, battle);
                        if(battle == "Use Potion" || battle == "Use potion" || battle == "use potion"){
                        healthPotion.use(playerhp, healthPotions);
                        if (playerhp > 100) {
                            playerhp = 100;
                        }
                    }
                    else if (battle == "Attack" || battle == "attack") {
                        attack = 0;
                        
                        if (job == "WARRIOR" || job == "Warrior" || job == "warrior") {
                            cout << "(Special ability applied)\n";
                            attack = strength + (playerlevel * 12) / 10;
                        } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                            cout << "(Special ability applied)\n";
                            attack = magic + (playerlevel * 12) / 10;
                        } else {
                            cout << "(Special ability applied)\n";
                            attack = dexterity + (playerlevel * 12) / 10;
                        }

                        skeletonhp = max(0, skeletonhp - attack);
                        archerskeletonhp = max(0, archerskeletonhp - attack);
                        shieldskeletonhp = max(0, shieldskeletonhp - attack);

                        cout << "You attacked the Archer Skeleton. Archer Skeleton's HP is " << archerskeletonhp << " now.\n";
                        if(archerskeletonhp > 0){
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 2;
                            enemydice += skeletonap;
                            playerhp -= enemydice;
                            cout << chosenskeleton << " attacked you. Your health is " << playerhp << " now.\n";
                            
                        }
                        if (chosenskeleton == archerskeleton && archerskeletonhp <= 0) {
                        cout << "You defeated the Archer Skeleton!\n\n";
                        defeatedgoblin++;
                        if (rand() % 10 == 0) {
                            healthPotions++;
                            cout << "You found a health potion! Remaining health potions: " << healthPotions << "\n";
                        }
                        break;
                    }
                    }
                    } else if (chosengoblin == shieldskeleton) {
                        cout << "Chosen Skeleton Type: Shield Skeleton\n";
                        cout << "---------------------------          ---------------------------\n";
                        cout << "|  Shield Skeleton        |          | Your Chart              | \n";
                        cout << "|                         |          |                         |\n";
                        cout << "| Skeletons lv: " << goblinlevel << "          |          | Your lv: "<< playerlevel << "               |\n";
                        cout << "| Skeletons hp: " << shieldskeletonhp << "          |" "          | Your hp: "<< playerhp << "            |\n";
                        cout << "| Skeletons ap: " << skeletonap << "           |          |                         |\n";
                        cout << "|                         |          |                         |\n";
                        cout << "|  [Attack] [Use Potion]  |          |                         |\n";
                        cout << "|                         |          |                         |\n";
                        cout << "---------------------------          ---------------------------\n\n";

                        getline(cin, battle);
                        if(battle == "Use Potion" || battle == "Use potion" || battle == "use potion"){
                        healthPotion.use(playerhp, healthPotions);
                        if (playerhp > 100) {
                            playerhp = 100;
                        }
                    }
                    else if (battle == "Attack" || battle == "attack") {
                        attack = 0;
                        
                        if (job == "WARRIOR" || job == "Warrior" || job == "warrior") {
                            cout << "(Special ability applied)\n";
                            attack = strength + (playerlevel * 12) / 10;
                        } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                            cout << "(Special ability applied)\n";
                            attack = magic + (playerlevel * 12) / 10;
                        } else {
                            cout << "(Special ability applied)\n";
                            attack = dexterity + (playerlevel * 12) / 10;
                        }

                        skeletonhp = max(0, skeletonhp - attack);
                        archerskeletonhp = max(0, archerskeletonhp - attack);
                        shieldskeletonhp = max(0, shieldskeletonhp - attack);

                        cout << "You attacked the Shield Skeleton. Shield Skeleton's HP is " << archerskeletonhp << " now.\n";
                        if(archerskeletonhp > 0){
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 2;
                            enemydice += skeletonap;
                            playerhp -= enemydice;
                            cout << "Shield Skeleton attacked you. Your health is " << playerhp << " now.\n";
                            
                        }
                        if (chosenskeleton == archerskeleton && archerskeletonhp <= 0) {
                        cout << "You defeated the Shield Skeleton!\n\n";
                        defeatedgoblin++;
                        if (rand() % 10 == 0) {
                            healthPotions++;
                            cout << "You found a health potion! Remaining health potions: " << healthPotions << "\n";
                        }
                        break;
                    }
                    }
                    } else if (chosengoblin == skeleton) {
                        cout << "Chosen Skeleton Type: Skeleton\n";
                        cout << "---------------------------          ---------------------------\n";
                        cout << "|  Skeleton               |          | Your Chart              | \n";
                        cout << "|                         |          |                         |\n";
                        cout << "| Skeletons lv: " << goblinlevel << "          |          | Your lv: "<< playerlevel << "               |\n";
                        cout << "| Skeletons hp: " << skeletonhp << "          |" "          | Your hp: "<< playerhp << "            |\n";
                        cout << "| Skeletons ap: " << skeletonap << "           |          |                         |\n";
                        cout << "|                         |          |                         |\n";
                        cout << "|  [Attack] [Use Potion]  |          |                         |\n";
                        cout << "|                         |          |                         |\n";
                        cout << "---------------------------          ---------------------------\n\n";

                        getline(cin, battle);
                        if(battle == "Use Potion" || battle == "Use potion" || battle == "use potion"){
                        healthPotion.use(playerhp, healthPotions);
                        if (playerhp > 100) {
                            playerhp = 100;
                        }
                    }
                    else if (battle == "Attack" || battle == "attack") {
                        attack = 0;
                        
                        if (job == "WARRIOR" || job == "Warrior" || job == "warrior") {
                            cout << "(Special ability applied)\n";
                            attack = strength + (playerlevel * 12) / 10;
                        } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                            cout << "(Special ability applied)\n";
                            attack = magic + (playerlevel * 12) / 10;
                        } else {
                            cout << "(Special ability applied)\n";
                            attack = dexterity + (playerlevel * 12) / 10;
                        }

                        skeletonhp = max(0, skeletonhp - attack);
                        archerskeletonhp = max(0, archerskeletonhp - attack);
                        shieldskeletonhp = max(0, shieldskeletonhp - attack);

                        cout << "You attacked the Skeleton. Skeleton's HP is " << archerskeletonhp << " now.\n";
                        if(archerskeletonhp > 0){
                            int enemydice = rand() % 6 + 1;
                            enemydice += goblinlevel * 2;
                            enemydice += skeletonap;
                            playerhp -= enemydice;
                            cout << "Skeleton attacked you. Your health is " << playerhp << " now.\n";
                            
                        }
                        if (chosenskeleton == archerskeleton && archerskeletonhp <= 0) {
                        cout << "You defeated the Skeleton!\n\n";
                        defeatedgoblin++;
                        if (rand() % 10 == 0) {
                            healthPotions++;
                            cout << "You found a health potion! Remaining health potions: " << healthPotions << "\n";
                        }
                        break;
                    }
                    }
                    }
                } while (playerhp > 0);

            }
        }
        else if(adv == "Stats" || adv == "stats"){
            cout << "---------------------------\n";
            cout << "|          STATS          |\n";
            cout << "|                         |\n";
            cout << "| DEXTERITY : "<< dexterity << "           |\n";
            cout << "| MAGIC : "<< magic <<"               |\n";
            cout << "| STRENGTH : "<< strength <<"            |\n";
            cout << "|                         |\n";
            cout << "---------------------------\n\n";
        }
        else if(adv == "quit" || adv == "q"){
            break;
        }
    } while (playerhp > 0);
}
void entrence(string choice, string job, char door){
    string adv, chosengoblin;
    int playerhp, playerlevel, healthPotions, defeatedgoblin;
    int strength = 0, magic = 0, dexterity = 0;
    if(choice == "Go in" || choice == "go in" || choice == "GO IN"){
        cout << "---------------------------\n";
        cout << "|   Please select your    |\n";
        cout << "|         class           |\n";
        cout << "|  [WARRIOR]   [MAGE]     |\n";
        cout << "|        [ARCHER]         |\n";
        cout << "|                         |\n";
        cout << "| (waiting for selection) |\n";
        cout << "---------------------------\n";
        cin >> job;
        if(job == "WARRIOR" || job == "warrior" || job == "Warrior"){
            strength += 5;
            magic += 1;
            dexterity += 1;
            cout << "You found yourself in a room and when you inspect the room you saw a bow, a sword and a wand.\n Without thinking twice you grabbed the sword.\n\n";
            cout << "O===[====================-\n\n";
            cout << "Sword has added in your inventory.\n";
            cout << "(Because of your choice strength stat increased 5)\n";
            cout << "You saw a door with a dragon's head on it.\n";
            cout << "Do you want to open it? (Y/N)\n\n";
            cin >> door;
            if(door == 'Y' || door == 'y'){
                stats(dexterity, magic, strength, job);
                gameplay(adv, chosengoblin, strength, dexterity, magic, playerhp, playerlevel, healthPotions, defeatedgoblin);
            }
            else if(door == 'N' || door == 'n'){
                cout << "You didn't want to enter from the door.\n";
                cout << "Nothing happened...\n";
                cout << "You felt like shit.\n";
                return;
            }
        }
        else if(job == "MAGE" || job == "Mage" || job == "mage"){
            magic += 5;
            dexterity += 1;
            strength += 1;
            cout << " ^          You found yourself in a room,\n";
            cout << "(o)         and when you inspect the room.\n";
            cout << "'V'         You saw a bow, a sword and a wand\n";
            cout << " I          Without thinking twice you grabbed\n";
            cout << " I          the wand.\n";
            cout << " !\n\n";
            cout << "Wand has added in your inventory.\n";
            cout << "(Because of your choice magic stat increased 5)\n";
            cout << "You saw a door with a dragon's head on it.\n";
            cout << "Do you want to open it? (Y/N)\n\n";
            cin >> door;
            if(door == 'Y' || door == 'y'){
                stats(dexterity, magic, strength, job);
                gameplay(adv, chosengoblin, strength, dexterity, magic, playerhp, playerlevel, healthPotions, defeatedgoblin);
            }
            else if(door == 'N' || door == 'n'){
                cout << "You didn't want to enter from the door.\n";
                cout << "Nothing happened...\n";
                cout << "You felt like shit.\n";
                return;
            }
        }
        else if(job == "ARCHER" || job == "Archer" || job == "archer"){
            dexterity += 5;
            magic += 1;
            strength += 1;
            cout << "    (          You found yourself in a room,\n";
            cout << "     )         and when you inspect the room.\n";
            cout << "##------>      You saw a bow, a sword and a wand.\n";
            cout << "     )         Without thinking twice you grabbed\n";
            cout << "    (          the bow.\n";
            cout << "Bow has added in your inventory.\n";
            cout << "(Because of your choice dexterity stat increased 5)\n";
            cout << "You saw a door with a dragon's head on it.\n";
            cout << "Do you want to open it?(Y/N)\n\n";
            cin >> door;
            if(door == 'Y' || door == 'y'){
                stats(dexterity, magic, strength, job);
                gameplay(adv, chosengoblin, strength, dexterity, magic, playerhp, playerlevel, healthPotions, defeatedgoblin);
            }
            else if(door == 'N' || door == 'n'){
                cout << "You didn't want to enter from the door.\n";
                cout << "Nothing happened...\n";
                cout << "You felt like shit.\n";
                return;
            }
        }
    }
    else if(choice == "walk away" || choice == "WALK AWAY" || choice == "Walk away"){
        cout << "--------------------------\n";
        cout << "|                        |\n";
        cout << "|                        |\n";
        cout << "|  Thanks for visiting   |\n";
        cout << "|        GOODBYE!        |\n";
        cout << "|                        |\n";
        cout << "|   and now exiting...   |\n";
        cout << "--------------------------\n";
    }
}
void saveGame(int saveSlot, int& playerhp, int& playerlevel, int& healthPotions, int& defeatedgoblin) {
    ofstream saveFile("savegame" + to_string(saveSlot) + ".txt");
    if (saveFile.is_open()) {
        saveFile << playerhp << "\n";
        saveFile << playerlevel << "\n";
        saveFile << healthPotions << "\n";
        saveFile << defeatedgoblin << "\n";
        saveFile.close();
        cout << "Game saved successfully.\n";
    } else {
        cout << "Unable to save the game.\n";
    }
}
bool loadGame(int saveSlot, int& playerhp, int& playerlevel, int& healthPotions, int& defeatedgoblin) {
    ifstream loadFile("savegame" + to_string(saveSlot) + ".txt");
    if (loadFile.is_open()) {
        loadFile >> playerhp;
        loadFile >> playerlevel;
        loadFile >> healthPotions;
        loadFile >> defeatedgoblin;
        loadFile.close();
         cout << "Loaded values: " << playerhp << " " << playerlevel << " " << healthPotions << " " << defeatedgoblin << endl;
        return true;
    } else {
        cout << "Unable to open the file: savegame" << to_string(saveSlot) << ".txt\n";
        return false;
    }
}
void deleteSave(int saveSlot) {
    if (remove(("savegame" + to_string(saveSlot) + ".txt").c_str()) == 0) {
        cout << "Save file for slot " << saveSlot << " deleted successfully.\n";
    } else {
        cout << "Unable to delete save file for slot " << saveSlot << ".\n";
    }
}
