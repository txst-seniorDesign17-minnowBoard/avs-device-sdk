/*
 * SQLiteUtils.h
 *
 * Copyright 2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ALEXA_CLIENT_SDK_CAPABILITY_AGENTS_ALERTS_INCLUDE_STORAGE_SQLITE_UTILS_H_
#define ALEXA_CLIENT_SDK_CAPABILITY_AGENTS_ALERTS_INCLUDE_STORAGE_SQLITE_UTILS_H_

#include <sqlite3.h>
#include <string>

namespace alexaClientSDK {
namespace capabilityAgents {
namespace alerts {
namespace storage {

/**
 * Creates a SQLite database at the given filePath.
 * If a file at the given path already exists, this function will fail.
 *
 * @param filePath The location where the database should be created.
 * @return A pointer to the created sqlite database.  If it could not be created, @c nullptr is returned.
 */
sqlite3* createSQLiteDatabase(const std::string & filePath);

/**
 * Opens a SQLite database that will be stored at the given (already existing) filePath.
 * If the database file does not already exist at the given filePath, this function will fail.
 *
 * @param filePath The location of the database file to be opened.
 * @return A pointer to the opened sqlite database.  If it could not be opened, @c nullptr is returned.
 */
sqlite3* openSQLiteDatabase(const std::string & filePath);

/**
 * Closes a SQLite database.
 *
 * @param The handle to sqlite database.
 * @return Whether the operation was successul.
 */
bool closeSQLiteDatabase(sqlite3* dbHandle);

/**
 * Performs a SQL query, and does not inspect any result.  This is an appropriate function to call for simple queries,
 * which do not require bound parameters, such as when creating tables in a database.
 *
 * @param dbHandle A SQLite handle to an open database.
 * @param sqlString The SQL string which contains the full query to be performed.
 * @return Whether the query was successfully performed.
 */
bool performQuery(sqlite3* dbHandle, const std::string & sqlString);

/**
 * Acquires the number of rows in a table within an open database.
 *
 * @param dbHandle A SQLite handle to an open database.
 * @param tableName The name of the table to be queried.
 * @param[out] numberRows Where the number of rows will be stored on a successful lookup.
 * @return Whether the lookup was successful or not.
 */
bool getNumberTableRows(sqlite3* dbHandle, const std::string & tableName, int* numberRows);

/**
 * Queries a specified column in a SQLite table, and identifies the highest value across all rows.
 * This function requires that the table and column exists, and that the column is of integer type.
 *
 * @param dbHandle A SQLite handle to an open database.
 * @param tableName The name of the table to be queried.
 * @param columnName The name of the column in the table to be queried.
 * @param[out] maxId Where the maximum id will be stored on a successful lookup.
 * @return Whether the lookup was successful or not.
 */
bool getTableMaxIntValue(sqlite3* dbHandle, const std::string & tableName, const std::string & columnName, int* maxId);

/**
 * Deletes all records from a table.
 *
 * @param dbHandle A SQLite handle to an open database.
 * @param tableName The name of the table from which all rows should be deleted.
 * @return Whether the table was cleared successfully.
 */
bool clearTable(sqlite3* dbHandle, const std::string & tableName);

} // namespace storage
} // namespace alerts
} // namespace capabilityAgents
} // namespace alexaClientSDK

#endif // ALEXA_CLIENT_SDK_CAPABILITY_AGENTS_ALERTS_INCLUDE_STORAGE_SQLITE_UTILS_H_
