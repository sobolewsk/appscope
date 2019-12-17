#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/resource.h>
#include <dirent.h>

#include "../../src/wrap.h"
#include "../../src/dbg.h"

// Anecdotal evidence that a proc entry should be max 4096 bytes
#define MAX_PROC 4096

extern char *program_invocation_short_name;
extern struct interposed_funcs_t g_fn;
extern struct rtconfig_t g_cfg;

extern int osGetProcname(char *, int);
extern int osGetNumThreads(pid_t);
extern int osGetNumFds(pid_t);
extern int osGetNumChildProcs(pid_t);
extern int osInitTSC(struct rtconfig_t *);
extern int osGetProcMemory(pid_t);
extern int osIsFilePresent(pid_t, const char *);
extern int osGetCmdline(pid_t, char *, size_t);
