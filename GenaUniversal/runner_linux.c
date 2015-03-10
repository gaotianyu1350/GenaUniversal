/***************************************************************
 * Name:      runner_linux.c
 * Purpose:   runner for unix-like operating system
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/timeb.h>
typedef char element[PATH_MAX];
element fin, fout;
element in, out, err;
element stop, pwd;
int n;
char **cmd;
char *getdir(const char *s, char *f)
{
    char *i = strrchr(s, '/');
    if (i == NULL)
        return strcpy(f, "./");
    else
    {
        strncpy(f, s, i - s + 1);
        f[i - s + 1] = '\0';
        return f;
    }
}
int isdir(const char *s)
{
    struct stat info;
    stat(s, &info);
    return S_ISDIR(info.st_mode);
}
const char *filetype(const char *s)
{
    int n = strlen(s), i;
    for (i = n - 1; i > 0; --i)
        if (s[i] == '/')
            return "";
        else if (s[i] == '.')
            return s + i + 1;
    return "";
}
void abspath(char *s)
{
    element tmp;
    int ok[PATH_MAX];
    if (s[0] != '/')
        sprintf(tmp, "%s%s", pwd, s);
    else
        strcpy(tmp, s);
    int i, j;
    for (i = 0; tmp[i];)
        if (tmp[i] == '.' && tmp[i + 1] == '.' && tmp[i + 2] == '/')
        {
            int k;
            for (k = i - 2; k >= 0; --k)
                if (tmp[k] == '/')
                    break;
            if (k >= 0)
            {
                for (j = k; j <= i + 1; ++j)
                    ok[j] = 0;
                ok[i + 2] = 1;
            }
            else
                ok[i] = ok[i + 1] = ok[i + 2] = 1;
            i += 3;
        }
        else if (tmp[i] == '.' && tmp[i + 1] == '/')
        {
            ok[i] = ok[i + 1] = 0;
            i += 2;
        }
        else
            ok[i++] = 1;
    for (i = j = 0; tmp[i]; ++i)
        if (ok[i])
            s[j++] = tmp[i];
    s[j] = '\0';
}
element tmp;
void check()
{
    if (access(in, R_OK))
    {
        printf("2\n");
        fclose(stdout);
        exit(0);
    }
    if (!isdir(getdir(out, tmp)))
    {
        printf("3\n");
        fclose(stdout);
        exit(0);
    }
    if (access(out, F_OK) == 0)
    {
        if (isdir(out))

        {
            printf("3\n");
            fclose(stdout);
            exit(0);
        }
        else if (access(out, W_OK))
        {
            printf("3\n");
            fclose(stdout);
            exit(0);
        }
    }
}
int ltime, lmem;
pid_t pid;
int exitcode = 259;
int active()
{
    sprintf(tmp, "ps -A | grep %d", pid);
    FILE *f = popen(tmp, "r");
    fgets(tmp, sizeof(tmp), f);
    pclose(f);
    if (strstr(tmp, "<defunct>"))
        return 0;
    else
        return 1;
}
int getexitcode()
{
    if (active())
        return exitcode = 259;
    if (exitcode != 259)
        return exitcode;
    wait(&exitcode);
    exitcode = WEXITSTATUS(exitcode);
    return exitcode;
}
void killjudge()
{
    sprintf(tmp, "kill %d > /dev/null", pid);
    system(tmp);
}
int getmemory()
{
    sprintf(tmp, "ps -eo pid,rss | grep %d", pid);
    FILE *f = popen(tmp, "r");
    int a;
    fscanf(f, "%d%d", &a, &a);
    pclose(f);
    return a;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int main(int argc, char *argv[])
{
    getcwd(pwd, sizeof(pwd));
    int lpwd = strlen(pwd);
    if (pwd[lpwd - 1] != '/')
        pwd[lpwd] = '/', pwd[lpwd + 1] = '\0';
    if (argc <= 10)
        return 1;
    int arg = 1;
    n = atoi(argv[arg++]);
    if (argc != 11 + n)
        return 1;
    freopen(argv[n + 10], "w", stdout);
    cmd = (char **)malloc(sizeof(char *) * (n + 1));
    int i;
    for (i = 0; i < n; ++i)
    {
        cmd[i] = (char *)malloc(sizeof(element));
        strcpy(cmd[i], argv[arg++]);
    }
    cmd[n] = NULL;
    getdir(cmd[0], tmp);
    if (strcmp(argv[arg], "!") == 0)
        fin[0] = '!', fin[1] = '\0';
    else
        sprintf(fin, "%s%s", tmp, argv[arg]);
    ++arg;
    if (strcmp(argv[arg], "!") == 0)
        fout[0] = '!', fout[1] = '\0';
    else
        sprintf(fout, "%s%s", tmp, argv[arg]);
    ++arg;
    chdir(tmp);
    strcpy(in, argv[arg++]);
    strcpy(out, argv[arg++]);
    strcpy(err, argv[arg++]);
    abspath(out);
    abspath(in);
    abspath(err);
    getcwd(pwd, sizeof(pwd));
    lpwd = strlen(pwd);
    if (pwd[lpwd] != '/')
        pwd[lpwd] = '/', pwd[lpwd + 1] = '\0';
    if (strcmp(fin, "!") != 0)
        abspath(fin);
    if (strcmp(fout, "!") != 0)
        abspath(fout);
    check();
    ltime = atoi(argv[arg++]);
    lmem = atoi(argv[arg++]);
    strcpy(stop, argv[arg++]);
    if (strcmp(fin, "!") != 0 && strcmp(fin, in) != 0)
    {
        sprintf(tmp, "cp \"%s\" \"%s\" > /dev/null 2>&1", in, fin);
        int t = system(tmp);
        if (t)
        {
            printf("2\n");
            fclose(stdout);
            return 0;
        }
    }
    struct timeb times, timet;
    int Time = 0, Mem = 0;
    pid = fork();
    if (!pid)
    {
        if (strcmp(fin, "!") == 0)
            freopen(in, "r", stdin);
        if (strcmp(fout, "!") == 0)
            freopen(out, "w", stdout);
        freopen(err, "w", stderr);
        execvp(cmd[0], cmd);
    }
    else
    {
        ftime(&times);
        do
        {
            if (access(stop, F_OK) == 0)
            {
                killjudge();
                printf("-1\n");
                fclose(stdout);
                return 0;
            }
            ftime(&timet);
            Time = (timet.time - times.time) * 1000 + (timet.millitm - times.millitm);
            Mem = max(Mem, getmemory());
            if (Mem > lmem || Time > ltime)
            {
                killjudge();
                printf("0\n");
                printf("%d\n", Time <= ltime ? (int)Time : -1);
                printf("%d\n", Mem <= lmem ? Mem : -1);
                fclose(stdout);
                return 0;
            }
        }
        while (active());
    }
    ftime(&timet);
    Time = (timet.time - times.time) * 1000 + (timet.millitm - times.millitm);
    if (strcmp(fout, "!") != 0 && strcmp(fout, out) != 0)
    {
        if (access(fout, F_OK))
        {
            FILE *ff = fopen(out, "w");
            fclose(ff);
        }
        else
        {
            sprintf(tmp, "cp \"%s\" \"%s\" > /dev/null 2>&1", fout, out);
            int t = system(tmp);
            if (t)
            {
                printf("3\n");
                fclose(stdout);
                return 0;
            }
            sprintf(tmp, "rm \"%s\" -f > /dev/null 2>&1", fout);
            t = system(tmp);
            if (t)
            {
                printf("3\n");
                fclose(stdout);
                return 0;
            }
        }
    }
    if (strcmp(fin, "!") != 0 && strcmp(fin, in) != 0)
    {
        sprintf(tmp, "rm \"%s\" -f > /dev/null 2>&1", fin);
        int t = system(tmp);
        if (t)
        {
            printf("2\n");
            fclose(stdout);
            return 0;
        }
    }
    printf("%d\n", getexitcode());
    printf("%d\n", Time);
    printf("%d\n", Mem);
    fclose(stdout);
    return 0;
}
