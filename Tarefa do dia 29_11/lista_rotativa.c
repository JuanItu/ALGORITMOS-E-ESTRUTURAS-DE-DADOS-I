/*
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head -> next == NULL || k == 0){
        return head;
    }

    int comprimento = 1;
    struct ListNode* ultimo = head;

    while(ultimo -> next != NULL ){
        ultimo = ultimo -> next;
        comprimento++;
    }
     
    k = k % comprimento;
    if(k == 0){
        return head;
    }

    struct ListNode* new_ultimo = head;

    for(int i = 0; i < comprimento - k - 1; i++){
        new_ultimo = new_ultimo -> next;
    }

    struct ListNode* new_head = new_ultimo -> next;
    new_ultimo -> next = NULL;
    ultimo -> next = head;

    return new_head;
}
*/