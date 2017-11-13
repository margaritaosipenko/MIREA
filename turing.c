void turing(DbLink *list, struct _progr arr[], int cmd) {
    int error = 0;
    int headstate = 1;
    char replace_symb;
    char temp;
    FILE *result = fopen("result.txt", "wb");
    int i = 0;
    Raw *tmp;
    tmp = list->head;
    fprintf(result, "Result is: ");
    while (tmp != NULL && error != 1) {
        for (i = 0; i < cmd; i++) {
            if (tmp != NULL) {
                temp = tmp->value;
                if (temp == arr[i].inputsymb && headstate == arr[i].state) {
                    replace_symb = arr[i].outputsymb;
                    headstate = arr[i].newstate;
                    fprintf(result, "%c", replace_symb);
                    printf("%c ", replace_symb);
                    switch (arr[i].action) {
                    case 'R': { tmp = tmp->next; break;}
                    case 'L': { tmp = tmp->prev; break;}
                    case 'S': { error = 1; break;}
                    }
                }
            }
        }
    }
    printf("\n");
}






