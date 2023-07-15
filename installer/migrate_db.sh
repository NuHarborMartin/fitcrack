#!/bin/bash

export MYSQL_PWD="$DB_PW"
echo "DB migration..."
mysql -h $DB_HOST -u $DB_USER -D"$DB_NAME" < server/sql/migration.sql --force