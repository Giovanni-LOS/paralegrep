#include "../include/thread_ranking.h"
#include "../include/utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void limpar_terminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void remove_if_exists(LinkedList *list, const char *filename) {
    Node *prev = NULL, *curr = list->head;
    while (curr) {
        if (strcmp(curr->filename, filename) == 0) {
            if (prev) {
                prev->next = curr->next;
            } else {
                list->head = curr->next;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

void add_sorted(LinkedList *list, const char *filename, int count) {
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->filename, filename);
    new_node->count = count;
    new_node->next = NULL;

    if (!list->head || list->head->count < count) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node *curr = list->head;
        while (curr->next && curr->next->count >= count) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

void print_ranking(LinkedList *list) {
    limpar_terminal();
    Node *curr = list->head;
    int rank = 1;

    printf("=== Top 10 Arquivos ===\n");
    while (curr && rank <= 10) {
        printf("%d. %s - %d ocorrências\n", rank, curr->filename, curr->count);
        curr = curr->next;
        rank++;
    }
    printf("=======================\n");
}

void *thread_ranking(void *arg) {
    LinkedList list;
    list.head = NULL;
    while (!terminate_program) {
        print_ranking(&list);
        sleep(1);
        pthread_mutex_lock(&rank_lock);
        while (rank_buffer_lenght == 0) {
            pthread_cond_wait(&rank_have_data, &rank_lock);
        }
        if (terminate_program) {
            pthread_mutex_unlock(&rank_lock);
            break;
        }
        remove_if_exists(&list, rank_buffer[rank_buffer_read_index].file_name);
        if (rank_buffer[rank_buffer_read_index].count >= 0) {
            add_sorted(&list, rank_buffer[rank_buffer_read_index].file_name, rank_buffer[rank_buffer_read_index].count);
        }
        rank_buffer_read_index = (rank_buffer_read_index + 1) % RANK_BUFFER_SIZE;
        rank_buffer_lenght--;
        pthread_cond_signal(&rank_have_space);
        pthread_mutex_unlock(&rank_lock);
    }
    Node *curr = list.head;
    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    printf("Ranking thread exiting\n");
    return NULL;
}