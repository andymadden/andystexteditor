#include "app_windows.h"

struct AppMainWindow 
create_main_window()
{
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW (window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW (window), 200, 200);

    GtkWidget *textarea = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (textarea));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_container_add(GTK_CONTAINER(window), textarea);

    gtk_widget_show_all(window);

    struct AppMainWindow mainWindow;
    mainWindow.window = window;
    mainWindow.editor_buffer = buffer;

    return mainWindow;
}