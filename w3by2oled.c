#include "w3by2oled.h"

#ifdef BONGO_ENABLE
#include "bongo.h"
#endif

void oled_task_user(void) {
draw_bongo();
}