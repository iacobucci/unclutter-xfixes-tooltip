// vim:ts=4:sw=4:expandtab
#include "../include/all.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <unistd.h>

static bool hidden = false;

coordinates_t saved_position = { 0, 0 };

Window root_window;
unsigned int curs_mask;

void cursor_show()
{
    if (!hidden)
        return;

    if (config.move_cursor) {
        XSelectInput(display, active_root, KeyReleaseMask);
        XWarpPointer(display, None, active_root, 0, 0, 0, 0, saved_position.x, saved_position.y);
        XFlush(display); // Flushes the output buffer, therefore updates the cursor's position. Thanks to Achernar.
    }

    DLOG("Showing the cursor.");
    XFixesShowCursor(display, active_root);
    XFlush(display);
    hidden = false;
}

void cursor_hide()
{
    if (hidden)
        return;

    if (config.move_cursor) {
        XQueryPointer(display, DefaultRootWindow(display), &root_window, &root_window, &saved_position.x, &saved_position.y, &saved_position.x, &saved_position.y, &curs_mask);

        XSelectInput(display, active_root, KeyReleaseMask);
        XWarpPointer(display, None, active_root, 0, 0, 0, 0, config.new_coordinates.x, config.new_coordinates.y);
        XFlush(display); // Flushes the output buffer, therefore updates the cursor's position. Thanks to Achernar.
    }

    DLOG("Hiding the cursor.");
    XFixesHideCursor(display, active_root);
    XFlush(display);
    hidden = true;
}

void cursor_find(Window* child, int* root_x, int* root_y)
{
    Window root;
    int win_x, win_y;
    unsigned int mask;
    int screen;

    for (screen = 0; screen < num_screens; screen++) {
        if (XQueryPointer(display, roots[screen], &root, child, root_x, root_y, &win_x, &win_y, &mask)) {
            active_screen = screen;
            active_root = roots[screen];
            break;
        }
    }
}
