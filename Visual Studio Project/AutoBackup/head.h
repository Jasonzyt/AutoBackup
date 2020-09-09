/* FILENAME = head.h */
#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include "operate_config.h"
#pragma warning(disable:4996)

using namespace std;

string getTime()
{
    time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
    return tmp;
}
string getZIPFilename()
{
    time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H.zip", localtime(&timep));
    return tmp;
}
int _PR(int PRtype, string text)
{
    ostringstream v1;
    string time = getTime();
    if (PRtype == 0)
    {
        v1 << "[" << time << " INFO] " << text;
        cout << v1.str() << endl;
    }
    else if (PRtype == 1)
    {
        v1 << "[" << time << " WARN] " << text;
        cout << v1.str() << endl;
    }
    else if (PRtype == 2)
    {
        v1 << "[" << time << " ERROR] " << text;
        cout << v1.str() << endl;
    }
    else if (PRtype == 3)
    {
        v1 << "[" << time << "DEBUG]" << text;
        cout << v1.str() << endl;
    }
    return 0;
}
string getCmdStr(string outputdir, string inputdir, string outputfilename)
{
    ostringstream v2;
    v2 << "bz.exe c -y -r -fmt:zip \"" << outputdir << outputfilename << "\" " << "\"" << inputdir << "\" ";
    string v3 = v2.str();
    return v3;
}


string getConfig(string configfile, string key)
{
    operate_config conf(configfile);
    string r1=conf.getValue(key);
    return r1;
}

int StringToInt(string str)
{
    int r2 = atoi(str.c_str());
    return r2;
}
