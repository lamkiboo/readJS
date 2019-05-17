#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <ctype.h>
#include "/home/lbf/Software/Web-1.0.0/cJSON/cJSON.h"
/*
typedef struct cJSON {  //cJSON结构体
       struct cJSON*next,*prev;          
       struct cJSON *child;                   
       int type;                                    
       char *valuestring;                       
       int valueint;                               
       double valuedouble;                    
       char *string;                              
} cJSON;
*/

char port_name[100];
char btr_val[100];

void main(){
    FILE *f;//输入文件
    long len;//文件长度
    char *content;//文件内容
    cJSON *json;//封装后的json对象
    f=fopen("can1.json","rb");
    fseek(f,0,SEEK_END);
    len=ftell(f);
    fseek(f,0,SEEK_SET);
    content=(char*)malloc(len+1);
    fread(content,1,len,f);
    fclose(f);

    cJSON* cjson=cJSON_Parse(content);   
    if(cjson == NULL){
    printf("json pack into cjson error...");
    }

    strcpy(port_name,cJSON_GetObjectItem(cjson,"port")->valuestring);
    strcpy(btr_val,cJSON_GetObjectItem(cjson,"baud")->valuestring);

    printf("%s",port_name);
    printf("%s",btr_val);

    cJSON_Delete(cjson);
}