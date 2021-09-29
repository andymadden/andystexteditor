#ifndef APP_WINDOWS_H
#define APP_WINDOWS_H

#include <gtk/gtk.h>
#include <string.h>

/**
 * @author Andrew Madden <andrewsmadden@gmail.com>
 * 
 * This file contains all the declarations used for creating application windows.
 */

/**
 * @struct AppMainWindow
 * 
 * @brief Contains information about an application editor window.
 * 
 * @param window A GTK Window pointer
 * @param editor_buffer A GTK Text Buffer pointer
 */
struct AppMainWindow {
    GtkWidget *window;
    GtkTextBuffer *editor_buffer;
};

/**
 * @brief Used to instantiate the main window of the application
 * 
 * @return AppMainWindow which contains information about the application editor
 */
struct AppMainWindow 
create_main_window();

#endif