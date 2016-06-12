/*************************************************************************
	> File Name: inmysql.c
	> Author: 
	> Mail: 
	> Created Time: Thu Apr  7 09:38:05 2016
 ************************************************************************/

#include<stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql.h"
#include "errmsg.h"
#include "mysqld_error.h"


MYSQL conn;

void connection(const char* host, const char* user, const char* password, const char* database) {
        mysql_init(&conn); // 注意取地址符&

    if (mysql_real_connect(&conn, host, user, password, database, 0, NULL, 0)) {
                printf("Connection success!\n");
            
    } else {
                fprintf(stderr, "Connection failed!\n");
        if (mysql_errno(&conn)) {
                        fprintf(stderr, "Connection error %d: %s\n", mysql_errno(&conn), mysql_error(&conn));
                    
        }
                exit(EXIT_FAILURE);
            
    }

}

void insert() {
        int res = mysql_query(&conn, "INSERT INTO Position (id,name,time,position) VALUES('3','2','3','4');");
    if (!res) {
                printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(&conn));
            
    } else {
                fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&conn), mysql_error(&conn));
            
    }

}

void update() {
        int res = mysql_query(&conn, "UPDATE student SET student_name='Anna' WHERE student_no='123465'");
    if (!res) {
                printf("Update %lu rows\n", (unsigned long)mysql_affected_rows(&conn));
            
    } else {
                fprintf(stderr, "Update error %d: %s\n", mysql_errno(&conn), mysql_error(&conn));
            
    }

}

void delete() {
        int res = mysql_query(&conn, "DELETE from student WHERE student_no='123465'");
    if (!res) {
                printf("Delete %lu rows\n", (unsigned long)mysql_affected_rows(&conn));
            
    } else {
                fprintf(stderr, "Delete error %d: %s\n", mysql_errno(&conn), mysql_error(&conn));
            
    }

}


int main (int argc, char *argv[]) {
    
        connection("localhost", "root", "linkosky8890", "testDB");
        insert();
        mysql_close(&conn);
        exit(EXIT_SUCCESS);

}

