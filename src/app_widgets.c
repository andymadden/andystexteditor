#include "app_windows.h"
#include "fileio.h"

gboolean
print_silly(char *text)
{
    g_print("%s\n", text);
    return TRUE;
}

gboolean
open_file_chooser(GtkWidget *widget, 
                  gpointer data)
{
    GtkWidget *file_select = gtk_file_chooser_dialog_new("Open File", GTK_WINDOW(data), GTK_FILE_CHOOSER_ACTION_OPEN, "Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, NULL);
    if (gtk_dialog_run(GTK_DIALOG(file_select)) == GTK_RESPONSE_ACCEPT)
    {
        char *filename;

        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_select));

        struct FileData file_data = read_file(filename);

        gtk_text_buffer_set_text(GTK_TEXT_BUFFER(data), file_data.buffer, strlen(file_data.buffer));
        g_free(filename);
    }
    gtk_widget_destroy(file_select);
    return TRUE;
}

GtkWidget *
create_file_menu(GtkWidget *window, GtkTextBuffer *editor_buffer)
{
    GtkWidget *file_menu = gtk_menu_new();

    // Create file menu items
    GtkWidget *file_menu_new_item = gtk_menu_item_new_with_label("New");
    GtkWidget *file_menu_open_item = gtk_menu_item_new_with_label("Open...");
    GtkWidget *file_menu_save_item = gtk_menu_item_new_with_label("Save");
    GtkWidget *file_menu_save_as_item = gtk_menu_item_new_with_label("Save As...");
    GtkWidget *file_menu_exit_item = gtk_menu_item_new_with_label("Exit");
    
    g_signal_connect(file_menu_open_item, "activate", G_CALLBACK(open_file_chooser), editor_buffer);

    g_signal_connect(file_menu_exit_item, "activate", G_CALLBACK(gtk_main_quit), NULL);

    // Populate file menu items
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_menu_new_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_menu_open_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_menu_save_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_menu_save_as_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_menu_exit_item);

    return file_menu;
}

GtkWidget *
create_help_menu(GtkWidget *window, GtkTextBuffer *editor_buffer)
{
    GtkWidget *help_menu = gtk_menu_new();

    GtkWidget *help_menu_help_item = gtk_menu_item_new_with_label("Help...");
    GtkWidget *help_menu_about_item = gtk_menu_item_new_with_label("About...");

    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), help_menu_help_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), help_menu_about_item);

    return help_menu;
}

GtkWidget *
create_menu_bar(GtkWidget *window, GtkTextBuffer *editor_buffer)
{
    GtkWidget *menu_bar = gtk_menu_bar_new();

    // Menu bar items
    GtkWidget *file_menu_item = gtk_menu_item_new_with_label("File");
    GtkWidget *help_menu_item = gtk_menu_item_new_with_label("Help");

    // Menus
    GtkWidget *file_menu = create_file_menu(window, editor_buffer);
    GtkWidget *help_menu = create_help_menu(window, editor_buffer);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_menu_item), help_menu);

    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_menu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), help_menu_item);

    return menu_bar;
}