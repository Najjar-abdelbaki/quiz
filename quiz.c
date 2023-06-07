#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char question[200];
    char options[4][100];
    int reponse;
} Question;

// Fonction pour afficher le menu d'aide
void help() {
    printf("=== Menu d'aide ===\n");
    printf("Ce jeu est un quiz de connaissances générales où vous pouvez gagner de l'argent en répondant correctement aux questions.\n");
    printf("Vous devez répondre correctement à un certain nombre de questions pour accumuler 1 million de dollars.\n");
    printf("Pour chaque question, vous avez 4 options de réponse : 0, 1, 2 et 3.\n");
    printf("Répondez en entrant la lettre correspondant à votre choix.\n");
    printf("Le jeu se termine si vous répondez incorrectement ou si vous atteignez 1 million de dollars.\n");
    printf("Bonne chance !\n");
}

// Fonction pour réinitialiser le score
void reset_score(int *score) {
    *score = 0;
    printf("Le score a été réinitialisé.\n");
}

// Fonction pour afficher le score le plus élevé
void record(int score) {
    printf("Le score le plus élevé est de %d $.\n", score);
}



// Fonction pour vérifier si l'utilisateur a réussi le tour d'échauffement
int check(int correct_answers) {
    if (correct_answers >= 2) {
        printf("Félicitations ! Vous avez réussi le tour d'échauffement.\n");
        return 1;
    } else {
        printf("Désolé, vous n'avez pas réussi le tour d'échauffement. Vous ne pouvez pas passer au tour suivant.\n");
        return 0;
    }
}

// Fonction pour jouer le jeu de quiz
void play_quiz(Question questions[], int num_questions) {
    int score = 0;
    int question_count = 0;
    int correct_answers = 0;
    
    printf("=== Tour d'échauffement ===\n");
    
    // Tour d'échauffement
    for (int i = 0; i < 3; i++) {
        printf("\nQuestion %d :\n", i + 1);
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j, questions[i].options[j]);
        }
        
        int answer;
        printf("Votre réponse : ");
        scanf(" %d", &answer);
        
        if (answer == questions[i].reponse) {
            printf("Bonne réponse ! Vous gagnez 10 000 $.\n");
            score += 10000;
            correct_answers++;
        } else {
            printf("Mauvaise réponse.\n");
            break;
        }
    }
    
    if (!check(correct_answers)) {
        return;
    }
    
    printf("\n=== Manche Challenge ===\n");
    
    // Manche Challenge
    while (score < 1000000 && question_count < num_questions) {
        printf("\nQuestion %d :\n", question_count + 1);
        printf("%s\n", questions[question_count].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j, questions[question_count].options[j]);
        }
        
        int answer;
        printf("Votre réponse : ");
        scanf(" %d", &answer);
        
        if (answer == questions[question_count].reponse) {
            printf("Bonne réponse ! Vous gagnez 100 000 $.\n");
            score += 100000;
        } else {
            printf("Mauvaise réponse. Le jeu est terminé.\n");
            break;
        }
        
        question_count++;
    }
    
    printf("\n=== Fin du jeu ===\n");
    printf("Votre score final : %d $\n", score);
}

int main() {
    // Définition des questions et des options de réponse 
    Question questions[] = {
        {"Quelle est la capitale de la France ?", {"Rome", "Paris", "Berlin", "Londres"}, 1},
        {"Quel est le symbole chimique de l'oxygène ?", {"O", "C", "H", "N"}, 0},
        {"Qui a écrit la pièce de théâtre 'Hamlet' ?", {"William Shakespeare", "Charles Dickens", "Mark Twain", "Jane Austen"}, 0},
        {"Quel est le plus haut sommet du monde ?", {"Mont Everest", "K2", "Mont Kilimandjaro", "Mont McKinley"}, 0},
        {"Quelle est la monnaie du Japon ?", {"Yen", "Dollar", "Euro", "Roupie"}, 0},
        {"Quelle est la langue officielle de l'Australie ?", {"Anglais", "Français", "Espagnol", "Allemand"}, 0},
        {"Qui a peint la Mona Lisa ?", {"Leonardo da Vinci", "Pablo Picasso", "Vincent van Gogh", "Michelangelo"}, 0},

    };
    
    int num_questions = sizeof(questions) / sizeof(questions[0]);
    
    int choice;
    int high_score = 0;
    
    do {
        printf("\n=== Jeu de Quiz ===\n");
        printf("1. Jouer\n");
        printf("2. Afficher le score le plus élevé\n");
        printf("3. Réinitialiser le score\n");
        printf("4. Aide\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                play_quiz(questions, num_questions);
                break;
            case 2:
                record(high_score);
                break;
            case 3:
                reset_score(&high_score);
                break;
            case 4:
                help();
                break;
            case 5:
                printf("Merci d'avoir joué ! Au revoir.\n");
                break;
            default:
                printf("Choix invalide. Veuillez sélectionner une option valide.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}
