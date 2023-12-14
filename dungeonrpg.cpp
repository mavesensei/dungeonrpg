#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
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
void gameplay(string adv, string chosengoblin, int& strength, int& dexterity, int& magic){
    string battle, job;
    srand(time(0));
    int attack = 0, flee, defeatedgoblin = 0, showxp = 0, goblinlevel, playerlevel = 1;
    int playerhp = 100;
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
                    cout << "---------------------------          ---------------------------\n\n";

                    
                    getline(cin, battle);
                    if(battle == "Flee" || battle == "flee"){
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
                        
                        attack = strength + (playerlevel * 1);
                        attack = min(11, strength);
                    } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                        cout << "(Special ability applied)\n";
                        attack = magic + (playerlevel * 1);
                        attack = min(11, magic);
                    } else {
                        cout << "(Special ability applied)\n";
                        attack = dexterity + (playerlevel * 1);
                        attack = min(11, dexterity);
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
                    cout << "---------------------------          ---------------------------\n\n";
                    getline(cin, battle);
                    
                    if(battle == "Flee" || battle == "flee"){
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
                        
                        attack = strength + (playerlevel * 1);
                        attack = min(11, strength);
                    } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                        cout << "(Special ability applied)\n";
                        attack = magic + (playerlevel * 1);
                        attack = min(11, magic);
                    } else {
                        cout << "(Special ability applied)\n";
                        attack = dexterity + (playerlevel * 1);
                        attack = min(11, dexterity);
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
                    cout << "---------------------------          ---------------------------\n\n";
                    getline(cin, battle);
                    
                    if(battle == "Flee" || battle == "flee"){
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
                        
                        attack = strength + (playerlevel * 1);
                        attack = min(11, strength);
                    } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                        cout << "(Special ability applied)\n";
                        attack = magic + (playerlevel * 1);
                        attack = min(11, magic);
                    } else {
                        cout << "(Special ability applied)\n";
                        attack = dexterity + (playerlevel * 1);
                        attack = min(11, dexterity);
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
                    cout << "---------------------------          ---------------------------\n\n";
                    getline(cin, battle);
                    
                    if(battle == "Flee" || battle == "flee"){
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
                        
                        attack = strength + (playerlevel * 1);
                        attack = min(11, strength);
                    } else if (job == "MAGE" || job == "Mage" || job == "mage") {
                        cout << "(Special ability applied)\n";
                        attack = magic + (playerlevel * 1);
                        attack = min(11, magic);
                    } else {
                        cout << "(Special ability applied)\n";
                        attack = dexterity + (playerlevel * 1);
                        attack = min(11, dexterity);
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
    } while (playerhp > 0);
}
void entrence(string choice, string job, char door){
    string adv, chosengoblin;
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
                gameplay(adv, chosengoblin, strength, dexterity, magic);
            }
            else if(door == 'N' || door == 'n'){
                cout << "You didn't want to enter from the door.\n";
                cout << "Nothing happened...\n";
                cout << "You felt like shit.\n";
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
                gameplay(adv, chosengoblin, strength, dexterity, magic);
            }
            else if(door == 'N' || door == 'n'){
                cout << "You didn't want to enter from the door.\n";
                cout << "Nothing happened...\n";
                cout << "You felt like shit.\n";
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
                gameplay(adv, chosengoblin, strength, dexterity, magic);
            }
            else if(door == 'N' || door == 'n'){
                cout << "You didn't want to enter from the door.\n";
                cout << "Nothing happened...\n";
                cout << "You felt like shit.\n";
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
int main(){
    string choice, job;
    char door;
    cout << "---------------------------\n";
    cout << "|                         |\n";
    cout << "|   DUNGEON OF MYSTERY    |\n";
    cout << "|                         |\n";
    cout << "|  [GO IN]  [WALK AWAY]   |\n";
    cout << "|                         |\n";
    cout << "| (waiting for selection) |\n";
    cout << "---------------------------\n";
    getline(cin, choice);
    entrence(choice, job, door);
    return 0;
}