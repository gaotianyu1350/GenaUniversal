/***************************************************************
 * Name:      runner_win.c
 * Purpose:   runner for windows operating system
 * Author:    VL (Vincent Gao, Liangjs)
 * Created:   2015-03-10
 * Copyright: VL (Vincent Gao, Liangjs)
 **************************************************************/

#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <string.h>
#include <dirent.h>
#include <direct.h>
#include <psapi.h>
typedef char element[MAX_PATH];
element fin, fout;
element in, out, err;
element stop, pwd;
char cmdline[1<<20];
int n;
element (*cmd);
char *getdir(const char *s, char *f)
{
    char *i = strrchr(s, '\\');
    if (i == NULL)
        return strcpy(f, ".\\");
    else
    {
        strncpy(f, s, i - s + 1);
        f[i - s + 1] = '\0';
        return f;
    }
}
int isdir(const char *s)
{
    if (access(s, F_OK))
        return 0;
    FILE *f = fopen(s, "r");
    if (f)
    {
        fclose(f);
        return 0;
    }
    return 1;
}
const char *filetype(const char *s)
{
    int n = strlen(s), i;
    for (i = n - 1; i > 0; --i)
        if (s[i] == '\\')
            return "";
        else if (s[i] == '.')
            return s + i + 1;
    return "";
}
void abspath(char *s)
{
    element tmp;
    int ok[MAX_PATH];
    int i, j;
    if (s[1] != ':' || s[2] != '\\')
        sprintf(tmp, "%s%s", pwd, s);
    else
        strcpy(tmp, s);
    for (i = 0; tmp[i];)
        if (tmp[i] == '.' && tmp[i + 1] == '.' && tmp[i + 2] == '\\')
        {
            int k;
            for (k = i - 2; k >= 0; --k)
                if (tmp[k] == '\\')
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
        else if (tmp[i] == '.' && tmp[i + 1] == '\\')
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
PROCESS_INFORMATION *pinfo;
DWORD exitcode()
{
    DWORD f;
    GetExitCodeProcess(pinfo->hProcess, &f);
    return f;
}
int active()
{
    return exitcode() == STILL_ACTIVE;
}
void kill()
{
    if (active())
        TerminateProcess(pinfo->hProcess, 4);
}
int main(int argc, char *argv[])
{
    getcwd(pwd, sizeof(pwd));
    int lpwd = strlen(pwd);
    if (pwd[lpwd - 1] != '\\')
        pwd[lpwd] = '\\', pwd[lpwd + 1] = '\0';
    if (argc <= 10)
        return 1;
    int arg = 1;
    n = atoi(argv[arg++]);
    if (argc != 11 + n)
        return 1;
    freopen(argv[n + 10], "w", stdout);
    cmd = (element*)malloc(sizeof(element) * n);
    int i;
    for (i = 0; i < n; ++i, ++arg)
    {
        int l = strlen(argv[arg]);
        if (argv[arg][l - 1] == '\\')
        {
            strncpy(cmd[i], argv[arg], l - 1);
            cmd[i][l - 1] = '\0';
        }
        else
            strcpy(cmd[i], argv[arg]);
    }
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
    if (pwd[lpwd - 1] != '\\')
        pwd[lpwd] = '\\', pwd[lpwd + 1] = '\0';
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
        sprintf(tmp, "copy \"%s\" \"%s\" /Y > nul 2>&1", in, fin);
        int t = system(tmp);
        if (t)
        {
           printf("2\n");
           fclose(stdout);
           return 0;
        }
    }
    pinfo = (PROCESS_INFORMATION*)malloc(sizeof(PROCESS_INFORMATION));
    SECURITY_ATTRIBUTES psa = {sizeof(psa), NULL, TRUE};
    psa.bInheritHandle = TRUE;
    HANDLE hInputFile, hOutFile, hErrorFile;
    STARTUPINFO StartInfo;
    memset(&StartInfo, 0, sizeof(STARTUPINFO));
    StartInfo.cb = sizeof(STARTUPINFO);
    StartInfo.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    StartInfo.wShowWindow = SW_HIDE;
    hErrorFile = CreateFile(err, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, &psa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    StartInfo.hStdError = hErrorFile;
    if (strcmp(fin, "!") == 0)
    {
        hInputFile = CreateFile(in, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, &psa, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        StartInfo.hStdInput = hInputFile;
    }
    if (strcmp(fout, "!") == 0)
    {
        hOutFile = CreateFile(out, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, &psa, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        StartInfo.hStdOutput = hOutFile;
    }
    for (i = 0; i < n; ++i)
        strcat(strcat(strcat(cmdline, "\""), cmd[i]), "\" ");
    CreateProcess(NULL, cmdline, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS, NULL, NULL, &StartInfo, pinfo);
    time_t times = clock(), Time = 0;
    int Mem = 0;
    while (active())
    {
        if (access(stop, F_OK) == 0)
        {
            kill();
            printf("-1\n");
            fclose(stdout);
            return 0;
        }
        PROCESS_MEMORY_COUNTERS pmc;
        GetProcessMemoryInfo(pinfo->hProcess, &pmc, sizeof(pmc));
        Mem = max(Mem, pmc.PeakWorkingSetSize / 1024);
        Time = (clock() - times) * 1000 / CLOCKS_PER_SEC;
        if (Mem > lmem || Time > ltime)
        {
            kill();
            printf("0\n");
            printf("%d\n", Time <= ltime ? (int)Time : -1);
            printf("%d\n", Mem <= lmem ? Mem : -1);
            fclose(stdout);
            return 0;
        }
    }
    Time = (clock() - times) * 1000 / CLOCKS_PER_SEC;
    if (strcmp(fout, "!") != 0 && strcmp(fout, out) != 0)
    {
        if (access(fout, F_OK))
        {
            FILE *ff = fopen(out, "w");
            fclose(ff);
        }
        else
        {
            sprintf(tmp, "copy \"%s\" \"%s\" /Y > nul 2>&1", fout, out);
            int t = system(tmp);
            if (t)
            {
                printf("3\n");
                fclose(stdout);
                return 0;
            }
            sprintf(tmp, "del \"%s\" /F > nul 2>&1", fout);
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
        sprintf(tmp, "del \"%s\" /F > nul 2>&1", fin);
        int t = system(tmp);
        if (t)
        {
            printf("2\n");
            fclose(stdout);
            return 0;
        }
    }
    printf("%d\n", (int)exitcode());
    printf("%d\n", (int)Time);
    printf("%d\n", Mem);
    fclose(stdout);
    return 0;
}
