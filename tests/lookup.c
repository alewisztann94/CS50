#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>



const char* lookup(const char* path)
{
    // TODO
    if (path == NULL)
        return "error";
    int length = strlen(path);
    char copy[length+1];
    strcpy(copy, path);
    char* fullStop = strrchr(copy, '.');
    if (strcasecmp(fullStop, ".css") == 0)
        return "text/css";
    else if (strcasecmp(fullStop, ".html") == 0)
        return "text/html";
    else if (strcasecmp(fullStop, ".ico") == 0)
        return "image/x-icon";
    else if (strcasecmp(fullStop, ".jpg") == 0)
        return "image/jpeg";
    else if (strcasecmp(fullStop, ".gif") == 0)
        return "image/gif";
    else if (strcasecmp(fullStop, ".js") == 0)
        return "text/javascript";
    else if (strcasecmp(fullStop, ".php") == 0)
        return "text/x-php";
    else if (strcasecmp(fullStop, ".png") == 0)
        return "image/png";
    else
        return NULL;
}

int main(void)
{
 
    
    char* line = "GET /hello.php?name=Alice HTTP/1.1\r\n";
    
    int linelen = strlen(line);
    char copyCat[linelen+1];
    strcpy(copyCat, line);
    int count = 0;
    for (int i = 0; i < linelen; i++)
    {
        if (copyCat[i] == ' ')
            count++;
        if (copyCat[linelen-2] != '\r' || copyCat[linelen-1] != '\n')
            printf("duh hellloh\n");
    }
    if (count != 2)
        printf("puck you fool!");
        
    
    
    
    
    char* firstSpace = strchr(line, ' ');
    int methodSize = firstSpace - line;
    char method[methodSize];
    strncpy(method, line, methodSize);
    char* secondSpace = strrchr(line, ' ');
    int reqSize = secondSpace - firstSpace - 1;
    char req[reqSize];
    strncpy(req, firstSpace+1, reqSize);
    req[reqSize] = '\0';
    char* CRLF = strchr(line, '\r');
    int versSize = CRLF - secondSpace - 1;
    char vers[versSize];
    strncpy(vers, secondSpace+1, versSize);

    if (strncmp(method, "GET", methodSize) != 0)
    {
        printf("nyes\n");
    }
    if (req[0] != '/')
    {   
        printf("nyes\n");
    }    
    if (strchr(req, '"') != NULL)
    {
        printf("nyes\n");
    }    
    if (strncmp(vers, "HTTP/1.1", versSize) != 0)
    {
        printf("nyes\n");
    }  
    
    char* abs_path = malloc(100);
  
    char* query = malloc(100);
    
    
    char* qmark = strchr(line, '?');
    if (qmark != NULL)
    {
        int querySize = secondSpace - qmark - 1;
        printf("%i", querySize);
        char queryCopy[querySize];
        strncpy(queryCopy, qmark+1, querySize+1);
        queryCopy[querySize] = '\0';
        strncpy(query, queryCopy, querySize+1);
        int distance = qmark - firstSpace - 1;
        req[distance] = '\0';
        strncpy(abs_path, req, distance+1);
    }    
    else 
    {
        query = "";
        strncpy(abs_path, req, reqSize+1);
    }    
    
    
    printf("%s\n", query);

}
