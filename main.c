#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOWNHALL_LEVEL 1
#define GOLD 1000
#define ELIXIR 1000
#define TROOP_CAPACITY 20

typedef struct {
    char name[50];
    int townhall_level;
    int gold;
    int elixir;
    int troop_capacity;
    char troops[TROOP_CAPACITY][50];
    int troop_count;
} Player;

void print_resources(Player* player) {
    printf("Gold: %d\n", player->gold);
    printf("Elixir: %d\n", player->elixir);
}

void print_troops(Player* player) {
    printf("Troops:\n");
    for (int i = 0; i < player->troop_count; i++) {
        printf("%s\n", player->troops[i]);
    }
}

void attack(Player* player) {
    int enemy_townhall_level = rand() % 10 + 1;
    if (player->townhall_level > enemy_townhall_level) {
        printf("You won the attack!\n");
    } else {
        printf("You lost the attack!\n");
    }
}

void train_troop(Player* player, const char* troop_name, int troop_cost) {
    if (player->troop_count >= player->troop_capacity) {
        printf("Troop capacity reached. Upgrade your camps to train more troops.\n");
    } else {
        if (player->gold >= troop_cost) {
            player->gold -= troop_cost;
            strcpy(player->troops[player->troop_count], troop_name);
            player->troop_count++;
        } else {
            printf("Not enough gold to train the troops.\n");
        }
    }
}

void game_loop() {
    printf("Welcome to Clash of Clans (CLI Version)!\n");
    Player player;
    printf("Enter Your Name: ");
    scanf("%s", player.name);
    player.townhall_level = TOWNHALL_LEVEL;
    player.gold = GOLD;
    player.elixir = ELIXIR;
    player.troop_capacity = TROOP_CAPACITY;
    player.troop_count = 0;

    while (1) {
        printf("\n[MAIN MENU]\n");
        printf("1. Print Resources\n");
        printf("2. Print Troops\n");
        printf("3. Train Troops\n");
        printf("4. Attack\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            print_resources(&player);
        } else if (choice == 2) {
            print_troops(&player);
        } else if (choice == 3) {
            char troop_name[50];
            int troop_cost;
            printf("Enter the Troop name: ");
            scanf("%s", troop_name);
            printf("Enter the troop cost: ");
            scanf("%d", &troop_cost);
            train_troop(&player, troop_name, troop_cost);
        } else if (choice == 4) {
            attack(&player);
        } else if (choice == 5) {
            printf("Thanks for Playing Clash of Clans (CLI version)!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    game_loop();
    return 0;
}
