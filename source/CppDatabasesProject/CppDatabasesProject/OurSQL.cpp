#pragma warning(disable : 4996)
//#include "OurSQL.h"

//#include <string.h>
//#include <wx/wx.h>
//
//OurSQL::OurSQL(const char *host, const char *user, const char *password, const char *db, unsigned int port, const char *unix_socket, unsigned long clientflag)
//{
//	this->conn = mysql_init(0);
//	this->conn = mysql_real_connect(conn, host, user, password, db, port, unix_socket, clientflag);
//	result = (char **)malloc(10 * sizeof(char *));
//}
//
//
//OurSQL::~OurSQL()
//{
//	mysql_close(this->conn);
//}
//
//bool OurSQL::make_query(const char *query) {
//	return mysql_query(conn, query);
//}
//
//char **OurSQL::query_get_result(const char *query, const char *table_name) {
//	// Stores the result of the SQL Query in an array of char arrays. 
//	// In -> Valid SQL Query and table name
//	// Out -> A char** array containing the result of the SQL Query.
//	/* TODO: Use std::vector<string> instead of char** as result size is unknown until the query is run. I.e. the result size is dynamic */
//
//	MYSQL_ROW ROW;
//	//mysql_query(this->conn, )
//	mysql_query(this->conn, query);
//	this->queryResult = mysql_store_result(this->conn);
//
//	int num_fields = mysql_num_fields(queryResult);
//	char **result = (char**)malloc((26) * sizeof(char*));
//	for (int i = 0; i < 26; i++)
//		result[i] = (char*)malloc(200 * sizeof(char));
//
//	char buffer[200];
//
//	int rowsCount = 0;
//	while ((ROW = mysql_fetch_row(queryResult))) {
//		rowsCount++;
//		for (int i = 0; i < num_fields; i += num_fields) {
//			sprintf(buffer, "%s %s %s %s", ROW[i], ROW[i + 1], ROW[i + 2], ROW[i + 3]);
//		}
//		strcpy(result[rowsCount], buffer);
//	}
//	//wxMessageBox("Result size: " + std::to_string(sizeof(result) / sizeof(result[0])));
//	return result;
//	//mysql_free_result(queryResult);
//
//}
