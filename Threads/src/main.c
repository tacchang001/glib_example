#include <glib.h>

#define MAX_THREAD 3

static gpointer gthread_func(gpointer data) {
    gint i, num;
    num = *((gint*)data);
    g_print("num=%d\n", num);
    for (i = 0; i < MAX_THREAD - num; i++) {
        g_print("Thread No. %d, of %d\n", i, num);
    }
    return 0;
}

/**
 * http://www.d3.dion.ne.jp/~fut_nis/Other/GLib_program_04.pdf
 */
gint main(gint argc, gchar* argv[]) {
    GThread *my_thread[MAX_THREAD];
    gint i;
    for (i = 0; i < MAX_THREAD; i++) {
        gchar thname[256];
        g_snprintf(thname, sizeof(thname), "Thread-%d", i);
        g_print("%s is %d\n", thname, i);
        my_thread[i] = g_thread_new(thname, gthread_func, &i);
    }
    g_print("End create thread.\n");
    for (i = 0; i < MAX_THREAD; i++) {
        g_thread_join(my_thread[i]);
    }
    g_print("End join thread.\n");
    return 0;
}
