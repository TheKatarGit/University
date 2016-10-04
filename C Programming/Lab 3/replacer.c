#include "replacer.h"

void replaceElements(struct list_node *head) {
  int max_el = head->num, min_el = head->num;
  struct list_node *max_el_pos, *min_el_pos;
  max_el_pos = head->next;
  min_el_pos = head->next;
  struct list_node *nodes = head;
  for ( ; head; head = head->next){
      if (head->num > max_el){
          max_el_pos = head->next;
          max_el = head->num;
        }
      if (head->num < min_el) {
        min_el_pos = head->next;
        min_el = head->num;
      }
    }
  head = nodes;
  for ( ; head; head = head->next){
    if (head->next == min_el_pos){
      head->num = max_el;
    }
    if (head->next == max_el_pos){
      head->num = min_el;
    }
  }
}
