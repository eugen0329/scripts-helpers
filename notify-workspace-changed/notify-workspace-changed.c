#include <stdlib.h>
#include <libwnck/libwnck.h>

static void on_workspace_changed(WnckScreen *screen, WnckWorkspace *space, gpointer data)
{
    system("xfconf-query -c xfce4-panel -p /panels/panel-2/autohide-behavior -t bool -s false");
    system("xfconf-query -c xfce4-panel -p /panels/panel-2/autohide-behavior -t int -s 2");
}

int main(int argc, char ** argv)
{

   GMainLoop *loop;
   WnckScreen *screen;

   gdk_init (&argc, &argv);

   loop = g_main_loop_new (NULL, FALSE);
   screen = wnck_screen_get_default();

   g_signal_connect(
        screen,
        "active-workspace-changed",
        G_CALLBACK (on_workspace_changed),
        NULL
    );

   g_main_loop_run(loop);
   g_main_loop_unref(loop);

   return 0;
}

