#pragma once

//#include <string>
//#include <mysql.h>
#include <wx/msgdlg.h>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

/* Class MySQL */
class MySQL
{

public:
	sql::Driver *driver;
	sql::Connection *conn;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *pstmt;

	MySQL(const char *hostName="tcp://127.0.0.1:3306", const char *userName="root", const char *password="root", const char *databaseName="lhu_db") {
		try {
			driver = get_driver_instance();

			conn = driver->connect(hostName, userName, password);
			conn->setSchema(databaseName);
		}
		catch (sql::SQLException &e) {
			wxMessageBox(e.what(), "Database Error", wxICON_ERROR);
		}
	}

	~MySQL() {
		//delete driver;
		delete conn;
		delete stmt;
		delete res;
		delete pstmt;
	}
};



