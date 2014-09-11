/**************************************************************************************************/
/* Copyright (C) luoxiaobo, SSE@USTC, 2014-2015                                                   */
/*                                                                                                */
/*  FILE NAME             :  cmddemo.c                                                            */
/*  PRINCIPAL AUTHOR      :  Luoxiaobo                                                            */
/*  SUBSYSTEM NAME        :  cmddemo                                                              */
/*  MODULE NAME           :  cmddemo                                                              */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/11                                                           */
/*  DESCRIPTION           :  This is a cmd demo program                                           */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Luoxiaobo, 2014/09/11
 *
 */


#include <stdio.h>
#include <stdlib.h>

int IsExist(char* cmd);
int ShowAllCmd();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    int     (*isexist)(char *);
    struct  DataNode *next;
} tDataNode;

static tDataNode head[] = 
{
    {"help", "this is help cmd!", IsExist,&head[1]},
    {"version", "cmd demo program v1.0", NULL, &head[2]},
    {"author", "luoxiaobo sse ustc", NULL, &head[3]},
    {"date", "date is 2014 9 11", NULL, &head[4]},
    {"log", "this is cmd log", NULL, NULL}
};
main()
{
   /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a command > ");
        scanf("%s", cmd);
	if(!strcmp(cmd,"help"))
	{
		ShowAllCmd();
	}
	else
	{
		head->isexist(cmd);
 	}      
        
    }
}

int IsExist (char* cmd)
{
    /*judge if the cmd exist and if yes then print */
    tDataNode *p = head;
    while(p != NULL)
    {
    	if(!strcmp(p->cmd, cmd))
        {
            printf("%s - %s\n", p->cmd, p->desc);
            return 1;
			break;
        }
        p = p->next;
    }
    if(p == NULL) 
    {
        printf("This is a wrong cmd!\n ");
		return 0;
    }
}

int ShowAllCmd()
{	
    /*show all cmds */
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s\n", p->cmd);
        p = p->next;
    }
    return 0; 
}
